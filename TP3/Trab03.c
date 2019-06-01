#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NOME "Joao"
#define DESCRICAO "XYZ"
#define PRECO 5.4
#define MAXi 99
#define MAXj 99
#define TAM_hash 1000000		// Tamanho da tabela hash.
#define PRIMO_hash 99971		// Numero primo escolhido para a funcao hash.
#define VALOR_default 1000		// Valor default para posicoes da tabela hash nao utilizadas.

int num_colisoes = 0;		    // Contador para casos de colisao.
int busca_mec = 0;
int busca_mecanizada[MAXi*MAXj];


int gera_random_2 () {
	
	int a = (rand() % 10000);
	return a;
}



typedef struct pro_duto {
	int codigo;
	char* nome;
	char* descricao;
	float preco;
} produto;

produto* novo_vetor[MAXi][MAXj];  // Matriz "Banco de Dados".

typedef struct local_ {	          // Estrutura usada na indexar os produtos.

	int hashIndex;		          // Index resultado da funcao hash.
	int Mi;				          // Valor linha da matriz.
	int Mj;				          // Valor coluna da matriz.
	struct local* lista_colisao;
} local;

local* vetor_tabela_hash[TAM_hash];	// Tabela hash.

void popula_matriz () {
	int i;
	int j;
	for (i = 0; i < MAXi; ++i) {
		for (j = 0; j < MAXj; ++j) {
			novo_vetor[i][j] = malloc(sizeof(produto));

			novo_vetor[i][j]->codigo = gera_random_2 ();
			
			// Preenche busa_mecanizada com os codigos de todos os produtos para depois ser utilizada para mecanizar 30 consulta a tabela hash.
			busca_mecanizada[busca_mec] = novo_vetor[i][j]->codigo;		
			busca_mec++;												
			
			novo_vetor[i][j]->nome = NOME;
			novo_vetor[i][j]->descricao = DESCRICAO;
			novo_vetor[i][j]->preco = PRECO;
		}
	}
}


int funcao_hash (int key) {		// Calcula e retorna o resultado da funcao hash para a chave key.

	int index;					// Posicao do elemento x na hashtable.
	index = key % PRIMO_hash;	// Funcao hash: resto da divisao da chave por PRIMO_hash (numero primo maior que TAM_hash).
	return index;				// Valor da indexacao (posicao do elemento na tabela hash).
}

void hashing () {				// Gera tabela hash da matriz de produtos.

	int i,j,posicao;
	for (i = 0; i < MAXi; ++i)	{		// Loop pelos elementos
		for (j = 0; j < MAXj; ++j) {	//da matriz dos produtos.

			posicao = funcao_hash(novo_vetor[i][j]->codigo); // "posicao" recebe o resultado da funcao hash (index da tabela) para a dada chave.
			
			tra_coli (posicao, i, j);
		}
	}
}

local* estru_coli (int x, int i, int j) {		// Inicializa nova estrutura do tipo "local" para receber dados do registro colidido.

	local* novo = (local *) malloc(sizeof(local));
	novo->hashIndex = x;
	novo->Mi = i;
	novo->Mj = j;
	novo->lista_colisao = NULL;

	return novo;
}

void tra_coli (int x, int i, int j) {							// Tratamento de colisões.
	
	if (vetor_tabela_hash[x]->hashIndex != VALOR_default) {		// Se hashIndex possuir valor diferente de VALOR_default significa que ha registro alocado na posicao e tratamento de colisao sera iniciado.
		
		if (vetor_tabela_hash[x]->lista_colisao == NULL) {		// Caso em que houve a primeira colisao na posicao dada.

			num_colisoes++;								        // Incremento do contador de colisoes.
			vetor_tabela_hash[x]->lista_colisao = estru_coli (x, i, j);
			
		} else {												// Caso em que ja houveram colisoes na posicao.

			num_colisoes++;								        // Incremento do contador de colisoes.
			local* aux = vetor_tabela_hash[x];
			
			while (aux->lista_colisao != NULL) {				// Loop atraves dos elementos na lista encadeada de colisoes ja alocadas.
				
				aux = aux->lista_colisao;
			}
			
			aux->lista_colisao = estru_coli (x, i, j);			
		}
		
	} else {													// hashIndex possui valor igual a VALOR_default (nao ha registo alocado na posicao - livre para indexacao).
		
		vetor_tabela_hash[x] = malloc(sizeof(local));			// Alocacao de memoria na x "x" para receber estrutura "local".
		vetor_tabela_hash[x]->hashIndex = x;					// Valor da funcao hash associado a chave.
		vetor_tabela_hash[x]->Mi = i;							// x i na matriz para a dada chave.
		vetor_tabela_hash[x]->Mj = j;							// x j na matriz para a dada chave.
		vetor_tabela_hash[x]->lista_colisao = NULL;				// Ponteriro para lista encadeada que aloca colisoes.
		
	}	
}

void print_table_element (int w) {								// Mostra registro de um elemento dado sua indexacao na tabela hash.

	int x,y;
	x = vetor_tabela_hash[w]->Mi;
	y = vetor_tabela_hash[w]->Mj;
}


void inicializar () {											// Inicializa a tabela designando valores default (flags - posicao nao ocupada) para suas estruturas constituintes.

	int b;
	for (b = 0; b < TAM_hash; ++b) {		
			
			vetor_tabela_hash[b] = malloc(sizeof(local));		// Alocacao de memoria na posicao "posicao" para receber estrutura "local".
			vetor_tabela_hash[b]->hashIndex = VALOR_default;	// Valor da funcao hash associado a chave (default).
			vetor_tabela_hash[b]->Mi = VALOR_default;			// Posicao i na matriz para a dada chave (default).
			vetor_tabela_hash[b]->Mj = VALOR_default;			// Posicao j na matriz para a dada chave (default).
			vetor_tabela_hash[b]->lista_colisao = NULL;			// Ponteriro para lista encadeada que aloca colisoes.
	}
}

void busca_produto (int p) {

	int func_hash, i, j;
	
	func_hash = funcao_hash (p);
	i = vetor_tabela_hash[func_hash]->Mi;
	j = vetor_tabela_hash[func_hash]->Mj;

	if (novo_vetor[i][j]->codigo == p) {
		//printf("[elemento nao foi uma colisao]\n");
		print_table_element (func_hash);
	} else {
		
		local* aux = vetor_tabela_hash[func_hash];

		int x, y, procurado;

		x = i;
		y = j;
		procurado = novo_vetor[x][y]->codigo;
		
		while (procurado != p) {
			
			aux = aux->lista_colisao;
			x = aux->Mi;
			y = aux->Mj;

			procurado = novo_vetor[x][y]->codigo;			
		}
		
	}
	
}

void busca_mecanizada_func () {

	int x = 0;
	int w;
	
	while (x < 30) {

		w = rand() % MAXi*MAXj;

		busca_produto(busca_mecanizada[w]);
		x++;
	}	
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


//Busca Sequencial
void buscaSeqMatriz(int valor){
	int i, j;
	for(i = 0; i < MAXi; ++i){
		for(j = 0; j < MAXj; ++j){
			if(novo_vetor[i][j]->codigo == valor){		
			}
		}
	}
}



// Busca na Arvore Binária
typedef struct NO {
	int codigo, i, j;
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
		(*raiz)->codigo = valor;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->i = x;
		(*raiz)->j = y;

	} else {
		

		
		if (valor < (*raiz)->codigo) {
			insere_ArvBin(&(*raiz)->esq, valor, x, y);
			
		}
		if (valor > (*raiz)->codigo) {
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

		if (numero == aux->codigo) {						

			return 1;									
		}//if
		if(numero > aux->codigo){
						aux = aux->dir;						
						
		}//if
		else{
						aux = aux->esq;		

		}//else		
	}

	return 1;
}



double tempo_execucao (clock_t inic, clock_t final) {
	double tempo_de_execucao = (double) (final-inic)/(CLOCKS_PER_SEC/1000);
	return tempo_de_execucao;
}


int main () {

	popula_matriz ();

	clock_t tempo_inicial, tempo_final, tempo_total;
	int i, j;
	double temp_bin_arv = 0.0;
	double temp_hash = 0.0;
	double temp_busca_seq = 0.0;

	ArvBin* raiz = cria_ArvBin();

	for (i = 0; i < MAXi; ++i) {

		for (j = 0; j < MAXj; ++j) {
			int valor = novo_vetor[i][j]->codigo;
			insere_ArvBin(&raiz, valor, i, j);
		}
	}

	inicializar ();
	hashing ();
	printf("\n");

	printf("Colisões: %d\n", num_colisoes);
	printf("\n");

	//Tabela Hash
	tempo_inicial = clock();
	busca_mecanizada_func ();
	tempo_final = clock();
	temp_hash = (tempo_execucao (tempo_inicial, tempo_final))/30;
	double hash = temp_hash;
	

	//Busca Sequencial
	tempo_inicial = clock();
	busca_mecanizada_func2 ();
	tempo_final = clock();
	temp_busca_seq = (tempo_execucao (tempo_inicial, tempo_final))/30;
	double seq = temp_busca_seq;
	

	// Arvore
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
	printf("Tempo de Busca Tabela Hash   : %0.20f\n", hash);
	printf("Tempo de Busca Árvore binária: %0.20f\n", bin);
	printf("Tempo de Busca Sequêncial    : %0.20f\n", seq);

	printf("\n");
	printf("Difereças de médias de tempos: \n");
	printf("\n");
	printf("Tabela hash e Árvore binária: %0.20f\n", bin-hash);
	printf("Árvore binária e Sequêncial : %0.20f\n", seq-bin);	
	printf("\n");
	printf("\n");

	return 0;
}