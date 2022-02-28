
#ifndef INDLL_H
#define INDLL_H

   #ifdef EXPORTING_DLL1
		extern __declspec(dllexport) void Addition(int,int) ;
   #else
		extern __declspec(dllimport) void Addition(int , int) ;
   #endif

   #ifdef EXPORTING_DLL2
		extern __declspec(dllexport) void Subtraction(int,int) ;
   #else
		extern __declspec(dllimport) void Subtraction(int , int) ;
   #endif

   #ifdef EXPORTING_DLL3
		extern __declspec(dllexport) void Multiplication(int,int) ;
   #else
		extern __declspec(dllimport) void Multiplication(int , int) ;
   #endif

#endif
