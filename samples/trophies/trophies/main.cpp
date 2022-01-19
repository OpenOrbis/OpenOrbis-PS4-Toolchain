#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>
#include <orbis/UserService.h>
#include <orbis/NpTrophy.h>

#include "util.h"

// global variables
int32_t UserID = NULL;
int32_t NPContext = NULL;
int32_t NPHandle = NULL;
int32_t NPplat = NULL;

int main()
{
	// No buffering
	setvbuf(stdout, NULL, _IONBF, 0);

	int ret = sceUserServiceInitialize(NULL);
	if (ret != 0 && ret != 0x80960003)
	{
		Notify("Failed to Initialize for 0x%lx", ret);
		goto end;
	}

	// Get UserID 
	if ((ret = sceUserServiceGetInitialUser(&UserID)) != 0)
	{
		// Failed to get userID, goto end
		Notify("Failed to get UserID for 0x%lx", ret);
		goto end;
	}

	if ((ret = sceSysmoduleLoadModule(ORBIS_SYSMODULE_NP_TROPHY)) != 0)
	{
		Notify("Failed to Load system trophy module for 0x%lx", ret);
		goto end;
	}

	if ((ret = sceNpTrophyCreateContext(&NPContext, UserID, 0, 0)) < 0)
	{
		Notify("Failed to create Trophy context for 0x%lx", ret);
		goto end;
	}

	if (((ret = sceNpTrophyCreateHandle(&NPHandle)) < 0))
	{
		Notify("Failed to create handle for 0x%lx", ret);
		goto end;
	}

	// if this fails, it will forcefully log-out the user
	if ((ret = sceNpTrophyRegisterContext(NPContext, NPHandle, 0)) < 0)
	{
		Notify("Failed to register context for 0x%lx", ret);
		goto end;

	}
	if ((ret = sceNpTrophyUnlockTrophy(NPContext, NPHandle, 1, &NPplat)) < 0)
	{
		Notify("Failed to unlock trophy for 0x%lx", ret);
		goto end;
	}

	goto end;

end:
    for (;;);
    return 0;
}