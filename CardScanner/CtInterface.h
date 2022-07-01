/**
 * @file
 * CtInterface.h
 * 
 * @brief
 * Header file for CtInterface.h
 *         
 * @par       
 * COPYRIGHT NOTICE: (c) 2022 Mark Greenwood - Liverpool Hope University .  All rights reserved.
 */

#pragma once

#include "ct_api.h"

// CT interface functions
LONG _ct_get_context(SCARDCONTEXT* hContext);
LONG _ct_get_reader_list(SCARDCONTEXT hContext, WCHAR** reader_list);
LONG _ct_scard_connect(SCARDCONTEXT hContext, SCARDHANDLE* hCard, DWORD* dwActProtocol);
LONG _ct_scard_disconnect(SCARDHANDLE hCard);

// Polling thread function
void _ct_poll();