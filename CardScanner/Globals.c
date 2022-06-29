#include "framework.h"
#include "globals.h"

WCHAR *_roomsList[] = {L"--- NONE --- ",
						L"FML 200",
						L"FML 201",
						L"FML 209",
						L"FML 211",
						L"FML 212",
						L"FML 215",
						L"FML 217",
						L"FML 300",
						L"FML 301",
						L"FML 309",
						L"FML 311A",     
						L"FML 400",
						L"FML 401",
						L"FML 408",
						L"FML 409",
						L"FML 411",
						L"FML 415",
						L"FML 420" };

WCHAR *_timesList[] = {L"--- NONE ---",
						L"09.00 am",
						L"10.00 am",
						L"11.00 am",
						L"12.00 pm",
						L"13.00 pm",
						L"14.00 pm",
						L"15.00 pm",
						L"16.00 pm",
						L"17.00 pm",
						L"18.00 pm" };

int _selectedRoom = 0;
int _roomsListSize = 19;

int _selectedTime = 0;
int _timesListSize = 11;

// Application state, use this to control menu states
SCARD_READER_STATE _readerAppState = NOT_CONFIGURED;

// Initialise all the HANDLES we need around the application
HINSTANCE _hInst = 0;
HWND _hMainWindow = 0;
HWND _hEditWindow = 0;

// Initialise all the SCARD handles also
SCARDCONTEXT _hScardContext = 0;     // Card context
SCARDHANDLE  _hCard = 0;				// Card context handle
DWORD _actProtocol = 0;




