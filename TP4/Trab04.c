#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NOME "Joao"
#define DESCRICAO "XYZ"
#define CODIGO 1234
#define MAXi 99
#define MAXj 99

int busca_mec = 0;
int busca_mecanizada[MAXi*MAXj];


int gera_random_2 () {

	int a = (rand() % 10000)+1;
	return a;
}

typedef struct produto {
	int codigo;
	char* nome;
	char* descricao;
	int preco;
} produto;

produto* novo_vetor[MAXi][MAXj];  // Matriz "Banco de Dados".

void popula_matriz () {
	int i;
	int j;
	for (i = 0; i < MAXi; ++i) {
		for (j = 0; j < MAXj; ++j) {
			novo_vetor[i][j] = malloc(sizeof(produto));

			novo_vetor[i][j]->preco = gera_random_2 ();

			// Preenche busa_mecanizada com os codigos de todos os produtos para depois ser utilizada para mecanizar 30 consulta a tabela hash.
			busca_mecanizada[busca_mec] = novo_vetor[i][j]->preco;
			busca_mec++;

			novo_vetor[i][j]->nome = NOME;
			novo_vetor[i][j]->descricao = DESCRICAO;
			novo_vetor[i][j]->codigo = CODIGO;
			//novo_vetor[i][j]->preco = PRECO;
		}
	}
}


//Busca Sequencial
// void percorreSeqMatriz(){
// 	int i, j;
// 	for(i = 0; i < MAXi; ++i){
// 		for(j = 0; j < MAXj; ++j){

// 		}
// 	}
// }

void buscaSeqMatriz(int valor){

	int i, j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			/*if(valor == novo_vetor[i][j]->preco){
				printf("Preço: %d", novo_vetor[i][j]->preco);
				printf("Código: %d\n",novo_vetor[i][j]->codigo);
				printf("Nome: %s\n", novo_vetor[i][j]->nome);
				printf("Descrição: %s\n",novo_vetor[i][j]->descricao);
			}*/
		}
	}
}


void buscaSeqMatrizMenores(int valor){
	int i, j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			if(valor > novo_vetor[i][j]->preco){
				printf("Preço: %d\n", novo_vetor[i][j]->preco);
				printf("Código: %d\n",novo_vetor[i][j]->codigo);
				printf("Nome: %s\n", novo_vetor[i][j]->nome);
				printf("Descrição: %s\n\n",novo_vetor[i][j]->descricao);

			}
		}
	}
	printf("\\\\\\ FIM DA BUSCA //////");
}



void busca_mecanizada_func2 () {

	int x = 0;
	int w;

	while (x < 30) {

		w = rand() % MAXi*MAXj;
		buscaSeqMatriz(busca_mecanizada[w]);
		x++;
	}
}

void buscaSeqMatrizMaiores(int valor){
	int i, j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			if(valor < novo_vetor[i][j]->preco){
				printf("Preço: %d\n", novo_vetor[i][j]->preco);
				printf("Código: %d\n",novo_vetor[i][j]->codigo);
				printf("Nome: %s\n", novo_vetor[i][j]->nome);
				printf("Descrição: %s\n",novo_vetor[i][j]->descricao);
			}
		}
	}
}

void buscaSeqMatrizIntervalo(int valor, int valor2){
	int i, j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			if ((valor > novo_vetor[i][j]->preco) && (valor2 < novo_vetor[i][j]->preco)||(valor2 > novo_vetor[i][j]->preco) && (valor < novo_vetor[i][j]->preco)){
				printf("Preco: %d\n", novo_vetor[i][j]->preco);
				printf("Código: %d\n",novo_vetor[i][j]->codigo);
				printf("Nome: %s\n", novo_vetor[i][j]->nome);
				printf("Descrição: %s\n",novo_vetor[i][j]->descricao);
			}
		}
	}
}

void mostraMatriz(){
	int i,j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			printf("Código: %d\n",novo_vetor[i][j]->codigo);
			printf("Nome: %s\n",novo_vetor[i][j]->nome);
			printf("Descrição: %s\n",novo_vetor[i][j]->descricao);
			printf("Preço: %f\n",novo_vetor[i][j]->preco);
		}
	}
}




// Busca na Arvore Binária
typedef struct NO {
	int i, j;
	float preco;
	struct NO *esq;
	struct NO *dir;
} ArvBin;

// Função que cria uma árvore
ArvBin* cria_ArvBin() {
	return NULL;
}

// Função que verifica se uma árvore é vazia
int arvoreEstaVazia(ArvBin * arv) {

	// Retorna 1 se a árvore for vazia e 0 caso contrário
	return arv == NULL;
}

// Função que insere um dado na árvore
void insere_ArvBin(ArvBin **raiz, int valor, int x, int y) {

	if (*raiz == NULL) {


		*raiz = (ArvBin*) malloc(sizeof(ArvBin));
		(*raiz)->preco = valor;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->i = x;
		(*raiz)->j = y;

	} else {

		if (valor < (*raiz)->preco) {
			insere_ArvBin(&(*raiz)->esq, valor, x, y);
		}
		if (valor > (*raiz)->preco) {
			insere_ArvBin(&(*raiz)->dir, valor, x, y);
		}
	}
}

int consulta_ArvBin(ArvBin* raiz, int numero) {
	if (arvoreEstaVazia(raiz)) {
		return 0;
	}

	int i, j;
	ArvBin* aux = raiz;

	while (aux != NULL) {

		if (numero == aux->preco) {
			return 1;
		}
		if(numero > aux->preco){
			aux = aux->dir;
		}else{
			aux = aux->esq;
		}
	}

	return 1;
}

double tempo_execucao (clock_t inic, clock_t fina) {
	double tempo_de_execucao = (double) (fina-inic)/(CLOCKS_PER_SEC/1000);
	return tempo_de_execucao;
}

void menu(){
    int opcao;
    printf("\\\\ MENU ////\n");
    printf("1. Listar itens menores que 3000.\n2. Listar itens maiores que 7000.\n3. Listar itens com o valor entre 4000 e 6000.");
    printf("\nDigite a opção desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1){
        buscaSeqMatrizMenores(3000);
    }
    else if (opcao == 2){
        buscaSeqMatrizMaiores(7000);
    }
    else if (opcao == 3){
        buscaSeqMatrizIntervalo(4000, 6000);
    }
    else{
        printf("erro");
    }

}
int main () {

	popula_matriz ();

    menu();


	clock_t tempo_inicial, tempo_final, tempo_total;
	int i, j;
	double temp_bin_arv = 0.0;
	double temp_busca_seq = 0.0;

	ArvBin* raiz = cria_ArvBin();

	for (i = 0; i < MAXi; ++i) {

		for (j = 0; j < MAXj; ++j) {
			int valor = novo_vetor[i][j]->preco;
			insere_ArvBin(&raiz, valor, i, j);
		}
	}

	printf("\n");

	//Busca Sequencial
	tempo_inicial = clock();
	busca_mecanizada_func2 ();
	tempo_final = clock();
	temp_busca_seq = (tempo_execucao (tempo_inicial, tempo_final))/30;
	double seq = temp_busca_seq;

	// Arvore Binaria
	int x = 0;
	int w;

	tempo_inicial = clock();
	while (x < 30) {

		w = rand() % MAXi*MAXj;
		consulta_ArvBin(raiz, busca_mecanizada[w]);
		x++;
	}
	tempo_final = clock();

	temp_bin_arv = (tempo_execucao (tempo_inicial, tempo_final))/30;
	double bin = temp_bin_arv;


	printf("\n");
	printf("Médias dos tempos de busca para 30 elementos: \n");
	printf("\n");
	printf("Tempo de Busca Árvore binária: %0.20f\n", bin);
	printf("Tempo de Busca Sequêncial    : %0.20f\n", seq);

	printf("\n");
	printf("Diferenças de médias de tempos: \n");
	printf("\n");
	printf("Árvore binária e Sequêncial : %0.20f\n", seq-bin);
	printf("\n");
	printf("\n");

	return 0;
}
