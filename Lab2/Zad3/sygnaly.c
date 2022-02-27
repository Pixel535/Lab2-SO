#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


void main()
{
	srand(time(NULL));
	int num;//liczba procesow
	int CzasUspienia;//czas uspienia procesu
	int pidGlowny;//pid procesu glownego
	int pidProc[num];//tablica przechowujaca pid procesow potomnych
	printf("Podaj liczbe procesow\n");
	scanf("%d", &num);
	printf("\nPodana liczba procesow: %d\n", num);
	
	for(int i = 0;i<num;i++)
	{
		CzasUspienia = rand()%10 +1;// wybranie losowej liczby czasu uspienia
		pidProc[i] = fork();//wpisanie do tablicy pid kolejnych procesow
		if(pidProc[i] == 0)
		{
			printf("Proces o nr id [%d] jest uspiony na %d\n", getpid(), CzasUspienia);
			sleep(CzasUspienia);
			printf("-----------------------------------------------------\n");
			printf("Proces o nr id [%d] zostal obudzony\n", getpid());
			printf("-----------------------------------------------------\n");
			exit(0);
		}
	}
	pidGlowny = wait(NULL);//wpisanie pid pierwszego obudzonego procesu do wartosci pid glownego
	for(int i = 0;i<num;i++)
	{
		if(pidProc[i] != pidGlowny)//usuwanie innych procesow
		{
			printf("Usuniecie procesu nr id [%d]\n", pidProc[i]);
			kill(pidProc[i], SIGTERM);
		}
	}
	
	return 0;
	
}
