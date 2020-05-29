#ifndef ORDEM_H
#define ORDEM_H

#include "util\define.h"
#include "util\structs.h"

Order *createOrder(void);

Hamburguer *createHamburguer(Order *);

Drink *createDrink(Order *);

int setHamburguerInfo(Order *, Hamburguer *);

int setDrinkInfo(Order *, Drink *);

int setDrinkID(Drink *);

int setDrinkPrice(Drink *, unsigned short int drinkId);

int setHamburguerID(Hamburguer *);

float setHamburguerPrice(Hamburguer *);

int setHamburguerCondition(Hamburguer *);

int setHamburguerPreferences(Hamburguer *);

#endif
