FROM	debian:buster

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install php7.3-fpm \
		wget \
		tar \
		vim \
		php-mbstring \
		php-mysql \
		mariadb-client


RUN		mkdir -p /var/www/html/
WORKDIR /var/www/html/
RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvzf latest.tar.gz

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

EXPOSE	9000

CMD		service php7.3-fpm start && tail -f /dev/null