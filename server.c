#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

//function compares strings, returns 0 if same, -1 otherwise
int compare_strings(char a[], char b[])
{
    int c = 0;
    while (a[c] == b[c]) 
    {
        if (a[c] == '\0' || b[c] == '\0')
        break;
        c++;
    }
    if (a[c] == '\0' && b[c] == '\0')
    return 0;
    else
    return -1;
}

int main() {
    //variable declarations: server and 3 clients
    int welcomeSocket, Client1, Client2, Client3;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    char buffer[1024];

    //parameters for server
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.01");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    //server is listening
    if (listen(welcomeSocket,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    //link the server and three clients
    addr_size = sizeof serverStorage;
    Client1 = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    Client2 = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    Client3 = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    int cmdEXIT = 0;
    recv(Client1, buffer, 1024, 0);
    //continue to send and receive messages until one of the clients enters "Exit"
    if(compare_strings(buffer, "conference talk Client2, Client3")==0 {
	while (cmdEXIT == 0) {
	    //clear buffer
	    memset(&buffer[0], 0, sizeof(buffer));
	    //get message from next source
            if(recv(Client1, buffer, 1024, 0)) {
                recv(Client1, buffer, 1024, 0);
                //send to client 2 and 3
                printf ("%s\nSent to Clients\n", buffer);
                send(Client2,buffer,1024,0);
                send(Client3,buffer,1024,0);
            }
            if(recv(Client2, buffer, 1024, 0)) {
                recv(Client2, buffer, 1024, 0);
                //send to client 1 and 3
                printf ("%s\nSent to Clients\n", buffer);
                send(Client1,buffer,1024,0);
                send(Client3,buffer,1024,0);
            }
            if(recv(Client3, buffer, 1024, 0)) {
                recv(Client3, buffer, 1024, 0);
                //send to client 1 and 2
                printf ("%s\nSent to Clients\n", buffer);
                send(Client1,buffer,1024,0);
                send(Client2,buffer,1024,0);
            }
	    //if command was "Exit"
            if (compare_strings(buffer, "Exit")==0)
            {
                cmdEXIT = 1;
            }
	}
    }
else if(compare_strings(buffer, "talk Client2")==0 {
    while (cmdEXIT == 0)
    {
recv(Client1, buffer, 1024, 0);
        //send to client 2
        printf ("%s\nSent to Client 2\n", buffer);
        send(Client2,buffer,1024,0);
        //exit if client 
        if (compare_strings(buffer, "Exit")==0)
        {   
            cmdEXIT = 1;
        }
        //sinon
        else 
        {
            //clear buffer
            memset(&buffer[0], 0, sizeof(buffer));
            //get message from client 2
            recv(Client2, buffer, 1024, 0);
            //send to client 1
            printf ("%s\nSent to Client 1\n", buffer);
            send(Client1,buffer,1024,0);
            //check if "Exit"
            if (compare_strings(buffer, "Exit")==0)
            {
                cmdEXIT = 1;
            }
        }
            //clear buffer
            memset(&buffer[0], 0, sizeof(buffer));
            //receive message from client 1
            recv(Client1, buffer, 1024, 0);
            //receive message from client 2
            recv(Client2, buffer, 1024, 0);
            //send back to client 1
            printf ("%s\nSending to Client 1\n", buffer);
            send(Client1,buffer,1024,0);
            //if Client 2 enters "Exit"
            if (compare_strings(buffer, "Exit")==0)
            {
                cmdEXIT = 1;
            }
        }
    }
else {
	printf("INVALID COMMAND. SERVER TERMINATING.");
	return -1;
}
    return 0;
}