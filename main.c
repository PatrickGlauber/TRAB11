#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

/* A funcao de comparação recebe dois valores x e y

   retorna 0: Caso x igual a y
   retorna 1: Caso x seja menor que y
   retorna -1: Caso x seja maior que y
*/
int comparar(void* x, void* y){
	int pontx = *((int*)x);
	int ponty = *((int*)y);
	if(pontx - ponty < 5){
		return -1;
	}else{
		if(pontx - ponty > 5) return 1;
		else return 0;
	}
}

//Print para a estrutura
void print(void** vetor, int num){
	int i;
	printf("VETOR DE %d TAMANHO:\n", num);		//Imprime o tamanho do vetor baseado nos dados dentro do vetor
	for(i = 0; i < num; i++){
		printf(" %d ", *((int*)vetor[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vetor = criar(10, comparar);

   	int* novoelem;
   	int i;

   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){			//chama a função adicionar 10 vezes a cada novo elemento inserido
		novoelem = malloc(sizeof(int));
		*novoelem = i*10;
		adicionar(vetor, novoelem);
	}

	print(vetor->elem, vetor->num);

  	printf("REMOVENDO!");
  	remover(vetor);

	print(vetor->elem, vetor->num);

	return 0;
}
