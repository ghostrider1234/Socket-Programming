/*
 * Author : Divyesh Srivastava
 * Organisation : Ekagga Technologies Service Pvt. Ltd.
 * Institute : National Institute of Technology, Meghalaya
 * Topic : Socket Programming, Server-Client Interaction Program
*/

                                                                       /*****  Server Part ***/


                   
                                          // Code Goes Here


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>
#define PORT 8080 




int main(int argc, char **argv)
{
	time_t now;

	time(&now);

	struct tm *local=localtime(&now);

	int hours = local->tm_hour;
	int minutes = local->tm_min;
	int seconds = local->tm_sec;

	int day   = local->tm_mday;
	int month = local->tm_mon+1;
	int year  = local->tm_year + 1990;

	char s1[10];
	char s2[10];
	char s3[10];
	char s4[10];
	char s5[]=":";
	char buf[20];
	sprintf(s1,"%d",hours);
	sprintf(s2,"%d",minutes);
	sprintf(s3,"%d",seconds);


	strcat(s1,s5);
	strcat(s1,s2);
	strcat(s1,s5);
	strcat(s1,s3);

	strcpy(buf,s1);

	char s11[10];
        char s21[10];
        char s31[10];
        char s41[10];
        char s51[]=":";
        char buff[20];
        sprintf(s11,"%d",day);
        sprintf(s21,"%d",month);
        sprintf(s31,"%d",year);


        strcat(s11,s51);
        strcat(s11,s21);
        strcat(s11,s51);
        strcat(s11,s31);

        strcpy(buff,s11);


	int sockfd, new_socket, value, opt=1;

	char buffer[8]={0};

	struct sockaddr_in address;

	int addrlen = sizeof(address);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if((sockfd=(socket(AF_INET, SOCK_STREAM, 0)))==0)
	{
		perror("Error in socket");
		exit(1);
	}

	if( bind ( sockfd, ( struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("Binding failed");
		exit(1);
	}

	if(listen(sockfd,3)<0)
	{
		perror("Error in listen");
		exit(1);
	}

	if( (new_socket = (accept ( sockfd, ( struct sockaddr *)&address, (socklen_t*)&addrlen)))<0)
	{
		perror("accept");
		exit(1);
	}

	while(1)
      {

	value = read( new_socket, buffer, 8);

	if(strcmp(buffer,"1")==0)
        {
		printf("You choosen time\n");
               
		 send(new_socket, buf, strlen(buf),0);
        }
		  
	else if(strcmp(buffer,"2")==0)
	{
		printf("You choosen date\n");

		send(new_socket, buff, strlen(buff),0);
        }

	else
	{
		printf("Bye");
		send(new_socket, "Thanks for connecting", strlen("Thanks for connecting"),0);

		 exit(1);
	}


      }
	return 0;
}

                                                                  // Code Ends Here













































