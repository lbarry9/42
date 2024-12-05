FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

# installs PHP FastCGI Process Manager
# used to serve PHP apps in web server env
RUN apt-get install -y wget php7.3 php-fpm php-mysql mariadb-client zsh git curl netcat mycli

COPY /conf/wordpress.sh /

RUN  chmod +x wordpress.sh

ENTRYPOINT ["./wordpress.sh"]