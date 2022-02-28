//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved
//
//
//// Modify the following definitions if you need to target a platform prior to the ones specified below.
//// Refer to MSDN for the latest info on corresponding values for different platforms.
////#ifndef WINVER              // Allow use of features specific to Windows 7 or later.
////#define WINVER 0x0700       // Change this to the appropriate value to target other versions of Windows.
////#endif
////
////#ifndef _WIN32_WINNT        // Allow use of features specific to Windows 7 or later.
////#define _WIN32_WINNT 0x0700 // Change this to the appropriate value to target other versions of Windows.
////#endif
////
////#ifndef UNICODE
////#define UNICODE
////#endif
//
//
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
//
//#pragma comment(lib, "Dwrite")
//
///******************************************************************
//*                                                                 *
//*  Macros                                                         *
//*                                                                 *
//******************************************************************/
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
//#ifndef Assert
//#if defined( DEBUG ) || defined( _DEBUG )
//#define Assert(b) if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}
//#else
//#define Assert(b)
//#endif //DEBUG || _DEBUG
//#endif
//
//
//#ifndef HINST_THISCOMPONENT
//EXTERN_C IMAGE_DOS_HEADER __ImageBase;
//#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
//#endif
//
//
///******************************************************************
//*                                                                 *
//*  Application entry point                                        *
//*                                                                 *
//******************************************************************/
//
//class DemoApp
//{
//public:
//    DemoApp();
//    ~DemoApp();
//
//    // Register the window class and call methods for instantiating drawing resources
//    HRESULT Initialize();
//
//    // Process and dispatch messages
//    void RunMessageLoop();
//
//private:
//    // Initialize device-independent resources
//    HRESULT CreateDeviceIndependentResources();
//
//    // Initialize device-dependent resources
//    HRESULT CreateDeviceResources();
//
//    HRESULT CreateGridPatternBrush(
//        ID2D1RenderTarget *pRenderTarget,
//        ID2D1BitmapBrush **ppBitmapBrush
//        );
//
//    // Release device-dependent resource
//    void DiscardDeviceResources();
//
//    // Draw content
//    HRESULT OnRender();
//
//    // Resize the render target
//    void OnResize(
//        UINT width,
//        UINT height
//        );
//
//    // The windows procedure
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
//    ID2D1HwndRenderTarget *m_pRenderTarget;
//    ID2D1SolidColorBrush *m_pBlackBrush;
//    ID2D1SolidColorBrush *m_pCornflowerBlueBrush;
//
//    ID2D1BitmapBrush *m_pGridPatternBitmapBrush;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidMiter;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidBevel;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidRoundwRoundCap;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidRoundwFlatCap;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidRoundwSquareCap;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidRoundwTriangleCap;
//    ID2D1StrokeStyle *m_pStrokeStyleSolidMiterOrBevel;
//    ID2D1StrokeStyle *m_pStrokeStyleDash;
//    ID2D1StrokeStyle *m_pStrokeStyleDot;
//    ID2D1StrokeStyle *m_pStrokeStyleDashDot;
//    ID2D1StrokeStyle *m_pStrokeStyleDashDotDot;
//    ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetZero;
//    ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetNegOne;
//    ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetNegTwo;
//    ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetPosOne;
//    ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetPosTwo;
//    ID2D1PathGeometry *m_pPathGeometry;
//
//    //DirectWrite
//    IDWriteFactory *m_pDWriteFactory;
//    IDWriteTextFormat *m_pTextFormat;
//};
//
//
//
//int WINAPI WinMain(
//    HINSTANCE /* hInstance */,
//    HINSTANCE /* hPrevInstance */,
//    LPSTR /* lpCmdLine */,
//    int /* nCmdShow */
//    )
//{
//    // Ignore the return value because we want to run the program even in the
//    // unlikely event that HeapSetInformation fails.
//    HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
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
//*  Initialize member data                                         *
//*                                                                 *
//******************************************************************/
//
//DemoApp::DemoApp() :
//    m_hwnd(NULL),
//    m_pD2DFactory(NULL),
//    m_pRenderTarget(NULL),
//    m_pBlackBrush(NULL),
//    m_pCornflowerBlueBrush(NULL),
//    m_pGridPatternBitmapBrush(NULL),
//    m_pStrokeStyleSolidMiter(NULL),
//    m_pStrokeStyleSolidBevel(NULL),
//    m_pStrokeStyleSolidRoundwRoundCap(NULL),
//    m_pStrokeStyleSolidRoundwFlatCap(NULL),
//    m_pStrokeStyleSolidRoundwSquareCap(NULL),
//    m_pStrokeStyleSolidRoundwTriangleCap(NULL),
//    m_pStrokeStyleSolidMiterOrBevel(NULL),
//    m_pStrokeStyleDash(NULL),
//    m_pStrokeStyleDot(NULL),
//    m_pStrokeStyleDashDot(NULL),
//    m_pStrokeStyleDashDotDot(NULL),
//    m_pStrokeStyleCustomOffsetZero(NULL),
//    m_pStrokeStyleCustomOffsetNegOne(NULL),
//    m_pStrokeStyleCustomOffsetNegTwo(NULL),
//    m_pStrokeStyleCustomOffsetPosOne(NULL),
//    m_pStrokeStyleCustomOffsetPosTwo(NULL),
//    m_pPathGeometry(NULL),
//    m_pDWriteFactory(NULL),
//    m_pTextFormat(NULL)
//{
//}
//
///******************************************************************
//*                                                                 *
//*  Release resources                                              *
//*                                                                 *
//******************************************************************/
//
//DemoApp::~DemoApp()
//{
//    SafeRelease(&m_pD2DFactory);
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pBlackBrush);
//    SafeRelease(&m_pCornflowerBlueBrush);
//    SafeRelease(&m_pGridPatternBitmapBrush);
//    SafeRelease(&m_pStrokeStyleSolidMiter);
//    SafeRelease(&m_pStrokeStyleSolidBevel);
//    SafeRelease(&m_pStrokeStyleSolidRoundwRoundCap);
//    SafeRelease(&m_pStrokeStyleSolidRoundwFlatCap);
//    SafeRelease(&m_pStrokeStyleSolidRoundwSquareCap);
//    SafeRelease(&m_pStrokeStyleSolidRoundwTriangleCap);
//    SafeRelease(&m_pStrokeStyleSolidMiterOrBevel);
//    SafeRelease(&m_pStrokeStyleDash);
//    SafeRelease(&m_pStrokeStyleDot);
//    SafeRelease(&m_pStrokeStyleDashDot);
//    SafeRelease(&m_pStrokeStyleDashDotDot);
//    SafeRelease(&m_pStrokeStyleCustomOffsetZero);
//    SafeRelease(&m_pStrokeStyleCustomOffsetNegOne);
//    SafeRelease(&m_pStrokeStyleCustomOffsetNegTwo);
//    SafeRelease(&m_pStrokeStyleCustomOffsetPosOne);
//    SafeRelease(&m_pStrokeStyleCustomOffsetPosTwo);
//    SafeRelease(&m_pPathGeometry);
//    SafeRelease(&m_pDWriteFactory);
//    SafeRelease(&m_pTextFormat);
//}
//
///******************************************************************
//*                                                                 *
//*  Create application window and device-independent resources     *
//*                                                                 *
//******************************************************************/
//
//HRESULT DemoApp::Initialize()
//{
//    HRESULT hr;
//
//    // Initialize device-indpendent resources, such
//    // as the Direct2D factory.
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
//        // Create the application window.
//        m_hwnd = CreateWindow(
//            L"D2DDemoApp",
//            L"Direct2D Demo Application",
//            WS_OVERLAPPEDWINDOW,
//            CW_USEDEFAULT,
//            CW_USEDEFAULT,
//            static_cast<UINT>(ceil(1024.f * dpiX / 96.f)),
//            static_cast<UINT>(ceil(900.f * dpiY / 96.f)),
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
//            UpdateWindow(m_hwnd);
//        }
//    }
//
//    return hr;
//}
//
///******************************************************************
//*                                                                 *
//*  This method is used to create resources which are not bound    *
//*  to any device. Their lifetime effectively extends for the      *
//*  duration of the app.                                           *
//*                                                                 *
//******************************************************************/
//
//HRESULT DemoApp::CreateDeviceIndependentResources()
//{
//    // Create a Direct2D factory.
//    HRESULT hr = D2D1CreateFactory(
//        D2D1_FACTORY_TYPE_SINGLE_THREADED,
//        &m_pD2DFactory
//        );
//
//    // Create a shared DirectWrite factory.
//    DWriteCreateFactory(
//        DWRITE_FACTORY_TYPE_SHARED,
//        __uuidof(IDWriteFactory),
//        reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
//        );
//
//    if (SUCCEEDED(hr))
//    {
//        // Create a text format.
//        hr = m_pDWriteFactory->CreateTextFormat(
//            L"Verdana",     // The font family name.
//            NULL,           // The font collection (NULL sets it to use the system font collection).
//            DWRITE_FONT_WEIGHT_REGULAR,
//            DWRITE_FONT_STYLE_NORMAL,
//            DWRITE_FONT_STRETCH_NORMAL,
//            14.0f,
//            L"en-us",
//            &m_pTextFormat
//            );
//     }
//
//    /****************************************************************************
//    *                                                                           *
//    * D2D1_LINE_JOIN_MITER, D2D1_LINE_JOIN_BEVEL, D2D1_LINE_JOIN_ROUND,         *
//    * or D2D1_LINE_JOIN_MITER_OR_BEVEL are the possible                         *
//    * values for D2D1_LINE_JOIN.                                                *
//    *                                                                           *
//    * Miter limit affects how sharp miter joins are allowed to be.              *
//    * If the line join style is D2D1_LINE_JOIN_MITER_OR_BEVEL, then D2D will    *
//    * miter the line join with regular angular vertices if it doesn't extend    *
//    * beyond the miter limit; otherwise, it will bevel the line join.           *
//    *                                                                           *
//    ****************************************************************************/
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_MITER,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidMiter
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_BEVEL,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidBevel
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_MITER_OR_BEVEL,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidMiterOrBevel
//            );
//    }
//
//    /*************************************************************************
//    *                                                                        *
//    * Round Line Join Styles with four different cap styles.  The four       *
//    * different cap styles are D2D1_CAP_STYLE_ROUND, D2D1_CAP_STYLE_FLAT,    *
//    * D2D1_CAP_STYLE_SQUARE, and D2D1_CAP_STYLE_TRIANGLE.                    *
//    *                                                                        *
//    *************************************************************************/
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_ROUND,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidRoundwRoundCap
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_ROUND,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidRoundwFlatCap
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_SQUARE,
//                D2D1_CAP_STYLE_SQUARE,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_ROUND,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidRoundwSquareCap
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_TRIANGLE,
//                D2D1_CAP_STYLE_TRIANGLE,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_LINE_JOIN_ROUND,
//                2.0f,
//                D2D1_DASH_STYLE_SOLID,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleSolidRoundwTriangleCap
//            );
//    }
//
//    // Stroke Style with Dash Style -- Dash
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_DASH,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleDash
//            );
//    }
//
//    // Stroke Style with Dash Style -- Dot
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_ROUND,
//                10.0f,
//                D2D1_DASH_STYLE_DOT,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleDot
//            );
//    }
//
//    // Stroke Style with Dash Style -- Dash Dot
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_DASH_DOT,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleDashDot
//            );
//    }
//
//
//    // Stroke Style with Dash Style -- Dash Dot Dot
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_SQUARE,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_DASH_DOT_DOT,
//                0.0f),
//            NULL,
//            0,
//            &m_pStrokeStyleDashDotDot
//            );
//    }
//
//    // Dash array for dashStyle D2D1_DASH_STYLE_CUSTOM
//    float dashes[] = {1.0f, 2.0f, 2.0f, 3.0f, 2.0f, 2.0f};
//
//    // Stroke Style with Dash Style -- Custom
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_CUSTOM,
//                0.0f),
//            dashes,
//            ARRAYSIZE(dashes),
//            &m_pStrokeStyleCustomOffsetZero
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_CUSTOM,
//                -1.0f),
//            dashes,
//            ARRAYSIZE(dashes),
//            &m_pStrokeStyleCustomOffsetNegOne
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_CUSTOM,
//                -2.0f),
//            dashes,
//            ARRAYSIZE(dashes),
//            &m_pStrokeStyleCustomOffsetNegTwo
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_CUSTOM,
//                1.0f),
//            dashes,
//            ARRAYSIZE(dashes),
//            &m_pStrokeStyleCustomOffsetPosOne
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreateStrokeStyle(
//            D2D1::StrokeStyleProperties(
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_FLAT,
//                D2D1_CAP_STYLE_ROUND,
//                D2D1_LINE_JOIN_MITER,
//                10.0f,
//                D2D1_DASH_STYLE_CUSTOM,
//                2.0f),
//            dashes,
//            ARRAYSIZE(dashes),
//            &m_pStrokeStyleCustomOffsetPosTwo
//            );
//    }
//
//    if (SUCCEEDED(hr))
//    {
//        hr = m_pD2DFactory->CreatePathGeometry(&m_pPathGeometry);
//
//        if (SUCCEEDED(hr))
//        {
//            ID2D1GeometrySink *pGeometrySink;
//
//            hr = m_pPathGeometry->Open(&pGeometrySink);
//            if (SUCCEEDED(hr))
//            {
//                pGeometrySink->BeginFigure(D2D1::Point2F(17, 17), D2D1_FIGURE_BEGIN_HOLLOW);
//                pGeometrySink->AddLine(D2D1::Point2F(45, 85));
//                pGeometrySink->AddLine(D2D1::Point2F(85, 45));
//                pGeometrySink->AddLine(D2D1::Point2F(85, 125));
//                pGeometrySink->AddLine(D2D1::Point2F(165, 17));
//                pGeometrySink->EndFigure(D2D1_FIGURE_END_OPEN);
//
//                hr = pGeometrySink->Close();
//            }
//
//            SafeRelease(&pGeometrySink);
//        }
//    }
//
//    return hr;
//}
//
///******************************************************************
//*                                                                 *
//*  This method creates resources which are bound to a particular  *
//*  D3D device. It's all centralized here, in case the resources   *
//*  need to be recreated in case of D3D device loss (eg. display   *
//*  change, remoting, removal of video card, etc).                 *
//*                                                                 *
//******************************************************************/
//
//HRESULT DemoApp::CreateDeviceResources()
//{
//    HRESULT hr = S_OK;
//
//    if (!m_pRenderTarget)
//    {
//        RECT rc;
//        GetClientRect(m_hwnd, &rc);
//
//        D2D1_SIZE_U size = D2D1::SizeU(
//            rc.right - rc.left,
//            rc.bottom - rc.top
//            );
//
//        // Create a Direct2D render target
//        hr = m_pD2DFactory->CreateHwndRenderTarget(
//            D2D1::RenderTargetProperties(),
//            D2D1::HwndRenderTargetProperties(m_hwnd, size),
//            &m_pRenderTarget
//            );
//
//        if (SUCCEEDED(hr))
//        {
//            // Create a black brush
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::Black),
//                &m_pBlackBrush
//                );
//        }
//        if (SUCCEEDED(hr))
//        {
//            // Create a blue brush
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::CornflowerBlue),
//                &m_pCornflowerBlueBrush
//                );
//        }
//
//        if (SUCCEEDED(hr))
//        {
//            hr = CreateGridPatternBrush(m_pRenderTarget, &m_pGridPatternBitmapBrush);
//        }
//    }
//
//    return hr;
//}
//
//HRESULT DemoApp::CreateGridPatternBrush(
//    ID2D1RenderTarget *pRenderTarget,
//    ID2D1BitmapBrush **ppBitmapBrush
//    )
//{
//    HRESULT hr = S_OK;
//
//    // Create a compatible render target.
//    ID2D1BitmapRenderTarget *pCompatibleRenderTarget = NULL;
//    hr = pRenderTarget->CreateCompatibleRenderTarget(
//        D2D1::SizeF(10.0f, 10.0f),
//        &pCompatibleRenderTarget
//        );
//
//    if (SUCCEEDED(hr))
//    {
//        // Draw a pattern.
//        ID2D1SolidColorBrush *pGridBrush = NULL;
//        hr = pCompatibleRenderTarget->CreateSolidColorBrush(
//            D2D1::ColorF(D2D1::ColorF(0.93f, 0.94f, 0.96f, 1.0f)),
//            &pGridBrush
//            );
//
//        if (SUCCEEDED(hr))
//        {
//            pCompatibleRenderTarget->BeginDraw();
//            pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 10.0f, 1.0f), pGridBrush);
//            pCompatibleRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 1.0f, 10.0f), pGridBrush);
//            pCompatibleRenderTarget->EndDraw();
//
//            // Retrieve the bitmap from the render target.
//            ID2D1Bitmap *pGridBitmap = NULL;
//            hr = pCompatibleRenderTarget->GetBitmap(&pGridBitmap);
//
//            if (SUCCEEDED(hr))
//            {
//                // Create the bitmap brush.
//                hr = m_pRenderTarget->CreateBitmapBrush(
//                    pGridBitmap,
//                    D2D1::BitmapBrushProperties(
//                        D2D1_EXTEND_MODE_WRAP,
//                        D2D1_EXTEND_MODE_WRAP),
//                    ppBitmapBrush
//                    );
//
//                pGridBitmap->Release();
//            }
//
//            pGridBrush->Release();
//        }
//
//        pCompatibleRenderTarget->Release();
//    }
//
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
//    SafeRelease(&m_pCornflowerBlueBrush);
//    SafeRelease(&m_pGridPatternBitmapBrush);
//}
//
///******************************************************************
//*                                                                 *
//*  Main window message loop                                       *
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
//    HRESULT hr = CreateDeviceResources();
//
//    if (SUCCEEDED(hr))
//    {
//        m_pRenderTarget->BeginDraw();
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//
//        // Clear the render target contents.
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
//
//        D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();
//
//        // Draw a grid background.
//        m_pRenderTarget->FillRectangle(
//            D2D1::RectF(0, 0, rtSize.width, rtSize.height),
//            m_pGridPatternBitmapBrush
//            );
//
//
//        // Line Join Styles
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(10, 20));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidMiter);
//
//        {
//            PCWSTR text = L"Miter Line Join";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(10, 210));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidBevel);
//
//        {
//            PCWSTR text = L"Bevel Line Join";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(230, 20));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidRoundwRoundCap);
//
//        {
//            PCWSTR text = L"Round Line Join";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(230, 210));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidMiterOrBevel);
//
//        {
//            PCWSTR text = L"Miter or Bevel Line Join";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//
//        // Cap Styles
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(480, 20));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidRoundwRoundCap);
//
//        {
//            PCWSTR text = L"Round Caps";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(700, 20));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidRoundwFlatCap);
//
//        {
//            PCWSTR text = L"Flat Caps";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//       }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(480, 210));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidRoundwSquareCap);
//
//        {
//            PCWSTR text = L"Square Caps";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(700, 210));
//        m_pRenderTarget->DrawRectangle(D2D1::RectF(0.0f, 0.0f, 180.0f, 150.0f), m_pBlackBrush);
//        m_pRenderTarget->DrawGeometry(m_pPathGeometry, m_pBlackBrush, 16, m_pStrokeStyleSolidRoundwTriangleCap);
//
//        {
//            PCWSTR text = L"Triangle Caps";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(2, 150, 215, 215),
//                m_pBlackBrush
//                );
//        }
//
//
//        // Dash Styles
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(10, 405));
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 10),
//            D2D1::Point2F(200, 10),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleSolidMiter
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Solid";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 20, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 70),
//            D2D1::Point2F(200, 70),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleDash
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Dash";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 80, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 130),
//            D2D1::Point2F(200, 130),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleDot
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Dot";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 140, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 190),
//            D2D1::Point2F(200, 190),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleDashDot
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Dash Dot";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 200, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 250),
//            D2D1::Point2F(200, 250),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleDashDotDot
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Dash Dot Dot";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 260, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 310),
//            D2D1::Point2F(200, 310),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetZero
//            );
//
//        {
//            PCWSTR text = L"Dash Style -- Custom";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 320, 200, 315),
//                m_pBlackBrush
//                );
//        }
//
//
//        //  Dash Offsets
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(300, 405));
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 10),
//            D2D1::Point2F(200, 10),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetNegTwo
//            );
//
//        {
//            PCWSTR text = L"-2";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 20, 200, 295),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 70),
//            D2D1::Point2F(200, 70),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetNegOne
//            );
//
//        {
//            PCWSTR text = L"-1";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 80, 200, 295),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 130),
//            D2D1::Point2F(200, 130),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetZero
//            );
//
//        {
//            PCWSTR text = L"0";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 140, 200, 295),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 190),
//            D2D1::Point2F(200, 190),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetPosOne
//            );
//
//        {
//            PCWSTR text = L"1";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 200, 200, 295),
//                m_pBlackBrush
//                );
//        }
//
//        m_pRenderTarget->DrawLine(
//            D2D1::Point2F(0, 250),
//            D2D1::Point2F(200, 250),
//            m_pCornflowerBlueBrush,
//            10.0f,
//            m_pStrokeStyleCustomOffsetPosTwo
//            );
//
//        {
//            PCWSTR text = L"2";
//            m_pRenderTarget->DrawText(
//                text,
//                wcslen(text),
//                m_pTextFormat,
//                D2D1::RectF(0, 260, 200, 295),
//                m_pBlackBrush
//                );
//        }
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
///******************************************************************
//*                                                                 *
//*  Window message handler                                         *
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
//                wasHandled = true;
//                result = 0;
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
//                wasHandled = true;
//                result = 1;
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
// 
//
// 
//
