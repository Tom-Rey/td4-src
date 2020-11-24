#include "../generic/myalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>  

#define TAILLE_MAX 1024

int main(int argc, char* argv[])
{
  printf("1");
  printf("[%s] lancee\n",argv[0]);
  //allocation d'un tableau
  printf("1");
  srand (time(NULL));
  int taille = 1 + (rand() % TAILLE_MAX);
  printf("1");
  int* buffer = (int*)myalloc(taille*sizeof(int));
  printf("allocation de %ld entiers (%d octect par entier) à: %p \n",taille,sizeof(int),(void*)buffer);
  int i ;
  for( i = 0; i < taille ; i++)
    {
      buffer[i] = taille-i;
    }  
  printf("2");
  for( i = 0; i < taille ; i++)
    {
      assert(buffer[i] == taille-i);
    }
  printf("3");  
  bloc_info(buffer);
  myfree(buffer);
  bloc_info(buffer);
  printf("[%s] termine\n",argv[0]);
}
