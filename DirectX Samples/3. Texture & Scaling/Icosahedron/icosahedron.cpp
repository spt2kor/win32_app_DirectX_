
#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include "resource.h"



#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")
using namespace DirectX;

//--------------------------------------------------------------------------------------
// Structures
//--------------------------------------------------------------------------------------
struct SimpleVertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};


struct ConstantBuffer
{
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;
};


//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               g_hInst = nullptr;
HWND                    g_hWnd = nullptr;
ID3D11Device*           g_pd3dDevice = nullptr;
ID3D11DeviceContext*    g_pImmediateContext = nullptr;
IDXGISwapChain*         g_pSwapChain = nullptr;
ID3D11RenderTargetView* g_pRenderTargetView = nullptr;
ID3D11VertexShader*     g_pVertexShader = nullptr;
ID3D11PixelShader*      g_pPixelShader = nullptr;
ID3D11InputLayout*      g_pVertexLayout = nullptr;
ID3D11Buffer*           g_pVertexBuffer = nullptr;
ID3D11Buffer*           g_pIndexBuffer = nullptr;
ID3D11Buffer*           g_pConstantBuffer = nullptr;
XMMATRIX                g_World;
XMMATRIX                g_View;
XMMATRIX                g_Projection;


//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow );
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK    WndProc( HWND, UINT, WPARAM, LPARAM );
void Render();


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow )
{
    //UNREFERENCED_PARAMETER( hPrevInstance );
    //UNREFERENCED_PARAMETER( lpCmdLine );


    if( FAILED( InitWindow( hInstance, nCmdShow ) ) )		// window Initialize
        return 0;

    if( FAILED( InitDevice() ) )
    {
        CleanupDevice();
        return 0;
    }

    // Main message loop
    MSG msg = {0};
	while (TRUE)
    {
        if( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            Render();
        }
    }

    CleanupDevice();
    return ( int )msg.wParam;
}


//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow )
{
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof( WNDCLASSEX );
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon( hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    wcex.hCursor = LoadCursor( nullptr, IDC_ARROW );
    wcex.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"TutorialWindowClass";
    wcex.hIconSm = LoadIcon( wcex.hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    if( !RegisterClassEx( &wcex ) )
        return E_FAIL;

    // Create window
    g_hInst = hInstance;
    RECT rc = { 0, 0, 800, 600 };
    AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
    g_hWnd = CreateWindow( L"TutorialWindowClass", L"Direct3D 11 Tutorial 4: 3D Spaces",
                           WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                           CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
                           nullptr );
    if( !g_hWnd )
        return E_FAIL;

    ShowWindow( g_hWnd, nCmdShow );

    return S_OK;
}



//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
HRESULT InitDevice()
{
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect( g_hWnd, &rc );
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

	DXGI_SWAP_CHAIN_DESC scd;

    // clear out the struct for use
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    // fill the swap chain description struct
    scd.BufferCount = 1;                                   // one back buffer
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // use 32-bit color
	scd.BufferDesc.Width = width;                   // set the back buffer width
    scd.BufferDesc.Height = height;                 // set the back buffer height
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;     // how swap chain is to be used
    scd.OutputWindow = g_hWnd;                               // the window to be used
    scd.SampleDesc.Count = 4;                              // how many multisamples
    scd.Windowed = TRUE;                                   // windowed/full-screen mode
    scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching

    // create a device, device context and swap chain using the information in the scd struct
    D3D11CreateDeviceAndSwapChain(NULL,
                                  D3D_DRIVER_TYPE_HARDWARE,
                                  NULL,
                                  NULL,
                                  NULL,
                                  NULL,
                                  D3D11_SDK_VERSION,
                                  &scd,
                                  &g_pSwapChain,
                                  &g_pd3dDevice,
                                  NULL,
                                  &g_pImmediateContext);

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = nullptr;

	// get the address of the backbuffer
    hr = g_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast<void**>( &pBackBuffer ) );

	// create render target
    hr = g_pd3dDevice->CreateRenderTargetView( pBackBuffer, nullptr, &g_pRenderTargetView );
    pBackBuffer->Release();

	// set render target
    g_pImmediateContext->OMSetRenderTargets( 1, &g_pRenderTargetView, nullptr );

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_pImmediateContext->RSSetViewports( 1, &vp );

	    ID3D10Blob * pVSBlob, * pPSBlob;  // blob object will be filled with the compiled code of the shader.
    D3DX11CompileFromFile(L"icosahedron.fx", 0, 0, "VS", "vs_4_0", 0, 0, 0, &pVSBlob, 0, 0); // VShader - Function , vs_4_0 - version
    D3DX11CompileFromFile(L"icosahedron.fx", 0, 0, "PS", "ps_4_0", 0, 0, 0, &pPSBlob, 0, 0); // PShader - Function , ps_4_0 - version

    // encapsulate both shaders into shader objects
   g_pd3dDevice->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &g_pVertexShader);
    g_pd3dDevice->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &g_pPixelShader);

    // set the shader objects
    g_pImmediateContext->VSSetShader(g_pVertexShader, 0, 0);
    g_pImmediateContext->PSSetShader(g_pPixelShader, 0, 0);

    // Define the input layout
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	UINT numElements = ARRAYSIZE( layout );

    // Create the input layout
	hr = g_pd3dDevice->CreateInputLayout( layout, numElements, pVSBlob->GetBufferPointer(),pVSBlob->GetBufferSize(), &g_pVertexLayout );
	pVSBlob->Release();

    // Set the input layout
    g_pImmediateContext->IASetInputLayout( g_pVertexLayout );
	FLOAT v = 1.61803398875f;
    // Create vertex buffer // A vertex buffer contains the vertex data used to define your geometry.
    SimpleVertex vertices[] =
    {
		{ XMFLOAT3( -1,  v,  0 ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) }, //0
		{ XMFLOAT3( 1,  v,  0 ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },  //1
		{ XMFLOAT3( -1,  -v,  0 ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) }, //2
        { XMFLOAT3( 1,  -v,  0 ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) }, //3

		{ XMFLOAT3(  0, -1,  v ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) }, //4 
		{ XMFLOAT3(  0, 1,  v ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },  //5 
		{ XMFLOAT3(  0, -1,  -v ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) }, //6
        { XMFLOAT3(  0, 1,  -v ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },  //7

		{ XMFLOAT3( v,  0, -1 ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) }, //8
		{ XMFLOAT3( v,  0, 1 ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },  //9
		{ XMFLOAT3( -v,  0, -1 ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) }, //10
		{ XMFLOAT3( -v,  0, 1), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) }, //11 
        

	
    };
    D3D11_BUFFER_DESC bd; // Describes a buffer resource.
	ZeroMemory( &bd, sizeof(bd) );
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof( SimpleVertex ) * 12;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA InitData;  // Specifies data for initializing a subresource. 
	ZeroMemory( &InitData, sizeof(InitData) );

    InitData.pSysMem = vertices;
    hr = g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );

    // Set vertex buffer // select which vertex buffer to display
    UINT stride = sizeof( SimpleVertex );
    UINT offset = 0;
    g_pImmediateContext->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );


	//int i;
	//FLOAT newx[12],newy[12];
	//int a,b,c; 
	//for(i=0;i<=11;i++)
	//{
	//	newx[i]= (vertices[i].Pos.x + vertices[i+1].Pos.x) /2 ;
	//	newy[i]= (vertices[i].Pos.y + vertices[i+1].Pos.y)/2 ;

	//	vertices[i],newx[i],newy[i];
	//}



    // Create index buffer // Index buffers contain integer offsets into vertex buffers and are used to render primitives more efficiently.
    WORD indices[] =
    {
  // 5 faces around point 0
	0, 11, 5,
	0, 5, 1,
	0, 1, 7,
	0, 7, 10,
	0, 10, 11,

// 5 adjacent faces
	1, 5, 9,
	5, 11, 4,
	11, 10, 2,
	10, 7, 6,
	7, 1, 8,

// 5 faces around point 3
	3, 9, 4,
	3, 4, 2,
	3, 2, 6,
	3, 6, 8,
	3, 8, 9,

// 5 adjacent faces
	4, 9, 5,
	2, 4, 11,
	6, 2, 10,
	8, 6, 7,
	9, 8, 1
    };
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof( WORD ) * 60;        // 36 vertices needed for 12 triangles in a triangle list
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;

    InitData.pSysMem = indices;
    hr = g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pIndexBuffer );
 
    // Set index buffer
    g_pImmediateContext->IASetIndexBuffer( g_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0 );

    // Set primitive topology
    g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Create the constant buffer // hold the information we want to pass to the constant buffer in the fx file
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(ConstantBuffer);
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;
    hr = g_pd3dDevice->CreateBuffer( &bd, nullptr, &g_pConstantBuffer );

    // Initialize the world matrix // create the world matrix which will be sent to the vertex shader to reposition the objects vertices correctly.
	// Builds the identity matrix.
	g_World = XMMatrixIdentity();

    // Initialize the view matrix // we will define our cameras position, Target, and up vectors
	XMVECTOR Eye = XMVectorSet( 0.0f, 1.0f, -5.0f, 0.0f ); // Position of the camera
	XMVECTOR At = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );   // Position of the focal point
	XMVECTOR Up = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );   // Up direction of the camera
	//Builds a view matrix for a left-handed coordinate system using a camera position, an up direction, and a focal point.
	g_View = XMMatrixLookAtLH( Eye, At, Up );

    // Initialize the projection matrix //Builds a left-handed perspective projection matrix based on a field of view.
	g_Projection = XMMatrixPerspectiveFovLH( XM_PIDIV2, width / (FLOAT)height, 0.01f, 100.0f );

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
	 g_pImmediateContext->ClearState();
	 g_pd3dDevice->Release();
	 g_pConstantBuffer->Release();
     g_pVertexBuffer->Release();
     g_pIndexBuffer->Release();
     g_pVertexLayout->Release();
     g_pVertexShader->Release();
     g_pPixelShader->Release();
     g_pRenderTargetView->Release();
     g_pSwapChain->Release();
	 g_pImmediateContext->Release();

}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch( message )
    {
    case WM_PAINT:
        hdc = BeginPaint( hWnd, &ps );
        EndPaint( hWnd, &ps );
        break;
	
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

    default:
        return DefWindowProc( hWnd, message, wParam, lParam );
    }

    return 0;
}


//--------------------------------------------------------------------------------------
// Render a frame
//--------------------------------------------------------------------------------------
void Render()
{

    static float t = 0.0f;

        static ULONGLONG timeStart = 0;
        ULONGLONG timeCur = GetTickCount64(); // Retrieves the number of milliseconds that have elapsed since the system was started.
        if( timeStart == 0 )
            timeStart = timeCur;
        t = ( timeCur - timeStart ) / 1000.0f;
   

    //
    // Animate the cube
    //
	g_World= XMMatrixRotationY( t );

    //
    // Clear the back buffer
    //
    g_pImmediateContext->ClearRenderTargetView( g_pRenderTargetView, Colors::MidnightBlue );

    //
    // Update variables
    //
    ConstantBuffer cb;

	// When sending matrices to the fx file in direct3d 11, we must send the matrices "transpose", where the rows and colums are switched.
	cb.mWorld = XMMatrixTranspose( g_World );
	cb.mView = XMMatrixTranspose( g_View );
	cb.mProjection = XMMatrixTranspose( g_Projection );

	// update our applications Constant Buffers Buffer with the ConstantBuffer structure containing our updated WVP matrix
	g_pImmediateContext->UpdateSubresource( g_pConstantBuffer, 0, nullptr, &cb, 0, 0 );

    //
    
    //set the Vertex Shaders constant buffer to our applications constant buffers buffer
	g_pImmediateContext->VSSetShader( g_pVertexShader, nullptr, 0 );
	g_pImmediateContext->PSSetShader( g_pPixelShader, nullptr, 0 );
	g_pImmediateContext->VSSetConstantBuffers( 0, 1, &g_pConstantBuffer );

	// Renders a triangle
	g_pImmediateContext->DrawIndexed( 60, 0, 0 );        // 36 vertices needed for 12 triangles in a triangle list

    //
    // Present our back buffer to our front buffer
    //
    g_pSwapChain->Present( 0, 0 );
}

