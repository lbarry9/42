# Creating a HTTP server in C++ with my mate [amben-ha](https://github.com/AmYre)

**Our webserver had to be very robust, handling as many server blocks as specified in the config file, and withstanding the dreaded load testing created by Siege.**

This project was no mean feat... Lots to implement and lots of room for error and undefined behaviour. Each time we added a new functionality, we had to rethink our whole project structure. 42 doesn't help by creating subject and evaluation sheets which seem to talk about two different projects (please update them pedago team :pray:) and by springing the Siege stress test on us out of the blue during evaluation. Despite our frustration, it was still very interesting better understand how the magic of the world wide web works behind the scenes. Even if we only needed to show basic proof of handling the back-end of client-server interactions, Amir doesn't do things by halves so decided a fully functioning website was the best way to present our project :nerd_face:

[webserv.webm](https://github.com/user-attachments/assets/35649ce5-3a3b-407d-9c9e-be4cb451e84e)

**We handled:**
- I/O multiplexing using EPOLL
- GET, POST and DELETE requests
- multiple servers with different hostname/port combinations
- error pages consistent with HTTP response status codes
- client body and upload file size limits
- internal server reroutes
- external server redirections
- modifable method permissions for different routes
- default files and directory indexing
- CGI's for GET and POST
- Cookies tracking session ID

**Resources for understanding the basic concepts:**
- [select/poll/epoll](https://www.youtube.com/watch?v=H9N_l85TpnI), epoll [in more detail](https://copyconstruct.medium.com/the-method-to-epolls-madness-d9d2d6378642)
- [TCP vs UDP](https://www.youtube.com/watch?v=uwoD5YsGACg)
- [HTTP requests](https://www.youtube.com/watch?v=-Zea7GB2OwA)
- [web sockets](https://www.youtube.com/watch?v=pnj3Jbho5Ck)
- For the NGINX inspired config file: its [structure](http://nginx.org/en/docs/beginners_guide.html); implementing [server_name](https://statuslist.app/nginx/server_name/)

**Reading:**
- _The Happy Couple_ by Naoise Dolan
