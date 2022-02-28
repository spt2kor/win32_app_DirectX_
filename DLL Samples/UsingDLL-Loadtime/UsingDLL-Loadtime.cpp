#include "windows.h"
#include "MathfuncDLL.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{ 	
   int a,b;
   a=10;b=5;
   Addition(a,b);
   Sleep(1000);
   Subtraction(a,b);
   Sleep(1000);
   Multiplication(a,b);
   return 0;
}