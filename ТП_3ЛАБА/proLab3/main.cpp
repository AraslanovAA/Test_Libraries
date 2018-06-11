#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <string>
#include <sstream>
#include <windowsx.h>
#include <TCHAR.H>
#include "Ferma_static_lib.h"
#include "MyDLL.h"

#pragma comment(lib,"MyDLL.lib")



using namespace Gdiplus;
using namespace std;

#pragma comment (lib,"Gdiplus.lib")


HMENU hMenu, hFileMenu, hHelpMenu;
HINSTANCE hInstance;

// ��������� �������� CALLBACK �������
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc2(HWND hWnd2, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND text, text2, text_out, text_out_2, text_out_nums, text_out_0, text_out_1,text_out_3, hWnd2, rbutton, rbutton2, rbut, rbut2, rbutton3, rbutton4, button1, edit, buttonClose, hEditD1, text_out_nums2,
hEditD2, hEditD3,  textP1, textP2, textP3, textP4, textP5, textP6, textP7,
textP8, textP9, textP10, textP11, textP12, textP13, textP14, textP15, textP16, button2, buttonnext;
HWND arrayEdits1[10][10];
int WhatMethod;
int mas1[16];
int flag = 1;
int n = 7;
int K_0;
bool result = false;
int k = 0;
bool crutch = false;
bool Mycase = false;
TCHAR HELPMESSAGE_2[25] = { '�','�',' ','�','�','�','�','�','�','�',' ','�','�','�','�','�',' ','�','�','�','�','�','�','x' };
TCHAR HELPMESSAGE[25] = { ' ',' ','�','�','�','�','e','�','�',' ','�','�','�','�','a',' ','�','p','a','�','�','�','e',' ' };//22
TCHAR THEEND[6] = { '�','o','�','e','�' };
int step = 0, nullstep = 0;
int NumElements;
int arrNums[100];
bool FirstMethod;
int menu = 0;
int p = 1;
bool LastOp = FALSE;
int l = 99;
int r = 2;
int a = 1;
int mas2[16];
int* resmas;
int DrawKey = 0;
TCHAR charBuffer[2];
bool ERR_NO_0_1 = false;
bool ERR_NO_SIMBOL = false;
int num;

// ������� WinAPI ��� ����� ����� � ���������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// ����������� ������ ����
	// ��������� ���������� ���� WNDCLASSEX

	WNDCLASSEX wClass, wNewClass, elseClass;
	ZeroMemory(&wClass, sizeof(wClass)); // �������� ������
	ZeroMemory(&wNewClass, sizeof(wNewClass));
	ZeroMemory(&elseClass, sizeof(wNewClass));
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	// ��������� ��������� WNDCLASSEX
	wClass.cbSize = sizeof(wClass); // ������ ����� ������� ���������
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wClass.hInstance = hInstance; // hInstance window
	wClass.lpfnWndProc = (WNDPROC)WndProc; // ��������� ��������� ����
	wClass.lpszClassName = "CLASS_1"; // ��� ������

	wNewClass.cbSize = sizeof(wNewClass); // ������ ����� ������� ���������
	wNewClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wNewClass.hInstance = hInstance; // hInstance window
	wNewClass.lpfnWndProc = (WNDPROC)WndProc2; // ��������� ��������� ����
	wNewClass.lpszClassName = "CLASS_2"; // ��� ������



	// ���� ��������� ������, �� ������� ���������
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, "����� ���� �� ��� ������!", "������", MB_ICONERROR);
	}

	if (!RegisterClassEx(&wNewClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, "����� ���� �� ��� ������!", "������", MB_ICONERROR);
	}



	// ������� ���� ��� ������ ������� WinApi CreateWindowEx
	HWND hWindow = CreateWindowEx(NULL,
		"CLASS_1", // ��� ������, ������� �� ���������� �����
		"����� ������� �����", // ��������� ����
		WS_TILED,
		300, // x ���������� �� �����������
		300, // y ���������� �� ���������
		270, // ������ ������������ ����
		350, // ������ ������������ ����
		NULL,
		NULL,
		hInstance, // ���������� ���������� ����������
		NULL);



	// ���� ���� �� ���� �������, �� ������ ���������
	if (!hWindow)
	{
		int nResult = GetLastError();
		MessageBox(NULL, "���� �� ���� �������!", "������", MB_ICONERROR);
	}

	hWnd2 = CreateWindowEx(NULL,
		"CLASS_2", // ��� ������, ������� �� ���������� �����
		"�������", // ��������� ����
		WS_TILED,
		200, // x ���������� �� �����������
		200, // y ���������� �� ���������
		660, // ������ ������������ ����
		530, // ������ ������������ ����
		hWindow,
		NULL,
		hInstance, // ���������� ���������� ����������
		NULL);

	if (!hWnd2)
	{
		int nResult = GetLastError();
		MessageBox(NULL, "���� �� ���� �������!", "������", MB_ICONERROR);
	}


	// ���������� ����
	ShowWindow(hWindow, SW_SHOW);
	UpdateWindow(hWindow);

	// ��������� ���������� ��� ��������� ���� MSG
	MSG msg;
	// �������� ������ �� ������� ��������� MSG
	ZeroMemory(&msg, sizeof(MSG));

	// ���� ��������� ���������
	for (;;)
	{
		BOOL const Status = GetMessage(&msg, NULL, 0, 0);

		if ((0 == Status) || (-1 == Status))
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	/*while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/
	GdiplusShutdown(gdiplusToken);
	return 0;
}

// ���������� ��������� ��������� ������ (WinApi)
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		
			rbutton3 = CreateWindow(
				"BUTTON",
				"���� �����",
				WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
				20,
				150,
				160,
				20,
				hwnd,
				(HMENU)5,
				hInstance,
				NULL
			);
		rbut = CreateWindow(
			"BUTTON",
			"������ ����������",
			WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
			20,
			40,
			160,
			20,
			hwnd,
			(HMENU)3,
			hInstance,
			NULL
		);
		SendMessage(rbut, BM_SETCHECK, BST_CHECKED, 0);
		rbut2 = CreateWindow(
			"BUTTON",
			"������ ������",
			WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
			20,
			70,
			150,
			20,
			hwnd,
			(HMENU)4,
			hInstance,
			NULL
		);



		text = CreateWindow("STATIC", "���������� ������� �����", WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 15, 220, 20, hwnd, (HMENU)10, NULL, NULL);
		text2 = CreateWindow("STATIC","����������� �������� �����", WS_VISIBLE | WS_CHILD | WS_BORDER,
			10, 125, 220, 20, hwnd, (HMENU)10, NULL, NULL);
		
		hEditD3 = CreateWindow("edit", "0", WS_CHILD | false | WS_BORDER | ES_LEFT | ES_READONLY, 140, 205, 15, 25, hwnd, NULL, hInstance, NULL);


		sprintf(charBuffer, "%d", 1);
		SetWindowText(hEditD3, charBuffer);
		// ����� ����� ��������� �������� ���������� ����
		HWND buttonpitch = CreateWindow("BUTTON", "��������", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 10, 260, 80, 30, hwnd, (HMENU)1, NULL, NULL);
		HWND buttonClose = CreateWindow("BUTTON", "�����", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 170, 260, 60, 30, hwnd, (HMENU)2, NULL, NULL);


		break;
	}
	case WM_CTLCOLORSTATIC: {
		if ((HWND)lParam == GetDlgItem(hwnd, 10))
		{
			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0, 0, 178));//��������� � ������� �������� - �����
			return (int)GetStockObject(NULL_BRUSH);

		}

	}

	case WM_NCLBUTTONDOWN: {
		if (wParam == HTCAPTION) {
			return 0;
		}
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
		case 1:
		{
			//ERR_NO_SIMBOL = FALSE;
			//ERR_NO_0_1 = FALSE;
			//mas2[0] = SendMessage(hEditD1, EM_LINELENGTH, -1, 0);
			//mas2[1] = SendMessage(hEditD2, EM_LINELENGTH, -1, 0);


			//for (int j = 0; j < 2; j++)
			//{
			//	if (mas2[j] == 0) {
			//		MessageBox(NULL, "������� �������", "������", MB_ICONERROR);
			//		ERR_NO_SIMBOL = TRUE;
			//		break;
			//	}
			//}
			//if (ERR_NO_SIMBOL == FALSE) {
			//	SendMessage(hEditD1, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
			//	mas1[0] = atoi(charBuffer);
			//	SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
			//	mas1[1] = atoi(charBuffer);



			//	for (int i = 0; i < 2; i++)
			//	{
			//		if ((mas1[i] == 0) || (mas1[i] == 1))
			//		{
			//			MessageBox(NULL, "����������� ����� �� 2 �� 99", "������", MB_ICONERROR);
			//			ERR_NO_0_1 = TRUE;
			//			break;
			//		}
			//	}
			//}
			//if ((ERR_NO_0_1 == FALSE) && (ERR_NO_SIMBOL == FALSE)) {
			//	
			//}
			ShowWindow(hWnd2, SW_SHOW);
			break;
		}

		case 2:
		{

			PostQuitMessage(0);
			return 0;
			break;
		}
		case 3: {
				SendMessage(rbut, BM_SETCHECK, BST_CHECKED, 0);
				SendMessage(rbut2, BM_SETCHECK, BST_UNCHECKED, 0);
				SendMessage(rbutton3, BM_SETCHECK, BST_UNCHECKED, 0);
				sprintf(charBuffer, "%d", 1);
				SetWindowText(hEditD3, charBuffer);
			break;
		}
		case 4: {
			SendMessage(rbut, BM_SETCHECK, BST_UNCHECKED, 0);
			SendMessage(rbut2, BM_SETCHECK, BST_CHECKED, 0);
			SendMessage(rbutton3, BM_SETCHECK, BST_UNCHECKED, 0);
			sprintf(charBuffer, "%d", 2);
			SetWindowText(hEditD3, charBuffer);
			break;
		}

		case 5: {
			SendMessage(rbut, BM_SETCHECK, BST_UNCHECKED, 0);
			SendMessage(rbut2, BM_SETCHECK, BST_UNCHECKED, 0);
			SendMessage(rbutton3, BM_SETCHECK, BST_CHECKED, 0);
			sprintf(charBuffer, "%d", 3);
			SetWindowText(hEditD3, charBuffer);
			break;

		}

				break;

		}

		break;
	}

	case WM_DESTROY: // ��������� ������� ������ �������� ����
	{
		// ������� ������� ����
		PostQuitMessage(0);
		return 0;
		break;
	}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



LRESULT CALLBACK WndProc2(HWND hWnd2, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int testP = 1;
	HDC hdc;

	string tmp;
	switch (uMsg)
	{
	case WM_CREATE:
	{
		button2 = CreateWindow("BUTTON", "�������", WS_VISIBLE | WS_CHILD
			| WS_BORDER, 360, 450, 70, 30, hWnd2, (HMENU)100, NULL, NULL);

		buttonnext = CreateWindow("BUTTON", "������", WS_VISIBLE | WS_CHILD//��������� �������� �� ������� ������
			| WS_BORDER, 160, 450, 120, 30, hWnd2, (HMENU)101, NULL, NULL);
		

		break;
	}
	case WM_PAINT: {
			SendMessage(hEditD3, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
			 WhatMethod = atoi(charBuffer);
			if (WhatMethod != 3) {//������
				hEditD1 = CreateWindow("edit", "2", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_READONLY, 20, 60, 20, 25, hWnd2, NULL, hInstance, NULL);
				EnableWindow(hEditD1, FALSE);
				hEditD2 = CreateWindow("edit", "99", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER, 80, 60, 20, 25, hWnd2, NULL, hInstance, NULL);
				text_out = CreateWindow("EDIT", "������� �������", WS_VISIBLE | WS_CHILD | ES_READONLY,// | WS_BORDER
					10, 35, 800, 25, hWnd2, NULL, NULL, NULL);
				if (WhatMethod == 1) {
					text_out_0 = CreateWindow("EDIT", "������ ����������", WS_VISIBLE | WS_CHILD | ES_READONLY,
						250, 10, 180, 25, hWnd2, NULL, NULL, NULL);
				}
				else
				{
					text_out_0 = CreateWindow("EDIT", "������ ������", WS_VISIBLE | WS_CHILD | ES_READONLY,
						250, 10, 180, 25, hWnd2, NULL, NULL, NULL);
				}

				text_out_1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					10, 100, 800, 25, hWnd2, NULL, NULL, NULL);
				text_out_3 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					10, 130, 800, 25, hWnd2, NULL, NULL, NULL);
				text_out_nums = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					10, 155, 800, 40, hWnd2, NULL, NULL, NULL);
				
			}
			else {//����������� ��������
				
				text_out_0 = CreateWindow("EDIT", "����� �����", WS_VISIBLE | WS_CHILD | ES_READONLY,
					250, 10, 180, 25, hWnd2, NULL, NULL, NULL);
				text_out = CreateWindow("EDIT", "������� �����:", WS_VISIBLE | WS_CHILD | ES_READONLY,// | WS_BORDER
					10, 35, 125, 25, hWnd2, NULL, NULL, NULL);
				hEditD2 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER, 135,35 , 30, 25, hWnd2, NULL, hInstance, NULL);

				text_out_nums = CreateWindow("EDIT", "", WS_VISIBLE|WS_CHILD | ES_READONLY,
					10, 130, 135, 40, hWnd2, NULL, NULL, NULL);

				text_out_nums2 = CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					145, 130, 80, 40, hWnd2, (HMENU)102, NULL, NULL);
				text_out_1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					10, 80, 800, 25, hWnd2, NULL, NULL, NULL);
				text_out_3 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | ES_READONLY,
					10, 105, 800, 25, hWnd2, NULL, NULL, NULL);
			}
	}
	
	case WM_NCLBUTTONDOWN: {
		if (wParam == HTCAPTION) {
			return 0;
		}
		break;
	}

	case WM_COMMAND:
	{

		switch (LOWORD(wParam))
		{
			// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
		case 100:
		{
			
				DestroyWindow(text_out_0);
				DestroyWindow(text_out);
				DestroyWindow(hEditD2);
				DestroyWindow(hEditD1);
				DestroyWindow(text_out_nums);
				DestroyWindow(text_out_nums2);
				DestroyWindow(text_out_1);
				DestroyWindow(text_out_3);
				
		
			
			ShowWindow(hWnd2, SW_HIDE);
			break;
		}
		case 101: {
			if (WhatMethod == 3) {
				SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
				int num = atoi(charBuffer);

				if (num >= 2) {
					result = ferma(num);
					SetWindowText(text_out_nums, "�������� ����� - ");
					if (result) {
						SetWindowText(text_out_nums2, "�������");
						SetWindowText(text_out_1, "����� ���� ���������� � 100 ��������� ����� �� ������ �����.");
						SetWindowText(text_out_3, "�������� ��������, ���:");
					}
					else {
						SetWindowText(text_out_nums2, "���������");
						SetWindowText(text_out_1, "");
						SetWindowText(text_out_3, "");
					}

				}
				else {
					MessageBox(hWnd2, "������� ����� >=2", "������������ ��������", NULL);
				}
			}
			if (WhatMethod == 1) {
				SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
				int num_ = atoi(charBuffer);
				if (num_ >= 2) {
					NumElements = num_ - 1;
					for (int i = 0;i < NumElements;i++) {
						arrNums[i] = 0;
					}

					typedef int(*MYFUNC)(int*, int);
					HMODULE hlib = LoadLibrary("MyDLL_2.dll");
					if (hlib == NULL) {
						MessageBox(hWnd2, "���������� DLL �� �������!", "Error", NULL);
						break;
					}
					MYFUNC get = (MYFUNC)GetProcAddress(hlib, "FindPrime");
					int res = 0;

					*arrNums = get(arrNums, NumElements);
					FreeLibrary(hlib);



					//����� �� �����
					int K_0 = 0;
					TCHAR DELETEDNUMBERS[1000];
					arrNums[0] = 0;
					for (int i = 0;i < NumElements;i++) {
						if (arrNums[i] == 0) {
							sprintf(charBuffer, "%d", i + 2);
							DELETEDNUMBERS[K_0] = ' ';
							K_0++;
							if (charBuffer[0] != '\0') {
								DELETEDNUMBERS[K_0] = charBuffer[0];
								K_0++;
							}
							if (charBuffer[1] != '\0') {
								DELETEDNUMBERS[K_0] = charBuffer[1];
								K_0++;
							}
						}
					}

					DELETEDNUMBERS[K_0] = '\0';
					SetWindowText(text_out_1, "������� �����:");
					SetWindowText(text_out_3, DELETEDNUMBERS);
					SetWindowText(text_out_nums, "������ ������ � �������������� ������������ ���������� � ����� ����������");
				}
				else {
					MessageBox(hWnd2, "������� ����� >=2", "������������ ��������", NULL);
				}
			}
			if (WhatMethod == 2) {
				SendMessage(hEditD2, WM_GETTEXT, (WPARAM)255, (LPARAM)charBuffer);
				int num_ = atoi(charBuffer);
				if (num_ >= 2) {
					NumElements = num_ - 1;
					for (int i = 0;i < NumElements;i++) {
						arrNums[i] = 0;
					}
					*arrNums = summ(arrNums, NumElements);


					//����� �� �����
					int K_0 = 0;
					TCHAR DELETEDNUMBERS[1000];
					arrNums[0] = 0;
					for (int i = 0;i < NumElements;i++) {
						if (arrNums[i] == 0) {
							sprintf(charBuffer, "%d", i + 2);
							DELETEDNUMBERS[K_0] = ' ';
							K_0++;
							if (charBuffer[0] != '\0') {
								DELETEDNUMBERS[K_0] = charBuffer[0];
								K_0++;
							}
							if (charBuffer[1] != '\0') {
								DELETEDNUMBERS[K_0] = charBuffer[1];
								K_0++;
							}
						}
					}

					DELETEDNUMBERS[K_0] = '\0';
					SetWindowText(text_out_1, "������� �����:");
					SetWindowText(text_out_3, DELETEDNUMBERS);
					SetWindowText(text_out_nums, "������ ������ � �������������� ������������ ���������� � �� ����� ����������");

				}
				else {
					MessageBox(hWnd2, "������� ����� >=2", "������������ ��������", NULL);
				}
			}
			
		}
		
		case WM_DESTROY: // ��������� ������� ������ �������� ����
		{
			// ������� ������� ����
			/*PostQuitMessage(0);
			return 0;
			break;*/
		}
		}
	}
	}

	return DefWindowProc(hWnd2, uMsg, wParam, lParam);
}
