/* $Id$
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            ntoskrnl/ke/mutex.c
 * PURPOSE:         Implements mutex
 * 
 * PROGRAMMERS:     David Welch (welch@mcmail.com)
 */

/* INCLUDES *****************************************************************/

#include <ntoskrnl.h>
#include <internal/debug.h>

/* FUNCTIONS *****************************************************************/

/*
 * @implemented
 */
VOID STDCALL
KeInitializeMutex(IN PKMUTEX Mutex,
		  IN ULONG Level)
{
  KeInitializeDispatcherHeader(&Mutex->Header,
			       InternalMutexType,
			       sizeof(KMUTEX) / sizeof(ULONG),
			       1);
  Mutex->MutantListEntry.Flink = NULL;
  Mutex->MutantListEntry.Blink = NULL;
  Mutex->OwnerThread = NULL;
  Mutex->Abandoned = FALSE;
  Mutex->ApcDisable = 1;
}

/*
 * @implemented
 */
LONG STDCALL
KeReadStateMutex(IN PKMUTEX Mutex)
{
  return(Mutex->Header.SignalState);
}

/*
 * @implemented
 */
LONG STDCALL
KeReleaseMutex(IN PKMUTEX Mutex,
	       IN BOOLEAN Wait)
{
  KIRQL OldIrql;

  OldIrql = KeAcquireDispatcherDatabaseLock();
  if (Mutex->OwnerThread != KeGetCurrentThread())
    {
      DbgPrint("THREAD_NOT_MUTEX_OWNER: Mutex %p\n", Mutex);
      KEBUGCHECK(THREAD_NOT_MUTEX_OWNER);
    }
  Mutex->Header.SignalState++;
  ASSERT(Mutex->Header.SignalState <= 1);
  if (Mutex->Header.SignalState == 1)
    {
      Mutex->OwnerThread = NULL;
      if (Mutex->MutantListEntry.Flink && Mutex->MutantListEntry.Blink)
	RemoveEntryList(&Mutex->MutantListEntry);
      KiDispatcherObjectWake(&Mutex->Header, IO_NO_INCREMENT);
    }

  if (Wait == FALSE)
    {
      KeReleaseDispatcherDatabaseLock(OldIrql);
    }
  else
    {
      KTHREAD *Thread = KeGetCurrentThread();
      Thread->WaitNext = TRUE;
      Thread->WaitIrql = OldIrql;
    }

  return(0);
}

/*
 * @implemented
 */
NTSTATUS STDCALL
KeWaitForMutexObject(IN PKMUTEX Mutex,
		     IN KWAIT_REASON WaitReason,
		     IN KPROCESSOR_MODE WaitMode,
		     IN BOOLEAN Alertable,
		     IN PLARGE_INTEGER Timeout)
{
  return(KeWaitForSingleObject(Mutex,WaitReason,WaitMode,Alertable,Timeout));
}


/*
 * @implemented
 */
VOID STDCALL
KeInitializeMutant(IN PKMUTANT Mutant,
		   IN BOOLEAN InitialOwner)
{
  if (InitialOwner == TRUE)
    {
      KeInitializeDispatcherHeader(&Mutant->Header,
				   InternalMutexType,
				   sizeof(KMUTANT) / sizeof(ULONG),
				   0);
      InsertTailList(&KeGetCurrentThread()->MutantListHead,
		     &Mutant->MutantListEntry);
      Mutant->OwnerThread = KeGetCurrentThread();
    }
  else
    {
      KeInitializeDispatcherHeader(&Mutant->Header,
				   InternalMutexType,
				   sizeof(KMUTANT) / sizeof(ULONG),
				   1);
      Mutant->MutantListEntry.Flink = NULL;
      Mutant->MutantListEntry.Blink = NULL;
      Mutant->OwnerThread = NULL;
    }
  Mutant->Abandoned = FALSE;
  Mutant->ApcDisable = 0;
}

/*
 * @implemented
 */
LONG STDCALL
KeReadStateMutant(IN PKMUTANT Mutant)
{
  return(Mutant->Header.SignalState);
}

/*
 * @implemented
 */
LONG STDCALL
KeReleaseMutant(IN PKMUTANT Mutant,
		IN KPRIORITY Increment,
		IN BOOLEAN Abandon,
		IN BOOLEAN Wait)
{
  KIRQL OldIrql;

  OldIrql = KeAcquireDispatcherDatabaseLock();
  if (Abandon == FALSE)
    {
      if (Mutant->OwnerThread != NULL && Mutant->OwnerThread != KeGetCurrentThread())
	{
	  DbgPrint("THREAD_NOT_MUTEX_OWNER: Mutant->OwnerThread %p CurrentThread %p\n",
		   Mutant->OwnerThread,
		   KeGetCurrentThread());
	  KEBUGCHECK(THREAD_NOT_MUTEX_OWNER);
	}
      Mutant->Header.SignalState++;
      ASSERT(Mutant->Header.SignalState <= 1);
    }
  else
    {
      if (Mutant->OwnerThread != NULL)
	{
	  Mutant->Header.SignalState = 1;
	  Mutant->Abandoned = TRUE;
	}
    }

  if (Mutant->Header.SignalState == 1)
    {
      Mutant->OwnerThread = NULL;
      if (Mutant->MutantListEntry.Flink && Mutant->MutantListEntry.Blink)
	RemoveEntryList(&Mutant->MutantListEntry);
      KiDispatcherObjectWake(&Mutant->Header, Increment);
    }

  if (Wait == FALSE)
    {
      KeReleaseDispatcherDatabaseLock(OldIrql);
    }
  else
    {
      KTHREAD *Thread = KeGetCurrentThread();
      Thread->WaitNext = TRUE;
      Thread->WaitIrql = OldIrql;
    }

  return(0);
}

/* EOF */
