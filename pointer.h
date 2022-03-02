#pragma once
#include "address.h"
#include "structure.h"

namespace pkodev
{
	namespace pointer
	{
#if defined MOD_SIDE_CLIENT
		// void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
		typedef void(__cdecl* CMiniMapMgr___MiniFormMouseEvent__Ptr)(void*, int, int, int, DWORD);
		CMiniMapMgr___MiniFormMouseEvent__Ptr CMiniMapMgr___MiniFormMouseEvent = (CMiniMapMgr___MiniFormMouseEvent__Ptr)(void*)(pkodev::address::MOD_EXE_VERSION::CMiniMapMgr___MiniFormMouseEvent);

		// void CS_StoreOpenAsk(const char szPassword[])
		typedef void(__cdecl* CS_StoreOpenAsk__Ptr)(const char *);
		CS_StoreOpenAsk__Ptr CS_StoreOpenAsk = (CS_StoreOpenAsk__Ptr)(void*)(pkodev::address::MOD_EXE_VERSION::CS_StoreOpenAsk);
#endif
	}
}