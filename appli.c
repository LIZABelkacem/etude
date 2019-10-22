#include "appli.h"
#include "etud.h"


int choix = 0;

int lire_choix(){
        
	//do{
	  
	  printf("dsfsdfsdfsdfsdfsdf");
	  scanf(" %d ", &choix);
	  printf("dsfsdfsdfsdfsdfsdf");
	//}while (choix == 1);   
	return choix;
}

void print_menu(){
  printf("\n 1) Afficher la liste      \n");
  printf(" 2) Ajouter un etudiant    \n");
  printf(" 3) Supprimer un etudiant  \n");
  printf(" 4) Rechercher un etudiant \n");
  printf(" 5) Afficher la moyenne    \n");
  printf("\n Saisir un choix :       \n");
 	
 
  scanf("%d", &choix);

 
    

  char nom[10];
  char prenom[10];
  float note;
  int num;
  
  if(choix==1 || choix==2 || choix ==3 || choix ==4 || choix==5) {

  switch (choix) {
  case 1:
  	print_list();
  	break;

  case 2:
  	
  	printf("Nom de l'étudiant : ");
  	scanf("%s", nom);
  	printf("Prénom de l'étudiant : ");
  	scanf("%s", prenom);
  	printf("Note de l'étudiant : ");
  	scanf("%f", &note);	
  	add_etud(nom, prenom, note);
  	break;

  case 3:
  	
  	printf("Numéro de l'étudiant : " ) ;
  	scanf("%d", &num);
  	delete_etud(num);
  	break;

  case 4:
  	printf("Numéro de l'étudiant : " ) ;
  	scanf("%d", &num);
        Etud* etud = find_etud(num);
  	break;

  case 5:
        average();
  	break;

  } }else { printf("\n Mauvais nombre. Réessayez. \n");

           print_menu();


}
}


