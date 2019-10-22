#include <stdio.h>
#include <stdlib.h>
#include "appli.h"
#include "etud.h"

/*
 * Variable globale qui contient la liste chainé etudiants
 */

Etud* pEtud;

int main (int argc, char* argv[]){
    printf(" === Scola === \n");
    id = 0;
    pEtud = malloc(sizeof *pEtud);

    print_menu();


    add_etud("BALIT", "Habib", 17);
	add_etud("LIZA", "BEL", 18);
	add_etud("Manel", "HFJ", 19);
	add_etud("Rouck", "R", 19);
    print_list();

    delete_etud(2);
    print_list();

    delete_etud(0);
    print_list();
    
    return 0; 
}
