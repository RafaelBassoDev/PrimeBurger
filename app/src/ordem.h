#ifndef ORDEM_H
#define ORDEM_H

#include "util\define.h"

typedef struct hamburguer{
	unsigned short int id;
	float price;
	unsigned short int burguerConditionId;
	char clientPreferences[STRING_MAX_BURGUER_PREFERENCES_LENGTH];
	
	struct hamburguer *next;
	struct hamburguer *prev;
} Hamburguer;

typedef struct drink{
	unsigned short int id;
	float price;
	
	struct drink *next;
	struct drink *prev;
} Drink;

typedef struct order {
	unsigned short int hamburguerQtd;
	unsigned short int drinkQtd;
	Hamburguer *hamburguer;
	Drink *drink;
} Order;

Order *createOrder();

Hamburguer *createHamburguer(Order *order);

Drink *createDrink(Order *order);

int setHamburguerInfo(Order *order, Hamburguer *hamburguer);

int setDrinkInfo(Order *order, Drink *drink);

int setDrinkID(Drink *drink);

int setDrinkPrice(Drink *drink, unsigned short int drinkId);

int setHamburguerID(Hamburguer *hamburguer);

float setHamburguerPrice(unsigned short int hamburguerId);

int setHamburguerCondition(Hamburguer *hamburguer);

int setHamburguerPreferences(Hamburguer *hamburguer);

#endif
