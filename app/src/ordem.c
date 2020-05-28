#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ordem.h"
#include "util\define.h"

Order *createOrder(){
	Order *order = (Order *)malloc(sizeof(Order));
	
	if(order != NULL){
		order->hamburguerQtd = 0;
		order->drinkQtd = 0;
		
		order->hamburguer = NULL;
		order->drink = NULL;
		
		return order;
	}
	

}

Hamburguer *createHamburguer(Order *order){
	Hamburguer *hamburguer = (Hamburguer *)malloc(sizeof(Hamburguer));
	
	if(hamburguer != NULL){
		setHamburguerInfo(order, hamburguer);
		
		hamburguer->next = NULL;
		hamburguer->prev = NULL;
		
		if(hamburguer->id == NO_HAMBURGUER){
			free(hamburguer);
			return NULL;
		} else {
			order->hamburguerQtd++;
			return hamburguer;
		}
	}
	
}

Drink *createDrink(Order *order){
	Drink *drink = (Drink *)malloc(sizeof(Drink));
	
	if(drink != NULL){
		setDrinkInfo(order, drink);
		
		drink->next = NULL;
		drink->prev = NULL;
		
		if(drink->id == NO_DRINK){
			free(drink);
			return NULL;
		} else {
			order->drinkQtd++;
			return drink;
		}
	}
	
	
}

int setHamburguerInfo(Order *order, Hamburguer *hamburguer){
	
	setHamburguerID(hamburguer);
	setHamburguerPrice(hamburguer->id);
	setHamburguerCondition(hamburguer);
	setHamburguerPreferences(hamburguer);
	
	return 0;
}

int setDrinkInfo(Order *order, Drink *drink){
	
	setDrinkID(drink);
	setDrinkPrice(drink, drink->id);
	
	return 0;
}

int setDrinkID(Drink *drink){
	char tmpStr[10];
	unsigned short int id;
	
	do{
		system("cls");
				
		printf("Bebida:\n\n");
		printf("<1> Coca-Cola\n");
		printf("<2> Guarana\n");
		printf("<3> Sem bebida\n");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &id);
		}
		
	} while(id < 1 || id > 3);
	
	drink->id = id;
	
	return 0;
}

int setDrinkPrice(Drink *drink, unsigned short int drinkId){
	float price;
	
	switch(drinkId){
		case COKE:
			price = 3.50;
			break;
			
		case GUARANA:
			price = 3.50;
			break;
			
		case NO_DRINK:
			price = 0.0;
			break;
	}
	
	drink->price = price;
	
	return 0;
}

int setHamburguerID(Hamburguer *hamburguer){
	char tmpStr[10];
	unsigned short int id;
	
	do{
		system("cls");
				
		printf("Hamburguer:\n\n");
		printf("<1> Prime Duplo\n");
		printf("<2> Salad Burguer\n");
		printf("<3> Prime Burguer\n");
		printf("<4> Prime barbecue\n");
		printf("<5> Sem hamburguer\n");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &id);
		}
		
	} while(id < 1 || id > 5);
	
	hamburguer->id = id;
	
	return 0;
}

float setHamburguerPrice(unsigned short int hamburguerId){
	
	switch(hamburguerId){
		case PRIME_DUPLO:
			return 19.99;
			break;
			
		case SALAD_BURGUER:
			return 15.99;
			break;
			
		case PRIME_BURGUER:
			return 11.99;
			break;
		
		case PRIME_BARBECUE:
			return 13.99;
			break;
		
		case NO_HAMBURGUER:
			return 0.0;
			break;
	}
	
}

int setHamburguerCondition(Hamburguer *hamburguer){
	char tmpStr[10];
	unsigned short int condition;
	
	do{
		system("cls");
				
		printf("Ponto do hamburguer:\n\n");
		printf("<1> Mal\n");
		printf("<2> Mal-Ponto\n");
		printf("<3> Ponto\n");
		printf("<4> Medio-Bem\n");
		printf("<5> Bem\n");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &condition);
		}
		
	} while(condition < 1 || condition > 5);
	
	hamburguer->burguerConditionId = condition;
	
	return 0;
}

int setHamburguerPreferences(Hamburguer *hamburguer){
	char tmpStr[STRING_MAX_BURGUER_PREFERENCES_LENGTH];
	unsigned short int jumpFlag = 0;
	
	do{
		system("cls");
		printf("Preferencias do Hamburguer ('...' para pular):\n> ");
		
		fflush(stdin);
		fgets(tmpStr, sizeof(tmpStr), stdin);
		
		if(strncmp(tmpStr, "...", 3) == 0){
			jumpFlag = 1;
		}
		
	} while(strlen(tmpStr) < 3);
	
	if(!jumpFlag){
		strcpy(hamburguer->clientPreferences, tmpStr);
	} else {
		strcpy(hamburguer->clientPreferences, " ");
	}
	
	return 0;
}
