#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

//function compares strings, returns 0 if same, -1 if different

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
    //variable declaration
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    int cmdEXIT = 0;

    //create client socket
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    addr_size = sizeof serverAddr;

    //connect to server
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    //print message for client one
    printf("Server: Enter Your Name. ");
    scanf(" %[^\n]s", buffer);
    send(clientSocket,buffer,sizeof buffer - 1,0);      

    //send and recieve messages until a client sends 'Exit'
    while (cmdEXIT == 0)
    {
        //check if 'Exit' was sent
        if (compare_strings(buffer, "Exit")==-1)
        {
            //empty the buffer
            memset(&buffer[0], 0, sizeof(buffer));
            //value of recv=1 if message has not been received
            //number of bits received otherwise
            int recvValue = recv(clientSocket, buffer, sizeof buffer - 1, 0);
            //check if recv not equal to 1 (message has been received)
            if (recvValue != 1)
            {
                //check if client requests conference call
		if (compare_strings(buffer, "conference talk Client2, Client3")==0) {
		    while (cmdEXIT == 0)
		    {
		        recv(clientSocket, buffer, sizeof buffer - 1, 0);
		        if (compare_strings(buffer, "Exit")==-1)
        		{
			    printf("New Message: ");
        		    printf("%s\n", buffer);
		            memset(&buffer[0], 0, sizeof(buffer));
		            printf("Message Send: ");
	        	    scanf(" %[^\n]s", buffer);
		            send(clientSocket,buffer,sizeof buffer - 1,0);
		            if (compare_strings(buffer, "Exit")==-1)
		            {
		                memset(&buffer[0], 0, sizeof(buffer));
		            }
        		    else cmdEXIT = 1;
		        }
	        else cmdEXIT = 1;
	    }
		}
                //check if content is not "Exit"
                else if (compare_strings(buffer, "Exit")==-1)
                {
                    //display message from Client 2
                    printf("Client 2: ");
                    printf("%s\n", buffer);
                    //empty buffer
                    memset(&buffer[0], 0, sizeof(buffer));
                }
                //if Client 2 sends "Exit"
                else cmdEXIT=1;
            }
            //if recv=1: no message received
            else
            {
                //Client 1 can enter message
                printf("Client 1: ");
                scanf(" %[^\n]s", buffer);
                //send message to Client 2
                send(clientSocket,buffer,sizeof buffer - 1,0);
            }
        }
        //finish loop otherwise
        else cmdEXIT=1;
    }

    return 0;
}