#include "etud.h"
#include <stdlib.h>
#include <string.h>

int add_etud(char* nom, char* prenom, float note){
	Etud* newEtud = malloc(sizeof *newEtud);
	strcpy(newEtud->nom, nom);
	strcpy(newEtud->prenom, prenom);
	newEtud->num = id++;
	newEtud->note = note;
	newEtud->next = pEtud->next;
	pEtud->next = newEtud;
  return 0;
}


void print_list(){
  printf(" Liste des etudiants \n ");
  Etud* etud = pEtud->next;
  printf("----------------\n");
  while(etud != NULL){
  	printf("Nom : %s \nPrenom : %s \nNum : %d \nNote : %.2f \n", etud->nom, etud->prenom, etud->num, etud->note);
  	printf("----------------\n");
  	etud = etud->next;
  }
}

int delete_etud(int num){
	Etud *currentEtud, *lastEtud;

	if(pEtud == NULL)
		return -1;

	lastEtud = currentEtud;
	currentEtud = pEtud->next;

	while(currentEtud->num != num){
		lastEtud = currentEtud;
		currentEtud = currentEtud->next;
	}

	if(currentEtud == NULL)
		return 1;

	lastEtud->next = currentEtud->next;
	free(currentEtud);
	return 0;
}

Etud* find_etud(int num){
	Etud *currentEtud, *lastEtud;
	
	if(pEtud == NULL)
		return NULL;

	lastEtud = currentEtud;
	currentEtud = pEtud->next;

	while(currentEtud->num != num){
		lastEtud = currentEtud;
		currentEtud = currentEtud->next;
	}

	if(currentEtud == NULL)
		return NULL;

	return lastEtud->next;
}
