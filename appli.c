#include "appli.h"
#include "etud.h"
#include <stdlib.h>


int lire_choix ()
{
  int choix;
  do{
        printf("Saisir un choix : ");
        fscanf (stdin, "%d", &choix);
  }while(choix < 0 || choix > 5);
  
  return choix;
}

void print_menu ()
{
    char nom[10], prenom[10];
    float note;
    int num, choix;

    while(1){
        printf (" 1) Afficher la liste      \n");
        printf (" 2) Ajouter un etudiant    \n");
        printf (" 3) Supprimer un etudiant  \n");
        printf (" 4) Rechercher un etudiant \n");
        printf (" 5) Afficher la moyenne    \n");
        printf (" 0) Quitter    \n");

        choix = lire_choix();

        switch (choix){
            case 0:
                printf("Good Bay  |-_-|     -_^       (;\n");
                return;

            case 1:
                print_list();
                break;

            case 2:
                printf("Nom de l'étudiant : ");
                fscanf(stdin, "%s", nom);

                printf("Prénom de l'étudiant : ");
                fscanf(stdin, "%s", prenom);

                printf("Note de l'étudiant : ");
                fscanf(stdin, "%f", &note);
                
                add_etud(nom, prenom, note, -1);
                break;

            case 3:
                printf("Numéro de l'étudiant : ");
                fscanf(stdin, "%d", &num);
                delete_etud(num);
                break;

            case 4:
                printf("Numéro de l'étudiant : ");
                fscanf(stdin, "%d", &num);
                Etud *etud = find_etud(num);
                if(etud == NULL)
                    printf("La liste d'etudiants est vide ou l'élèment n'existe pas.\n");
                else
                    printf("l'étudiant est trouvé : %s, %s, %d, %.2f\n", etud->nom, etud->prenom, etud->num, etud->note);

                break;

            case 5:
                printf("moyenne : %.2f\n", average());
                break;
        }
    }
}
