#include <Windows.h>
#include "resource.h"
#include <stdio.h>

char Buffer[64];
double FirstOper, SecondOper, Result;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
	return 0;
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_Sum:
		{
			SendDlgItemMessage(hwnd, IDC_FirstParam, WM_GETTEXT, 255, (LPARAM)Buffer);
			if (sscanf_s(Buffer, "%lf", &FirstOper) < 1)
			{
				MessageBox(hwnd, "Wrong first operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_Second_Param, WM_GETTEXT, 255, (LPARAM)Buffer);

			if (sscanf_s(Buffer, "%lf", &SecondOper) < 1)
			{
				MessageBox(hwnd, "Wrong second operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_Second_Param, WM_GETTEXT, 255, (LPARAM)Buffer);
			
			char Sign;
			Result = FirstOper + SecondOper; Sign = '+';
			sprintf_s(Buffer, "%f", Result);
			SendDlgItemMessage(hwnd, IDC_Result, WM_SETTEXT, 0, (LPARAM)Buffer);

			sprintf_s(Buffer, "%f %c %f = %f", FirstOper, Sign, SecondOper, Result);
			SendDlgItemMessage(hwnd, IDC_ListOfOper, LB_ADDSTRING, 0, (LPARAM)Buffer);
			
		}
		break;
		case IDC_Min:
		{
			SendDlgItemMessage(hwnd, IDC_FirstParam, WM_GETTEXT, 255, (LPARAM)Buffer);
			if (sscanf_s(Buffer, "%lf", &FirstOper) < 1)
			{
				MessageBox(hwnd, "Wrong first operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_Second_Param, WM_GETTEXT, 255, (LPARAM)Buffer);

			if (sscanf_s(Buffer, "%lf", &SecondOper) < 1)
			{
				MessageBox(hwnd, "Wrong second operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_Second_Param, WM_GETTEXT, 255, (LPARAM)Buffer);
			char Sign;
			Result = FirstOper - SecondOper; Sign = '-';
			sprintf_s(Buffer, "%f", Result);
			SendDlgItemMessage(hwnd, IDC_Result, WM_SETTEXT, 0, (LPARAM)Buffer);
			

			sprintf_s(Buffer, "%f %c %f = %f", FirstOper, Sign, SecondOper, Result);
			
			SendDlgItemMessage(hwnd, IDC_ListOfOper, LB_ADDSTRING, 0, (LPARAM)Buffer);
			
		}
		break;
		case IDC_Clear:
		{
			SendDlgItemMessage(hwnd, IDC_ListOfOper, LB_RESETCONTENT, 0, 0);
			return TRUE;
		}
		break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return FALSE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return FALSE;

	}
	return FALSE;
}
