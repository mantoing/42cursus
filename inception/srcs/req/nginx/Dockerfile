FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt-get install openssl -y
RUN apt-get install vim -y

COPY conf/nginx.conf /etc/nginx/sites-available/default

RUN	openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" \
	-out /etc/ssl/certs/jaeywon.42.fr.crt \
	-keyout /etc/ssl/private/jaeywon.42.fr.key

ENTRYPOINT ["nginx", "-g", "daemon off;"]

EXPOSE 443
