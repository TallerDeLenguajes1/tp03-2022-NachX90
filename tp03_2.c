#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5

void main() {
    char *V[TAMA];
    char *Buff;
    Buff= (char *) malloc(100*sizeof(char));
    printf("Ingrese 5 nombres:\n");
    for (int i=0; i<5; i++)
    {
        printf("   Nombre %i: ",i+1);
        gets(Buff);
        V[i]=(char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(V[i],Buff);
    }
    printf("\nMostrando los nombres:\n");
    for (int i=0; i<TAMA; i++)
    {
        printf("   Nombre %i: %s\n",i+1,*(V+i));
        free(V[i]);
    }
}