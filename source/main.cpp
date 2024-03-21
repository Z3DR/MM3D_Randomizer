#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <3ds.h>

#include "menu.hpp"
#include "hint_list.hpp"
#include "item_list.hpp"
#include "item_location.hpp"
#include "location_access.hpp"
#include "custom_messages.hpp"
#include "system.hpp"


#define TICKS_PER_SEC 268123480.0

int main() {
    gfxInitDefault();
    // Register graphics to quit at exit. New to libctru update.
    atexit(gfxExit);
    HintTable_Init();
    ItemTable_Init();
    LocationTable_Init();
    MenuInit();
    SystemInfoInit();

    /*CustomMessages::CreateMessage(0x0224, 0x8000, 0x3FFFFFFF, 0xFF0000,
        "This is a test scrolling #custom message# with #multiple# #colours#, %d%e%l%a%y%s, and icons $ $ $^Let's also test filename:&#@#",
        { QM_GREEN, QM_MAGENTA, QM_CYAN, QM_RED }, { ZL_BUTTON, MAJORA_ICON, ZR_BUTTON }, { 5, 10, 15, 20, 25, 30 },
        0x0000, false, false
    );
    CustomMessages::CreateMessage(0x8000, 0xFFFF, 0x3FFFFFFF, 0xFF0000,
        "This is a test instant #custom message# with #multiple# #colours#, %d%e%l%a%y%s, and icons $ $ $^Let's also test filename:&#@#",
        { QM_GREEN, QM_MAGENTA, QM_CYAN, QM_RED }, { ZL_BUTTON, MAJORA_ICON, ZR_BUTTON }, { 5, 10, 15, 20, 25, 30 },
        0x0000, true, false
    );*/

    CustomMessages::CreateBaselineCustomMessages();

    u64 initialHoldTime = svcGetSystemTick();
    u64 intervalTime = initialHoldTime;
    while (aptMainLoop()) {

        hidScanInput();
        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        if (kDown & KEY_SELECT) break; //stop the app

        //Time calculations for menu scrolling
        if (kHeld & KEY_DDOWN || kHeld & KEY_DUP || kHeld & KEY_DLEFT || kHeld & KEY_DRIGHT) {
            float totalHoldTime = (svcGetSystemTick() - initialHoldTime) / TICKS_PER_SEC;
            float intervalElapsedTime = (svcGetSystemTick() - intervalTime) / TICKS_PER_SEC;

            if (intervalElapsedTime > 0.09 && totalHoldTime > 0.4) {
                kDown |= kHeld & (KEY_DUP | KEY_DDOWN | KEY_DLEFT | KEY_DRIGHT); //add input to kDown for simplicity
                intervalTime = svcGetSystemTick();
            }
        }
        else {
            initialHoldTime = svcGetSystemTick();
        }

        //send inputs off to the menu
        if (kDown)
            MenuUpdate(kDown);

        //launch MM3d directly by holding L and R (cartridge only)
        if (kHeld & KEY_L && kHeld & KEY_R) {
            aptSetChainloader(0x0004000000125500, 2);
            break;
        }

        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        //Wait for VBlank
        gspWaitForVBlank();
    }
    
    return 0;
}
