/* 2ª Lista de Exercicios [AED 2014/2015] 
   Ingrid Lima dos Santos               
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 4


typedef struct {
	char nome[20];
	char endereco[40];
	int id;
} tipoDados; 

typedef struct tipoNo{
	tipoDados dado;
	struct tipoNo *prox;
	char nome[50];
} tipoNo;

typedef struct noInt{
	int dado;
	struct noInt *prox;
}noInt;
typedef struct {
	tipoNo *topo;
} tipoPilha; 

typedef struct {
	tipoNo *prim;
	tipoNo *ult;
} tipoFila; 

typedef struct tipoNoInt{ 
	int num;
	struct tipoNoInt *prox;
} tipoNoInt;

typedef struct{
	tipoNoInt *topo;
} tipoPilhaInt; 

typedef struct {
	tipoNo *atual;
} tipoListCirc; 

typedef struct {
  tipoNo *prim;
  int numElem;
} tipoLista;

typedef struct{
	noInt *atual;
} tipoListaInt;


// Q1. Funçao para remover,inserir e criar elementos na pilha.

tipoDados removedaPilha (tipoPilha *pilha){
	tipoNo *aux;
	tipoDados dado;
	
	aux = pilha -> topo;
	dado = aux -> dado;
	pilha -> topo = aux -> prox;
	
	free(aux);
	
	return dado;
} 

void insereNaPilha(tipoPilha *pilha, tipoDados dado){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	aux -> dado = dado;
	aux -> prox = pilha -> topo;
	pilha -> topo = aux;
}

void criarNaPilha (tipoPilha *pilha){

	pilha -> topo = NULL;
}

// Q2. Funçao para remover,inserir e criar elementos na fila.

tipoDados removeNaFila(tipoFila *fila){
	tipoNo *aux;
	tipoDados dado;
	
	aux = fila -> prim;
	dado = aux -> dado; 
	fila -> prim = aux -> prox;
	free(aux);
	
	if (fila -> prim == NULL){
		fila -> ult = NULL;
	}
	
	return dado;
}

void insereNaFila (tipoFila *fila, tipoDados dado){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc (sizeof(tipoNo));
	aux -> dado = dado;
	aux -> prox = NULL;
	
	if(fila -> prim == NULL){
		fila -> prim = aux;
	}
	else if(fila -> prim != NULL){
		fila -> ult -> prox = aux;
	}
	
	fila -> ult = aux; 
}

void criarFila(tipoFila *fila){
	
	fila -> prim = NULL;
	fila -> ult = NULL;
}

// Q3. Funcao para inserir, criar e remover elementos na Lista Circular.

void insereNaListCirc(tipoListCirc *listCirc, tipoDados dado){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc (sizeof(tipoNo));
	aux -> dado = dado;
	
	if(listCirc -> atual == NULL){
		listCirc -> atual = aux;
	}
	else if(listCirc -> atual != NULL){
		listCirc -> atual -> prox = aux;
	}
}

// Q4. Funcao que retorna quantas vezes os elementos da lista circular sao iguais a chave K.

int KListCirc(tipoListCirc *listCirc, tipoDados *dado,int chave){
	tipoNo *aux;
	int cont = 0;
	
	aux = listCirc -> atual;
	
	do {
		if(aux -> dado.id == chave){
			cont++;
		}
		aux = aux -> prox;
	}
	while(aux != listCirc -> atual);
	
	
	return cont;
}

//Q5. Funcao que insere os elementos de um vetor na Pilha.

void insereVetNaPilha(tipoPilhaInt *pilhaInt, int vet[], int k){
	int i;
	
	for(i=0; i < k; i++){
		tipoNoInt *aux;
		
		aux = (tipoNoInt*) malloc (sizeof(tipoNoInt));
		
		aux -> num = vet[i];
		aux -> prox = pilhaInt -> topo;
		pilhaInt -> topo = aux;
	}
} 

//Q6. Funçao que remove o elemente na posiçao K.

void removeElemK(tipoLista *lista, tipoDados *dado, int k){
	tipoNo *aux, *tmp, *fim;
	int i, tam = 1;
	
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	tmp = (tipoNo*) malloc(sizeof(tipoNo));
	fim = (tipoNo*) malloc(sizeof(tipoNo)); 
	
	fim = lista -> prim;
	
	while(fim->prox){
        fim = fim->prox;
        tam++;
	}
	if(lista -> prim != NULL){
		aux = lista -> prim;
		if (k <= tam && k > 0){
			for(i = 1; i < k - 1; i++){
			aux = aux -> prox;
			} 
			tmp = aux -> prox;
			aux -> prox = tmp -> prox; 
			free(tmp);
		} 
	}
}

// Q7. Função que verifica se as listas sao simetricas.

int verificaSimetria(tipoListaInt lista){
	int tam, mtd;
	noInt *aux;
	noInt *meio;
	
	if(lista.atual){
		aux = lista.atual;
		tam = 0;
	
	while(aux){
		tam ++;
		aux = aux -> prox;
	}
	mtd = tam/2;
	meio = lista.atual;
	while(mtd){
		meio = meio -> prox;
		mtd --;
	} 
	while(lista.atual != meio){
		aux = meio;
		while(aux){
			if(lista.atual -> dado == aux -> dado){
				break;
			} else{
				if(lista.atual -> dado != aux -> prox){
					return 0;
				}
			}
			aux = aux -> prox;
		}
		lista.atual = lista.atual -> prox;
	 }
	 
	} else {
		return 0;
	} 
	return 1;
	
} 

//Q8. Funcao para transferir dados da lista encadeada para um vetor. 

void transferirDados(tipoLista *lista, tipoDados *dado, int vet[]){
	tipoNo *aux;
	int i;
	
	vet= (int*) malloc(sizeof(int));
	aux= (tipoNo*) malloc(sizeof(tipoNo));
	
	if(lista -> prim){
		aux = lista -> prim;
		vet[i] = aux;
		i++;
		free(aux);
	}  
	else{
		while(aux -> prox != NULL){
			aux = aux -> prox;
			vet[i] = aux;
			i++;
			free(aux);
		}
	}
	
	free(lista);	
}

//Q9. Funçao para mostrar os elementos de uma fila. 

void mostrarElemFila(tipoFila *fila){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc (sizeof(tipoNo));
	
	if(fila -> prim != NULL){
		aux = fila -> prim;
		fila -> prim = aux -> prim;
		mostrarElemFila(&fila);
		printf("%s\n", aux -> nome);
	}
}


//Q10. Funçao quickSort para ordenar dados a partir do campo nome.

void inserir(tipoDados dado[], int inicio, int fim){
	int i, j;
	tipoDados pivot;
	
	for(i = inicio + 1; i <= fim; i++){
		pivot = dado[i];
		for(j = i - 1; j >= inicio; j--){
			if(strcasecmp(pivot.nome, dado[j].nome) > 0){
				dado[j + 1] = dado[j];
			} 
			 else{
			 	break;
			 }
		} 
		dado[j + 1] = pivot;
	}
}

void quickS(tipoDados dado[], int inicio, int fim){
	tipoDados pivot;
	tipoDados tmp;
	int i,j;
	
	i = inicio;
	j = fim;
	pivot = dado[(i+j)/2];
	
	do{
		while(strcasecmp(pivot.nome, dado[i].nome) > 0){ i++; }
		while(strcasecmp(pivot.nome, dado[j].nome) < 0){ j--; } 
		if(i <= j){
			tmp = dado[i];
			dado[i] = dado[j];
			dado[j] = tmp;
			i++;
			j--;
		} 
		while(i <= j);
		
		if(inicio < j) {
			if(j - inicio >= 10){
				quickS(dado, inicio, j);
			}
			 else{
			 	inserir(dado, inicio,j);
			 }
		}
		if(i < fim) {
			if(fim - i >= 10){
				quickS(dado, i, fim);
			}
			 else{
			 	inserir(dados, i, fim);
			 }
		}
	}
} 

void qSort(tipoDados dado[], int x){
	if( x >= 10){
		quickS(dado, 0, x - 1);
	} 
	 else{
	 	inserir(dado, 0, x - 1);
	 }
}

	

//Q11. Funcao mergesort para ordenar vetor com dados tipoDados, ordenados pelo nome.

void mergS(tipoDados v[], int inicio, int fim){
	tipoDados *aux;
	int i, j,l;
	int meio;
	
	meio = (inicio + fim)/2;
	
	if(inicio < fim){
		mergS(v, inicio, meio, aux);
		mergS(v, meio+1, fim, aux);
		
		i = inicio;
		j = meio + 1;
		l = inicio;
		
		while(i <= meio && j <= fim){
			if(strcasecmp(v[i].nome, v[j].nome) > 0){
				aux[l] = v[i];
				i++;
				l++;
			}
			else{
				aux[l] = v[j];
				j++;
				l++;
			} 
	}
			while(i <= meio){
				aux[l] = v[i];
				i++;
				l++;
			}
			while(j <= fim){
				aux[l] = v[j];
				j++;
				l++;		
			}
			do{
				l--;
				v[fim] = aux[l];
				fim--;
			}
	     	 while(inicio <= fim);
	 }
} 

void mSort(tipoDados v[], int tam){
	tipoDados aux[tam];
	mergS(v, 0, tam-1, aux);
}


//Q12. Funcao quicksort para ordenar um vetor com dados do tipoDados, ordenados pelo id.

void qId(tipoDados dado[], int inicio, int fim){
	tipoDados pivot;
	tipoDados tmp;
	int i,j;
	
	i = inicio;
	j = fim;
	pivot = dado[(i+j)/2];
	
	do{
		while(dado[i].id < pivot.id){ i++; }
		while(dado[j].id > pivot.id){ j--; }
		if(i <= j){
			tmp = dado[i];
			dado[i] = dado[j];
			dado[j] = tmp;
			i++;
			j--;
		}
		while(i <= j);
		if(inicio < j){
			qId(dado, inicio, j);
		} 
		if(i < fim){
			qId(dado, i, fim);
		}
	}
}

void qSortId(tipoDados dado[], int x){
	qSortId(dado, 0, x-1);
}
//Q13. Funçao quickSort modificada da questao 12.

void qsIdK(tipoDados dado[], int inicio, int fim, int k){
	int i,j;
	tipoDados pivot;
	tipoDados tmp;
	
	i = inicio;
	j = fim;
	pivot = dado[(i+j)/2];
	
	do{
		while(pivot.id > dado[i].id){ i++; }
		while(pivot.id < dado[j].id){ j--; }
		if(i <= j){
			tmp = dado[i];
			dado[i] = dado[j];
			dado[j] = tmp;
			i++;
			j--;
		} 
	}
	while(i <= j);
	if(inicio < j){
		qsIdk(dado, inicio, j, k);
	} 
	if(i < k){
		qsIdk(dado, i, fim, k);
	}
}

void qSortIdK(tipoDados dado[], int x, int k){
	qsIdk(dado, 0, x-1,k);
}
// Questoes 14 à 17.
typedef struct {
	int matricula;
	int turma;
	char CPF[12];
	char nome[20];
} tipoAluno;

typedef struct no {
	tipoAluno al;
	int linha, coluna;
	struct no * prox; 
} tipoNo;

typedef struct {
	tipoNo *prim;
} tipoListaDeAluno;

//Q14. Funcao que retorna os alunos da turma K 

void imprimiAlunoK(tipoLista *lista, tipoAluno *aluno, char k){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	
	aux = lista -> prim;
	
	do{
		if(aux -> aluno.turma == k){
			printf("%s\n", aux ->aluno.turma);
		} else {
			aux = aux -> prox;
		}
		
	} 
	while(aux != lista -> prim);
}	

//Q15. Funcao que move ultimo elemento para primeira posicao.

void moveUltimoElem(tipoListaDeAluno *pilha){
	tipoAluno aluno;
	tipoNo *aux;
	
	aux = pilha -> prim;
	
	while(aux -> prox != NULL){
		aux = aux -> prox;
	}
	aluno = pilha -> prim -> al;
	pilha -> prim ->  al = aux -> prox;
	aux -> al = aluno;
	
}

//Q16.Funçao que cria lista encadeada e recebe nela os alunos da turma k que estao na matriz NxN.

tipoListaDeAluno inserirMatrizNaLista(tipoAluno m[N][N], int k){
	int i, j;
	tipoListaDeAluno lista;
	tipoNo *aux;
	
	lista.prim = NULL;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(m[i][j].turma == k){
				aux = (tipoNo*) malloc(sizeof(tipoNo));
				aux -> al = m[i][j];
				aux -> linha = i;
				aux -> coluna = j;
				aux -> prox = lista.prim;
				lista.prim = aux;
			}
		}
	}
	
	return lista;
}

//Q17. Funcao que transfere os elementos da lista encadeada para uma matriz NxN

void transferirListaParaMatriz(tipoAluno *lista, tipoAluno m[N][N]){
	tipoNo *aux;
	
	aux = lista -> prim;
	
	while(aux != NULL){
		m[aux -> linha][aux -> coluna] = aux -> al;
		lista -> prim = aux -> prox;
		free(aux);
		aux = lista -> prim;
	}
}
