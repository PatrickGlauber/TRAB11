#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"


/* cria um vetor inteiramente nulo baseado na funcao de comparação

   retorna um ponteiro VETORORD, perceba que a alocação de memória
   deve ser feita nele
*/

VETORORD* criar(int tam, compara* comp){
    VETORORD* vetord = malloc(sizeof(VETORORD));
    vetord->comp = comp;
    vetord->tam = tam;
    vetord->num = 0;
    vetord->elem = malloc(tam * sizeof(void *));
    for(int i = 0;i<tam;i++){
        vetord->elem[i] = NULL;
    }
    return vetord;
}

/* adiciona um novo elemento no vetor ordenado, na posicao correta caso seja possivel, se não e caso haja espaço o adiciona

   o vetor está ordenado de maneira crescente
*/

void adicionar(VETORORD* vetor, void* novoelem){
    if (vetor->num < vetor->tam) {
        if (vetor->num == 0) {
            vetor->elem[0] = novoelem;
        }
        else if(vetor->comp(novoelem, vetor->elem[vetor->num-1]) == -1 || vetor->comp(novoelem, vetor->elem[vetor->num-1]) == 0) {
            vetor->elem[vetor->num] = novoelem;
        }else{
            for(int i = vetor->num-1; i > -1; i--){
                if (vetor->comp(novoelem, vetor->elem[i]) == 1) {
                    vetor->elem[i+1] = vetor->elem[i];
                    vetor->elem[i] = novoelem;
                }
                else break;
            }
        }
        vetor->num++;
    }
}

/* remove o menor elemento do vetor ordenado baseado na função de comparação, e o reorganiza para manter a ordem crescente
*/

void* remover(VETORORD* vetor){
    void* aux = vetor->elem[0];
    for(int i = 0;i<vetor->num;i++){
        vetor->elem[i] = vetor->elem[i+1];
    }
    vetor->num--;
    return aux;
}
