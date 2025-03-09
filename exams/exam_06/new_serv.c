#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <sys/socket.h>

typedef struct s_client
{
	int id;
	char msg[290000];
} t_client;

t_client clients[1024];
char send_buffer[300000], recv_buffer[300000];
fd_set readable, writable, current_set;
int max_fd = 0;
int uuid = 0;

void my_err(char *err_msg)
{
	if (err_msg)
		write(2, err_msg, strlen(err_msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void send_to_all(int except)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &writable) && fd != except)
		{
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				my_err(NULL);				
		}
	}
}

int main(int arc, char **argv)
{
	// parsing
	if (arc != 2)
		my_err("Wrong number of arguments");
	
	// ------- modified bit from main -------
	struct sockaddr_in servaddr, cli_addr; // modified var names
	socklen_t len = sizeof(cli_addr); // len int -> socklen_t, deleted 2 other vars

	int server_fd = socket(AF_INET, SOCK_STREAM, 0); // modified var name
	if (server_fd == -1)
		my_err(NULL); // use err func, don't need else
	max_fd = server_fd; // added this init
	
	FD_ZERO(&current_set); // added
	FD_SET(server_fd, &current_set); // added
	bzero(&servaddr, sizeof(servaddr)); 
	bzero(clients, sizeof(clients)); // added
	 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1])); // swap port for atoi(av[1])

	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
		my_err(NULL); // use err func, don't need else
	if (listen(server_fd, 10) == -1)
		my_err(NULL); // use err func, don't need else
	// ------- end of modified bit from main -------
	
	while (1)
	{
		readable = writable = current_set;
		
		if (select(max_fd + 1, &readable, &writable, 0, 0) == -1)
			continue;
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &readable))
			{
				if (fd == server_fd)
				{
					int client_fd = accept(server_fd, (struct sockaddr *)&cli_addr, &len);
					if (client_fd == -1)
						continue;
					if (client_fd > max_fd)
						max_fd = client_fd;
					FD_SET(client_fd, &current_set);
					clients[client_fd].id = uuid++;
					sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
					send_to_all(fd);						
				}
				else 
				{
					int msg_len = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if (msg_len <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						FD_CLR(fd, &current_set);
						close(fd);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < msg_len; i++, j++)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}
							
						}
					}
				}
				break;
			}
		}
	}
	return (0);
}