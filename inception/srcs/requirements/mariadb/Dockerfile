
# Use a debian base image
FROM debian:bullseye

# Update and install necessary packages
RUN apt-get update && apt-get upgrade -y && apt-get install -y wget mariadb-server

# Create necessary directories and set permissions - runtime file like socket files, database files
RUN mkdir -p /var/run/mysqld /var/lib/mysql && \
    chown -R mysql:mysql /var/run/mysqld /var/lib/mysql && \
    chmod 777 /var/run/mysqld /var/lib/mysql

# Expose the MariaDB port
EXPOSE 3306

# Copy bash script which configures MariaDB server into container
# and make it executable so there's no permission error 
COPY conf/mariadb.sh /mariadb.sh
RUN chmod +x /mariadb.sh

# When container starts, .sh executed first as main process
# set to an executable form (JSON array)
ENTRYPOINT ["/bin/bash", "/mariadb.sh"]