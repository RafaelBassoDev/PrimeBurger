#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "util\define.h"

int menu(){
	
	drawMenu();
	
	return getMenuOption(MENU_OPTIONS);
}

int drawMenu(){
	
	system("cls");
	
	printf("     +- PRIME BURGUER -+\n\n");
	
	printf("    <1> CADASTRAR ORDEM\n");
	printf("    <2> EDITAR ORDEM\n");
	printf("    <3> RETIRAR ORDEM\n");
	printf("    <4> VER ORDENS\n");
	
	printf("\n> ");
	
	return 0;
}

int getMenuOption(int optionsQnt){
	int option=0;
	char str[10];
	
	do{

		if(fgets(str, sizeof(str), stdin)){
			if(sscanf(str, "%d", &option) == 1){
				if(option < 1 || option > optionsQnt){
					drawMenu();
				} else {
					system("cls");
				}
			} else {
				option = 0;
			}
		}
		
	}while(option < 1 || option > optionsQnt);
	
	return option;
}
