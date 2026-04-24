#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// IMPORTANT: change this to a unique number between 2000 and 30000.
// Every student running on the same machine needs a different port,
// otherwise the bind() in server.c will fail with "Address already in use".
#define PORT 12345

int main() {
    int socket_fd;

    // 1. Create a TCP socket (AF_INET = IPv4, SOCK_STREAM = TCP)
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    // 2. Configure the server address to connect to
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Connect to 127.0.0.1 (localhost)
    address.sin_port = htons(PORT);

    // 3. Connect to the server (server must already be running and listening)
    if (-1 == connect(socket_fd, (struct sockaddr *)&address, addrlen)) {
        perror("connect");
        close(socket_fd);
        return 1;
    }

    printf("Connected to server on port %d\n", PORT);

    // TODO: Complete the client by implementing steps 4-6 below.

    // 4. Use fdopen to wrap socket_fd in a C stdio FILE* for writing.

    // 5. In a loop, use fgets to read lines from stdin and send each to the
    //    server. Remember to flush after each send. Exit the loop when stdin
    //    is closed (Ctrl-D).

    // 6. Close the FILE* (this also closes socket_fd), then return 0.

    close(socket_fd);
    return 0;
}
