#include "../generic/myalloc.h"
#include "myalloc-bloc-entete-0.h"
#include <stdio.h>

#include "myalloc-1.c.inc"
#include "myfree-1.c.inc"
#include "blocinfo-1.c.inc"

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
	bloc_entete* bloc_tot=(bloc_entete*) ((char*)ptr - ENTETE_SIZE);
	printf("pointeur bloc%p \n, pointeur donnees %p \n, taille totale: %d, \nbloc libre? %d\n",
	bloc_tot,
	ptr
	bloc_tot->taille,
	bloc_tot->libre);
}
