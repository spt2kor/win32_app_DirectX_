
#include "stdafx.h"
#include "MathfuncDLL.h"
#include "tchar.h"

BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void Addition(int a, int b)
{
  _TCHAR szBuffer[100];
  int c =a+b;
  _stprintf_s(szBuffer, _T("%d"), c);
  MessageBox( NULL, szBuffer, _T("Addition DLL"), MB_OK);
}

void Subtraction(int a, int b)
{
  _TCHAR szBuffer[100];
  int c =a-b;
  _stprintf_s(szBuffer, _T("%d"), c);
  MessageBox( NULL, szBuffer, _T("Subtraction DLL"), MB_OK);
}

void Multiplication(int a, int b)
{
  _TCHAR szBuffer[100];
  int c =a*b;
  _stprintf_s(szBuffer, _T("%d"), c);
  MessageBox( NULL, szBuffer, _T("Multiplication DLL"), MB_OK);
}

