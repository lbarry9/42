# docker build -t nginx:laura .
# docker run -d -p 443:443 --name nginx-cont nginx:laura
# docker image ls
# docker ps -a
# network cleaning -sudo lsof -t -i :443 | xargs -r sudo kill -9
# sudo docker exec -it wordpress /bin/bash

DC := sudo docker compose -f srcs/docker-compose.yml

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

fclean:
	sudo docker system prune -a --volumes
	sudo rm -rf /home/lbarry/data

re: fclean all

logs:
	$(DC) logs

help:
	@echo "Utilisez 'make all' pour construire et démarrer les services."
	@echo "Utilisez 'make build' pour construire les services."
	@echo "Utilisez 'make up' pour lancer les services en arrière-plan."
	@echo "Utilisez 'make down' pour arrêter les services."
	@echo "Utilisez 'make clean' pour arrêter et supprimer les conteneurs, réseaux, images, et volumes."
	@echo "Utilisez 'make fclean' pour un nettoyage complet, y compris les volumes non anonymes."
	@echo "Utilisez 'make re' pour reconstruire et redémarrer les services."
	@echo "Utilisez 'make logs' pour afficher les logs des services."