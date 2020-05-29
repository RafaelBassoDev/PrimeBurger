#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "util\define.h"
#include "util\structs.h"

Payment *createPayment(void);

int setPaymentInfo(Payment *);

int setPaymentMethod(Payment *);

int setPaymentChangeValue(Payment *, float orderValue, float clientValue);

#endif
