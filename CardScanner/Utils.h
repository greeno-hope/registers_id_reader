#pragma once

#include "globals.h"

// TextEdit Utility methods
// These just manilupate the main text region in
// the app or write it's contents to file not
// complicated
void clearEditText();
BOOL saveEditText(WCHAR* pFileName);
void appendEditText(WCHAR* pNewText);

// String utility methods - these are just knocked up
// because we are dealing with WCHAR (_L / UCS2) strings
// or ASCII (char) which we want to write to file for
// the Chrome plugin.
// Don't need to bother with the complexity of multibyte
// char sets like UTF8 or UTF16 etc...
int ucs2ToAscii(WCHAR *src, char *dest, int charsToCopy);
int asciiToUcs2(char *src, WCHAR *dest, int charsToCopy);


