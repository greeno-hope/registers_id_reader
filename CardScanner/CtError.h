/**
 * @file
 * CtError.h
 * 
 * @brief
 * Header file for CtError.c
 *         
 * @par       
 * COPYRIGHT NOTICE: (c) 2022 Mark Greenwood - Liverpool Hope University .  All rights reserved.
 */

#pragma once

#include <winscard.h>

void show_scard_error(LONG err_code);