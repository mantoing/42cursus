#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void)
{
	printf("쓰레드 함수 실행..\n");
	for (int i = 1; i <= 5; i++)
	{
		usleep(1000 * 1000);
		printf("쓰레드 함수 실행중..(%d/5)\n",i);
	}
	printf("쓰레드 함수 종료\n");
	return (void *)2147483647;
}

int main()
{
	pthread_t p_thread;
	int		thr_id;
	int		result;

	thr_id = pthread_create(&p_thread, NULL, t_function, NULL);
	if (thr_id < 0)
	{
		perror("thread create error:");
		exit(0);
	}
	pthread_join(p_thread, (void *)&result);
	printf("thread join 실행됨;%d\n", result);
	printf("main()종료\n");
	return 0;
}