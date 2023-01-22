#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int RA;
    char nomeArquivo[30];
    char extensaoArquivo[4];
    int matriculaProf;
    struct NO* prox;
}NO;

typedef struct FILA{
    struct NO* inicio;
    struct NO* fim;
} FILA;

FILA *f;

void imprimeFila(){
	struct NO *ptr = f->inicio;
	if(ptr == NULL){
		printf("FILA VAZIA.\n");
		return;
	} else {
		printf("Conteudo da Fila \n");
		while(ptr != NULL){
			printf("\nRA: %d ", ptr->RA);
			printf("\nNome Arquivo %d ", ptr->nomeArquivo);
			printf("\nExtensao do Arquivo  %d ", ptr->extensaoArquivo);
			printf("\nMatricula do professor %d\n", ptr->matriculaProf, "\n");
			ptr = ptr->prox;
		}
	}
}

void adicionaFila(int RA, char nomeArquivo, char extensaoArquivo, int matriculaProf){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->RA = RA;
	ptr->nomeArquivo = nomeArquivo;
	ptr->extensaoArquivo = extensaoArquivo;
	ptr->matriculaProf = matriculaProf;
	ptr->prox = NULL;
	if(f->inicio == NULL)
		f->inicio = ptr;
	else
		f->fim->prox = ptr;
	f->fim = ptr;
}

void removeElemento(){
	struct NO* ptr = f->inicio;
  	int RA, matriculaProf;
	char nomeArquivo, extensaoArquivo;
    if(ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        RA = ptr->RA;
        nomeArquivo = ptr->nomeArquivo;
        extensaoArquivo = ptr->extensaoArquivo;
        matriculaProf = ptr->matriculaProf;
        free(ptr);
    }
}

void esvaziaFila(){
	struct NO* ptr = f->inicio;
	int RA, matriculaProf;
	char nomeArquivo, extensaoArquivo;
	while(ptr != NULL){
		f->inicio = ptr->prox;
		ptr->prox = NULL;
		RA = ptr->RA;
        nomeArquivo = ptr->nomeArquivo;
        extensaoArquivo = ptr->extensaoArquivo;
        matriculaProf = ptr->matriculaProf;
		free(ptr);
	}
}
void encerra(){
	NO *ptr;
	NO *del;
	printf("Liberando o espaço da fila;\n");
	ptr = f->inicio;
	while(ptr != NULL){
		del = ptr;
		ptr = ptr->prox;
		free(del);
	}
	f->inicio = NULL;
	imprimeFila();
}
void menu(){
	imprimeFila();
	printf("\n1 - Para inserir um elemento;\n");
	printf("2 - Para remover um elemento;\n");
	printf("3 - Para esvaziar a fila;\n");	
	printf("4 - Para encerrar o programa;\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int opcao, RA, matriculaProf;
	char nomeArquivo, extensaoArquivo;
	
	f = (FILA *) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;

    do{   	
    imprimeFila();
		system("cls");
		menu();
		scanf("%d", &opcao);
		fflush(stdin);
		system("cls");

		switch(opcao){
			case 1:

				printf("Informe o RA do aluno:\n");
				scanf("%d", &RA);
				fflush(stdin);
				printf("Informe o Nome do arquivo:\n");
				scanf("%d", nomeArquivo);
				fflush(stdin);
				printf("Informe a extensão do arquivo:\n");
				scanf("%d", extensaoArquivo);
				fflush(stdin);
				printf("Informe Matricula do Professor:\n");
				scanf("%d", &matriculaProf);
				fflush(stdin);
				adicionaFila(RA, nomeArquivo, extensaoArquivo, matriculaProf);
				system("pause");
				break;
			case 2:
				removeElemento(); 
				system("pause");
				break;
			case 3:
				esvaziaFila();
				system("pause");
				break;
			case 4:
				encerra();
				break;
			default:
				printf("Opçãoo invalida.\n");
				break;
		}
	}while(opcao != 4);
}
