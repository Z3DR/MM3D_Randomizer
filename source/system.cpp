#include "system.hpp"

CFG_Region systemRegion;
CFG_Language systemLanguage;

void SystemInfoInit(void) {
    cfguInit();
    CFGU_SecureInfoGetRegion((u8*)&systemRegion);
    CFGU_GetSystemLanguage((u8*)&systemLanguage);
    cfguExit();
}

CFG_Region SystemInfo_GetRegion(void) { return systemRegion; }
CFG_Language SystemInfo_GetLanguage(void) { return systemLanguage; }
