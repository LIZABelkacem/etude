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
*\biref ajouter un étudiant 
*\param : char*
*\param : char*
*\param : float 
*\return : int

*/

int add_etud(char* nom, char* prenom, float note); 


/**
*\brief afficher la liste des étudiants 
*/
void print_list() ;



/**
*\brief supprimer un étudiant 
*\param: int
*\ return : int  -1 si la liste est vide , 1 s'il n'a pas trouvé l'élément saisi  , 0 sinon   et au même temps elle supprime l'élément 

*/ 
int delete_etud(int num)


/**
*\brief recherhcer un étudiant 
*\param: int
*\ return : Etud* les informations relatives au numéro de l'étudiant tappé par l'utilisateur 

*/ 
Etud* find_etud(int num)







