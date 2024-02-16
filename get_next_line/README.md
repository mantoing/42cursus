# get_next_line

### 공부
- getline함수를 보고 파일 디스크립터의 개념과 사용방법등을 익히고 또한 자료구조중 하나인 list에 대해서 상세하게 다뤄보았다.

# 참조

- fd
  fd는 파일디스크립터의 약자이다.
  이는 스트림을 사용하기 위해 붙이는 번호라고 생각하면된다.
  ### [기본적으로 운영체제가 자주쓰는 스트림 3개](https://sublivan.tistory.com/60#%EA%B-%B-%EB%B-%B-%EC%A-%--%EC%-C%BC%EB%A-%-C%--%EC%-A%B-%EC%--%--%EC%B-%B-%EC%A-%-C%EA%B-%--%--%EC%-E%--%EC%A-%BC%EC%--%B-%EB%-A%--%--%EC%-A%A-%ED%-A%B-%EB%A-%BC%---%EA%B-%-C)
  - 표준입력 : 0
  - 표준 출력 : 1
  - 표준 오류 출력 : 2
  open 함수를 통해 새 스트림을 열어주면 운영체제는 자동으로 기존에 사용하던 스트림 번호에 +1을 하여 이를 해당 스트림의 fd로 부여한다.
- OPEN_MAX
  **OPEN_MAX**
  파일 디스크립터의 최대갓은 OPEN_MAX라는 값이다.
  OPEN_MAX는 단일 프로그램에 허용되는 최대 열린 파일 수를 정의하는 상수다.
  즉, 하나의 프로세스 당 최대 OPEN_MAX개의 파일을 열 수 있다.
  OPEN_MAX 값은 플랫폼에 따라 다르다.
  Unix 시스템에서 C언어의 OPEN_MAX는 limits.h에 정의되어 있다.
  (OPEN_MAX와 FOPEN_MAX와 \_SC_OPEN_MAX는 조금씩 다르다고 한다.
- line
  line은 함수의 매개변수로 들어가는 포인터이다.
  포인터를 매개변수로 사용하는 경우 2가지
  1. 함수의 매개변수로 전달하기에 변수가 너무 클 경우
     - 주로 구조체에 해당한다.따라서 이 변수의 메모리 공간을 가리키는 포인터 변수를 함수의 매개변수로 전달하면 낭비를 막을 수 있다.
     - : 구조체는 여러 유형의 변수를 모아놓고 쓰는 것이므로 크기가 커질 수 있다.이를 함수에 그대로 전달할 경우 함수는 해당 변수를 그대로 스택에 복사하여 사용해야 하므로 메모리 낭비가 심해진다.
  2. 함수 내부에서 매개변수로 오는 변수의 값을 함수 내부에서 변경할 수 있다.
     - 포인터란 어떠한 변수의 메모리 주소를 담고 있으므로 이를 전달하면 해당 변수의 값을 함수 내부에서 변경할 수 있다.
  **_이 과제에선 2번의 경우에 해당하여 포인터를 매개변수로 전달하였다._**
  fd로 부터 파일의 내용을 읽어들이고 개행을 단위로 문자열을 잘라 line에 넣어주는 것이다.line은 함수 밖에서 선언될 것이고 이를 함수 내부에서 변경해야 한다.
- 반환값 1, 0 -1
  1 : 한 줄이 읽혔다.
  0 : 파일의 끝에 도달했다.
  -1 : 에러가 발생했다.
  fd로 부터 제대로 한 문장을 가져왔는지 여부를 -1, 0, 1로 반환한다.
  따라서 -1, 0이면 함수는 중간에 return을 시켜서 중단해줘야 할 것이고 1인 경우 제대로 문장 취득이 이루어 졌으니 다음 문장을 출력할 수 있게 준비해둬야한다.
- 허용된 외부함수
  - read :
    read 함수는 `int read (int fd, buf, buffer_size);` 로 정의된 함수다.
    특정 fd로부터 바이트 단위로 내용을 읽어들어와 버퍼에 버퍼사이즈만큼 저장한다.
    반환값은 읽어들인 바이트 수다. 버퍼사이즈보다 적게 읽어들일 경우엔 읽어들인 바이트 수를 반환한다.
    이 시스템 콜은 동작 후에 읽어들인 버퍼만큼 파일 오프셋(스트림이 파일과 연결되어 있는 부분)을 이동시킨다.따라서 같은 파일 디스크립터에 대해 read() 시스템 콜을 반복해서 호출하면 파일의 마지막에 도달하게 된다.
  - free :
    free는 메모리 공간을 해제하는 함수이다.
    read는 계속 버퍼사이즈를 최대 크기로 해서 파일이든 stdin이든 입력 소스로부터 읽어들일 것이다.따라서 반복할 때마다 앞의 읽었던 문장에다가 새로 읽어들인 문장을 붙여줘야한다. 그래야지 개행을 기준으로 문장들을 출력할 원본이 생긴다.
- static variable
  ### 정적 변수(Static variable)
  ### 1. 정적변수란?
  : 정적 변수는 일반적인 auto변수 또는 dynamic변수와 작동 방식이 다르다. 정적 변수는 프로그램 시작 시 메모리에 할당되고, 프로그램 종료 시 메모리가 해제된다.(변수의 범위를 벗어나도 값을 유지한다.)
  : 이러한 정적 변수는 프로그램의 수정, 유지 보수, 재사용을 어렵게하는 단점이 있는 전역 변수의 단점을 부분적으로 보완한다고 볼 수 있다. (물론 정적변수와 전역변수가 아예 다르다 라는 뜻은 아님)
  ### 2. 사용법
  ```
  static 자료형 변수이름;
  ```
  변수를 선언할 때 자료형 앞에 static키워드를 붙여 사용.
  ### 3. static 지역 / static 전역
  : static 지역 변수는 함수 블록을 벗어나도 값이 사라지지 않지만, **변수를 선언한 함수 블록 안에서만 접근**할 수 있다.
  : static 전역 변수는 해당 소스 파일의 다른 함수에서도 접근할 수 있다. 하지만 **다른 소스 파일에서 extern으로 static 전역 변수를 호출하면 컴파일에러가 발생**한다.즉, 자신이 선언된 소스 파일 내에서만 사용 가능하다.이를 이용해 전역 변수에 static을 붙여 변수의 범위를 해당 소스 파일로 제한할 수 있다.
  ### 4. 특징
  **1) 초기화를 하지 않아도 자동으로 0이 저장됨.**
  **2) 초기화는 한번만 수행.**: 적정 지역 변수가 선언된 함수를 여러번 호출하거나, 반복문의 중괄호 안에 정적 변수를 선언했더라도 초기화는 맨 처음 한번만 수행한다.
  **3) 함수의 매개변수로 사용할 수 없음.**: 함수의 매개변수에 static을 붙이더라도, 매개 변수는 정적 변수가 되지 않으며 값이 유지되지 않음. (잘못된 문법)

# 함수설명

- 개요
  서브젝트 get_next_line은 이미 실행한 파일의 fd를 토대로 텍스트를 읽어와서, 개행문자가 있는 부분까지 - 즉, 한 줄의 텍스트만 - 읽어와서 매개변수로 받은 char \*\*line 에 할당하는 함수이다. 함수가 실행된 이후, 읽어온 버퍼의 상태에 따라 서로 다른 리턴값을 반환해야한다.
  해당 함수를 구현하면서 작업자는 static variable, 커널에서 파일이 open & read되는 매커니즘과 파일 서술자(fd)에 대해서 배울 수 있다. 또한 함수의 메모리 관리를 위해 premature free 상황에 대한 대처와 댕글링 포인터 처리를 배울 수 있다.
- Mandatory part
  ![Untitled](https://github.com/mantoing/libft/assets/90916425/db12fbd5-d678-460f-b287-870fc0025fc3)
 ![Untitled 1](https://github.com/mantoing/libft/assets/90916425/72f36417-b3c5-4c82-a144-83351e5ca584)
  - `get_next_line` 함수를 실행시키면, fd에서 사용가능한 텍스트를 읽어와서, EOF가 나올 때까지 한 번에 한 줄씩 읽어올 수 있다. 즉, 해당 함수를 1회 실행시켰을 때에는 개행문자가 있는 곳까지 텍스트를 읽어 라인에 할당하거나, 그렇지 않으면 EOF까지 텍스트를 읽어들인 후 라인으로 할당해야한다.
  - 함수를 구현할 때, 파일에서 읽어올 때와 표준입력에서 읽어올 때 모두에서 작동하는 지 체크할 것.
  - 이전 프로젝트인 libft를 직접 활용하는 것은 금지된다. 별도의 함수가 필요한 경우, libft에서 가져오거나 자신이 구현한 함수를 `get_next_line_utils.c` 에 넣어야 한다. 즉, norminette 규정에 맞추어 해당 서브젝트의 구현을 위해 최대로 사용할 수 있는 함수의 갯수는 10개 이다.
  - 구현한 `get_next_line` 함수는 -D BUFFER_SIZE=n 플래그를 사용하여 컴파일하게 될 것이다. 해당 변수 `BUFFER_SIZE`는 구현하실 함수에서 사용하여야 한다. 해당 변수는 평가를 위해 평가자나 moulinette가 수정할 수 있다. moulinette나 테스터는 구현한 함수를 컴파일 할 때에 -D 에 활용되는 n값을 임의로 수정하면서 컴파일 된다.
  - 컴파일은 다음과 같이 실행될 것이다. ; `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c`
  - 함수 구현시 내부에서 사용될 read 함수를 사용할 때에, 매개변수로 `BUFFER_SIZE`를 사용해야만 한다.
  - 헤더 파일 `get_next_line.h` 안에는 구현한 함수들 중 `get_next_line`의 프로토타입은 반드시 있어야 합니다.
  - 파일 지정자 `fd` 의 두 번의 호출 사이에서, 첫 번째 fd 호출 이후 EOF에 도달하기 전에 다른 파일로 전환될 경우, `get_next_line`은 정의되지 않은 동작을 한다고 여겨야 한다. 즉, get_next_line에서 한 번 사용을 시작한 fd는 텍스트를 끝까지 읽어들여서 반환값이 0이 되기 전에는 같은 파일을 계속해서 읽어들이고 있다고 여겨도 좋다.
  - 바이너리 파일을 읽어들이는 것은 정의되지 않은 동작이지만, 원한다면 논리적으로 구현할 수는 있다.
  - lseek 및 전역변수의 사용은 금지된다.
- Bonus part
  ![Untitled 1](https://github.com/mantoing/libft/assets/90916425/21108a01-22a9-4813-8ab6-69008ff093c3)

  mandatory part를 모두 구현하였다면, 아래의 사항들을 준수하여 구현하면 된다. 단, bonus part의 사항을 모두 지켰다고 하여도, mandatory part에서 완벽하지 않다면 옳지 못한 구현으로 여겨질 것이다.
  - 단 하나의 static variable 만을 사용하여 `get_next_line` 을 구현하기.
  - 여러 개의 fd를 받아서 다수의 fd를 관리할 수 있는 `get_next_line` 함수를 구현하기.
  > 이미 실행된 파일이 있어서 파일 지정자로 3,4,5가 있는 경우를 상상해보라. 해당 사항을 잘 준수하였다면, get_next_line 을 각 파일 지정자의 reading thread를 잃지 않으면서 3에서 한 번, 4에서 한 번, 3에서 또 다시 한 번, 5에서 한 번 호출하도록 구현할 수 있을 것이다.
  >
  > 즉, fd를 하나 이상 받을 수 있음을 상정하고, 해당 fd의 reading thread를 보존하기 위해서 static variable을 어떤 타입으로, 또 어떤 방식으로 사용할 지 고민이 필요할 것이다.
  > 대개 이 부분을 먼저 상정하고 시작하는 것이 편하다. 첫 구현시 보너스 파트까지 모두 구현하는 것을 목표로 하자. 보너스 파트 구현시, include하는 헤더파일을 잘 확인하자. get_next_line.c / get_next_line_utils.c 는 get_next_line.h를, get_next_line_bonus.c / get_next_line_utils_bonus.c 는 get_next_line_bonus.h를 include 해야한다. 내부적인 코드는 동일하여도 좋다.

## get_next_line.c

```c
#include "get_next_line_bonus.h"

int	check_newline(char *line) //개행이 있는지 확인하는 함수
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_newline(char **line, int rsize)
{
	char	*res;
	char	*tmp;
	int		pos;

	if (!line || !*line || rsize < 0)
		return (NULL);
	pos = check_newline(*line); //어디에 개행이 있는지 저장하는것
	if (pos > -1)
	{
		res = ft_substr(*line, 0, pos + 1); //pos에 개행까지 출력을 하기ㅣ위해서 +1을 해준것 (0부터 시작을 해서 pos + 1 앞까지 구간을 추출하기 위해)
		tmp = ft_substr(*line, pos + 1, ft_strlen(*line) - (pos + 1)); //res값에 저장된 부분말고 남은 라인을 저장해 놓기 위해서 처리
		free(*line); //쓸모없기 때문에 free
		*line = tmp; //아까 잘라낸 tmp를 다시 line에 할당
		if (**line != '\0')
			return (res); //만약 우리가 읽은것이 개행 끝에 NULL이 없으면 뒤에 계속 읽어야 하기 때문에 해제하지않고 리턴
	}
	else
		res = ft_strdup(*line); //개행이 없는 상태에서 다 읽었을경우 처리하기 위해서 (남아있는 부분 전부 할당)
	free(*line); //더이상 읽을것이 없는 경우 메모리 누수를 막기 위해 다쓴 라인 free
	*line = NULL; //free 쓰레기값이 남아있기 때문에 NULL로 초기화 (메모리 해제가 되어도 값은 남아있음)
	return (res);
}
static int	add_rsize(int rsize, int fd, char *buff, char **line)
{
	char *tmp;

	while (rsize > 0)
	{
		buff[rsize] = '\0'; //읽은것 제일 마지막에  NULL을 넣어준것
		if (!line[fd])
			~~line[fd] =~~ ft_strdup("");//strjoin을 하기위해 메모리값이 할당 되어야 하기때문에 주소값이 아예 비어있는 경우에 NULL할당
		if (!line[fd])
			return (-2); //static int의 반환값이 NULL이 될수없기 때문에 -2로 반환
		tmp = line[fd];//strjoin을 새로 할당해야하기 때문에 임시로 저장
		line[fd] = ft_strjoin(tmp, buff); //strjoin을 통해서 이전의 라인과 이번에 읽은 buff를 연결해준것
		free(tmp);//이전의 라인은 free
		if (!line[fd])
			return (-2); //static int의 반환값이 NULL이 될수없기 때문에 -2로 반환
		if (check_newline(line[fd]) > -1)
			break ; //시작하자마자 개행일수가 있기 때문에 0이아닌 -1로 조건설정
		rsize = read(fd, buff, BUFFER_SIZE);
	}
	return (rsize);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rsize;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rsize = read(fd, buff, BUFFER_SIZE);
	rsize = add_rsize(rsize, fd, bufff, line);
	if (rsize == -2)
		return (NULL); //위의 add_rsize의 -2반환값을 NULL로 변경.
	if (!line[fd])
		return (NULL);
	return (get_newline(&line[fd], rsize));
}

//OPEN_MAX : 파일 디스크립터가 가질수 있는 최댓값(운영체제마다 다름), 컴파일 해서 보내는것이 아니기 때문에 어차피 상관없고 사용자 환경을 이미 고정을 해놓고 코드를 작성하는데 그것에 관해 딴지 거는것은 말이 안된다.
```

## get_next_line_utils.c

```c
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
	{
		str[s1_len] = s2[i];
		s1_len++;
	}
	str[s1_len] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (src[i])
		i++;
	temp = (char *)malloc(i * sizeof(char) + 1);
	if (!temp)
		return (0);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s || start < 0)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (len > str_len)
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
```

## get_next_line.h

```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	check_newline(char *line);
char	get_newline(char **line, int rsize);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strjoin(charㅇㅁㄴㅇㅈ\

 const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
```

OPEN_MAX를 사용하기 위해서 limits.h 를 사용

**저수준입출력함수**는 **유닉스계열**의 함수이기 때문에 운영체제에 따라 선언되지 않는 경우가 있다. **ifndef ~endif** 매크로 처리로 **OPEN_MAX**가 선언되어 있지 않는 다면 10240으로 선언하도록 처리했다.

(맥os환경에서 10240으로 선언 되어있다.)
