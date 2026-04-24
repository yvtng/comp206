#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// IMPORTANT: change this to a unique number between 2000 and 30000.
// Every student running on the same machine needs a different port,
// otherwise bind() below will fail with "Address already in use".
#define PORT 12345

int main() {
    int server_fd;

    // 1. Create a TCP socket (AF_INET = IPv4, SOCK_STREAM = TCP)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        return 1;
    }

    // Allow reusing the port quickly after the server exits
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    // 2. Configure the address: accept connections on any local network interface
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT);

    // 3. Bind: attach the socket to the port so the OS routes incoming
    //    connections on PORT to this process
    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
        perror("bind");
        close(server_fd);
        return 1;
    }

    // 4. Listen: mark the socket as passive (ready to accept connections).
    //    The second argument is the maximum number of pending connections.
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    // 5. Accept: block until a client connects, then return a *new* file
    //    descriptor (client_fd) for that specific connection.
    //    server_fd keeps listening; client_fd is used to talk to this client.
    int client_fd;
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
        perror("accept");
        close(server_fd);
        return 1;
    }

    printf("Client connected\n");

    // TODO: Complete the server by implementing steps 6-8 below.

    // 6. Use fdopen to wrap client_fd in a C stdio FILE* for reading.

    // 7. In a loop, use fgets to receive lines from the client and print each
    //    to stdout. Exit the loop when the client disconnects (i.e. when fgets fails)

    // 8. Close the client FILE* and server_fd, then return 0.

    return 0;
}
