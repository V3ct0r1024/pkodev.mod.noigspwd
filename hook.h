#pragma once
#include "structure.h"

namespace pkodev
{
	namespace hook
	{
#if defined MOD_SIDE_CLIENT
		// void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
		void __cdecl CMiniMapMgr___MiniFormMouseEvent(void* pSender, int nMsgType, int x, int y, DWORD dwKey);
#endif
	}
}