#include <stdio.h>

typedef struct etud
{
  unsigned int num;
  char  nom[50];
  char  prenom[50];
  float note;
  struct etud* next;
}Etud;


/*
 * variable global externe
 */

extern Etud* pEtud;
int id;

/**
 *
 */
void print_list();


/**
 *
 */
int add_etud(char* nom, char* prenom, float note);


/**
 *
 */
int lire_choix();



/**
 *
 */
int delete_etud(int num);


/**
 *
 */

float average();
