#!/bin/sh

# 스크립트가 실행 중에 오류가 발생하면 즉시 중단하도록 설정
set -e

# MySQL 데이터베이스가 설정되었음을 나타내기 위한 파일 경로를 환경 변수로 지정
MYSQL_SETUP_FILE=/var/lib/mysql/.setup

# MySQL 데이터베이스 서버를 시작
service mysql start;

# 만약 데이터베이스가 설정되어 있지 않다면 다음 코드를 실행
if [ ! -e $MYSQL_SETUP_FILE ]; then

	# 데이터베이스와 사용자 생성 시작
	# MySQL 쿼리를 실행하여 데이터베이스 생성
	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
	# 새로운 사용자 생성 및 비밀번호 설정
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
	# 사용자에게 데이터베이스에 대한 모든 권한을 부여하고 권한 설정 적용
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
	mysql -e "FLUSH PRIVILEGES";
	# root 사용자의 비밀번호 설정
	mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

	# 설정이 완료되면 root 사용자로 생성한 데이터베이스에 접속하여 쿼리 실행
	mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
	# 데이터베이스 접속 종료
	mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

	# 데이터베이스 설정이 완료되었음을 나타내는 파일 생성
	touch $MYSQL_SETUP_FILE
fi

# MySQL 데이터베이스 서버를 콘솔 모드로 실행
exec mysqld --console