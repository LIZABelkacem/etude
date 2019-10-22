#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appli.h"
#include "etud.h"

/*
 * Variable globale qui contient la liste chainé etudiants
 */

Etud* pEtud;

int main (int argc, char* argv[]){

    char* fileName = "list_etud.csv";
    id = 0;
    
    printf(" === Scola === \n");
    
    pEtud =  malloc(sizeof *pEtud);

    load(fileName);
    
    print_menu();

    save(fileName);

    /*print_list();

    add_etud("BALIT", "Habib", 17, -1);
	add_etud("LIZA", "BEL", 18, -1);
	add_etud("Manel", "HFJ", 19, -1);
	add_etud("Rouck", "R", 19, -1); 
	add_etud("rahim", "R", 19, -1);
	add_etud("abdrahim", "R", 19, -1); 

    print_list();

    delete_etud(2);

    printf("Average :%.2f\n", average()); 

    setNote(3, 9);
    print_list();


    find_etud_by_name("rahim");*/
    
    return 0; 
}
