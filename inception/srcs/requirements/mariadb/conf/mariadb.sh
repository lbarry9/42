#!/bin/bash

# Start MariaDB service
service mariadb start

# Wait for MariaDB to be ready
until mariadb -u root -proot1234 -e "SELECT 1" &>/dev/null; do
  echo "Waiting for MariaDB to be ready..."
  sleep 1
done

# Secure the initial root access
mariadb -h localhost -u root -proot1234 <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root1234';
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF

# Now we can proceed with your database setup using the root password
mariadb -h localhost -u root -proot1234 <<EOF
CREATE DATABASE IF NOT EXISTS wordpress_db;
CREATE USER IF NOT EXISTS 'lbarry'@'localhost' IDENTIFIED BY 'db1234';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'lbarry' IDENTIFIED BY 'db1234';
FLUSH PRIVILEGES;
EOF

# Shutdown and restart with your specified configuration
mysqladmin -u root -proot1234 shutdown
mysqld_safe --user=mysql --port=3306 --bind-address=0.0.0.0  --socket='/run/mysqld/mysqld.sock' --datadir='/var/lib/mysql' --pid-file='/var/run/mysqld/mysqld.pid' --skip-networking=off --max_allowed_packet=64M #--log-error='/var/log/mysql/error.log'

echo "MariaDB is ready to use!"
