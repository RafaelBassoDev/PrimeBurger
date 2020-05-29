#ifndef PEDIDO_H
#define PEDIDO_H

#include "util\define.h"
#include "util\structs.h"

Request *createRequest(void);

int setRequest(Client *, Order *, Payment *);

int setClientRequest(Client *);

int setHamburguerRequest(Order *);

int setDrinkRequest(Order *);

int setPaymentRequest(Payment *);

#endif
