#include <condefs.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct{
	char nome[25];
	int idade;
	float salario;
	char excluido;
}Registro;

/* função que consulta um registro do arquivo
 retorna a posição fisica onde o registro foi encontrado ou 
-1 caso o registro nao tenha sido encontrado */

consultaReg(FILE *arq, Registro reg){
	Registro regLido;
	int posicao;
	
	if(arq != NULL){
	 fseek(arq, 0L, SEEK_SET);
	 posicao = 0;
     }
	while(fread(&regLido, sizeof(regLido), 1, arq)){
		if(strcmpi(regLido.nome, reg.nome) == 0 && (regLido.excluido == 0))
	       return posicao;
	       posicao++;
           }
      }
	return -1;
}

/*função que insere um registro no arquivo e
 retorna 1 se o registro for incluido com sucesso 
 e 0 caso nao possa ser incluido */

insereReg(FILE *arq, Registro reg){
	Registro regLido;
	int posicao;
	
	if(arq != NULL){
	 posicao = 0;
	 if(consultaRef(arq, reg)){
		fseek(arq, 0L, SEEK_SET);
        while(fread(&regLido, sizeof(regLido), 1, arq)){
		if(regLido.exluido == 1){
		  break;

		  posicao++;
		}
		fseek(arq, posicao*sizeof(reg), SEEK_SET);
		reg.exluido = 0;
		if(fwrite(&reg, sizeof(reg), 1, arq)){ 
			return 1;
           }
        }
	  return 0; 
    }
 }
/* função para exluir um registro do arquivo e 
 retorna 1 se o registro foi exluido com sucesso ou 
 0 caso nao possa ser excluido */

excluiReg(FILE *arq, Registro reg){
	int posicao;
	
	if(arq != NULL){
	  posicao = consultaReg(arq, reg);
		if(posicao != NULL){
		  fseek(arq, posicao*sizeof(reg), SEEK_SET);
		  reg.excluido = 1;
		   if(fwrite(&reg, sizeof(reg), 1, arq)){
			return 1;
              }
          }
         return 0;
      }
}

/* funçao que altera um registro no arquivo e 
  retorna 1 se o registro for alterado com sucesso ou 
  0 caso nao seja possivel alterado */

alteraReg(FILE *arq, Registro reg_antigo, Registro reg_novo){
	int posicao;
	
	if(arq != NULL){
	  posicao = consultaReg(arq, reg_antigo);
		if(posicao != -1){
		  fseek(arq, posicao*sizeof(Registro), SEEK_SET);
		  fread(&reg_antigo, sizeof(reg_antigo), 1, arq);
		  reg_antigo.salario = reg_novo.salario;
		  fseek(arq, posicao*sizeof(Registro), SEEk_SET);
		  fwrite(&reg_antigom sizeof(reg_novo), 1, arq);
	
		  return 1;
           }
      }
	return 0;
}

void main(void){
	FILE *arq;
	Registro funcionario;
	char opcao;

	arq = fopen("c:\\temp\\func.dbf", "r+b");
	if(arq == NULL){
	 arq = fopen("c:\\temp\\func.dbf", "w+b");
	}
	if(arq != NULL){
	  do{
		clrscr();
		printf("Arquivo Serial\n");
		printf("==============\n\n");
		printf("\t[1] Consulta registro\n");
		printf("\t[2] Insere registro\n");
		printf("\t[3] Exclui registro\n");
		printf("\t[4] Altera registro\n");
		printf("\t[5] Lista registros\n");
		printf("\t[6] Sai do programa\n");
		
		flushall();
		opcao = getch()

		clrscr()/
		switch (opcao){

		case '1' : int posicao;
				printf("Consulta por:");
					scanf("%s", funcionario.nome);
				if((posicao = consultaReg(arq, funcionario))  != -1){
					fseek(arq, posicao*sizeof(funcionario), SEEK_SET);
				   fread(&funcionario, sizeof(funcionario), 1, arq);
				   printf("Funcionario: %25s %3d %6.2f", funcionario.nome, funcionario.idade, funcionario.salario);
				}
				getch();
					break;
		case '2': printf("Inserir (nome,idade,salario):");
				scanf("%s %d %f", funcionario.nome, &funcionario.idade, &funcionario.salario);
				insereReg(arq, funcionario);
				break;
		case '3': printf("Excluir            :");
				scanf("%s", funcionario.nome);
				excluiReg(arq, funcionario);
				break;
		case '4': printf("Alterar            :");
				scanf("%s", funcionario.nome);
				prinft("Novo salario:");
				scanf("%f", &funcionario.salario);
				alteraReg(arq, funcionario, funcionario);
				break;
		case '5': fseek(arq, 0L, SEEK_SET);
				printf("Funcionarios:\n\n");
				while(fread(&funcionario, sizeof(funcionario), 1, arq)){
					if(!funcionario.excluido){
						printf("\t%25s %3d %6.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
				getch();
				  break;
                     }
                  }
			while(opcao != '6');
			
			fclose(arq);
            }
       }
    }
}
