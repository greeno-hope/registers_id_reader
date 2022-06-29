#include "utils.h"

void clearEditText() {
	SetWindowText(_hEditWindow, L"");
}

BOOL saveEditText(WCHAR* pFileName) {
	BOOL ok = FALSE;
	HANDLE hFile = CreateFile(pFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		DWORD textLen = GetWindowTextLength(_hEditWindow);
		if (textLen > 0) {

			LPWSTR pWideText;
			DWORD wBuffSize = (textLen + 1) * sizeof(WCHAR);
			pWideText = GlobalAlloc(GPTR, wBuffSize);

			if (NULL != pWideText) {
				if (GetWindowText(_hEditWindow, pWideText, wBuffSize)) {

					LPSTR pChars;
					pChars = GlobalAlloc(GPTR, textLen + 1);
					ucs2ToAscii(pWideText, pChars, textLen);
					DWORD written;
					if (WriteFile(hFile, pChars, textLen, &written, NULL)) {
						ok = TRUE;
					}
					GlobalFree(pChars);
				}
			}
			GlobalFree(pWideText);
		}
		CloseHandle(hFile);
	}
	return ok;
}

void appendEditText(WCHAR* newText) {
	int index = GetWindowTextLength(_hEditWindow);
	//SetFocus(hEditWindow);											// set focus
	SendMessage(_hEditWindow, EM_SETSEL, (WPARAM)index, (LPARAM)index);  // set selection - end of text
	SendMessage(_hEditWindow, EM_REPLACESEL, 0, (LPARAM)newText);		// append!
}

int ucs2ToAscii(WCHAR* src, char* dest, int charsToCopy) {
	int i = 0;
	for (i = 0; i < charsToCopy; i++) {
		*dest++ = (char)*src++;
	}
	return i;
}

int asciiToUcs2(char* src, WCHAR* dest, int charsToCopy) {
	int i = 0;
	for (i = 0; i < charsToCopy; i++) {
		*dest++ = (WCHAR)*src++;
	}
	return i;
}


