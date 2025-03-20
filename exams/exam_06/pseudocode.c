// includes

// struct client
	// id
	// msg

// declare global variables (clients, send_buffer, rcv_buffer, fd sets, max_fd, uuid)

// error message function

// send to all function - send message to all clients except the client sending message

// main

	// parsing

	// modified bit from main- BIND, LISTEN

	// while
		// update current_set
		// is there an event to listen to? SELECT - if not, continue
		// loop through fds
			// is it readable?
				// is it the server?
					// ACCEPT client trying to comm with server, add to set, announce (9 lines)
				// else its a client
					// RECV message from client
					// if msg_len <= 0, client left
						// announce and close (5 lines)
					// else interpret message and send to all
						// for i/ j
							// stock msg from recv_buffer to clients struct .msg char by char
							// if new line
								// null terminate and send message to all, bzero .msg, reset j (5 lines)
				// break
	// return (0)


// why the break?
// - only one client event handled per loop, then server refeshes socket states and returns to begginning of loop
// (prevents getting stuck on one overactive client)
