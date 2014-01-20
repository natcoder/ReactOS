/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS System Libraries
 * FILE:            dll/ntdll/include/ntdll.h
 * PURPOSE:         Native Libary Header
 * PROGRAMMER:      Alex Ionescu (alex@relsoft.net)
 */

/* INCLUDES ******************************************************************/

/* We're a core NT DLL, we don't import syscalls */
#define _NTSYSTEM_
#define _NTDLLBUILD_

/* C Headers */
#define _CTYPE_DISABLE_MACROS
#define _CRT_SECURE_NO_DEPRECATE
#define _INC_SWPRINTF_INL_
#include <stdio.h>

/* SDK/DDK/NDK Headers. */
#define WIN32_NO_STATUS
#include <windef.h>
#include <winbase.h>
#include <winreg.h>
#include <winuser.h>
#define NTOS_MODE_USER
#include <ndk/cmfuncs.h>
#include <ndk/exfuncs.h>
#include <ndk/iofuncs.h>
#include <ndk/kdtypes.h>
#include <ndk/kefuncs.h>
#include <ndk/ldrfuncs.h>
#include <ndk/mmfuncs.h>
#include <ndk/obfuncs.h>
#include <ndk/psfuncs.h>
#include <ndk/rtlfuncs.h>
#include <ndk/umfuncs.h>

/* Internal NTDLL */
#include "ntdllp.h"

/* CSRSS Headers */
#include <csr/csr.h>

/* PSEH */
#include <pseh/pseh2.h>

/* EOF */
