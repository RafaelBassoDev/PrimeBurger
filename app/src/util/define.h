#ifndef DEFINE_H
#define DEFINE_H

// Client options

#define STRING_MAX_NAME_LENGHT 70
#define STRING_MAX_ADDRESS_STREET_LENGTH 70
#define STRING_MAX_ADDRESS_REFERENCE_LENGHT 140
#define STRING_MAX_TELEPHONE_NUMBER_LENGHT 16

// Menu options

#define MENU_OPTIONS 4

// Order options

#define STRING_MAX_BURGUER_PREFERENCES_LENGTH 140

enum drinkId {
	COKE = 1,
	GUARANA,
	NO_DRINK
};

enum hamburguerId {
	PRIME_DUPLO = 1,
	SALAD_BURGUER,
	PRIME_BURGUER,
	PRIME_BARBECUE,
	NO_HAMBURGUER
};

// Payment options

enum paymentId {
	CREDIT,
	DEBIT,
	MONEY
};

#endif
