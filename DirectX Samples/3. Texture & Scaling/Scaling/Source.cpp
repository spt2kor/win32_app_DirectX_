//Include and link appropriate libraries and headers//
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <xnamath.h>

//Global Declarations - Interfaces//
IDXGISwapChain* SwapChain;
ID3D11Device* d3d11Device;
ID3D11DeviceContext* d3d11DevCon;
ID3D11RenderTargetView* renderTargetView;
ID3D11Buffer* squareIndexBuffer;
ID3D11Buffer* squareVertBuffer;
ID3D11VertexShader* VS;
ID3D11PixelShader* PS;
ID3D10Blob* VS_Buffer;
ID3D10Blob* PS_Buffer;
ID3D11InputLayout* vertLayout;
ID3D11Buffer* cbPerObjectBuffer;
ID3D11ShaderResourceView* CubesTexture;
ID3D11SamplerState* CubesTexSamplerState;


//Global Declarations - Others//


XMMATRIX WVP;
XMMATRIX cubeWorld;
XMMATRIX camView;
XMMATRIX camProjection;

XMVECTOR camPosition;
XMVECTOR camTarget;
XMVECTOR camUp;

XMMATRIX Rotation;
XMMATRIX Scale;
XMMATRIX Translation;
float rot = 0.01f;

LPCTSTR WndClassName = L"firstwindow";
HWND hwnd = NULL;
HRESULT hr;

const int Width  = 800;
const int Height = 600;

float R=0.0f;
float G=0.0f;
float B=0.0f;


//Function Prototypes//
bool InitializeDirect3d11App(HINSTANCE hInstance);
void CleanUp();
bool InitScene();
void DrawScene();
bool InitializeWindow(HINSTANCE hInstance,int ShowWnd,int width, int height,bool windowed);
int  messageloop();

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);

//Create effects constant buffer's structure//
struct cbPerObject
{
    XMMATRIX  WVP;
};

cbPerObject cbPerObj;

//Vertex Structure and Vertex Layout (Input Layout)//
struct Vertex    
{
    XMFLOAT3 pos;
    XMFLOAT2 texCoord;
};

D3D11_INPUT_ELEMENT_DESC layout[] =
{
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },  
    { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },  
};
UINT numElements = ARRAYSIZE(layout);

 //Main windows function
int WINAPI WinMain(HINSTANCE hInstance,   HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd)
{

		InitializeWindow(hInstance, nShowCmd, Width, Height, true);

		InitializeDirect3d11App(hInstance);

		InitScene();

		messageloop();

		CleanUp();    

		return 0;
}

bool InitializeWindow(HINSTANCE hInstance,int ShowWnd,int width, int height,bool windowed)
{

    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = WndClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wc);

    hwnd = CreateWindowEx(
        NULL,
        WndClassName,
        L"Scaling",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL,
        NULL,
        hInstance,
        NULL
        );

    ShowWindow(hwnd, ShowWnd);
    UpdateWindow(hwnd);

    return true;
}

bool InitializeDirect3d11App(HINSTANCE hInstance)
{
    //Describe our SwapChain Buffer
    DXGI_MODE_DESC bufferDesc;

    ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

    bufferDesc.Width = Width;
    bufferDesc.Height = Height;
    bufferDesc.RefreshRate.Numerator = 60;
    bufferDesc.RefreshRate.Denominator = 1;
    bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    //Describe our SwapChain
    DXGI_SWAP_CHAIN_DESC swapChainDesc; 

    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    swapChainDesc.BufferDesc = bufferDesc;
    swapChainDesc.SampleDesc.Count = 4;
    swapChainDesc.SampleDesc.Quality = 0;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount = 1;
    swapChainDesc.OutputWindow = hwnd; 
    swapChainDesc.Windowed = TRUE; 
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;


    //Create our SwapChain
    hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
        D3D11_SDK_VERSION, &swapChainDesc, &SwapChain, &d3d11Device, NULL, &d3d11DevCon);

    //Create our BackBuffer
    ID3D11Texture2D* BackBuffer;
    hr = SwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&BackBuffer );

    //Create our Render Target
    hr = d3d11Device->CreateRenderTargetView( BackBuffer, NULL, &renderTargetView );
    BackBuffer->Release();

	d3d11DevCon->OMSetRenderTargets( 1, &renderTargetView, nullptr);

    return true;
}

void CleanUp()
{
    //Release the COM Objects we created
    SwapChain->Release();
    d3d11Device->Release();
    d3d11DevCon->Release();
    renderTargetView->Release();
    squareVertBuffer->Release();
    squareIndexBuffer->Release();
    VS->Release();
    PS->Release();
    VS_Buffer->Release();
    PS_Buffer->Release();
    vertLayout->Release();
    cbPerObjectBuffer->Release();

}

bool InitScene()
{
    //Compile Shaders from shader file
    hr = D3DX11CompileFromFile(L"Effects.fx", 0, 0, "VS", "vs_4_0", 0, 0, 0, &VS_Buffer, 0, 0);
    hr = D3DX11CompileFromFile(L"Effects.fx", 0, 0, "PS", "ps_4_0", 0, 0, 0, &PS_Buffer, 0, 0);

    //Create the Shader Objects
    hr = d3d11Device->CreateVertexShader(VS_Buffer->GetBufferPointer(), VS_Buffer->GetBufferSize(), NULL, &VS);
    hr = d3d11Device->CreatePixelShader(PS_Buffer->GetBufferPointer(), PS_Buffer->GetBufferSize(), NULL, &PS);

    //Set Vertex and Pixel Shaders
    d3d11DevCon->VSSetShader(VS, 0, 0);
    d3d11DevCon->PSSetShader(PS, 0, 0);

    //Create the vertex buffer
    Vertex v[] =
    {
        // Front Face
		{ XMFLOAT3( -1.0f, -1.0f, -1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( -1.0f, 1.0f, -1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, -1.0f ), XMFLOAT2( 1.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, -1.0f, -1.0f ), XMFLOAT2( 1.0f, 1.0f) },


        // Back Face
		{ XMFLOAT3( -1.0f, -1.0f, 1.0f ), XMFLOAT2( 1.0f, 1.0f) },
		{ XMFLOAT3( 1.0f, -1.0f, 1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, 1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( -1.0f, 1.0f, 1.0f ), XMFLOAT2( 1.0f, 0.0f) },

        // Top Face
		{ XMFLOAT3( -1.0f, 1.0f, -1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( -1.0f, 1.0f, 1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, 1.0f ), XMFLOAT2( 1.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, -1.0f ), XMFLOAT2( 1.0f, 1.0f) },


        // Bottom Face
		{ XMFLOAT3( -1.0f, -1.0f, -1.0f ), XMFLOAT2( 1.0f, 1.0f) },
		{ XMFLOAT3( 1.0f, -1.0f, -1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( 1.0f, -1.0f, 1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( -1.0f, -1.0f, 1.0f ), XMFLOAT2( 1.0f, 0.0f) },


        // Left Face
		{ XMFLOAT3( -1.0f, -1.0f, 1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( -1.0f, 1.0f, 1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( -1.0f, 1.0f, -1.0f ), XMFLOAT2( 1.0f, 0.0f) },
		{ XMFLOAT3( -1.0f, -1.0f, -1.0f ), XMFLOAT2( 1.0f, 1.0f) },


        // Right Face
		{ XMFLOAT3(1.0f, -1.0f, -1.0f ), XMFLOAT2( 0.0f, 1.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, -1.0f ), XMFLOAT2( 0.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, 1.0f, 1.0f ), XMFLOAT2( 1.0f, 0.0f) },
		{ XMFLOAT3( 1.0f, -1.0f, 1.0f ), XMFLOAT2( 1.0f, 1.0f) },

    };

    DWORD indices[] = {
        // Front Face
        0,  1,  2,
        0,  2,  3,

        // Back Face
        4,  5,  6,
        4,  6,  7,

        // Top Face
        8,  9, 10,
        8, 10, 11,

        // Bottom Face
        12, 13, 14,
        12, 14, 15,

        // Left Face
        16, 17, 18,
        16, 18, 19,

        // Right Face
        20, 21, 22,
        20, 22, 23
    };

    D3D11_BUFFER_DESC indexBufferDesc;
    ZeroMemory( &indexBufferDesc, sizeof(indexBufferDesc) );

    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(DWORD) * 12 * 3;
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA iinitData;

    iinitData.pSysMem = indices;
    d3d11Device->CreateBuffer(&indexBufferDesc, &iinitData, &squareIndexBuffer);

    d3d11DevCon->IASetIndexBuffer( squareIndexBuffer, DXGI_FORMAT_R32_UINT, 0);


    D3D11_BUFFER_DESC vertexBufferDesc;
    ZeroMemory( &vertexBufferDesc, sizeof(vertexBufferDesc) );

    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof( Vertex ) * 24;
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA vertexBufferData; 

    ZeroMemory( &vertexBufferData, sizeof(vertexBufferData) );
    vertexBufferData.pSysMem = v;
    hr = d3d11Device->CreateBuffer( &vertexBufferDesc, &vertexBufferData, &squareVertBuffer);

    //Set the vertex buffer
    UINT stride = sizeof( Vertex );
    UINT offset = 0;
    d3d11DevCon->IASetVertexBuffers( 0, 1, &squareVertBuffer, &stride, &offset );

    //Create the Input Layout
    hr = d3d11Device->CreateInputLayout( layout, numElements, VS_Buffer->GetBufferPointer(), VS_Buffer->GetBufferSize(), &vertLayout );

    //Set the Input Layout
    d3d11DevCon->IASetInputLayout( vertLayout );

    //Set Primitive Topology
    d3d11DevCon->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

    //Create the Viewport
    D3D11_VIEWPORT viewport;
    ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = Width;
    viewport.Height = Height;
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;

    //Set the Viewport
    d3d11DevCon->RSSetViewports(1, &viewport);

    //Create the buffer to send to the cbuffer in effect file
    D3D11_BUFFER_DESC cbbd;    
    ZeroMemory(&cbbd, sizeof(D3D11_BUFFER_DESC));

    cbbd.Usage = D3D11_USAGE_DEFAULT;
    cbbd.ByteWidth = sizeof(cbPerObject);
    cbbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbbd.CPUAccessFlags = 0;
    cbbd.MiscFlags = 0;

    hr = d3d11Device->CreateBuffer(&cbbd, NULL, &cbPerObjectBuffer);

    //Camera information
    camPosition = XMVectorSet( 0.0f, 3.0f, -8.0f, 0.0f );
    camTarget = XMVectorSet( 0.0f, 0.0f, 0.0f, 0.0f );
    camUp = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );

    //Set the View matrix
    camView = XMMatrixLookAtLH( camPosition, camTarget, camUp );

    //Set the Projection matrix
    camProjection = XMMatrixPerspectiveFovLH( 0.4f*3.14f, (float)Width/Height, 1.0f, 1000.0f);

    hr = D3DX11CreateShaderResourceViewFromFile( d3d11Device, L"Dinner.jpg",NULL, NULL, &CubesTexture, NULL );   // bmp,jpg,png,dds,tiff,gif,wmp
	//hr = D3DX11CreateShaderResourceViewFromFile( d3d11Device, L"images.png",NULL, NULL, &CubesTexture, NULL );

    // Describe the Sample State
    D3D11_SAMPLER_DESC sampDesc;
    ZeroMemory( &sampDesc, sizeof(sampDesc) );
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

    //Create the Sample State
    hr = d3d11Device->CreateSamplerState( &sampDesc, &CubesTexSamplerState );



    return true;
}


void DrawScene()
{
    //Clear our backbuffer
	d3d11DevCon->ClearRenderTargetView(renderTargetView, D3DXCOLOR(R, G, B, 1.0f));

    WVP = cubeWorld * camView * camProjection;
    cbPerObj.WVP = XMMatrixTranspose(WVP);    
    d3d11DevCon->UpdateSubresource( cbPerObjectBuffer, 0, NULL, &cbPerObj, 0, 0 );
    d3d11DevCon->VSSetConstantBuffers( 0, 1, &cbPerObjectBuffer );
    d3d11DevCon->PSSetShaderResources( 0, 1, &CubesTexture );
    d3d11DevCon->PSSetSamplers( 0, 1, &CubesTexSamplerState );

    //Draw the second cube
    d3d11DevCon->DrawIndexed( 36, 0, 0 );



    //Present the backbuffer to the screen
    SwapChain->Present(0, 0);
}

int messageloop(){
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while(true)
    {
        BOOL PeekMessageL( 
            LPMSG lpMsg,
            HWND hWnd,
            UINT wMsgFilterMin,
            UINT wMsgFilterMax,
            UINT wRemoveMsg
            );

        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);    
            DispatchMessage(&msg);
        }
        else{
            // run game code            
            DrawScene();
	}
    }
    return msg.wParam;
}

FLOAT scale_up=0.2f;
FLOAT scale_down=3.0f;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    switch( msg )
    {
					case WM_KEYDOWN:
						if( wParam == VK_ESCAPE )
						{
								DestroyWindow(hwnd);
						}
					return 0;

					case WM_MOUSEWHEEL:
 					if ((short )GET_WHEEL_DELTA_WPARAM(wParam) > 0)		// Rotate wheel upwards
					{
						  rot += .0005f;
							if(rot > 6.26f)
							rot = 0.0f;

						    XMVECTOR rotaxis = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

							//Reset cubeWorld
						    cubeWorld = XMMatrixIdentity();

							//Define cube's world space matrix
							Rotation = XMMatrixRotationAxis( rotaxis, -rot);
							Scale = XMMatrixScaling(scale_up,scale_up,scale_up  );
							            
							if(scale_up <3.0f)
								scale_up=scale_up+0.02; 
							else
								scale_up=0.0;

							//Set cube's world space matrix
							cubeWorld = Rotation * Scale;
				   }
				   if ((short)GET_WHEEL_DELTA_WPARAM(wParam) < 0)		// Rotate wheel downwards
				   {
						    rot += .0005f;
							if(rot > 6.26f)
							rot = 0.0f;

							XMVECTOR rotaxis = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

							//Reset cubeWorld
							cubeWorld = XMMatrixIdentity();

							//Define cube's world space matrix
							Rotation = XMMatrixRotationAxis( rotaxis, -rot);
							Scale = XMMatrixScaling( scale_down, scale_down, scale_down );
							if(scale_down >0.0f)
								scale_down=scale_down-0.02; 
							else
								scale_down=3.0;

							//Set cube's world space matrix
							cubeWorld = Rotation * Scale;
				}
				break;

				case WM_CHAR: 
					switch (wParam) 
					{ 
						case 0x52: 
							if(R <1.0f)
								R=R+0.01; 
							else
								R=0.0;
						break;

						case 0x47:
							if(G <1.0f)
								G=G+0.01;	 
							else
								G=0.0;
						break; 
 
						case 0x42:  
							if(B <1.0f)
								B=B+0.01;
							else
								B=0.0;
						break;
				}
				break;

				case WM_DESTROY:
					PostQuitMessage(0);
				return 0;
    }
    return DefWindowProc(hwnd,msg,wParam,lParam);
}