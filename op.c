#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int ac, char **argv, char **envp)
{
	int fd = open("infile", O_RDWR);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("hhhhh");
	printf("boooommmmm");
	execve("/bin/ls", argv, NULL);
}
