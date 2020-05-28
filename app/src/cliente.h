#ifndef CLIENTE_H
#define CLIENTE_H

#include "util\define.h"

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

Client *createClient();

int setClientInfo(Client *client);

int setClientName(Client *client);

int setClientTelephone(Client *client);

int setClientNeighborhood(Client *client);

int setClientStreet(Client *client);

int setClientNumber(Client *client);

int setClientAddressReference(Client *client);

int drawNeighborhoodPrices();

#endif
