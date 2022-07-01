/**
 * @file
 * AboutDialog.h
 * 
 * @brief
 * Declaration of the Windows callback function for the 'About' (help) dialog.
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2022 Mark Greenwood - Liverpool Hope University .  All rights reserved.
 */

#pragma once

#include "framework.h"

// Message handler for about box.
INT_PTR CALLBACK AboutDialogCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);