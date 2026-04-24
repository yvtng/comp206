#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

//  pick a random number between 2000 and 30000
#define PORT 24818

int main() {
    int server_fd;

    // 1. Create socket
    //
    //  like a power socket, 
    //  tells us about cultural cirucmstance when terms were created
    //  
    //  fd here stands for file descriptor
    //  this integer is the 3rd type of file descriptor,
    //  (stdin=0, stdout=1, stderr=2, fd #3 is called when we open socket
    //  ) 
    //  (                type of socket            )
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return 1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // 2. Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT);
    //  htons
    //  host to network short
    //
    //  converts port number, which is a 2 byte int fro the host
    //  because computer store the byte orders backwards and internet stores it hwo humans read it
    //  this is just because they made it this way
    //  network ordering??
    //
    //  converts from little ndn to big ndn so order of bytes is correct
    //  all calls are requests to linux kernel, to os, not library
    //

    // 3. Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return 1;
    }

    // 4. Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    // 5. Accept client
    // TODO
    //
    int client_fd;
    //  assinment is an expression
    if(client_fd=accept(server_fd, (struct socksddr*)&address, sizeof(address))<0){

    }
            

    printf("Client connected\n");

    // 6. Switch file descriptor to stdio FILE*
    // TODO

    // 7. Receive and echo loop
    // TODO

    // 8. Cleanup
    // TODO

    return 0;
}
