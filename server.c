#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    const int PORT = 8080;

    struct sockaddr_in address = {
        .sin_family = AF_INET, // IPv4
        .sin_addr.s_addr = INADDR_ANY, // Accept connections for any IP address
        .sin_port = htons(PORT) // Convert to network byte order
    };

    // Create socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // TODO: error handling  
    
    // Bind the socket to the pecified port
    int did_bind = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    // TODO: error handling  

    // Start listening for incoming connections
    listen(server_fd,3);
    // TODO: error handling  

    printf("Server is listening on port %d\n", PORT);

    // Accept incoming connection
    int socket = accept(server_fd, (struct sockaddr *)&address, &(socklen_t){sizeof(address)});
    // TODO: error handling  
    
    // TODO: Read request data...
    // int r = read(...);

    const char* response = "Hello, world!\n";
    
    // Send a response message to the client
    send(socket, response, strlen(response), 0);
    //TODO: error handling  

    // close socket
    close(socket);
    close(server_fd);
    
    return 0;
}
