#include <stdlib.h>
#include <stdio.h>

#include "util\define.h"
#include "util\structs.h"

#include "pedido.h"
#include "ordem.h"
#include "pagamento.h"
#include "cliente.h"

Request *createRequest(){
	Request *request = (Request *)malloc(sizeof(Request));
	
	request->client = createClient();
	request->order = createOrder();
	request->payment = createPayment();
	
	return request;
}

int setRequest(Client *client, Order *order, Payment *payment){
	
	setClientRequest(client);
	setHamburguerRequest(order);
	setDrinkRequest(order);
	setPaymentRequest(payment);
	
	return 0;
}

int setClientRequest(Client *client){
	
	setClientInfo(client);
	
	return 0;
}

int setHamburguerRequest(Order *order){

	if(order->hamburguer == NULL){

		order->hamburguer = createHamburguer(order);
	} else {

		Hamburguer *th;
		
		th = order->hamburguer;
		
		while(th->next != NULL){
			th = th->next;
		}
		
		th->next = createHamburguer(order);
	}
	
	return 0;
}

int setDrinkRequest(Order *order){
	
	if(order->drink == NULL){
		order->drink = createDrink(order);
	} else {
		Drink *td;
		
		td = order->drink;
		
		while(td->next != NULL){
			td = td->next;
		}
		
		td->next = createDrink(order);
		
	}
	
	return 0;
}

int setPaymentRequest(Payment *payment){
	
	setPaymentInfo(payment);
	
	return 0;
}

//float getRequestPrice(Request *request){
//	float price=0.0;
//	
//	if(order.hamburguerQtd > 0){
//		
//	}
//	
//	if(order.drinkQtd > 0){
//		
//	}
//	
//	return price;
//			
//}
