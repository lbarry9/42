#!/bin/bash

# explain this **********
chsh -s $(which zsh)
wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh
echo "alias zshi='sh /install.sh'" >> ~/.zshrc

service mariadb start

# make sure MariaDB is fully set up and ready for following commands
sleep 6

# MariaDB expects SQL strings on setup
mariadb -e "CREATE DATABASE IF NOT EXISTS \`${DATABASE}\`;"
mariadb -e "CREATE USER IF NOT EXISTS \`${ADMIN}\`@'localhost' IDENTIFIED BY '${ADMIN_PASSWORD}';"
mariadb -e "GRANT ALL PRIVILEGES ON \`${DATABASE}\`.* TO \`${ADMIN}\`@'%' IDENTIFIED BY '${ADMIN_PASSWORD}';"
mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${ADMIN_PASSWORD}';"
mariadb -e "FLUSH PRIVILEGES;"

# shutdown cleanly and restarted in safe mode with desired config*
mysqladmin -u root -p$ADMIN_PASSWORD shutdown
mysqld_safe --port=3306 --bind-address=0.0.0.0 --datadir='/var/lib/mysql'

# *config:
# listen on default port
# accept connections from any IP address (external communication)
# default socket file used for internal communication
# run as mysql user- default user with low level privileges- good practice security measure
# specify where to store databases