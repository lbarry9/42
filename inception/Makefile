# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 17:04:43 by lbarry            #+#    #+#              #
#    Updated: 2024/12/13 17:04:45 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DC := sudo -plbarry docker compose -f srcs/docker-compose.yml

all:
	@mkdir -p /home/lbarry/data/mariadb
	@mkdir -p /home/lbarry/data/wordpress
	@docker ps -q | grep . || $(DC) up --build -d

stop:
	$(DC) stop

start:
	$(DC) start

down:
	$(DC) down

clean:
	$(DC) down --rmi all --volumes

fclean: clean
	sudo docker system prune -a --volumes
	sudo rm -rf /home/lbarry/data
	sudo rm -rf /home/lbarry/inception/srcs/requirements/nginx/ssl

re: fclean all

logs:
	$(DC) logs

help:
	@echo "Use 'make' to build and run services"
	@echo "Use 'make stop' to stop services without deleting them"
	@echo "Use 'make start' to restart services after stopping"
	@echo "Use 'make down' to stop and delete services"
	@echo "Use 'make clean' to stop and delete services and remove the containers, images, network and volumes"
	@echo "Use 'make fclean' to do a complete clean, including non-anonymous volumes, data and folders"
	@echo "Use 'make re' to fclean then rebuild and run services"
	@echo "Use 'make logs' to show service logs after building"
	
# docker build -t nginx:laura .
# docker run -d -p 443:443 --name nginx-cont nginx:laura
# docker image ls
# docker ps -a
# network cleaning - sudo lsof -t -i :443 | xargs -r sudo kill -9

# sudo docker exec -it wordpress /bin/bash
	
# sudo systemctl stop docker
# sudo systemctl start docker

# sudo systemctl stop docker.socket
# sudo systemctl stop docker.service
# sudo systemctl start docker.socket
# sudo systemctl start docker.service

# docker system prune -af
# docker stop `docker ps -q`
# docker rm `docker ps -aq`
# docker rmi `docker image -aq`
# docker volume rm `docker volume ls -q`
# docker network rm `docker network ls -q`
# docker system prune -af

# proving that maridb database is there
# docker exec -t mariadb bash
# mysql -u root -p --> works with root1234 env password
# show databases; --> works 3 databases - information_schema, mysql, performance_schema
# use inception; --> doesn't work - no inception database present
# show tables;  
# show comments from wordpress site
# SELECT * FROM wp_comments;