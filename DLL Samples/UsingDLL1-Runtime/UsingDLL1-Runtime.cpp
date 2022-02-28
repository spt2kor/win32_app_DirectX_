
#include "windows.h"
#include "tchar.h"
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{ 	
	int a,b;
    a=10;
	b=5;
    typedef void (*DLLPROC) (int,int);

	HINSTANCE hinstDLL;
	DLLPROC fun;
	BOOL fFreeDLL;
	_TCHAR szBuffer[100];
	hinstDLL = LoadLibrary(_T("MathfuncDLL1.dll"));

	if( hinstDLL == NULL)
		{
			MessageBox( NULL, _T("ERROR"), _T(" DLL"), MB_OK);
		}

	if (hinstDLL != NULL)
		{
			fun = (DLLPROC) GetProcAddress(hinstDLL, "Addition");
				if (fun != NULL)
					fun(a,b);

			fun = (DLLPROC) GetProcAddress(hinstDLL, "Subtraction");
				if (fun != NULL)
					fun(a,b);

			fun = (DLLPROC) GetProcAddress(hinstDLL, "Multiplication");
				if (fun != NULL)
					fun(a,b);

			fFreeDLL = FreeLibrary(hinstDLL);
		}   

	return 0;
}