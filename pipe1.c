/*********************************
    > File Name: pipe1.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月22日 星期二 13时54分32秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	int fds[2];
	char str[] = "Who are you? ";
	char buf[BUF_SIZE];
	pid_t pid;

	pipe(fds);
	pid = fork();
	if(pid == 0)
	{
		write(fds[1], str, sizeof(str));//change

	}
	else
	{
		read(fds[0], buf, BUF_SIZE);
		puts(buf);
	}
	return 0;
}
