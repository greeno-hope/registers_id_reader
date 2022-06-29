#pragma once

#include "framework.h"
#include "winscard.h"
#include "ct_api.h"

// Application state
typedef enum {
    NOT_CONFIGURED = 0,
    CONFIGURED,
    READER_CONNECTED,
    READER_POLLING,
    READER_NOT_POLLING,
    READER_DISCONNECTED,
    READER_TERMINATED
} SCARD_READER_STATE;

// Globals for the rooms list control (defined in globals.c)
extern WCHAR	*_roomsList[];
extern int		_selectedRoom;
extern int		_roomsListSize;

// Globals for the times list (also defiens in globals.c)
extern WCHAR    *_timesList[];
extern int      _selectedTime;
extern int      _timesListSize;

// Current Application state (configured, reading etc - also set in globals.c)
extern SCARD_READER_STATE _readerAppState;

// The HANDLEs that are convenient to have hanging arond
extern HINSTANCE _hInst;
extern HWND _hMainWindow;
extern HWND _hEditWindow;

// SCARD specific handles
extern SCARDCONTEXT _hScardContext; // Card context
extern SCARDHANDLE _hCard;          // Card context handle
extern DWORD _actProtocol;          // Protocol ID

// New custom messages
#define WM_NULL_POLL        WM_USER+1
#define WM_NEW_SID          WM_USER+2
#define WM_STATE_CHANGE     WM_USER+3


