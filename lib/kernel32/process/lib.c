/* $Id: lib.c,v 1.6 2000/04/14 01:49:18 ekohl Exp $
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS system libraries
 * FILE:            lib/kernel32/proc/proc.c
 * PURPOSE:         Process functions
 * PROGRAMMER:      Ariadne ( ariadne@xs4all.nl)
 * UPDATE HISTORY:
 *                  Created 01/11/98
 */

/* INCLUDES ****************************************************************/

#define UNICODE
#include <ddk/ntddk.h>
#include <windows.h>
#include <kernel32/proc.h>
#include <kernel32/thread.h>
#include <wchar.h>
#include <string.h>
#include <internal/i386/segment.h>
#include <internal/teb.h>

#include <kernel32/kernel32.h>

/* FUNCTIONS ****************************************************************/

#if 0
HINSTANCE
STDCALL
LoadLibraryW (
	LPCWSTR	lpLibFileName
	)
{
   UNIMPLEMENTED;
   return(NULL);
}
#endif




/* EOF */
