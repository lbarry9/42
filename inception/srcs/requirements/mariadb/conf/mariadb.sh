#!/bin/bash

# Start MariaDB service
service mariadb start

# Wait for MariaDB to be ready
# tries to connect as root to Mariadb and launch a simple mysql command to check if it's ready
# dev/null used to suppress output
until mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "SELECT 1" &>/dev/null; do
  echo "Waiting for MariaDB to be ready..."
  sleep 1
done

# Secure the initial root access and remove default databases
mariadb -h localhost -u root -p"${DB_ROOT_PASSWORD}" <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF

# Create a new database and user, use env credentials
mariadb -h localhost -u root -p"${DB_ROOT_PASSWORD}" <<EOF
CREATE DATABASE IF NOT EXISTS ${DATABASE};
CREATE USER IF NOT EXISTS '${DB_USER}'@'localhost' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DATABASE}.* TO '${DB_USER}' IDENTIFIED BY '${DB_PASSWORD}';
FLUSH PRIVILEGES;
EOF

# Shutdown and restart with your specified configuration
mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown
mysqld_safe --user=mysql --port=3306 --bind-address=0.0.0.0  --socket='/run/mysqld/mysqld.sock' --datadir='/var/lib/mysql' --pid-file='/var/run/mysqld/mysqld.pid' --skip-networking=off --max_allowed_packet=64M #--log-error='/var/log/mysql/error.log'

echo "MariaDB is ready to use!"
