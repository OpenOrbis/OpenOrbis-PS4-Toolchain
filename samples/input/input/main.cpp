#include <stdio.h>
#include <orbis/libkernel.h>
#include <orbis/Pad.h>
#include <orbis/UserService.h>

void printButtonsPressed(unsigned int buttons)
{
    printf("Pressed: ");

    if (buttons & PAD_BUTTON_TRIANGLE)   printf("Triangle ");
    if (buttons & PAD_BUTTON_CIRCLE)     printf("Circle ");
    if (buttons & PAD_BUTTON_X)          printf("X ");
    if (buttons & PAD_BUTTON_SQUARE)     printf("Square ");
    if (buttons & PAD_BUTTON_L1)         printf("L1 ");
    if (buttons & PAD_BUTTON_R1)         printf("R1 ");
    if (buttons & PAD_BUTTON_L2)         printf("L2 ");
    if (buttons & PAD_BUTTON_R2)         printf("R2 ");
    if (buttons & PAD_BUTTON_L3)         printf("L3 ");
    if (buttons & PAD_BUTTON_R3)         printf("R3 ");
    if (buttons & PAD_BUTTON_START)      printf("Start ");
    if (buttons & PAD_BUTTON_DPAD_UP)    printf("DPAD Up ");
    if (buttons & PAD_BUTTON_DPAD_RIGHT) printf("DPAD Right ");
    if (buttons & PAD_BUTTON_DPAD_DOWN)  printf("DPAD Down ");
    if (buttons & PAD_BUTTON_DPAD_LEFT)  printf("DPAD Left ");
    if (buttons & PAD_BUTTON_TOUCHPAD)   printf("Touch-Pad ");

    printf("\n");
}

int main(void)
{
    int userID;
    unsigned int curButtons = 0;
    unsigned int prevButtons = 0;
    OrbisPadData padData;

    // Initialize the Pad library
    if (scePadInit() != 0)
    {
        printf("[DEBUG] [ERROR] Failed to initialize pad library!\n");
        return -1;
    }

    // Get the user ID
    OrbisUserServiceInitializeParams param;
    param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
    sceUserServiceInitialize(&param);
    sceUserServiceGetInitialUser(&userID);

    // Open a handle for the controller
    int pad = scePadOpen(userID, 0, 0, NULL);

    if (pad < 0)
    {
        printf("[DEBUG] Failed to open pad!\n");
        return -1;
    }

    // Poll the controller state and print the buttons that are currently being pressed. Sleep every 0.05s
    // to lighten the CPU load.
    for (;;)
    {
        scePadReadState(pad, &padData);
        curButtons = padData.buttons;

        if (curButtons != prevButtons)
        {
            printButtonsPressed(curButtons);
            prevButtons = curButtons;
        }

        sceKernelUsleep(50000);
    }
}
