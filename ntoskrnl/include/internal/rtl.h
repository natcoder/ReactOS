#ifndef __NTOSKRNL_INCLUDE_INTERNAL_NLS_H
#define __NTOSKRNL_INCLUDE_INTERNAL_NLS_H

extern PSECTION_OBJECT NlsSectionObject;

extern ULONG NlsAnsiTableOffset;
extern ULONG NlsOemTableOffset;
extern ULONG NlsUnicodeTableOffset;

extern PUSHORT NlsUnicodeUpcaseTable;
extern PUSHORT NlsUnicodeLowercaseTable;

VOID
STDCALL
RtlpInitNls(VOID);

VOID
NTAPI
RtlpImportAnsiCodePage(
    PUSHORT TableBase,
    ULONG Size
);

VOID
NTAPI
RtlpImportOemCodePage(
    PUSHORT TableBase,
    ULONG Size
);

VOID
NTAPI
RtlpImportUnicodeCasemap(
    PUSHORT TableBase,
    ULONG Size
);

VOID
NTAPI
RtlpCreateInitialNlsTables(VOID);

VOID
NTAPI
RtlpCreateNlsSection(VOID);

NTSTATUS
NTAPI
RtlQueryAtomListInAtomTable(
    IN PRTL_ATOM_TABLE AtomTable,
    IN ULONG MaxAtomCount,
    OUT ULONG *AtomCount,
    OUT RTL_ATOM *AtomList
);

#endif /* __NTOSKRNL_INCLUDE_INTERNAL_NLS_H */

/* EOF */
