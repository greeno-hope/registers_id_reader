/**
 * @file
 * AboutDialog.c
 * 
 * @brief
 * Implementation of the Windows callback function for the 'About' (help) dialog.
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2022 Mark Greenwood - Liverpool Hope University .  All rights reserved.
 */

#include "AboutDialog.h"

// Message handler for about box.
INT_PTR CALLBACK AboutDialogCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}