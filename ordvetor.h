/*Definicao do tipo de funcao a ser utilizado para comparacao
Esta função recebe dois valores x e y e retorna

1 : se x é menor que y.
0 : se x é equivalente a y.
-1: se x é maior que y na ordem.

*/
#include <stdio.h>
#include <stdlib.h>

#ifndef ORDVETOR_H
#define ORDVETOR_H

//Vetor ordenado estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.

typedef int compara(void* x, void* y);


typedef struct vet{
	int tam;//tamanho do vetor
	int num;//numero de elementos no vetor
	void** elem;//o vetor de elementos
	compara* comp;//a funcao de comparacao
}VETORORD;


/**
Cria um vetor ordernado vazio de tamanho tam e com funcao de comparacao comparar

@param tam: o tamanho do vetor
@param comp: a funcao de comparacao

@return um ponteiro para uma estrutura VETORORD, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/


VETORORD* criar(int tam, compara* comp);

/**
Adiciona o elemento novoelem ao vetor ordenado, na posicao correta se for possível
ainda incluir o elemento (se existe espaco no vetor). O vetor deve estar ordenado em
ordem crescente, ou seja: x[i] é menor que ou equivalente a x[j] para todo i < j.

@param vetor: o vetor ordenado a ter o elemento incluído
@param novoelem: o elemento a ser adicionado
*/

void adicionar(VETORORD* vetor, void* novoelem);

/**
Remove o menor elemento do vetor, de acordo com a funcao compara.

@param vetor: o vetor a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do vetor.
*/
void* remover(VETORORD* vetor);

#endif
