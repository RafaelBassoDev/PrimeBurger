#include <stdlib.h>
#include <stdio.h>

#include "util\structs.h"

#include "pagamento.h"

Payment *createPayment(){
	Payment *payment = (Payment *)malloc(sizeof(Payment));
	
	if(payment != NULL){
		
		payment->change = 0.0;
		
		return payment;
	}
	
}

int setPaymentInfo(Payment *payment){
	
	setPaymentMethod(payment);
	
	if(payment->paymentMethod == 3){
		
	}
	
};

int setPaymentMethod(Payment *payment){
	char tmpStr[5];
	unsigned short int method;
	
	do{
		system("cls");
				
		printf("Forma de pagamento:\n\n");
		printf("<1> Crédito\n");
		printf("<2> Débito\n");
		printf("<3> Dinheiro\n\n> ");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &method);
		}
		
	} while(method < 1 || method > 3);
	
	payment->paymentMethod = method;
	
	return 0;
}

int setPaymentChangeValue(Payment *payment, float orderValue, float clientValue){
	
	payment->change =  clientValue - orderValue;
	
	return 0;
}

