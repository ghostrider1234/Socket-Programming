
/*
 *   Author : Divyesh Srivastava
 *   Organisation : Ekagga Technologies Service Pvt. Ltd.
 *   Institute : National Institute of Technology, Meghalaya
 *   Topic : Socket Programming, Server-Client Interaction
*/

                                         /*** Client Part ***/


                          // Code Goes Here

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 8080

int main( int argc, char **argv)
{
	int sock=0, value;

	struct sockaddr_in serv_addr;

	serv_addr.sin_family = AF_INET;

	serv_addr.sin_port = htons(PORT);

	char *hello = "Hello from client";

	char buffer[1024]={0};

	if((sock=(socket(AF_INET, SOCK_STREAM, 0)))<0)
	{
		perror("Socket error");
		exit(1);
	}

	if( inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		perror("Invalid address");
		exit(1);
	}

	if( connect( sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
	{
		perror("Connection failed");
		exit(1);
	}

	while(1)
	{
		printf("\t\t\tWelcome To time Zone\n");
		printf("1.) Date\n");
		printf("2.) Time\n");
		printf("3.) Exit\n");

		printf("Enter your choice : ");
		int choice;
		scanf("%d",&choice);

		char s[10];

		sprintf(s,"%d",choice);

		send(sock,s,strlen(s),0);

		value = read(sock,buffer,1024);

		printf("\n\t\t%s",buffer);

		if(choice==3)
			exit(1);

		printf("\n\n");

	}
	return 0;
}

                                                         // Code Ends Here 














































