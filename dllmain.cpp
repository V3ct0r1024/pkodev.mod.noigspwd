#include <Windows.h>

#if defined MOD_SIDE_CLIENT
#include <detours.h>
#include <algorithm>
#include <string>
#endif

#include "loader.h"
#include "address.h"
#include "pointer.h"
#include "hook.h"
#include "structure.h"


// Patch Game.exe
#if defined MOD_SIDE_CLIENT
    unsigned int backup = 0;
    void do_game_patch(); 
    void undo_game_patch();
#endif

// Patch GameServer.exe
#if defined MOD_SIDE_SERVER 
    unsigned short int backup = 0;
    void do_gameserver_patch();
    void undo_gameserver_patch();
#endif

// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // Nothing to do . . .
    return TRUE;
}

// Get mod information
void GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void Start(const char* path)
{
    // Check that it is Game.exe
    #if defined MOD_SIDE_CLIENT

        // Patch Game.exe
        do_game_patch();

    #endif

    // Check that it is GameServer.exe
    #if defined MOD_SIDE_SERVER

        // Patch GameServer.exe
        do_gameserver_patch();

    #endif
}

// Stop the mod
void Stop()
{
    // Check that it is Game.exe
    #if defined MOD_SIDE_CLIENT

        // Remove Game.exe patch
        undo_game_patch();

    #endif

    // Check that it is GameServer.exe
    #if defined MOD_SIDE_SERVER

        // Remove GameServer.exe patch
        undo_gameserver_patch();

    #endif
}

// Patch Game.exe
#if defined MOD_SIDE_CLIENT

void do_game_patch()
{
    // Enable hooks
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::pointer::CMiniMapMgr___MiniFormMouseEvent, pkodev::hook::CMiniMapMgr___MiniFormMouseEvent);
    DetourTransactionCommit();
}

void undo_game_patch()
{
    // Disable hooks
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::pointer::CMiniMapMgr___MiniFormMouseEvent, pkodev::hook::CMiniMapMgr___MiniFormMouseEvent);
    DetourTransactionCommit();
}

// void CMiniMapMgr::_MiniFormMouseEvent(CCompent *pSender, int nMsgType, int x, int y, DWORD dwKey)
void __cdecl pkodev::hook::CMiniMapMgr___MiniFormMouseEvent(void* pSender, int nMsgType, int x, int y, DWORD dwKey)
{
    // Get pointer to the social button name
    const char* szName = reinterpret_cast<const char*>(reinterpret_cast<int>(pSender) + 0x14);

    // Check the pointer
    if (szName != nullptr)
    {
        // Convert const char * to std::string type
        std::string button{ szName };

        // Convert the button name to the lower case
        std::transform(button.begin(), button.end(), button.begin(), std::tolower);

        // Check that the button name is "btnOpenStore"
        if (button == "btnopenstore")
        {
            // Go to In-Game Mall (IGS)
            pkodev::pointer::CS_StoreOpenAsk("");

            // Exit form the hook
            return;
        }
    }

    // Call the original function CMiniMapMgr___MiniFormMouseEvent()
    pkodev::pointer::CMiniMapMgr___MiniFormMouseEvent(pSender, nMsgType, x, y, dwKey);
}

#endif

// Patch GameServer.exe
#if defined MOD_SIDE_SERVER

void do_gameserver_patch()
{
    // Access type
    DWORD access = PAGE_EXECUTE_READWRITE;

    // Change the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch),
        sizeof(backup), access, &access);

    // Backup old bytes
    backup = *reinterpret_cast<unsigned short int*>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch);

    // Write patch bytes
    *reinterpret_cast<unsigned short int*>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch) = 0x9090;

    // Rollback the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch),
        sizeof(backup), access, &access);
}

void undo_gameserver_patch()
{
    // Access type
    DWORD access = PAGE_EXECUTE_READWRITE;

    // Change the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch),
        sizeof(backup), access, &access);

    // Write old bytes
    *reinterpret_cast<unsigned short int*>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch) = backup;

    // Rollback the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CCharacter__ProcessPacket__Patch),
        sizeof(backup), access, &access);
}

#endif