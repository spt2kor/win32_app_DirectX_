// include the basic windows header file
#include <windows.h>


// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, // handle to window
                         UINT message, // system defined messages // check msdn
                         WPARAM wParam,  // 64bit 'W'ord  // handle or integer is passed
                         LPARAM lParam); // 64 bit 'L'ong // pointers are passed 

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,  // handle to current instance
                   HINSTANCE hPrevInstance,  // handle to prev-instance
                   LPSTR lpCmdLine, // stores the entire command line minus the program name
                   int nCmdShow) // controls how the window is to be shown
{
    // the handle for the window, filled by a function
    HWND hWnd;
    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW; //  store the style of the window.
    wc.lpfnWndProc = WindowProc;  // is a pointer to an application-defined function called the window procedure
    wc.hInstance = hInstance; // is the handle to the application instance.
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); //  stores the default mouse image for the window class.
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //  contains the 'brush' that will be used to color the background of our window. 
    wc.lpszClassName = L"WindowClass1";  // is a string that identifies the window class.

    // register the window class
    RegisterClassEx(&wc);

    // create the window and use the result as the handle
    hWnd = CreateWindowEx(NULL,
                          L"WindowClass1",    // name of the window class
                          L"Our First Windowed Program",   // title of the window
                          WS_OVERLAPPEDWINDOW,    // window style
                          300,    // x-position of the window
                          300,    // y-position of the window
                          500,    // width of the window
                          400,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL

    // display the window on the screen
    ShowWindow(hWnd, nCmdShow);

    // enter the main loop:

    // this struct holds Windows event messages
    MSG msg;

    // wait for the next message in the queue, store the result in 'msg'
    while(GetMessage(&msg, NULL, 0, 0)) // check the message queue for messgae , if no message it will wait
	//while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)) // check the message queue for messages , if no message it will return nothing //eats CPU time
    {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);

        // send the message to the WindowProc function
        DispatchMessage(&msg);
    }

    // return this part of the WM_QUIT message to Windows
    return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch(message)
    {
        // this message is read when the window is closed
        case WM_DESTROY:  
            {
                // close the application entirely
				MessageBox ( NULL , L"End of Simple_Window",L"Thank you !!", MB_ICONSTOP | MB_OK ); // MB_ICONWARNING
                PostQuitMessage(0); // tell our program to finish up the WinMain() function properly.
                return 0;
            } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc (hWnd, message, wParam, lParam);
}