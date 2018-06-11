#include "stdafx.h"
#include <Windows.h>

extern "C" _declspec(dllexport) int* FindPrime(int *arrNums, int NumElements)
{
	int p = 0;
	for (int k = 0;k < NumElements;k++) {
		if (arrNums[k] == 0) {
			p = k + 2;//нашли p
			for (int i = k;i < NumElements;i++) {
				if (((i + 2) != p) && ((i + 2) % p == 0) && (arrNums[i] == 0)) {
					arrNums[i] = 1;
				}
			}
		}
	}
	
	return arrNums;
}