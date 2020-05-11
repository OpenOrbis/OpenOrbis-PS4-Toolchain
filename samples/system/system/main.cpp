#include <stdio.h>
#include <string.h>
#include <orbis/UserService.h>

int main(void)
{
    int userID;
    char username[32];

    // Get the user ID
    OrbisUserServiceInitializeParams param;
    param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
    sceUserServiceInitialize(&param);
    sceUserServiceGetInitialUser(&userID);

    (void)memset(username, 0, sizeof(username));

    if (sceUserServiceGetUserName(userID, username, sizeof(username) - 1) < 0)
    {
        printf("[DEBUG] [ERROR] Failed to get username!\n");
        return -1;
    }

    printf("[DEBUG] Currently logged in user: %s (user ID: 0x%08x)\n", username, userID);
    for (;;) {}
}
