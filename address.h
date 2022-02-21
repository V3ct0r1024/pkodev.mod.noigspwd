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
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x00473D0A;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x00463660;
            }

            // Game.exe 1 (1243412597)
            namespace GAME_13X_1
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x00473DCA;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x004636A0;
            }

            // Game.exe 2 (1252912474)
            namespace GAME_13X_2
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x00473E6A;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x004636B0;
            }

            // Game.exe 3 (1244511158)
            namespace GAME_13X_3
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x00473E5A;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x004636A0;
            }

            // Game.exe 4 (1585009030)
            namespace GAME_13X_4
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x00473FDA;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x004637A0;
            }

            // Game.exe 5 (1207214236)
            namespace GAME_13X_5
            {
                // void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey) patch
                const unsigned int CMiniMapMgr___MiniFormMouseEvent__Patch = 0x004739DA;

                // void CDoublePwdMgr::SendPackageStoreOpen()
                const unsigned int CDoublePwdMgr__SendPackageStoreOpen = 0x00463300;
            }

        #endif
	}
}