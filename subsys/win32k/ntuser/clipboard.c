/*
 *  ReactOS W32 Subsystem
 *  Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003 ReactOS Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/*
 * COPYRIGHT:        See COPYING in the top level directory
 * PROJECT:          ReactOS kernel
 * PURPOSE:          Clipboard routines
 * FILE:             subsys/win32k/ntuser/clipboard.c
 * PROGRAMER:        Filip Navara <xnavara@volny.cz>
 */

#include <include/clipboard.h>
#define NDEBUG
#include <debug.h>

#if 0
PW32THREAD ClipboardThread;
HWND ClipboardWindow;
#endif

UINT FASTCALL
IntEnumClipboardFormats(UINT format)
{
   UNIMPLEMENTED;
   return 0;
}

BOOL STDCALL
NtUserOpenClipboard(HWND hWnd, DWORD Unknown1)
{
#if 0
   if (ClipboardThread && ClipboardThread != PsGetWin32Thread())
   {
      SetLastWin32Error(ERROR_LOCKED);
      return FALSE;
   }
   ClipboardWindow = hWnd;
   ClipboardThread = PsGetWin32Thread();
   return TRUE;
#else
   UNIMPLEMENTED
   return FALSE;
#endif
}

BOOL STDCALL
NtUserCloseClipboard(VOID)
{
#if 0
   if (ClipboardThread && ClipboardThread != PsGetWin32Thread())
   {
      SetLastWin32Error(ERROR_LOCKED);
      return FALSE;
   }
   ClipboardWindow = 0;
   ClipboardThread = NULL;
   return TRUE;
#else
   UNIMPLEMENTED
   return FALSE;
#endif
}

/*
 * @unimplemented
 */
HWND STDCALL
NtUserGetOpenClipboardWindow(VOID)
{
   UNIMPLEMENTED
   return 0;
}

BOOL STDCALL
NtUserChangeClipboardChain(HWND hWndRemove, HWND hWndNewNext)
{
   UNIMPLEMENTED
   return 0;
}

DWORD STDCALL
NtUserCountClipboardFormats(VOID)
{
   UNIMPLEMENTED
   return 0;
}

DWORD STDCALL
NtUserEmptyClipboard(VOID)
{
   UNIMPLEMENTED
   return 0;
}

HANDLE STDCALL
NtUserGetClipboardData(UINT uFormat, DWORD Unknown1)
{
   UNIMPLEMENTED
   return 0;
}

INT STDCALL
NtUserGetClipboardFormatName(UINT format, PUNICODE_STRING FormatName,
   INT cchMaxCount)
{
   UNIMPLEMENTED
   return 0;
}

HWND STDCALL
NtUserGetClipboardOwner(VOID)
{
   UNIMPLEMENTED
   return 0;
}

DWORD STDCALL
NtUserGetClipboardSequenceNumber(VOID)
{
   UNIMPLEMENTED
   return 0;
}

HWND STDCALL
NtUserGetClipboardViewer(VOID)
{
   UNIMPLEMENTED
   return 0;
}

INT STDCALL
NtUserGetPriorityClipboardFormat(UINT *paFormatPriorityList, INT cFormats)
{
   UNIMPLEMENTED
   return 0;
}

WINBOOL STDCALL
NtUserIsClipboardFormatAvailable(UINT format)
{
   UNIMPLEMENTED
   return 0;
}

HANDLE STDCALL
NtUserSetClipboardData(UINT uFormat, HANDLE hMem, DWORD Unknown2)
{
   UNIMPLEMENTED
   return 0;
}

HWND STDCALL
NtUserSetClipboardViewer(HWND hWndNewViewer)
{
   UNIMPLEMENTED
   return 0;
}

/* EOF */
