# Use a debian base image
FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

# Install NGINX
RUN apt-get install nginx -y

# Install openSSL - dependancy
RUN apt-get install openssl -y

# Create directory to store SSL/TLS certificates and private keys
# they're used to communicate between NGINX server + clients
RUN mkdir -p /etc/nginx/ssl

# Generate new certificate signing request, self-signed, key not encrypted
# -out and -keyout specify cert/key outfiles
# -subj info about certificate's owner- location, domaine owner/user
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=lbarry.42.fr/UID=lbarry"

# certficate read only for all but owner- common practice
RUN chmod 644 /etc/nginx/ssl/inception.key /etc/nginx/ssl/inception.crt

# Create directory to store NGINX PID file
RUN mkdir -p /var/run/nginx

# Copy the configuration file from the current directory and paste it inside the container
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Use port 443
EXPOSE 443

# Start NGINX in the foreground
CMD ["nginx", "-g", "daemon off;"]