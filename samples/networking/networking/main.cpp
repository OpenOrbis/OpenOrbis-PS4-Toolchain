#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <orbis/libkernel.h>
#include <orbis/Pad.h>
#include <orbis/UserService.h>

#define IP "192.168.0.10"
#define PORT 9030

void waitOnButton(int pad, unsigned int button)
{
	OrbisPadData padData;
	
	for(;;)
	{
		scePadReadState(pad, &padData);
		
		if(padData.buttons & button) {
			return;
		}
	}
}	

int main(void)
{
    int userID;
    const char *msg = "ping";
    struct sockaddr_in addr;

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
    
    // Setup the socket
    (void)memset(&addr, 0, sizeof(struct sockaddr_in));

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    
    // Wait on X
    waitOnButton(pad, ORBIS_PAD_BUTTON_CROSS);

    if (inet_pton(AF_INET, IP, &addr.sin_addr) <= 0)
    {
        printf("[DEBUG] [ERROR] IP Address not supported.\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("[DEBUG] [ERROR] Failed to connect to %s:%d.\n", IP, PORT);
        return -1;
    }

    printf("[DEBUG] Sending message to %s:%d.\n", IP, PORT);
    send(sock, msg, strlen(msg), 0);
    printf("[DEBUG] Message sent. Closing and infinitely looping.\n");

    close(sock);
    for (;;) {}
}
