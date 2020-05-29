#ifndef PEDIDO_H
#define PEDIDO_H

#include "define.h"

typedef struct address{
	unsigned short int neighborhood;
	unsigned int number;
	char street[STRING_MAX_ADDRESS_STREET_LENGTH];
	char addressReference[STRING_MAX_ADDRESS_REFERENCE_LENGHT];
}Address;

typedef struct client{
	char name[STRING_MAX_NAME_LENGHT];
	char telephone[STRING_MAX_TELEPHONE_NUMBER_LENGHT];
	Address address;
}Client;

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

typedef struct payment{
	unsigned short int paymentMethod;
	float change;
} Payment;

typedef struct request {
	Client *client;
	Order *order;
	Payment *payment;
} Request;

#endif
