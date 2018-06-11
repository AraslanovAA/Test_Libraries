#include "stdafx.h"
#include <Windows.h>
#include "MyDLL.h"

int* summ(int *arrNUms, int NUmElemets)
{
	for (int i = 0;i < NUmElemets;i++) {//удалены остатки по модулю 60кратные 2,3,5

		if ((arrNUms[i] == 0) && ((i + 2) != 2) && (((i + 2) % 60) % 2 == 0))
		{
			arrNUms[i] = 1;
		}
		if ((arrNUms[i] == 0) && ((i + 2) != 3) && (((i + 2) % 60) % 3 == 0))
		{
			arrNUms[i] = 1;
		}
		if ((arrNUms[i] == 0) && ((i + 2) != 5) && (((i + 2) % 60) % 5 == 0))
		{
			arrNUms[i] = 1;
		}
	}
	int n = 7;
	for (int i = 0; i < NUmElemets;i++) {

		if ((arrNUms[i] == 0) && (((i + 2) % 60) % 4 == 1))
		{
			if (((i + 2) == n*n) || (i == 75)) {
				arrNUms[i] = 1;
			}
			else {
				arrNUms[i] = 0;
			}
		}
		if ((arrNUms[i] == 0) && (((i + 2) % 60) % 6 == 1))
		{
			if ((i + 2) == 91) {
				arrNUms[i] = 1;
			}
			else {
				arrNUms[i] = 0;
			}
		}
		if ((arrNUms[i] == 0) && (((i + 2) % 60) % 12 == 11))
		{
			arrNUms[i] = 0;
		}
	}
	
	return arrNUms;
}