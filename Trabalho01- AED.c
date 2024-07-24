#include <stdio.h>

// Criando a struct Aluno
struct Aluno{ 
	char nome[50];
	int matricula;
	float nota1, nota2;
};

// Implementando a fun��o cadastrarAluno: solicita ao usu�rio informa��es de um aluno
struct Aluno cadastrarAluno() {
	struct Aluno cadastroDoAluno;
	
	printf("Nome do aluno: ");
	scanf("%s", cadastroDoAluno.nome);
	
	printf("Matricula: ");
	scanf("%d", &cadastroDoAluno.matricula);
	
	printf("Nota 1: ");
	scanf("%f", &cadastroDoAluno.nota1);
	
	printf("Nota 2: ");
	scanf("%f", &cadastroDoAluno.nota2);
	printf("\n");
	
	return cadastroDoAluno;
}

// Implementando a fun��o calcularMedia
float calcularMedia(struct Aluno mediaDoAluno) {
	return (mediaDoAluno.nota1 + mediaDoAluno.nota2) / 2;
}

// Implementando a fun��o imprimirAluno: imprime os detalhes do aluno
void imprimirAluno(struct Aluno impressaoDoAluno, float media) {
	
	printf("Aluno: %s\n", impressaoDoAluno.nome);
	printf("Matricula: %d\n", impressaoDoAluno.matricula);
	printf("Nota 1: %.1f\n", impressaoDoAluno.nota1);
	printf("Nota 2: %.1f\n", impressaoDoAluno.nota2);
	printf("Media: %.1f\n\n", media);
}

int main() {
	// Declarando duas vari�veis do tipo Aluno
	struct Aluno aluno1, aluno2; 
	
	// Preenchendo as informa��es de cada aluno
	aluno1 = cadastrarAluno(); 
	aluno2 = cadastrarAluno(); 
	
	// Calculando a m�dia de cada aluno
	float mediaAluno1 = calcularMedia(aluno1); 
	float mediaAluno2 = calcularMedia(aluno2); 
	
	// Exibindo os detalhes de cada aluno na tela
	imprimirAluno(aluno1, mediaAluno1);
	imprimirAluno(aluno2, mediaAluno2);
	
	return 0;
}
