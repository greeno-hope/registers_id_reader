#include "ConfigureDialog.h"

#include "framework.h"
#include "Resource.h"
#include "globals.h"
#include "utils.h"

// Message handler for about box.
INT_PTR CALLBACK ConfigureDlgCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    HWND hClassListBox = GetDlgItem(hDlg, IDC_LIST_ROOMS);
    HWND hTimeListBox = GetDlgItem(hDlg, IDC_LIST_TIME);
    HWND hTitleBox = GetDlgItem(hDlg, IDC_EDIT1);

    INT_PTR retVal = (INT_PTR)FALSE;

    switch (message)
    {
    case WM_INITDIALOG:

        // Populate the rooms list control
        // TODO do this from a dynamic resource and/or file eventually 
        for (int i = 0; i < _roomsListSize; i++) {
            SendMessage(hClassListBox, LB_ADDSTRING, 0, (LPARAM) _roomsList[i]);
        }

        // Populate the times list control
        // TODO do this from a dynamic resource and/or file eventually 
        for (int i = 0; i < _timesListSize; i++) {
            SendMessage(hTimeListBox, LB_ADDSTRING, 0, (LPARAM) _timesList[i]);
        }
        
        retVal = (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            // Store the selected room into the global variable
            _selectedRoom = SendMessage(hClassListBox, LB_GETCURSEL, 0, 0);
            _selectedTime = SendMessage(hTimeListBox, LB_GETCURSEL, 0, 0);

            // If no valid room chosen display error message box abd exit dialog
            if ( _selectedRoom < 1 || _selectedRoom > 50){
                MessageBox(0, L"You must select a valid room number", L"Warning", MB_ICONEXCLAMATION);
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
             }
            // If no valid room chosen display error message box abd exit dialog
            if (_selectedTime < 1 || _selectedTime> 50) {
                MessageBox(0, L"You must select a valid session time", L"Warning", MB_ICONEXCLAMATION);
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }

            WCHAR title[512];
            GetWindowText(hTitleBox, title, 512);

            // Valid configuration exists, write text then sent main window a reset command for the new state
            appendEditText(L"Starting new register session: ");
            appendEditText(title);
            appendEditText(L"\n");
            appendEditText(L"\n");
            appendEditText(L"Room: ");
            appendEditText(_roomsList[_selectedRoom]);
            appendEditText(L"\n");
            appendEditText(L"Time: ");
            appendEditText(_timesList[_selectedTime]);
            appendEditText(L"\n");
            appendEditText(L"\n");

            _readerAppState = CONFIGURED;
            SendMessage(_hMainWindow, WM_STATE_CHANGE, 0, 0);
            EndDialog(hDlg, LOWORD(wParam));
        }
        else if (LOWORD(wParam) == IDCANCEL) {
            _selectedRoom = 0;
            EndDialog(hDlg, LOWORD(wParam));
        }
        retVal = (INT_PTR)TRUE;
        break;
    }
    return retVal;
}
