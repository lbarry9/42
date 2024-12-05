# Use a debian base image
FROM debian:bullseye

# Synchronize time (prev error: system time inside Docker container is not
# synchronized with actual time, release files then considered invalid)
RUN apt-get update && apt-get install -y tzdata && \
    ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata

# Update and install necessary packages
RUN apt-get update && apt-get upgrade -y && apt-get install -y wget mariadb-server

# Copy configuration files
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy bash script which configures MariaDB server into container
# and make it executable so there's no permission error 
COPY conf/mariadb.sh /mariadb.sh
RUN chmod +x /mariadb.sh

# When container starts, .sh executed first as main process
# set to an executable form (JSON array)
ENTRYPOINT ["./mariadb.sh"]