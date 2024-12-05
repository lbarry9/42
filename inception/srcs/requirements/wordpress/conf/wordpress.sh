#!/bin/bash

# downloads commandline interface for Wordpress
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# makes downloaded file executable
chmod +x wp-cli.phar
# move executable and make it accessible - wp command
mv wp-cli.phar /usr/local/bin/wp

# go into dir where wordpress installed, set permissions (write only by owner, read/execute by all)
# change ownership of all files in wordpress dir to www-data (user associated with NGINX)
cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress

echo "...Installing WordPress..."
# delete any existing files in wordpress dir
find /var/www/wordpress/ -mindepth 1 -delete
# download latest version and make sure download is finished before next cmds
wp core download --allow-root --path="/var/www/wordpress"
sleep 6

# configures wordpress to connect to mariadb database
wp core config --dbhost=mariadb:3306 --dbname="$DATABASE" --dbuser="$ADMIN" --dbpass="$ADMIN_PASSWORD" --allow-root --path="/var/www/wordpress"
# installs wordpress with specified site parameters
wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$ADMIN" --admin_password="$ADMIN_PASSWORD" --admin_email="$ADMIN_EMAIL" --allow-root --path="/var/www/wordpress"
# create new user as author with env varuables
wp user create "$WP_USER" "$WP_EMAIL" --user_pass="$WP_PASSWORD" --role=author --allow-root --path="/var/www/wordpress"

# Configure PHP-FPM to run on TCP port 9000- means it can interact with the web server inside the container
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf
mkdir -p /run/php
# start in foregrand so continues running in container
/usr/sbin/php-fpm7.4 -F