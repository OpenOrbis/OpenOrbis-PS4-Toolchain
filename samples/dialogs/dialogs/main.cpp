#include <sstream>
#include <iostream>
#include <orbis/libkernel.h>

#include "../../_common/log.h"

// Logging
std::stringstream debugLogStream;

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#include <orbis/CommonDialog.h>
#include <orbis/MsgDialog.h>

#define MDIALOG_OK		0
#define MDIALOG_YESNO	1


static inline void _orbisCommonDialogSetMagicNumber(uint32_t* magic, const OrbisCommonDialogBaseParam* param)
{
    *magic = (uint32_t)(ORBIS_COMMON_DIALOG_MAGIC_NUMBER + (uint64_t)param);
}

static inline void _orbisCommonDialogBaseParamInit(OrbisCommonDialogBaseParam *param)
{
    memset(param, 0x0, sizeof(OrbisCommonDialogBaseParam));
    param->size = (uint32_t)sizeof(OrbisCommonDialogBaseParam);
    _orbisCommonDialogSetMagicNumber(&(param->magic), param);
}

static inline void orbisMsgDialogParamInitialize(OrbisMsgDialogParam *param)
{
    memset(param, 0x0, sizeof(OrbisMsgDialogParam));
    _orbisCommonDialogBaseParamInit(&param->baseParam);
    param->size = sizeof(OrbisMsgDialogParam);
}

int show_dialog(int tdialog, const char * format, ...)
{
    OrbisMsgDialogParam param;
    OrbisMsgDialogUserMessageParam userMsgParam;
    OrbisMsgDialogResult result;
    char str[0x800];
    va_list	opt;

    memset(str, 0, sizeof(str));
    va_start(opt, format);
    vsprintf(str, format, opt);
    va_end(opt);

    sceMsgDialogInitialize();
    orbisMsgDialogParamInitialize(&param);
    param.mode = ORBIS_MSG_DIALOG_MODE_USER_MSG;

    memset(&userMsgParam, 0, sizeof(userMsgParam));
    userMsgParam.msg = str;
    userMsgParam.buttonType = (tdialog ? ORBIS_MSG_DIALOG_BUTTON_TYPE_YESNO_FOCUS_NO : ORBIS_MSG_DIALOG_BUTTON_TYPE_OK);
    param.userMsgParam = &userMsgParam;

    if (sceMsgDialogOpen(&param) < 0)
        return 0;

    do { } while (sceMsgDialogUpdateStatus() != ORBIS_COMMON_DIALOG_STATUS_FINISHED);
    sceMsgDialogClose();

    memset(&result, 0, sizeof(result));
    sceMsgDialogGetResult(&result);
    sceMsgDialogTerminate();

    return (result.buttonId == ORBIS_MSG_DIALOG_BUTTON_ID_YES);
}

void init_progress_bar(const char* msg)
{
    OrbisMsgDialogParam param;
    OrbisMsgDialogProgressBarParam userBarParam;

    sceMsgDialogInitialize();
    orbisMsgDialogParamInitialize(&param);
    param.mode = ORBIS_MSG_DIALOG_MODE_PROGRESS_BAR;

    memset(&userBarParam, 0, sizeof(userBarParam));
    userBarParam.msg = msg;
    userBarParam.barType = ORBIS_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE;
    param.progBarParam = &userBarParam;

    if (sceMsgDialogOpen(&param) < 0)
        return;

}

void end_progress_bar(void)
{
    sceMsgDialogClose();
    sceMsgDialogTerminate();
}

void update_progress_bar(uint64_t progress, const uint64_t total_size, const char* msg)
{
    float bar_value = (100.0f * ((double) progress)) / ((double) total_size);

    if (sceMsgDialogUpdateStatus() == ORBIS_COMMON_DIALOG_STATUS_RUNNING)
    {
        sceMsgDialogProgressBarSetMsg(0, msg);
        sceMsgDialogProgressBarSetValue(0, (uint32_t) bar_value);
    }

}

int main(void)
{
    int sleepSeconds = 2;
    
    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    
//    DEBUGLOG << "Hello world! Waiting " << sleepSeconds << " seconds!";
//    sceKernelUsleep(2 * 1000000);
//    DEBUGLOG << "Done. Infinitely looping...";

    if (sceCommonDialogInitialize() < 0)
	{
		printf("Failed to init CommonDialog!");
		return (-1);
	}

    if (show_dialog(MDIALOG_YESNO, "Do you like %s?", "OpenOrbis"))
    {
        init_progress_bar("User likes OpenOrbis :)");
        for (int i=0; i <= 1000; i++)
            update_progress_bar(i, 1000, "Loading...");
    }
    else
    {
        init_progress_bar("User doesn't like OpenOrbis :(");
        for (int i=1000; i >= 0; i--)
            update_progress_bar(i, 1000, "Unloading...");
    }

    end_progress_bar();

    for (;;) {}
}
