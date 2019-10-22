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
int add_etud(char* nom, char* prenom, float note, int num);


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
Etud* find_etud(int num);

/**
 *
 */
int find_etud_by_name(char* nom);

/**
 *
 */
float average();

/**
 *
 */
int setNote(int num, float note);

/**
 *
 */
void save();

/**
 *
 */
void load(char* fileName);