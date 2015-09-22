/*********************************
    > File Name: pipe2.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月22日 星期二 14时01分10秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv)
{
	int fds[2];
	char str1[] = "Who are you?";
	char str2[] = "I'm your God.";
	char buf[BUF_SIZE];
	pid_t pid;
	int 1 =0;
	pipe(fds);
	pid = fork();
	if(pid == 0)
	{
		write(fds[1], str1, sizeof(str1));
		//sleep(2);
		read(fds[0], buf, sizeof(buf));
		printf("Child proc output: %s \n", buf);
	}
	else
	{
		read(fds[0], buf, BUF_SIZE);
		printf("Parent proc output: %s \n", buf);
		write(fds[1], str2, sizeof(str2));
		sleep(3);
	}
	return 0;
}
