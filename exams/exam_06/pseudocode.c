// includes

// struct client
	// id
	// msg

// declare global variables (clients, send_buffer, rcv_buffer, fd sets, max_fd, uuid)

// error message function

// send to all function - send message to all clients except the client sending message

// main 

	// parsing
	
	// modified bit from main
	
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
						//announce and close (5 lines)
					// else interpret message and send to all 
						// stock recv_buffer in clients struct
				// break - only one client event handled per loop, then server refeshes socket states and returns to begginning of loop
				// (prevents getting stuck on one overactive client)
	// return (0)