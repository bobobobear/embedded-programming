#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

void error(char *m) {
    perror(m);
}

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    if (argc < 3) error("usage client [hostname] [port]\n");
    port = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if ((server == NULL)) error("ERROR, no such host\n");
    // start with a clean address structure
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    // internet socket
    serv_addr.sin_family = AF_INET;
    // copy address
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (const struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    error("ERROR connecting");

    printf("Please enter the number: ");
    fgets(buffer, 255, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("Error writing to socket");

    n = read(sockfd, buffer, 255);
    if (n < 0) error("Error reading from socket");
    
    printf("%s\n", buffer);
    return 0;
}