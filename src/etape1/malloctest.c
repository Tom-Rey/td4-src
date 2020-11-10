#include "../generic/myalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>  


#define TAILLE_MAX 1024

void* myalloc(size_t n){
  size_t taille=ALIGN(n+ENTETE_SIZE);
  void* ptr=(void*) sbrk(taille);

  bloc_entete* ptr_entete=(bloc_entete*) ptr;
  ptr-entete->taille = taille;
  ptr-entete->libre=0;

  void* user_addresse = ((char*) ptr)+ENTETE_SIZE;
  return user_addresse;
}
void myfree(void* user_addresse){
  bloc_entete* ptr-entete= (bloc_entete*) ((char*)user_addresse - ENTETE_SIZE);
  
  ptr-entete->libre=1;
}

void blocinfo(void* ptr){
  bloc_entete* bloc_total=(bloc_entete*) ((char*)ptr - ENTETE_SIZE);
  printf("pointeur bloc%p \n, pointeur donnees %p \n, taille totale: %d, \nbloc libre? %d\n",
  bloc_total,
  ptr
  bloc_total->taille,
  bloc_total->libre);
}

void test0()
{
  int i = 1;
  int* table_des_pointeurs[10]; 
  for(i = 0; i< 10; i++)
    { 
      int taille = (i+1)*sizeof(int);
      table_des_pointeurs[i] = myalloc(taille);
      printf("allocation de %d bytes à %p \n",taille,table_des_pointeurs[i]);
      int j ;
      for( j = 0; j < taille ; j++)
  {
    table_des_pointeurs[i][j] = taille-j;
  }  
      for( j = 0; j < taille ; j++)
  {
    assert( table_des_pointeurs[i][j] == taille-j);
  }
    }
  
  for(i = 0; i< 10; i++)
    {
      myfree(table_des_pointeurs[i]);
    }
 
}

void test2()
{
  static char* buffer_ptr = NULL;
  if(buffer_ptr == NULL)
    {
      buffer_ptr = myalloc(1024*sizeof(char));
      printf("allocation de 1024 bytes à %p \n",buffer_ptr);
      assert(buffer_ptr != NULL);
      bloc_info(buffer_ptr);
    }
  else
    {
      myfree(buffer_ptr);
    }
};
void test1()
{
  int i ;
  for(i = 10; i> 0; i--)
    { 
      int taille = i*sizeof(int);
      int* buffer = myalloc(taille);
      printf("allocation de %d bytes à %p \n",taille,buffer);
      int j ;
      for( j = 0; j< taille ; j++)
  {
    buffer[j] = taille-j;
  }  
      for( j = 0; j < taille ; j++)
  {
    assert(buffer[j] == taille-j);
  }
      myfree(buffer);
    }
}
int main(int argc, char* argv[])
{
  printf("[%s] lancee\n",argv[0]);
  test2();
  test1();
  test2();
  test0();
  printf("[%s] termine\n",argv[0]);
}
