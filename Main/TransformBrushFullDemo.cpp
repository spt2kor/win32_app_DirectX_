//#ifndef UNICODE
//#define UNICODE
//#endif
//
//#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
//// Windows Header Files:
//#include <windows.h>
//
//// C RunTime Header Files
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <wchar.h>
//#include <math.h>
//
//#include <d2d1.h>
//#include <d2d1helper.h>
//#include <dwrite.h>
//#include <wincodec.h>
//
///******************************************************************
//*                                                                 *
//*  Macros                                                         *
//*                                                                 *
//******************************************************************/
//
//template<class Interface>
//inline void
//SafeRelease(
//    Interface **ppInterfaceToRelease
//    )
//{
//    if (*ppInterfaceToRelease != NULL)
//    {
//        (*ppInterfaceToRelease)->Release();
//
//        (*ppInterfaceToRelease) = NULL;
//    }
//}
//
//#ifndef Assert
//#if defined( DEBUG ) || defined( _DEBUG )
//#define Assert(b) do {if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
//#else
//#define Assert(b)
//#endif //DEBUG || _DEBUG
//#endif
//
//#ifndef HINST_THISCOMPONENT
//EXTERN_C IMAGE_DOS_HEADER __ImageBase;
//#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
//#endif
//
//
///******************************************************************
//*                                                                 *
//*  DemoApp                                                        *
//*                                                                 *
//******************************************************************/
//class DemoApp
//{
//public:
//    DemoApp();
//    ~DemoApp();
//
//    HRESULT Initialize();
//
//    void RunMessageLoop();
//
//private:
//    HRESULT CreateDeviceIndependentResources();
//    HRESULT CreateDeviceResources();
//    void DiscardDeviceResources();
//
//    HRESULT OnRender();
//
//    HRESULT LoadResourceBitmap(
//        ID2D1RenderTarget *pRenderTarget,
//        IWICImagingFactory *pIWICFactory,
//        PCWSTR resourceName,
//        PCWSTR resourceType,
//        ID2D1Bitmap **ppBitmap
//    );
//
//    void OnResize(
//        UINT width,
//        UINT height
//        );
//
//    static LRESULT CALLBACK WndProc(
//        HWND hWnd,
//        UINT message,
//        WPARAM wParam,
//        LPARAM lParam
//        );
//
//private:
//    HWND m_hwnd;
//    ID2D1Factory *m_pD2DFactory;
//
//    // Declare WIC members.
//    IWICImagingFactory *m_pWICFactory;
//    ID2D1Bitmap *m_pBitmap;
//    ID2D1HwndRenderTarget *m_pRenderTarget;
//    ID2D1SolidColorBrush *m_pBlackBrush;
//    ID2D1BitmapBrush *m_pBitmapBrush;
//
//    ID2D1BitmapBrush *m_pGridPatternBitmapBrush;
//
//};
//
//
//
///******************************************************************
//*                                                                 *
//* Provides the entry point for the application.                   *
//*                                                                 *
//******************************************************************/
//
//int WINAPI WinMain(
//    HINSTANCE /* hInstance */,
//    HINSTANCE /* hPrevInstance */,
//    LPSTR /* lpCmdLine */,
//    int /* nCmdShow */
//    )
//{
//    // Ignore the return value because we want to continue running even in the
//    // unlikely event that HeapSetInformation fails.
//    HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
//
//    if (SUCCEEDED(CoInitialize(NULL)))
//    {
//        {
//            DemoApp app;
//
//            if (SUCCEEDED(app.Initialize()))
//            {
//                app.RunMessageLoop();
//            }
//        }
//        CoUninitialize();
//    }
//
//    return 0;
//}
//
///******************************************************************
//*                                                                 *
//*  Initialize members.                                            *
//*                                                                 *
//******************************************************************/
//
//DemoApp::DemoApp() :
//    m_hwnd(NULL),
//    m_pD2DFactory(NULL),
//    m_pBitmap(NULL),
//    m_pRenderTarget(NULL),
//    m_pBitmapBrush(NULL),
//    m_pBlackBrush(NULL)
//{
//}
//
///******************************************************************
//*                                                                 *
//*  Release resources.                                             *
//*                                                                 *
//******************************************************************/
//
//DemoApp::~DemoApp()
//{
//    SafeRelease(&m_pD2DFactory);
//    SafeRelease(&m_pBitmap);
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pBitmapBrush);
//    SafeRelease(&m_pBlackBrush);
//}
//
///******************************************************************
//*                                                                 *
//*  Create theapplication window and device-independent resources. *
//*                                                                 *
//******************************************************************/
//
//HRESULT DemoApp::Initialize()
//{
//    HRESULT hr;
//
//    hr = CreateDeviceIndependentResources();
//    if (SUCCEEDED(hr))
//    {
//        // Register the window class.
//        WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
//        wcex.style         = CS_HREDRAW | CS_VREDRAW;
//        wcex.lpfnWndProc   = DemoApp::WndProc;
//        wcex.cbClsExtra    = 0;
//        wcex.cbWndExtra    = sizeof(LONG_PTR);
//        wcex.hInstance     = HINST_THISCOMPONENT;
//        wcex.hbrBackground = NULL;
//        wcex.lpszMenuName  = NULL;
//        wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
//        wcex.lpszClassName = L"D2DDemoApp";
//
//        RegisterClassEx(&wcex);
//
//        // Create the application window.
//        //
//        // Because the CreateWindow function takes its size in pixels, we
//        // obtain the system DPI and use it to scale the window size.
//        FLOAT dpiX, dpiY;
//        m_pD2DFactory->GetDesktopDpi(&dpiX, &dpiY);
//
//        m_hwnd = CreateWindow(
//            L"D2DDemoApp",
//            L"Direct2D Demo App",
//            WS_OVERLAPPEDWINDOW,
//            CW_USEDEFAULT,
//            CW_USEDEFAULT,
//            static_cast<UINT>(ceil(640.f * dpiX / 96.f)),
//            static_cast<UINT>(ceil(480.f * dpiY / 96.f)),
//            NULL,
//            NULL,
//            HINST_THISCOMPONENT,
//            this
//            );
//
//        hr = m_hwnd ? S_OK : E_FAIL;
//        if (SUCCEEDED(hr))
//        {
//            ShowWindow(m_hwnd, SW_SHOWNORMAL);
//
//            UpdateWindow(m_hwnd);
//        }
//    }
//
//    return hr;
//}
//
//
///******************************************************************
//*                                                                 *
//*  This method is used to create resources which are not bound    *
//*  to any device. Their lifetime effectively extends for the      *
//*  duration of the app.                                           *
//*                                                                 *
//******************************************************************/
//HRESULT DemoApp::CreateDeviceIndependentResources()
//{
//    HRESULT hr;
//
//    // Create a WIC factory.
//    hr = CoCreateInstance(
//        CLSID_WICImagingFactory,
//        NULL,
//        CLSCTX_INPROC_SERVER,
//        IID_PPV_ARGS(&m_pWICFactory)
//        );
//
//    if (SUCCEEDED(hr))
//    {
//        // Create a Direct2D factory.
//        hr = D2D1CreateFactory(
//            D2D1_FACTORY_TYPE_SINGLE_THREADED,
//            &m_pD2DFactory
//            );
//    }
//
//    return hr;
//}
//
///******************************************************************
//*                                                                 *
//*  DemoApp::CreateDeviceResources                                 *
//*                                                                 *
//*  This method creates resources which are bound to a particular  *
//*  D3D device. It's all centralized here, in case the resources   *
//*  need to be recreated in case of D3D device loss (eg. display   *
//*  change, remoting, removal of video card, etc).                 *
//*                                                                 *
//******************************************************************/
//HRESULT DemoApp::CreateDeviceResources()
//{
//    HRESULT hr = S_OK;
//
//    if (!m_pRenderTarget)
//    {
//        RECT rc;
//        GetClientRect(m_hwnd, &rc);
//        D2D1_SIZE_U size = D2D1::SizeU(
//            rc.right - rc.left,
//            rc.bottom - rc.top
//            );
//
//        // Create a Direct2D render target.
//        hr = m_pD2DFactory->CreateHwndRenderTarget(
//            D2D1::RenderTargetProperties(),
//            D2D1::HwndRenderTargetProperties(m_hwnd, size),
//            &m_pRenderTarget
//            );
//
//        if (SUCCEEDED(hr))
//        {
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                 D2D1::ColorF(D2D1::ColorF::Black), 
//                &m_pBlackBrush
//                );
//        }
//        // Create the bitmap to be used by the bitmap brush.
//        if (SUCCEEDED(hr))
//        {
//
//            //hr = LoadResourceBitmap(
//            //    m_pRenderTarget,
//            //    m_pWICFactory,
//            //    L"FERN",
//            //    L"Image",
//            //    &m_pBitmap
//            //    );
//
////-----------------------------------------------------------------------------------------
//    IWICBitmapDecoder *pDecoder = NULL;
//    IWICBitmapFrameDecode *pSource = NULL;
//    IWICStream *pStream = NULL;
//    IWICFormatConverter *pConverter = NULL;
//    IWICBitmapScaler *pScaler = NULL;
//
//	HRESULT hr = m_pWICFactory->CreateDecoderFromFilename(
//        L"C:\\Users\\bkoushik\\Desktop\\DXTraningAll\\DX\\D2D\\Main\\koushik.bmp",
//        NULL,
//        GENERIC_READ,
//        WICDecodeMetadataCacheOnLoad,
//        &pDecoder
//        );
//
////-----------------------------------------------------------------------------------------   
//        }
//
//        if (SUCCEEDED(hr))
//        {
//            hr = m_pRenderTarget->CreateBitmapBrush(
//                m_pBitmap,
//                &m_pBitmapBrush
//                );
//        }
//    }
//    return hr;
//}
//
///******************************************************************
//*                                                                 *
//*  Discard device-specific resources which need to be recreated   *
//*  when a Direct3D device is lost.                                *
//*                                                                 *
//******************************************************************/
//
//void DemoApp::DiscardDeviceResources()
//{
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pBlackBrush);
//    SafeRelease(&m_pBitmapBrush);
//}
//
///******************************************************************
//*                                                                 *
//*  The main window message loop.                                  *
//*                                                                 *
//******************************************************************/
//
//void DemoApp::RunMessageLoop()
//{
//    MSG msg;
//
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//}
//
//
//
///******************************************************************
//*                                                                 *
//*  Called whenever the application needs to display the client    *
//*  window.                                                        *
//*                                                                 *
//*  Note that this function will automatically discard             *
//*  device-specific resources if the Direct3D device disappears    *
//*  during execution, and will recreate the resources the          *
//*  next time it's invoked.                                        *
//*                                                                 *
//******************************************************************/
//HRESULT DemoApp::OnRender()
//{
//
//    HRESULT hr = CreateDeviceResources();
//
//    if (SUCCEEDED(hr))
//    {
//        m_pRenderTarget->BeginDraw();
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//
//          
//        // Define the shape of rectangles to be filled with brushes. 
//        D2D1_RECT_F rcBrushRect = D2D1::RectF(5, 0, 150, 150);
//        D2D1_RECT_F rcTransformedBrushRect = D2D1::RectF(100, 100, 200, 200);
//
//
//
//        // Start with a white background.
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
//        
//        // Use the bitmap brush to paint the rcBrushRect
//        m_pRenderTarget->FillRectangle(&rcBrushRect, m_pBitmapBrush);
//        m_pRenderTarget->DrawRectangle(&rcBrushRect, m_pBlackBrush, 1, NULL);
//
//        // Use the bitmap brush to paint the rcTransformedBrushRect
//        m_pRenderTarget->FillRectangle(
//            rcTransformedBrushRect,
//            m_pBitmapBrush
//            );
//
//        // Demonstrate the effect of transforming a bitmap brush.
//        m_pBitmapBrush->SetTransform(
//            D2D1::Matrix3x2F::Translation(D2D1::SizeF(50,50))
//            );
//
//        // To see the content of the rcTransformedBrushRect, comment
//        // out this statement.
//        m_pRenderTarget->FillRectangle(
//            &rcTransformedBrushRect, 
//            m_pBitmapBrush
//            );
//
//        m_pRenderTarget->DrawRectangle(rcTransformedBrushRect, m_pBlackBrush, 1, NULL);
//
//        hr = m_pRenderTarget->EndDraw();
//
//        if (hr == D2DERR_RECREATE_TARGET)
//        {
//            hr = S_OK;
//            DiscardDeviceResources();
//        }
//    }
//
//    return hr;
//}
//
//
///******************************************************************
//*                                                                 *
//*  If the application receives a WM_SIZE message, this method     *
//*  resizes the render target appropriately.                       *
//*                                                                 *
//******************************************************************/
//
//void DemoApp::OnResize(UINT width, UINT height)
//{
//    if (m_pRenderTarget)
//    {
//        // Note: This method can fail, but it's okay to ignore the
//        // error here -- the error will be repeated on the next call to
//        // EndDraw.
//        m_pRenderTarget->Resize(D2D1::SizeU(width, height));
//    }
//}
//
//
///******************************************************************
//*                                                                 *
//*                                                                 *
//*  The window message handler.                                    *
//*                                                                 *
//******************************************************************/
//
//LRESULT CALLBACK DemoApp::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    LRESULT result = 0;
//
//    if (message == WM_CREATE)
//    {
//        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
//        DemoApp *pDemoApp = (DemoApp *)pcs->lpCreateParams;
//
//        ::SetWindowLongPtrW(
//            hwnd,
//            GWLP_USERDATA,
//            PtrToUlong(pDemoApp)
//            );
//
//        result = 1;
//    }
//    else
//    {
//        DemoApp *pDemoApp = reinterpret_cast<DemoApp *>(static_cast<LONG_PTR>(
//            ::GetWindowLongPtrW(
//                hwnd,
//                GWLP_USERDATA
//                )));
//
//        bool wasHandled = false;
//
//        if (pDemoApp)
//        {
//            switch (message)
//            {
//            case WM_SIZE:
//                {
//                    UINT width = LOWORD(lParam);
//                    UINT height = HIWORD(lParam);
//                    pDemoApp->OnResize(width, height);
//                }
//                result = 0;
//                wasHandled = true;
//                break;
//
//            case WM_DISPLAYCHANGE:
//                {
//                    InvalidateRect(hwnd, NULL, FALSE);
//                }
//                wasHandled = true;
//                result = 0;
//                break;
//
//            case WM_PAINT:
//                {
//                    pDemoApp->OnRender();
//
//                    ValidateRect(hwnd, NULL);
//                }
//                wasHandled = true;
//                result = 0;
//                break;
//
//            case WM_DESTROY:
//                {
//                    PostQuitMessage(0);
//                }
//                result = 1;
//                wasHandled = true;
//                break;
//            }
//        }
//
//        if (!wasHandled)
//        {
//            result = DefWindowProc(hwnd, message, wParam, lParam);
//        }
//    }
//
//    return result;
//}
//
//
///******************************************************************
//*                                                                 *
//*                                                                 *
//*  This method will create a Direct2D bitmap from a resource in   *
//*  this DLL.                                                      *
//*                                                                 *
//******************************************************************/
//
//HRESULT DemoApp::LoadResourceBitmap(
//    ID2D1RenderTarget *pRenderTarget,
//    IWICImagingFactory *pIWICFactory,
//    PCWSTR resourceName,
//    PCWSTR resourceType,
//    ID2D1Bitmap **ppBitmap
//    )
//{
//    HRESULT hr = S_OK;
//    IWICBitmapDecoder *pDecoder = NULL;
//    IWICBitmapFrameDecode *pSource = NULL;
//    IWICStream *pStream = NULL;
//    IWICFormatConverter *pConverter = NULL;
//
//    HRSRC imageResHandle = NULL;
//    HGLOBAL imageResDataHandle = NULL;
//    void *pImageFile = NULL;
//    DWORD imageFileSize = 0;
//
//    // Locate the resource.
//    imageResHandle = FindResourceW(HINST_THISCOMPONENT, resourceName, resourceType);
//
//    hr = imageResHandle ? S_OK : E_FAIL;
//    if (SUCCEEDED(hr))
//    {
//        // Load the resource.
//        imageResDataHandle = LoadResource(HINST_THISCOMPONENT, imageResHandle);
//
//        hr = imageResDataHandle ? S_OK : E_FAIL;
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Lock it to get a system memory pointer.
//        pImageFile = LockResource(imageResDataHandle);
//
//        hr = pImageFile ? S_OK : E_FAIL;
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Calculate the size.
//        imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);
//
//        hr = imageFileSize ? S_OK : E_FAIL;
//
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Create a WIC stream to map onto the memory.
//        hr = pIWICFactory->CreateStream(&pStream);
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Initialize the stream with the memory pointer and size.
//        hr = pStream->InitializeFromMemory(
//            reinterpret_cast<BYTE*>(pImageFile),
//            imageFileSize
//            );
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Create a decoder for the stream.
//        hr = pIWICFactory->CreateDecoderFromStream(
//            pStream,
//            NULL,
//            WICDecodeMetadataCacheOnLoad,
//            &pDecoder
//            );
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Create the initial frame.
//        hr = pDecoder->GetFrame(0, &pSource);
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Convert the image format to 32bppPBGRA
//        // (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
//        hr = pIWICFactory->CreateFormatConverter(&pConverter);
//    }
//    if (SUCCEEDED(hr))
//    {
//        hr = pConverter->Initialize(
//            pSource,
//            GUID_WICPixelFormat32bppPBGRA,
//            WICBitmapDitherTypeNone,
//            NULL,
//            0.f,
//            WICBitmapPaletteTypeMedianCut
//            );
//    }
//    if (SUCCEEDED(hr))
//    {
//        // Create a Direct2D bitmap from the WIC bitmap.
//        hr = pRenderTarget->CreateBitmapFromWicBitmap(
//            pConverter,
//            NULL,
//            ppBitmap
//            );
//    }
//
//    SafeRelease(&pDecoder);
//    SafeRelease(&pSource);
//    SafeRelease(&pStream);
//    SafeRelease(&pConverter);
//
//    return hr;
//}
//
//
// 
//
// 
//
