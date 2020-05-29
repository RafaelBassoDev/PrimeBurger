#ifndef CLIENTE_H
#define CLIENTE_H

#include "util\define.h"
#include "util\structs.h"

Client *createClient(void);

int setClientInfo(Client *);

int setClientName(Client *);

int setClientTelephone(Client *);

int setClientNeighborhood(Client *);

int setClientStreet(Client *);

int setClientNumber(Client *);

int setClientAddressReference(Client *);

int drawNeighborhoodPrices(void);

#endif
