//// Windows Header Files:
//#include <windows.h>
//
//// C RunTime Header Files:
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
////-------------------------------------------------------------------------
//ID2D1BitmapBrush* m_BitmapBrush = NULL;
//ID2D1SolidColorBrush* m_pSolidColorBrushBlack = NULL;
//ID2D1SolidColorBrush* m_pSolidColorBrush2 = NULL;
//
//ID2D1Factory* m_pDirect2dFactory = NULL;
//ID2D1HwndRenderTarget* m_pRenderTarget = NULL;
//ID2D1SolidColorBrush* m_pLightSlateGrayBrush = NULL;
//ID2D1SolidColorBrush* m_pSolidColorBrush = NULL;
//
//ID2D1GradientStopCollection *pGradientStops = NULL;
//ID2D1LinearGradientBrush *m_pLinearGradientBrush = NULL;
////D2D1_GRADIENT_STOP gradientStops[2];
//D2D1_GRADIENT_STOP gradientStops[3];
//
//ID2D1GradientStopCollection *pGradientStopsForRadial = NULL;
//ID2D1RadialGradientBrush *m_pRadialGradientBrush = NULL;
//D2D1_GRADIENT_STOP gradientStopsForRadial[2];
//
//ID2D1BitmapBrush *m_pBitmapBrush = NULL;
//
////-------------------------------------------------------------------------
//HWND m_hwnd;
//HRESULT hr = S_OK;
////-------------------------------------------------------------------------
//
//template<class Interface>
//inline void SafeRelease(
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
////================================================================================================
//void DoDraw1()
//{
//		m_pRenderTarget->BeginDraw();
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
////-------------------------------------------------------------------------
//		ID2D1StrokeStyle *m_pStrokeStyleCustomOffsetZero;
//		//float dashes[] = {1.0f, 2.0f, 2.0f, 3.0f, 2.0f, 2.0f};
//		float dashes[] = {1.0f, 2.0f, 4.0f, 8.0f, 16.0f, 2.0f};
//		m_pDirect2dFactory->CreateStrokeStyle(
//			D2D1::StrokeStyleProperties(
//				D2D1_CAP_STYLE_FLAT,
//				D2D1_CAP_STYLE_TRIANGLE,
//				//D2D1_CAP_STYLE_ROUND,
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_LINE_JOIN_MITER,
//				10.0f,
//				D2D1_DASH_STYLE_CUSTOM,
//				0.0f),
//		dashes,
//		ARRAYSIZE(dashes),
//		&m_pStrokeStyleCustomOffsetZero
//		);
//		FLOAT xMove = 0.0, yMove = 20.0;
//		m_pRenderTarget->DrawLine(
//		D2D1::Point2F(10, yMove),
//		D2D1::Point2F(600, yMove),
//		m_pLinearGradientBrush,
//		15.0f,
//		m_pStrokeStyleCustomOffsetZero
//		);
//	//----------------------------------------------------
//
//		m_pDirect2dFactory->CreateStrokeStyle(
//			D2D1::StrokeStyleProperties(
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_CAP_STYLE_ROUND,
//				D2D1_CAP_STYLE_SQUARE,
//				D2D1_LINE_JOIN_MITER,
//				10.0f,
//				D2D1_DASH_STYLE_DASH,
//				//D2D1_DASH_STYLE_DOT,
//				0.0f),
//		NULL,
//		0,
//		&m_pStrokeStyleCustomOffsetZero
//		);
//		xMove += 0.0, yMove += 40.0;
//		m_pRenderTarget->DrawLine(
//		D2D1::Point2F(10, yMove),
//		D2D1::Point2F(600, yMove),
//		m_pSolidColorBrushBlack,
//		10.0f,
//		m_pStrokeStyleCustomOffsetZero
//		);
//	//----------------------------------------------------
//		m_pDirect2dFactory->CreateStrokeStyle(
//			D2D1::StrokeStyleProperties(
//				D2D1_CAP_STYLE_ROUND,
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_CAP_STYLE_SQUARE,
//				D2D1_LINE_JOIN_BEVEL,
//				10.0f,
//				//D2D1_DASH_STYLE_DASH,
//				D2D1_DASH_STYLE_DOT,
//				0.0f),
//		NULL,
//		0,
//		&m_pStrokeStyleCustomOffsetZero
//		);
//		xMove += 0.0, yMove += 40.0;
//		m_pRenderTarget->DrawLine(
//		D2D1::Point2F(10, yMove),
//		D2D1::Point2F(600, yMove),
//		m_pRadialGradientBrush,
//		10.0f,
//		m_pStrokeStyleCustomOffsetZero
//		);
//
//	//----------------------------------------------------
//		m_pDirect2dFactory->CreateStrokeStyle(
//			D2D1::StrokeStyleProperties(
//				D2D1_CAP_STYLE_ROUND,
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_CAP_STYLE_SQUARE,
//				D2D1_LINE_JOIN_BEVEL,
//				10.0f,
//				//D2D1_DASH_STYLE_DASH,
//				D2D1_DASH_STYLE_DOT,
//				0.0f),
//		NULL,
//		0,
//		&m_pStrokeStyleCustomOffsetZero
//		);
//		xMove += 0.0, yMove += 40.0;
//		m_pRenderTarget->DrawLine(
//		D2D1::Point2F(10, yMove),
//		D2D1::Point2F(600, yMove),
//		m_pRadialGradientBrush,
//		15.0f,
//		m_pStrokeStyleCustomOffsetZero
//		);
//	//----------------------------------------------------
//		m_pDirect2dFactory->CreateStrokeStyle(
//			D2D1::StrokeStyleProperties(
//				D2D1_CAP_STYLE_ROUND,
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_CAP_STYLE_TRIANGLE,
//				D2D1_LINE_JOIN_BEVEL,
//				10.0f,
//				//D2D1_DASH_STYLE_DASH,
//				D2D1_DASH_STYLE_DOT,
//				0.0f),
//		NULL,
//		0,
//		&m_pStrokeStyleCustomOffsetZero
//		);
//		xMove += 0.0, yMove += 40.0;
//		m_pRenderTarget->DrawLine(
//		D2D1::Point2F(10, yMove),
//		D2D1::Point2F(600, yMove),
//		m_pLinearGradientBrush,
//		15.0f,
//		m_pStrokeStyleCustomOffsetZero
//		);
//
////-------------------------------------------------------------------------
//		ID2D1PathGeometry* m_pPathGeometry;
//		m_pDirect2dFactory->CreatePathGeometry(&m_pPathGeometry);
//		ID2D1GeometrySink *pGeometrySink;
//		m_pPathGeometry->Open(&pGeometrySink);
//        pGeometrySink->BeginFigure(D2D1::Point2F(17, 17), D2D1_FIGURE_BEGIN_HOLLOW);
//        pGeometrySink->AddLine(D2D1::Point2F(45, 85));
//        pGeometrySink->AddLine(D2D1::Point2F(85, 45));
//        pGeometrySink->AddLine(D2D1::Point2F(85, 125));
//        pGeometrySink->AddLine(D2D1::Point2F(165, 17));
//        pGeometrySink->EndFigure(D2D1_FIGURE_END_OPEN);
//        hr = pGeometrySink->Close();
//		SafeRelease(&pGeometrySink);
//
//
//		hr = m_pRenderTarget->EndDraw();
//}
////================================================================================================
//void DoDraw()
//{
//		m_pRenderTarget->BeginDraw();
//
//        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
//
//        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
//
//		D2D1_SIZE_F rtSize = m_pRenderTarget->GetSize();
//
//		// Draw a grid background.
//        int width = static_cast<int>(rtSize.width);
//        int height = static_cast<int>(rtSize.height);
//
//        for (int x = 0; x < width; x += 10)
//        {
//            m_pRenderTarget->DrawLine(
//                D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
//                D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
//                m_pLightSlateGrayBrush,
//                0.5f
//                );
//        }
//
//        for (int y = 0; y < height; y += 10)
//        {
//            m_pRenderTarget->DrawLine(
//                D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
//                D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
//                m_pLightSlateGrayBrush,
//                0.5f
//                );
//        }
//
//
//        // Draw 5 rectangles.
//        D2D1_RECT_F rectangle1 = D2D1::RectF(
//            rtSize.width/2 - 100.0f,
//            rtSize.height/2 - 100.0f,
//            rtSize.width/2 + 100.0f,
//            rtSize.height/2 + 100.0f
//            );
//
//        D2D1_RECT_F rectangle2 = D2D1::RectF(
//            10.0f,
//            10.0f,
//            100.0f,
//            90.0f
//            );
//
//		float xMove, yMove;
//
//		xMove = 0.0f;
//		yMove = 200.0f;
//        D2D1_RECT_F rectangle3 = D2D1::RectF(
//            xMove + 10.0f,
//            yMove + 10.0f,
//            xMove + 200.0f,
//            yMove + 150.0f
//            );
//
//		xMove = 430.0f;
//		yMove = 300.0f;
//		D2D1_RECT_F rectangle4 = D2D1::RectF(
//            xMove + 10.0f,
//            yMove + 10.0f,
//            xMove + 180.0f,
//            yMove + 120.0f
//            );
//
//		xMove = 420.0f;
//		yMove = 0.0f;
//        D2D1_RECT_F rectangle5 = D2D1::RectF(
//            xMove + 10.0f,
//            yMove + 10.0f,
//            xMove + 200.0f,
//            yMove + 130.0f
//            );
//		
//		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(500.0, 300.0),100, 80);
//
//
//		// Draw a filled rectangle.
//        //m_pRenderTarget->FillRectangle(&rectangle1, m_pLightSlateGrayBrush);
//		m_pRenderTarget->DrawRectangle(&rectangle1, m_pSolidColorBrushBlack);
//		m_pRenderTarget->FillRectangle(&rectangle1, m_pLinearGradientBrush);
//		// Draw the outline of a rectangle.
//        m_pRenderTarget->FillRectangle(&rectangle2, m_pSolidColorBrush);
//
//		m_pRenderTarget->FillRectangle(&rectangle3, m_pRadialGradientBrush);
//
//		m_pRenderTarget->FillRectangle(&rectangle4, m_pSolidColorBrush);
//
//		m_pRenderTarget->FillRectangle(&rectangle5, m_pSolidColorBrushBlack);
//
//		m_pRenderTarget->FillEllipse(ellipse, m_pRadialGradientBrush);
//
//		hr = m_pRenderTarget->EndDraw();
//}
////================================================================================================
//
//HRESULT CreateDeviceResources()
//{
//    hr = S_OK;
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
//        // Create a Direct2D render target.
//        hr = m_pDirect2dFactory->CreateHwndRenderTarget(
//            D2D1::RenderTargetProperties(),
//            D2D1::HwndRenderTargetProperties(m_hwnd, size),
//            &m_pRenderTarget
//            );
//
//
//        if (SUCCEEDED(hr))
//        {
//			//---------------------------------------------------
//            // Create a gray brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::LightSlateGray),
//                &m_pLightSlateGrayBrush
//                );
//
////-------------------------------------------------------------------------------------------------
//// Create a  LinearGradientBrush (Start)
////-------------------------------------------------------------------------------------------------
//			gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::ForestGreen, 1);
//			gradientStops[0].position = 0.0f;
//			gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Yellow, 1);
//			gradientStops[1].position = 0.5f;
//			gradientStops[2].color = D2D1::ColorF(D2D1::ColorF::Indigo, 1);
//			gradientStops[2].position = 1.0f;
//			// Create the ID2D1GradientStopCollection from a previously
//			// declared array of D2D1_GRADIENT_STOP structs.
//			hr = m_pRenderTarget->CreateGradientStopCollection(
//				gradientStops,
//				3,
//				D2D1_GAMMA_2_2,
//				D2D1_EXTEND_MODE_CLAMP,
//				&pGradientStops
//				);
//
//			if (SUCCEEDED(hr))
//			{
//				hr = m_pRenderTarget->CreateLinearGradientBrush(
//					D2D1::LinearGradientBrushProperties(
//						D2D1::Point2F(0, 0),
//						D2D1::Point2F(500, 0)),
//					pGradientStops,
//					&m_pLinearGradientBrush
//					);
//			}
//        
////-------------------------------------------------------------------------------------------------
//// Create a  LinearGradientBrush (End)
////-------------------------------------------------------------------------------------------------
//
//
////-------------------------------------------------------------------------------------------------
//// Create a  RadialGradientBrush (Start)
////-------------------------------------------------------------------------------------------------
//			gradientStopsForRadial[0].color = D2D1::ColorF(D2D1::ColorF::Crimson, 0.5);
//			gradientStopsForRadial[0].position = 0.0f;
//			gradientStopsForRadial[1].color = D2D1::ColorF(D2D1::ColorF::Yellow, 1);
//			gradientStopsForRadial[1].position = 1.0f;
//			// Create the ID2D1GradientStopCollection from a previously
//			// declared array of D2D1_GRADIENT_STOP structs.
//			hr = m_pRenderTarget->CreateGradientStopCollection(
//				gradientStopsForRadial,
//				2,
//				D2D1_GAMMA_2_2,
//				D2D1_EXTEND_MODE_CLAMP,
//				&pGradientStopsForRadial
//				);
//
//			if (SUCCEEDED(hr))
//			{
//				hr = m_pRenderTarget->CreateRadialGradientBrush(
//					D2D1::RadialGradientBrushProperties(
//						D2D1::Point2F(0, 0),
//						D2D1::Point2F(410, 0),
//						100,
//						300),
//					pGradientStopsForRadial,
//					&m_pRadialGradientBrush
//					);
//			}
//        }//if (SUCCEEDED(hr))
////-------------------------------------------------------------------------------------------------
//// Create a  RadialGradientBrush (End)
////-------------------------------------------------------------------------------------------------
//
//
//
////-------------------------------------------------------------------------------------------------
//        if (SUCCEEDED(hr))
//        {
//			//---------------------------------------------------
//            // Create a blue brush.
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::CornflowerBlue),
//                &m_pSolidColorBrush
//                );
//
//            hr = m_pRenderTarget->CreateSolidColorBrush(
//                D2D1::ColorF(D2D1::ColorF::Black),
//                &m_pSolidColorBrushBlack
//                );
//			
//        }
//    }//if (!m_pRenderTarget)
//
//    return hr;
//}
//
////================================================================================================
//void DiscardDeviceResources()
//{
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pLightSlateGrayBrush);
//    SafeRelease(&m_pSolidColorBrush);
//}
////================================================================================================
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    LRESULT result = 0;
//
//    if (message == WM_CREATE)
//    {
//          result = 1;
//    }
//    else
//    {
//        bool wasHandled = false;
//
//
//        switch (message)
//        {
//        case WM_SIZE:
//            {
//                UINT width = LOWORD(lParam);
//                UINT height = HIWORD(lParam);
//                //pDemoApp->OnResize(width, height);
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//        case WM_DISPLAYCHANGE:
//            {
//                InvalidateRect(hwnd, NULL, FALSE);
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//        case WM_PAINT:
//            {
//                //
//				//CreateDeviceResources();
//				DoDraw();
//                ValidateRect(hwnd, NULL);
//				if (hr == D2DERR_RECREATE_TARGET)
//				{
//					hr = S_OK;
//					DiscardDeviceResources();
//				}
//            }
//            result = 0;
//            wasHandled = true;
//            break;
//
//        case WM_DESTROY:
//            {
//                PostQuitMessage(0);
//            }
//            result = 1;
//            wasHandled = true;
//            break;
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
////================================================================================================
//int WINAPI WinMain(
//    HINSTANCE  hInstance ,
//    HINSTANCE hPrevInstance,
//    LPSTR /* lpCmdLine */,
//    int /* nCmdShow */
//    )
//{
//
//    if (!SUCCEEDED(CoInitialize(NULL))) //COM Initialize
//    {
//		return 1;
//	}
//
//	
//
//	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pDirect2dFactory);
//	
//    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
//    wcex.style         = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc   = WndProc;
//    wcex.cbClsExtra    = 0;
//    wcex.cbWndExtra    = sizeof(LONG_PTR);
//    wcex.hInstance     = hInstance;
//    wcex.hbrBackground = NULL;
//    wcex.lpszMenuName  = NULL;
//    wcex.hCursor       = LoadCursor(NULL, IDI_APPLICATION);
//    wcex.lpszClassName = L"D2DDemoApp";
//
//    RegisterClassEx(&wcex);
//
//
//	// Because the CreateWindow function takes its size in pixels,
//    // obtain the system DPI and use it to scale the window size.
//	// The factory returns the current system DPI. This is also the value it will use
//    // to create its own windows.
//    FLOAT dpiX, dpiY;
//	m_pDirect2dFactory->GetDesktopDpi(&dpiX, &dpiY);
//
//        // Create the window.
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
//            hInstance,
//            NULL
//            );
//
//		CreateDeviceResources();
//		 ShowWindow(m_hwnd, SW_SHOWNORMAL);
//         UpdateWindow(m_hwnd);
//
//		MSG msg;
//
//		while (GetMessage(&msg, NULL, 0, 0))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//
//		
////============================================================================	
//	SafeRelease(&m_pDirect2dFactory);
//    SafeRelease(&m_pRenderTarget);
//    SafeRelease(&m_pLightSlateGrayBrush);
//    SafeRelease(&m_pSolidColorBrush);
//	SafeRelease(&m_pLinearGradientBrush);
//	SafeRelease(&m_pRadialGradientBrush);
//
//	CoUninitialize(); //COM Uninitialize
//    return 0;
//}
