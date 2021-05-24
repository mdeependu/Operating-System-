#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define MSGSIZE 50

char* message = "How are you ?";

int main()
{
	char store[MSGSIZE];
	int p[2];

	if (pipe(p)<0)
		exit(1);

	write(p[1], message, MSGSIZE);
    read(p[0], store, MSGSIZE);
    fork();
    printf("%s\n", store);

	return 0;
}
