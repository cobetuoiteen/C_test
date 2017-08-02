#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sock, length, n;
	struct sockaddr_in server, from;
	struct hostent *hp;
	char buff[1024];
	
	if (argc != 3)
	{
		fprintf(stderr, "ERROR, no port provided\n");
		exit(1);
	}
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
		error("Init socket 1 failed\n");
	
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if (hp == 0)
		error("Unknown host\n");

	bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
	
	server.sin_port = htons(atoi(argv[2]));
	length = sizeof(struct sockaddr_in);

	char* connect_mess = "Hello";
	n = sendto(sock, connect_mess, strlen(connect_mess), 0, (const struct sockaddr *)&server, length);
	if (n < 0)
		error("Send error\n");

	bzero(buff, 1024);
	n = recvfrom(sock, buff, 1024, 0, (struct sockaddr *)&from, &length);
	if (n < 0)
		error("Receive port error\n");
	
	write(1, "Receive port: ", 14);
	write(1, buff, n);
	write(1, "\n", 2);
	
	int new_port = atoi(buff);
	close(sock);
	


	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
                error("Init socket 2 failed\n");
	
	server.sin_port = htons(new_port);
	while (1)
	{
		printf("Enter message: ");
		fgets(buff, 1023, stdin);

		n = sendto(sock, buff, strlen(buff), 0, (const struct sockaddr *)&server, length);
		if (n < 0)
			error("Send message error\n");

		n = recvfrom(sock, buff, 1024, 0, (struct sockaddr *)&from, &length);
		if (n < 0)
			error("Receive sequence number error\n");

		write(1, "Got ACK sequence number: ", 25);
		write(1, buff, n);
		write(1, "\n", 2);

		if (strcmp(buff, "0") == 0)
		{
			write(1, "Exit\n", 6);
			close(sock);
			break;
		}
	}
	return 0;
}
