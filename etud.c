#include "etud.h"
#include <stdlib.h>
#include <string.h>

/**
 *ydgd
 *dhgc
 */

/**
 *\brief ajouter un étudiant 
 *\param : char*
 *\param : char*
 *\param : float 
 *\return : int  0 si la liste est vide  1 sinon 
 */

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

/**
*\brief afficher la liste des étudiants 
*/

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
/**
*\brief supprimer un étudiant 
*\param: int
*\ return : int  -1 si la liste est vide , 1 s'il n'a pas trouvé l'élément saisi  , 0 sinon   et au même temps elle supprime l'élément 

*/

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

/**
*\brief recherhcer un étudiant 
*\param: int
*\ return : Etud* les informations relatives au numéro de l'étudiant tappé par l'utilisateur 

*/ 

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



git status 
git add si ajouter un fichier
git commit -m "msg" pour commiter
git push 