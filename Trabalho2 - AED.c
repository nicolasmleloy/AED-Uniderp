#include <stdio.h>
#include <stdlib.h>

struct Banco{
	int numero_conta;
	char nome_cliente[30];
	float saldo;
	struct Banco* proximo;
};
typedef struct Banco node;

void inserir(node* CABECA){
	node* novo = (node*) malloc(sizeof(node));
	if(!novo){
		printf("Espaco nao alocado");
	}
	
	printf("Inserindo...\n\n");
	printf("Informe o numero da conta: \n");
	scanf("%d", &novo->numero_conta);
	printf("Informe o nome do cliente: \n");
	scanf("%s", novo->nome_cliente);
	printf("Informe o saldo do cliente: \n");
	scanf("%f", &novo->saldo);
	printf("\n");
	
	if(CABECA->proximo == NULL){
		CABECA->proximo = novo;
	}else{
		node* aux = CABECA->proximo;
		novo->proximo = aux;
		CABECA->proximo = novo;
	}
}

void remover(node* CABECA){ //ARRUMAR TUDO
	if(CABECA->proximo == NULL){
		printf("Lista vazia, nao ha nada a remover\n");
	}else{
		printf("Removendo node da lista...\n");
		printf("Informe o node a ser removido: ");
		int node_a_ser_removido;
		scanf("%d", &node_a_ser_removido);
		
		node* aux1 = CABECA->proximo;
		node* aux2 = aux1->proximo;
		
		while(aux1 != NULL && aux2->numero_conta != node_a_ser_removido){
			aux1 = aux2;
			aux2 = aux2->proximo;
			
			aux1->proximo = aux2->proximo;
			
			free(aux2);
			printf("Remocao feita com sucesso");
		}
	}
}

void imprimir(node* CABECA){
	if(CABECA->proximo == NULL){
		printf("Lista vazia!\n");
	}else{
		printf("\nImprimindo lista...\n");
		node* aux = CABECA->proximo;
		while(aux != NULL){
			printf("\n----------------------\n");
			printf("Conta do cliente: %d\n", aux->numero_conta);
			printf("Nome do cliente: %s\n", aux->nome_cliente);
			printf("Saldo do cliente: %.2f\n", aux->saldo);
			printf("Endereco do node: %x ", &aux); //ARRUMAR
			printf("Endereco do node next: %x\n", &aux->proximo);//ARRUMAR
			printf("\n----------------------\n");
			
			aux = aux->proximo;
		}
	}
}

int main(){
	int opcao;
	
	node* CABECA = (node*) malloc(sizeof(node));
	if(!CABECA){
		printf("Cabeca da lista não alocado\n");
	}
	CABECA->proximo = NULL;
	
	do{
		printf("Escolha a opcao\n");
		printf("0. Sair\n");
		printf("1. Exibir lista\n");
		printf("2. Adicionar node\n");
		printf("3. Remove node da lista\n");
		
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0: 
				printf("\nSaindo...");
				break;
			case 1:
				imprimir(CABECA);
				break;
			case 2:
				inserir(CABECA);
				break;
			case 3:
				remover(CABECA);
				break;
			default:
				printf("Opcao invalida, digite novamente:\n");
				break;
		}
		
	}while(opcao != 0);
	
	return 0;
}
