#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int result = 0;


void* square(void* x)
{
	
	int xi = (int)x;
	
	result = result + xi*xi;
	printf("Wynik potegowania dla podanego x: %d\n", xi*xi);
	printf("Id watka: %ld\n",pthread_self());
	return NULL;
}



int main(int argc, char* argv[])
{
	int i;
	int liczby[argc+1];
	pthread_t th[argc+1];
	for(i = 1; i<argc; i++)
	{
		liczby[i] = atoi(argv[i]);
		th[argc] = *liczby;
		printf("Pobrana wartosc x do obliczenia: %d\n", liczby[i]);
		pthread_create(&th[i], NULL, square, (void*)liczby[i]);
	}
	
	printf("Id watka glownego: %ld\n",pthread_self());
	for(i = 1; i<argc; i++)
	{
		void* add;
		pthread_join(th[i], &add);
	}
	
	printf("Wynik = %d\n", result);
	return 0;
	
}
