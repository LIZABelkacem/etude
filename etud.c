#include "etud.h"
#include <stdlib.h>
#include <string.h>
#define SIZE_MAX 1000

int add_etud(char* nom, char* prenom, float note, int num){
	if(pEtud == NULL)
		return -1;

	Etud* newEtud = malloc(sizeof *newEtud);
	strcpy(newEtud->nom, nom);
	strcpy(newEtud->prenom, prenom);
	newEtud->num = (num == -1)? id++ : num;
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

	return currentEtud;
}


float average(){
	Etud* etud = pEtud->next;
	float average = 0.0;
	int count = 0;
	if (pEtud == NULL)
		return 0.0;
	while(etud != NULL){
		count++;
		average += etud->note;
		etud = etud->next;
	}
	return average / (float)count;
}



int setNote(int num, float note){
	Etud* etud = find_etud(num);
	if(etud == NULL)
		return -1;

	etud->note = note;
	return 0;
}


void save(){
	FILE* fichier = NULL;

    fichier = fopen("list_etud.csv", "w");

    if (fichier != NULL)
    {
    	printf("Saving ...\n");
    	Etud* etud = pEtud->next;
		while(etud != NULL){
			fprintf(fichier, "%s,%s,%d,%.2f\n", etud->nom, etud->prenom, etud->num, etud->note);
			etud = etud->next;
		}
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}

void load(char* fileName){
	FILE* fichier = NULL;

    fichier = fopen("list_etud.csv", "a+");

    if (fichier != NULL)
    {
    	printf("Loading ...\n");
    	//Etud* etud = pEtud->next;
    	char line[SIZE_MAX];
    	char* token;
		char *nom, *prenom;
		int num;
		float note;
		while(fgets(line, SIZE_MAX, fichier) != NULL){
			printf("%s", line);
			Etud* etud = malloc(sizeof *etud);
			token = strtok(line, ",");
			nom = token;

			token = strtok(NULL, ",");
			prenom = token;

			token = strtok(NULL, ",");
			num = atoi(token);

			token = strtok(NULL, ",");
			note = strtod(token, NULL);

			add_etud(nom, prenom, note, num);
			//fprintf(fichier, "%s,%s,%d,%.2f\n", etud->nom, etud->prenom, etud->num, etud->note);
			//etud = etud->next;
		}
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }

}

int find_etud_by_name(char* nom){
	Etud *currentEtud, *lastEtud;
	int count = 0;
	if(pEtud == NULL)
		return -1;

	lastEtud = currentEtud;
	currentEtud = pEtud->next;
	
	while( currentEtud->next != NULL){
		char* pch = strstr(currentEtud->nom, nom);
		if(pch != NULL){
			printf("%s, %s, %d, %.2f\n", currentEtud->nom, currentEtud->prenom, currentEtud->num, currentEtud->note);
			count++;
		}
		lastEtud = currentEtud;
		currentEtud = currentEtud->next;
	}

	return count;
}