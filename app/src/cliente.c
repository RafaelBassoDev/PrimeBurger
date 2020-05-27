#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cliente.h"

int setClientInfo(Client *client){
		
	setClientName(client);
	setClientTelephone(client);
	
	setClientNeighborhood(client);
	setClientStreet(client);
	setClientNumber(client);
	setClientAddressReference(client);
	
}

int updateClientInfo(Client *client){
	char tmpStr[5];
	unsigned short int choice;
	
	do{
		system("cls");
				
		printf("Alteracao de dados:\n\n");
		printf("<1> Nome\n");
		printf("<2> Telefone\n");
		printf("<3> Endereco");
		printf("> ");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &choice);
		}
	} while(choice < 1 || choice > 3);
	
	switch(choice){
		case 1:
			setClientName(client);
			break;
			
		case 2:
			setClientTelephone(client);
			break;
			
		case 3:
			do{
				system("cls");
				
				printf("Alteracao de dados:\n\n");
				printf("Endereço:\n");
				printf("<1> Bairro\n");
				printf("<2> Rua\n");
				printf("<3> Numero\n");
				printf("<4> Referência\n");
				printf("> ");
				
				fflush(stdin);
				if(fgets(tmpStr, sizeof(tmpStr), stdin)){
					sscanf(tmpStr, "%d", &choice);
				}
			} while(choice < 1 || choice > 4);
			
			switch(choice){
				case 1:
					setClientNeighborhood(client);
					break;
					
				case 2:
					setClientStreet(client);
					break;
					
				case 3:
					setClientNumber(client);
					break;
					
				case 4:
					setClientAddressReference(client);
					break;
			}
			
			break;
	}

	
}

int setClientName(Client *client){
	char tmpStr[STRING_MAX_NAME_LENGHT];
	
	fflush(stdin);
	
	do{
		system("cls");
		printf("Nome do Cliente:\n> ");
		fgets(tmpStr, sizeof(tmpStr), stdin);
	} while(strlen(tmpStr) < 3);
	
	strcpy(client->name, tmpStr);

	return 0;
}

int setClientTelephone(Client *client){
	char tmpStr[STRING_MAX_TELEPHONE_NUMBER_LENGHT];
	unsigned short int jumpFlag = 0;
	
	do{
		system("cls");
		printf("Telefone do Cliente ('...' para pular):\n> ");
		
		fflush(stdin);
		fgets(tmpStr, sizeof(tmpStr), stdin);
		
		if(strncmp(tmpStr, "...", 3) == 0){
			jumpFlag = 1;
		}
		
	} while(strlen(tmpStr) < 3);
	
	if(!jumpFlag){
		strcpy(client->telephone, tmpStr);
	} else {
		strcpy(client->telephone, " ");
	}
	
	return 0;
}

int setClientNeighborhood(Client *client){
	char tmpStr[5];
	unsigned short int neighborhood=0;
	
	do{
		system("cls");
		
		drawNeighborhoodPrices();
		
		printf("\nBairro do Cliente:\n> ");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &neighborhood);
		}
		
	} while(neighborhood < 0 || neighborhood > 60);

	client->address.neighborhood = neighborhood;

	return 0;
}

int setClientStreet(Client *client){
	char tmpStr[STRING_MAX_ADDRESS_STREET_LENGTH];
	
	fflush(stdin);
	
	do{
		system("cls");
		printf("Rua do Cliente:\n> ");
		fgets(tmpStr, sizeof(tmpStr), stdin);
	} while(strlen(tmpStr) < 3);
	
	strcpy(client->address.street, tmpStr);

	return 0;
}

int setClientNumber(Client *client){
	char tmpStr[10];
	unsigned int number;
	
	do{
		system("cls");
				
		printf("Num. da rua do Cliente:\n> ");
		
		fflush(stdin);
		if(fgets(tmpStr, sizeof(tmpStr), stdin)){
			sscanf(tmpStr, "%d", &number);
		}
		
	} while(number < 0 || number > 99999999);

	client->address.number = number;

	return 0;
}

int setClientAddressReference(Client *client){
	char tmpStr[STRING_MAX_ADDRESS_REFERENCE_LENGHT];
	
	fflush(stdin);
	
	do{
		system("cls");
		printf("Ponto de referencia do Cliente:\n> ");
		fgets(tmpStr, sizeof(tmpStr), stdin);
	} while(strlen(tmpStr) < 3);
	
	strcpy(client->address.addressReference, tmpStr);

	return 0;
}

int drawNeighborhoodPrices(){
	unsigned short int i;
	char neighborhoods[][35] = {
	"Alto Belvedere",
	"Alto dos Cerrados",
	"Bahia Farm show",
	"Boa Vista",
	"Boates",
	"Bosque dos Girassóis",
	"Bosque dos Ipês II",
	"Bosque dos Ipês",
	"BR 020, Altura Rio das Pedras",
	"Buritis",
	"Campos Elíseos",
	"Central Park",
	"Centro",
	"Cidade Alta",
	"Cidade do Automóvel",
	"Cidade Universitária II",
	"Cidade Universitária",
	"Complexo Bahia Farm Show",
	"Conquista",
	"Florais Léa",
	"Florais Léa II",
	"Florais Léa III",
	"Jardim Alvorada",
	"Jardim das Acácias",
	"Jardim das Oliveiras",
	"Jardim Imperial",
	"Jardim Ipê",
	"Jardim Paraiso",
	"Jardim Paraíso Fase I",
	"Jardim Paraíso Fase II",
	"Jardim Paraíso Fase III",
	"Jardim Primavera",
	"Jardim Sol Nascente",
	"JK",
	"Luar do Cerrado",
	"Luar do Oeste",
	"Mimoso I",
	"Mimoso II",
	"Mimoso III",
	"Nova Barreiras",
	"Nova Brasília",
	"Novo Horizonte",
	"Novo Paraíso",
	"Parque São José",
	"Posto 020",
	"Posto Imperador",
	"Residencial 90",
	"Rio de Pedras",
	"Santa Cruz I",
	"Santa Cruz II",
	"Santa Cruz III",
	"Setor Industrial",
	"Sol do Cerrado",
	"Texana",
	"Tropical Ville",
	"Tropical Ville 2",
	"Vale do Amanhecer",
	"Verde Vida",
	"Vereda Tropical",
	"Vila da Bunge",
	"Vista Alegre" };
	
	printf("                                  Tabela de Bairros\n\n");
	for(i=0; i < 31; i++){
		if(i != 30){
			printf("<%2d> %-35s  |  <%1d> %-35s\n", i, neighborhoods[i], i+31, neighborhoods[i+31]);
		} else {
			printf("<%2d> %-35s  |\n", i, neighborhoods[i]);
		}
	}

	
	return 0;
}
