#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IP "192.168.0.10"
#define PORT 9030

int main(void)
{
    const char *msg = "ping";
    struct sockaddr_in addr;

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    (void)memset(&addr, 0, sizeof(struct sockaddr_in));

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, IP, &addr.sin_addr) <= 0)
    {
        printf("[DEBUG] [ERROR] IP Address not supported.\n");
        for (;;);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("[DEBUG] [ERROR] Failed to connect to %s:%d.\n", IP, PORT);
        for (;;);
    }

    printf("[DEBUG] Sending message to %s:%d.\n", IP, PORT);
    send(sock, msg, strlen(msg), 0);
    printf("[DEBUG] Message sent. Closing and infinitely looping.\n");

    close(sock);
    for (;;);
}
