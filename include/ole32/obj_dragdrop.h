/*
 * Defines the COM interfaces and APIs related to OLE Drag and Drop.
 */

#ifndef __WINE_WINE_OBJ_DRAGDROP_H
#define __WINE_WINE_OBJ_DRAGDROP_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*****************************************************************************
 * Predeclare the interfaces
 */
DEFINE_OLEGUID(IID_IDropSource,	0x00000121L, 0, 0);
typedef struct IDropSource IDropSource,*LPDROPSOURCE;

DEFINE_OLEGUID(IID_IDropTarget,	0x00000122L, 0, 0);
typedef struct IDropTarget IDropTarget,*LPDROPTARGET;

/*****************************************************************************
 * DROPEFFECT enumeration
 */
#define MK_ALT (0x20)
#define	DROPEFFECT_NONE		0
#define	DROPEFFECT_COPY		1
#define	DROPEFFECT_MOVE		2
#define	DROPEFFECT_LINK		4
#define	DROPEFFECT_SCROLL	0x80000000
#define DD_DEFSCROLLINSET 11
#define DD_DEFSCROLLDELAY 50
#define DD_DEFSCROLLINTERVAL 50
#define DD_DEFDRAGDELAY   50
#define DD_DEFDRAGMINDIST  2

/*****************************************************************************
 * IDropSource interface
 */
#define ICOM_INTERFACE IDropSource
#define IDropSource_METHODS \
    ICOM_METHOD2(HRESULT, QueryContinueDrag, BOOL, fEscapePressed, DWORD, grfKeyState) \
    ICOM_METHOD1(HRESULT, GiveFeedback, DWORD, dwEffect)
#define IDropSource_IMETHODS \
	IUnknown_IMETHODS \
	IDropSource_METHODS
ICOM_DEFINE(IDropSource,IUnknown)
#undef ICOM_INTERFACE

/*** IUnknown methods ***/
#define IDropSource_QueryInterface(p,a,b) ICOM_CALL2(QueryInterface,p,a,b)
#define IDropSource_AddRef(p)             ICOM_CALL (AddRef,p)
#define IDropSource_Release(p)            ICOM_CALL (Release,p)
/*** IDropSource methods ***/
#define IDropSource_QueryContinueDrag(p,a,b) ICOM_CALL2(QueryContinueDrag,p,a,b)
#define IDropSource_GiveFeedback(p,a)        ICOM_CALL1(GiveFeedback,p,a)

/*****************************************************************************
 * IDropTarget interface
 */
#define ICOM_INTERFACE IDropTarget
#define IDropTarget_METHODS \
    ICOM_METHOD4(HRESULT, DragEnter, IDataObject*, pDataObject, DWORD, grfKeyState, POINTL, pt, DWORD*, pdwEffect) \
    ICOM_METHOD3(HRESULT, DragOver, DWORD, grfKeyState, POINTL, pt, DWORD*, pdwEffect) \
    ICOM_METHOD(HRESULT, DragLeave) \
    ICOM_METHOD4(HRESULT, Drop, IDataObject*, pDataObject, DWORD, grfKeyState, POINTL, pt, DWORD*, pdwEffect)
#define IDropTarget_IMETHODS \
	IUnknown_IMETHODS \
	IDropTarget_METHODS
ICOM_DEFINE(IDropTarget,IUnknown)
#undef ICOM_INTERFACE

/*** IUnknown methods ***/
#define IDropTarget_QueryInterface(p,a,b) ICOM_CALL2(QueryInterface,p,a,b)
#define IDropTarget_AddRef(p)             ICOM_CALL (AddRef,p)
#define IDropTarget_Release(p)            ICOM_CALL (Release,p)
/*** IDropTarget methods ***/
#define IDropTarget_DragEnter(p,a,b,c,d)  ICOM_CALL4(DragEnter,p,a,b,c,d)
#define IDropTarget_DragOver(p,a,b,c)     ICOM_CALL3(DragOver,p,a,b,c)
#define IDropTarget_DragLeave(p)          ICOM_CALL(DragLeave,p)
#define IDropTarget_Drop(p,a,b,c,d)       ICOM_CALL4(Drop,p,a,b,c,d)

#if _WIN32_IE >= 0x0500

#pragma pack(push,8)

typedef struct
{
	SIZE		sizeDragImage;
	POINT		ptOffset;
	HBITMAP 	hbmpDragImage;
	COLORREF	crColorKey;
} SHDRAGIMAGE, *LPSHDRAGIMAGE;

#pragma pack(pop)

#undef INTERFACE
#define INTERFACE IDragSourceHelper

DECLARE_INTERFACE_(IDragSourceHelper, IUnknown)
{
	STDMETHOD (QueryInterface)(THIS_ REFIID riid, void **ppv) PURE;
	STDMETHOD_(ULONG, AddRef) (THIS) PURE;
	STDMETHOD_(ULONG, Release) (THIS) PURE;
	STDMETHOD (InitializeFromBitmap)(THIS_ LPSHDRAGIMAGE pshdi, IDataObject* pDataObject) PURE;
	STDMETHOD (InitializeFromWindow)(THIS_ HWND hwnd, POINT* ppt, IDataObject* pDataObject) PURE;
};

DEFINE_GUID(CLSID_DragDropHelper, 0x4657278AL, 0x411B, 0x11D2, 0x83, 0x9A, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xD0);
DEFINE_GUID(IID_IDropTargetHelper, 0x4657278BL, 0x411B, 0x11D2, 0x83, 0x9A, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xD0);
DEFINE_GUID(IID_IDragSourceHelper, 0xDE5BF786L, 0x477A, 0x11D2, 0x83, 0x9D, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xD0);

#endif /* _WIN32_IE >= 0x0500 */

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /*  __WINE_WINE_OBJ_DRAGDROP_H */





