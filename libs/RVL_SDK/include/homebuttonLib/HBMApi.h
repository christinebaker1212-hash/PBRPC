// Imported from doldecomp/ogws (CC0), include/homebuttonMiniLib/HBMApi.h
#ifndef HOME_BUTTON_LIB_API_H
#define HOME_BUTTON_LIB_API_H
#ifdef __cplusplus
extern "C" {
#endif

#include <homebuttonLib/HBMTypes.h>

void HBMCreate(const HBMDataInfo* pHBInfo);
void HBMInit();

HBMSelectBtnNum HBMCalc(const HBMControllerData* pController);
void HBMDraw();

HBMSelectBtnNum HBMGetSelectBtnNum();
void HBMSetAdjustFlag(BOOL flag);
void HBMStartBlackOut();
void HBMSetBlackOutColor(u8 r, u8 g, u8 b);
BOOL HBMIsReassignedControllers();

void HBMCreateSound(const char* pPath, void* pBuf, u32 size);
void HBMDeleteSound();
void HBMUpdateSound();

#ifdef __cplusplus
}
#endif
#endif
