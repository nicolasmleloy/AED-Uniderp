//Trabalho 04 - AED
#include <stdio.h>
#include <string.h>

int main(){
	char letras[100];
	printf("Informe o texto a ser compactado: \n");
	scanf("%s", letras);
	
	int compactado = 0; //Para contar o tamanho depois de compactado e fazer o caluculo
	int cont = 0;
	int qtd = 1;
	
	printf("\nTexto apos a compactacao: \n");
	while(cont < strlen(letras)){
		if(letras[cont] == letras[cont + 1]){
			while(letras[cont] == letras[cont + 1]){
				cont++;
				qtd++;
			}
			if(qtd < 10){ //Se a qtd for uma unidade
				compactado += 2; // A qtd e a letra (Ex: 3B)
			}else if(qtd >= 10 && qtd < 100){ // Se a qtd for unidade de dezena
				compactado += 3;
			}else{ // Se qtd do caracter se repetir 100 vezes
				compactado += 4;
			}
			printf("%d%c", qtd, letras[cont]);
			qtd = 1;
			
		}else{
			printf("%c", letras[cont]);
			qtd = 1;
			compactado++;
		}
		
		cont++;
	}
	
	float reducao = 100.0 - ((compactado * 100.0) / cont); // Utilizei o contador para determinar o tamanho e calcular
	printf("\n\nApos a compactacao obteve-se uma reducao de %.2f%%", reducao);
	
	return 0;
}
