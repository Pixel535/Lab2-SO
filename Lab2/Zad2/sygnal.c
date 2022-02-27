#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void C(int sig)
{
	signal(sig,SIG_IGN);
	printf("Wcisnieto CTRL-C\n");
	printf("Numer sygnalu: %d\n", sig);
	signal(SIGINT,C);
}

void znak(int sig)
{
	signal(sig,SIG_IGN);
	printf("Wcisnieto CTRL-\\\n");
	printf("Numer sygnalu: %d\n", sig);
	signal(SIGQUIT,znak);
}

void z(int sig)
{
	signal(sig,SIG_IGN);
	printf("Wcisnieto CTRL-z\n");
	printf("Numer sygnalu: %d\n", sig);
	signal(SIGTSTP,z);
}

int main(void)
{
	signal(SIGINT, C);
	signal(SIGQUIT,znak);
	signal(SIGTSTP,z);
	while(1)
	{
		pause();
	}
	return 0;
}

