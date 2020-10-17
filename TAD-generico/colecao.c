#define __COLECAO_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "colecao.h" 
#define true 1
#define false 0


typedef struct _Colecao_{

    int qtd_atual;
    int tam_max;
    void **dados;

}Colecao;


Colecao *criar(int tam){
    if(tam<0){
        return 0;
    }
    Colecao *cofo;
    cofo=(Colecao*)malloc(sizeof(Colecao));
    if(cofo==NULL){
        return 0;
    }
    cofo->dados=(void**)malloc(tam*sizeof(void*));
    if(cofo->dados==NULL){
        return 0;
    }
    cofo->tam_max=tam;
    cofo->qtd_atual=0;
    return cofo;
}

int inserir(Colecao *cofo, void *dado){
    if(cofo==NULL || cofo->dados == NULL )  {
        return 0;
    }
    if(cofo->qtd_atual == (cofo->tam_max)){ //ta cheio
       return 0;
    }
    cofo->dados[cofo->qtd_atual]=dado;
    cofo->qtd_atual+=1;
    return 1;
}
void *procurar(Colecao *cofo, void *key, int(*cmp)(void* elm,void* key)){
    if(cofo==NULL || cofo->dados == NULL || cofo->qtd_atual == 0 )  { //nao tem oq procurar
        return 0;
    }
    
    for(int i=0;i<cofo->qtd_atual;i++){
        if(cmp(cofo->dados[i],key)==1){
            return key;
        }
    }
    return 0;
}


void *printarElementos(Colecao *cofo, void (*listar)(void* elm)){
    if(cofo==NULL || cofo->dados == NULL || cofo->qtd_atual == 0 )  { //nao tem oq procurar
        return 0;
    }

    for(int i=0;i<cofo->qtd_atual;i++){
        listar(cofo->dados[i]);
    }
} 


void *remover(Colecao *cofo, void *key, int (*cmp)(void*,void*)){
     if(cofo==NULL || cofo->dados == NULL || cofo->qtd_atual == 0 )  {
        return 0;
    }
    int i;
    for(i=0;i<cofo->qtd_atual;i++){
        if((cmp(cofo->dados[i],key))==1){
            while (i<cofo->qtd_atual){
                cofo->dados[i]=cofo->dados[i+1];
                i++;
            }
            cofo->qtd_atual--;
            return key;
    }
}
}

int destruir(Colecao *cofo) {
    if(cofo==NULL || cofo->dados == NULL){
        return 0;
    }
    free(cofo->dados);
    free(cofo);
    return 1;
}

