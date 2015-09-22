/*********************************
    > File Name: pipe3.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月22日 星期二 14时17分28秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30
int main(int argc, char *argv[])
{
	int fds1[2], fds2[2];
	char str1[] = "Who I'm I";
	char str2[] = "Your are God!";
	char buf[BUF_SIZE];
	pid_t pid;

	pipe(fds1), pipe(fds2);
	//pipe(fds1);
	//pipe(fds2);
	//居然都行得通
	pid = fork();
	if(pid == 0)
	{
		write(fds1[1], str1, sizeof(str1));
		read(fds2[0], buf, sizeof(buf));
		printf("Chile proc output: %s \n", buf);
	}
	else
	{
		read(fds1[0], buf, BUF_SIZE);
		printf("Parent proc output: %s \n", buf);
		write(fds2[1], str2, sizeof(str2));
		sleep(3);
	}
	return 0;
}
