#include <stdio.h>
#include <stdlib.h>
#define N 3

void gravaMatriz(int mat[N][N], FILE *f){
 int i, j; 

	for(i=0; i < N; i++){
	  for(j=0; j < N; j++){
		fwrite(&mat[i][j], sizeof(int),1,f);
	}
  }
}

void lerMatriz(FILE *f, int mat[N][N]){
  int i, j;
	
	for(i=0; i < N; i++){
	  for(j=0; j < N; j++){
		fread(&mat[i][j], sizeof(int),1,f);
	}
  }
}

void gravaMat(FILE *f, mat[N][N], int m){
 int i, j;
	
	for(i=0; i < m; i++){
	  for(j=0; j < m; j++){
		fwrite(&mat[i][j], sizeof(int),m, f);
	}
  }
}

void gravaTxt(FILE *f, mat[N][N]){
  int i, j;
	
	for(i=0; i < N; i++){
	  for(j=0; j < N; j++){
		fprintf(f, "%d  ", mat[i][j]);
	}
	printf(&, "\n");
  }
}


void lerTxt(FILE *f, mat[N][N]){
  int i, j;
	
	for(i=0; i < N; i++){
	  for(j=0; j < N; j++){
		fscanf(f, "%d", &mat[i][j]);
	}
  }
} 

