// includes
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <sys/socket.h>

// struct client
	// id
	// msg

typedef struct s_client
{
	int id;
	char msg[290000];
} t_client;

// declare global variables (clients, send_buffer, rcv_buffer, fd sets, max_fd, uuid)
t_client clients[1024];
char send_buffer[300000], recv_buffer[300000];
fd_set readable, writeable, current_set;
int max_fd = 0;
int uuid = 0;

// error message function
void my_err(char *err_msg)
{
	if (err_msg)
		write(2, err_msg, strlen(err_msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

// send to all function - send message to all clients except the client sending message
void send_to_all(int except)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &writeable) && fd != except)
		{
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				my_err(NULL);
		}
	}
}

// main 
int main(int ac, char **av)
{
	// parsing
	if (ac != 2)
		my_err("Wrong number of arguments");
	
	// ------- modified bit from main -------
	struct sockaddr_in servaddr, cli_addr; 
	socklen_t len = sizeof(cli_addr);

	// socket create and verification 
	int serv_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (serv_fd == -1)
		my_err(NULL);
	max_fd = serv_fd;
	
	FD_ZERO(&current_set);
	FD_SET(serv_fd, &current_set);
	bzero(&servaddr, sizeof(servaddr)); 
	bzero(clients, sizeof(clients));

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); 
	servaddr.sin_port = htons(atoi(av[1])); 
	
	if ((bind(serv_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
		my_err(NULL);
	if (listen(serv_fd, 10) == -1)
		my_err(NULL);
		
	// ------- end of modified bit from main -------
	// while
		// update readable and writable sets to current_set
		// if there's no event to listen to, continue
		// loop through fds
			// is something readable?
				// is it the server?
					// accept client trying to communicate with server, add to set, announce (9 lines)	
				// else its a client
					// recv data from client
					// if msg length <= 0, client left
						// announce and close (5 lines)
					// else interpret message and send to all 
						// stock recv_buffer in clients struct
				// break - only one client event handled per loop, then server refeshes socket states and returns to begginning of loop
	return (0);
}