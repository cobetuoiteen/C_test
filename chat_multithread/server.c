#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <pthread.h>


struct to_thread {
	int port;
	int id;
};

void error(char *msg)
{
	perror(msg);
	exit(1);
}

void *connect_thread(void *var)
{
	int port, id;
	struct to_thread *t_var = var;
	
	port = t_var -> port;
	id = t_var -> id;

	int soc, len, n;
	socklen_t fromlen;
	struct sockaddr_in t_server, t_from;
	char t_buff[1024];
	char temp[10];
	int num = 1;
	
	soc = socket(AF_INET, SOCK_DGRAM, 0);
	if (soc < 0)
		error("Thread socket already in use\n");
	
	len = sizeof(t_server);
	bzero(&t_server, len);
	
	t_server.sin_family = AF_INET;
        t_server.sin_addr.s_addr = INADDR_ANY;
        t_server.sin_port = htons(port);

	if (bind(soc, (struct sockaddr *)&t_server, len) < 0)
		error("Thead bind() failed\n");

	fromlen = sizeof(struct sockaddr_in);
	
	while (1) {
		n = recvfrom(soc, t_buff, 1024, 0, (struct sockaddr *)&t_from, &fromlen);
		if (n < 0)
			error("Thread receive error\n");

		char m_temp[1024];
		bzero(&m_temp, 1024);
		snprintf(m_temp, sizeof(m_temp), "Thread %d receive message: ", id);
		write(1, m_temp, sizeof(m_temp));
		write(1, t_buff, n);
		
		bzero(&temp, 10);
		
		if (t_buff[0] == '#')
		{
	                snprintf(temp, 10, "%d", 0);
			n = sendto(soc, temp, 10, 0, (struct sockaddr *)&t_from, fromlen);
	                if (n < 0)
        	                error("Thead send fail\n");

			char m_temp[1024];
			bzero(&m_temp, 1024);
			snprintf(m_temp, sizeof(m_temp), "Stop connection thread %d\n", id);
			write(1, m_temp, sizeof(m_temp));
			sleep(2);
			close(soc);
			break;
		}
		else
		{
			snprintf(temp, 10, "%d", num);
        	        n = sendto(soc, temp, 10, 0, (struct sockaddr *)&t_from, fromlen);
	                if (n < 0)
                	        error("Thead send fail\n");
		}
		num++;
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	int sock, length, n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	struct to_thread t_var;
	char buff[1024];
	char temp[10];
	
	if (argc < 2) {
		fprintf(stderr, "ERROR, no port provided\n");
		exit(0);
	}

	int port = atoi(argv[1]);

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
		error("Socket already in use\n");
	
	length = sizeof(server);
	bzero(&server, length);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	
	if (bind(sock,(struct sockaddr *)&server, length) < 0)
		error("Bind() failed\n");
	
	fromlen = sizeof(struct sockaddr_in);

	int new_port = port + 100;
	int id = 1;

	while (1) {
		n = recvfrom(sock, buff, 1024, 0, (struct sockaddr *)&from, &fromlen);
		if (n < 0)
			error("Receive error\n");
		write(1, "Received a request: ", 20);
		write(1, buff, n);
		write(1, "\n", 2);

		bzero(&temp, 10);		
		snprintf(temp, 10, "%d", new_port);
		n = sendto(sock, temp, 10, 0, (struct sockaddr *)&from, fromlen);
		if (n < 0)		
			error("Send error\n");

		//Create thread for new_port
		pthread_t connect_handler;
		t_var.port = new_port;
		t_var.id = id;
		if (pthread_create(&connect_handler, NULL, connect_thread, &t_var))
		{
			fprintf(stderr, "Error creating thread\n");
			exit(1);
		}
		id++;
		new_port++;
		
	}
	return 0;
}
