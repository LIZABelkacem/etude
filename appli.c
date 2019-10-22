#include "appli.h"


void print_menu(){
  printf(" 1) Afficher la liste      \n");
  printf(" 2) Ajouter un etudiant    \n");
  printf(" 3) Supprimer un etusiant  \n");
  printf(" 4) Afficher la moyenne    \n");
  printf("\n Saisir un choix :       \n");
  int choix = lire_choix();

  switch (choix) {
  case 1:
  print_list();
  break;

  case 2:
  char nom;
  char prenom;
  float note;
  printf("Nom de l'étudiant : ");
  scanf("%s", nom);
  printf("Prénom de l'étudiant : ");
  scanf("%s", prenom);
  printf("Note de l'étudiant : ");
  scanf("%f", note);	
  add_etud(nom, prenom, note);
  break;

  case 3:
  int num;
  printf("Numéro de l'étudiant : " )
  scanf("%d", num)
  delete_etud(num);
  break;

  case 4:
  average();
  break;

}
}

int lire_choix(){
do{
  

  scanf(" %d ", &choix);
}
while (choix != 1 || choix != 2 || choix != 3 || choix != 4);   
}

