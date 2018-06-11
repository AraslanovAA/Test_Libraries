#include "stdafx.h"
#include <Windows.h>
#include "MyDLL.h"

int summ(int **mas, int m1, int n1)
{
	/*#include "MyDLL.h" 

#pragma comment(lib,"MyDLL.lib")*/
	int mul = 0;
	int min = mas[0][0];
	for (int i = 0; i < m1; i++){
		for (int j = 1; j < n1; j++){
			if (mas[i][j] < min) {
				min = mas[i][j];
			}
		}
	}
	int max = mas[0][0];
	for (int i = 0; i < m1; i++){
		for (int j = 1; j < n1; j++){
			if (mas[i][j] > max) {
				max = mas[i][j];
			}
		}
	}
	mul = min*max; 
	return mul;
}