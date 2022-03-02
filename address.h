#pragma once

namespace pkodev
{
	namespace address
	{
        #if defined MOD_SIDE_SERVER

            // GameServer.exe 1.36
            namespace GAMESERVER_136
            {
                // void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk) patch
                // JNZ SHORT <address> -> NOP NOP
                // [75 13] -> [90 90]
                const unsigned int CCharacter__ProcessPacket__Patch = 0x004DF6D6;
            }

            // GameServer.exe 1.38
            namespace GAMESERVER_138
            {
                // void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk) patch
                // JNZ SHORT <address> -> NOP NOP
                // [75 13] -> [90 90]
                const unsigned int CCharacter__ProcessPacket__Patch = 0x004E7ECD;
            }

        #endif

        #if defined MOD_SIDE_CLIENT

            // Game.exe 0 (1222073761)
            namespace GAME_13X_0
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x00473BF0;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x00509C10;
            }

            // Game.exe 1 (1243412597)
            namespace GAME_13X_1
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x00473CB0;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x00509D20;
            }

            // Game.exe 2 (1252912474)
            namespace GAME_13X_2
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x00473D50;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x00509DF0;
            }

            // Game.exe 3 (1244511158)
            namespace GAME_13X_3
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x00473D40;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x00509DE0;
            }

            // Game.exe 4 (1585009030)
            namespace GAME_13X_4
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x00473EC0;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x0050A000;
            }

            // Game.exe 5 (1207214236)
            namespace GAME_13X_5
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
                const unsigned int CMiniMapMgr___MiniFormMouseEvent = 0x004738C0;

                // void CS_StoreOpenAsk(const char szPassword[])
                const unsigned int CS_StoreOpenAsk = 0x00509A80;
            }

        #endif
	}
}