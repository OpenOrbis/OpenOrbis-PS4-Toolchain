#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>
#include <orbis/UserService.h>
#include <orbis/NpTrophy.h>

// global variables
int32_t UserID = NULL;
int32_t NPContext = NULL;
int32_t NPHandle = NULL;
int32_t NPplat = NULL;

char* CreateMessage(const char* FMT, ...)
{
	char MessageBuf[1024];
	va_list args;
	va_start(args, FMT);
	vsprintf(MessageBuf, FMT, args);
	va_end(args);

	return MessageBuf;
}

int main()
{
	// No buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	int ret = sceUserServiceInitialize(NULL);
	if (ret != 0 && ret != 0x80960003)
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to Initialize for 0x%lx", ret));
		goto end;
	}

	// Get UserID 
	if ((ret = sceUserServiceGetInitialUser(&UserID)) != 0)
	{
		// Failed to get userID, goto end
		sceKernelDebugOutText(0, CreateMessage("Failed to get UserID for 0x%lx", ret));
		goto end;
	}

	if ((ret = sceSysmoduleLoadModule(ORBIS_SYSMODULE_NP_TROPHY)) != 0)
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to Load system trophy module for 0x%lx", ret));
		goto end;
	}

	if ((ret = sceNpTrophyCreateContext(&NPContext, UserID, 0, 0)) < 0)
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to create Trophy context for 0x%lx", ret));
		goto end;
	}

	if (((ret = sceNpTrophyCreateHandle(&NPHandle)) < 0))
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to create handle for 0x%lx", ret));
		goto end;
	}

	// if this fails, it will forcefully log-out the user
	if ((ret = sceNpTrophyRegisterContext(NPContext, NPHandle, 0)) < 0)
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to register context for 0x%lx", ret));
		goto end;

	}
	if ((ret = sceNpTrophyUnlockTrophy(NPContext, NPHandle, 1, &NPplat)) < 0)
	{
		sceKernelDebugOutText(0, CreateMessage("Failed to unlock trophy for 0x%lx", ret));
		goto end;
	}

	goto end;

end:
    for (;;);
    return 0;
}