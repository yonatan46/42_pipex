#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[], char **env)
{
	char *st[3];
	st[0] = "/cat";
	st[1] = "infile";
	st[2] = NULL;
	int er = execve(st[0], st, env);
	printf("%d", er);
	return 0;
}
