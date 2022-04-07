#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    int cant;
    char **V;
    char *Buff;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%i",&cant);
    getchar();
    
    V=(char **)malloc(sizeof(char *)*cant);
    Buff=(char *)malloc(100*sizeof(char));
    for (int i=0; i<cant; i++)
    {
        printf("   Nombre %i: ",i+1);
        gets(Buff);
        *(V+i)=(char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(V[i],Buff);
    }
    printf("\nMostrando los nombres:\n");
    for (int i=0; i<cant; i++)
    {
        printf("   Nombre %i: %s\n",i+1,*(V+i));
        free(V[i]);
    }
}