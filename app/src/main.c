#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menu.h"
#include "cliente.h"

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Client *client = createClient();
	
	
	switch(menu()){
		case 1:
			setClientInfo(client);
			break;
		
		case 2:
			updateClientInfo(client);
			break;
		
		case 3:
			
			break;
		
		case 4:
			
			break;
		
	}
	
	return 0;
}
