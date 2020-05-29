#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "util\structs.h"

#include "menu.h"
#include "pedido.h"

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Request *request = (Request *)malloc(sizeof(Request));
	
	switch(menu()){
		case 1:
			request = createRequest();
			setRequest(request->client, request->order, request->payment);
			break;
		
		case 2:
			
			break;
		
		case 3:
			
			break;
		
		case 4:
			
			break;
		
	}
	
	printf("%s\n", request->client->name);
	printf("%s\n", request->client->telephone);
	printf("%s\n", request->client->address.street);
	printf("%d\n", request->client->address.number);
	printf("%d\n", request->order->hamburguer->id);
	printf("R$%3.2f\n", request->order->hamburguer->price);-
	printf("%d\n", request->payment->paymentMethod);
	
	getch();
	
	return 0;
}
