#include <stdlib.h>
#include <stdio.h>

#include "ordem.h"
#include "util\define.h"

Order *createOrder(){
	Order *order = (Order *)malloc(sizeof(Order));
	
	order->hamburguerQtd = 0;
	order->drinkQtd = 0;
	
	order->hamburguer = NULL;
	order->drink = NULL;
	
	return order;
}

Hamburguer *createHamburguer(Order *order){
	Hamburguer *hamburguer = (Hamburguer *)malloc(sizeof(Hamburguer));
	
	setHamburguerInfo(order, hamburguer);
	
	return hamburguer;
}

Drink *createDrink(Order *order){
	Drink *drink = (Drink *)malloc(sizeof(Drink));
	
	setDrinkInfo(order, drink);
	
	return drink;
}

int setHamburguerInfo(Order *order, Hamburguer *hamburguer){
	
	hamburguer->id = 0;
	hamburguer->price = 0.0;
	hamburguer->burguerConditionId = 0;
	
	hamburguer->next = NULL;
	hamburguer->prev = NULL;
	
	return 0;
}

int setDrinkInfo(Order *order, Drink *drink){
	
	drink->id = setDrinkID(drink);
	drink->price = 0.0;
	
	drink->next = NULL;
	drink->prev = NULL;
	
	return 0;
}

int setDrinkID(Drink *drink){
	char tmpStr[10];
	unsigned int id;
	
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

float setDrinkPrice(unsigned short int drinkId){
	
	switch(drinkId){
		case COKE:
			
			break;
			
		case GUARANA:
			break;
			
		case NO_DRINK:
			break;
	}
	
}

