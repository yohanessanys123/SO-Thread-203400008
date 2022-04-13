/* Program to compute Pi using Monte Carlo methods */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int amtWanted = 0;
int totalPts  = 0;

void *count(void *X)
{ 
    /* initialize random numbers */
    for (i=0; i < amtWanted; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)    //Rumus perhitungan phi
        {
            totalPts++;
        }
    }
    return NULL;
}

int main()
{
    printf("\n\nWelcome\n\n");
    srand(time(NULL));
    pthread_t thread;
//proses pemanggilan thread
    do
	{
        printf("Masukkan Angka \n");
        scanf("%d", &amtWanted);  	
	}while (amtWanted <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * totalPts;
    double pi = points / amtWanted;
    printf("Phi yang di dapat (%d) is: %f \n", amtWanted, pi);  //hasil dari phi
    return 0;
}
