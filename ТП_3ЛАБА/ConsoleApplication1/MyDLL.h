#pragma once
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif


extern "C" _declspec(dllexport) int summ(int **mas, int m1, int n1);
