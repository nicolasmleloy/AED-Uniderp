#include <stdio.h>
#include <stdlib.h>

struct Banco{
    int numero_conta;
	char nome_cliente[30];
	float saldo;
	struct Banco *anterior;
	struct Banco *proximo;
};
typedef struct Banco node;

void adicionar(node* CABECA){
	node* novo = (node*) malloc(sizeof(node));
	if(!novo){
		printf("\nNode nao alocado! Sem espaço...\n");
		exit(1);
	}
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	printf("\nInserindo no!\n");
	printf("Informe o numero da conta: ");
	scanf("%d", &novo->numero_conta);
	
	if(novo->numero_conta <= 0 || novo->numero_conta > 99999){
		do{
			printf("\nNumero de conta invalido! Digite novamente: ");
			scanf("%d", &novo->numero_conta);
		}while(novo->numero_conta > 99999);
	}
	
	node* aux = CABECA->proximo;
	while(aux != NULL){
		if(aux->numero_conta == novo->numero_conta){
			printf("\nNumero de conta ja existe, nao foi possivel adiciona-lo!\n");
			free(novo);
			return;			
		}
		aux = aux->proximo;
	}
	
	printf("Informe o nome do cliente: ");
	scanf("%s", &novo->nome_cliente);
	printf("Informe o saldo do cliente: ");
	scanf("%f", &novo->saldo);	
	
	
	if(CABECA->proximo == NULL){
		CABECA->proximo = novo;
	}else{
		node* aux = CABECA->proximo;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
		novo->anterior = aux;
	}
}

void remover(node* CABECA){
	if(CABECA->proximo == NULL){
		printf("\nLista vazia!\n");
	}else{
		printf("\nRemovendo node da lista!\n");
		
		int conta_remover;
		printf("Informe o node a ser removido: ");
		scanf("%d", &conta_remover);
		
		node* aux = CABECA->proximo;
		while(aux != NULL && aux->numero_conta != conta_remover){
			aux = aux->proximo;
		}
		
		if(aux == NULL){
			printf("\nNode nao esta na lista!\n");
			return;
		}
		
		printf("-----------------------------------\n");
		printf("Node a ser removido: \n");
		printf("Conta do cliente: %d\n", aux->numero_conta);
		printf("Nome do cliente: %s\n", aux->nome_cliente);
		printf("Saldo do cliente: %.2f\n", aux->saldo);
		printf("Endereco do node: %d ", aux);
		printf("Endereco do node next: %d\n", aux->proximo);
		printf("-----------------------------------\n");
		
		if(aux->proximo == NULL && aux->anterior == NULL){
			CABECA->proximo = NULL;
			free(aux);
			printf("Removendo UNICO node da lista\n");
			printf("Node removido com sucesso!\n");
		}else if(aux->proximo != NULL && aux->anterior == NULL){
			CABECA->proximo = aux->proximo;
			node* aux2 = aux->proximo;
			aux2->anterior = NULL;
			free(aux);
			printf("Removendo PRIMEIRO node da lista\n");
			printf("Node removido com sucesso!\n");
		}else if(aux->proximo == NULL && aux->anterior != NULL){
			node* aux2 = aux->anterior;
			aux2->proximo = NULL;
			free(aux);
			printf("Removendo ULTIMO node da lista\n");
			printf("Node removido com sucesso!\n");
		}else{
			node* aux1 = aux->anterior;
			node* aux2 = aux->proximo;
			aux1->proximo = aux2;
			aux2->anterior = aux1;
			free(aux);
			printf("Removendo node do MEIO da lista\n");
			printf("Node removido com sucesso!\n");
		}
	}
}

void exibir(node* CABECA){
	if(CABECA->proximo == NULL){
		printf("\nLista vazia!\n");
	}else{
		printf("\nImprimindo a lista!\n");
		
		node* aux = CABECA->proximo;
		while(aux != NULL){
			printf("-----------------------------------\n");
			printf("Conta do cliente: %d\n", aux->numero_conta);
			printf("Nome do cliente: %s\n", aux->nome_cliente);
			printf("Saldo do cliente: %.2f\n", aux->saldo);
			printf("Endereco do node ant: %d\n", aux->anterior);
			printf("Endereco do node: %d\n", aux);
			printf("Endereco do node next: %d\n", aux->proximo);
			printf("-----------------------------------\n");	
			aux = aux->proximo;
		}	
	}
}

int main(){
    int opt = 0;
    
    node* CABECA = (node*) malloc(sizeof(node));
    if(!CABECA){
        printf("Sem espaco em memoria");
        exit(1);
    }
    
    CABECA->proximo = NULL;
    
    do{
    	printf("\n0- Sair\n");
        printf("1- Exibir lista\n");
        printf("2- Adicionar node\n");
        printf("3- Remove node da lista\n");
        printf("Opcao: ");
        scanf("%d", &opt);
        
        switch(opt){
            case 1:
                exibir(CABECA);
                break;
            case 2: 
                adicionar(CABECA);
                break;
            case 3:
            	remover(CABECA);
            	break;
            case 0: 
                printf("Encerrando..\n");
                break;
            default:
                printf("\nOpcao invalida...\n");
        }
        
    }while(opt != 0);
    
    return 0;
}
