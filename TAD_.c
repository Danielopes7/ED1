#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _sequencia_{
    int *dados;
    int tam_max;
    int qtd_now;

}sequencia;

sequencia *criar( int tam){
    if(tam<0){
        return 0;
    }
    sequencia *vetor;
    vetor=(sequencia*)malloc(sizeof(sequencia));
    if(vetor==NULL){
        return 0;
    }
    vetor->dados=(int*)malloc(tam*sizeof(int));
    if(vetor->dados==NULL){
        return 0;
    }
    vetor->tam_max=tam;
    vetor->qtd_now=0;
    return vetor;
}

int insert(sequencia *vetor, int dado){
    if(vetor==NULL || vetor->dados == NULL )  {
        return 0;
    }
    if(vetor->qtd_now == (vetor->tam_max)){
       return 0;
    }
    vetor->dados[vetor->qtd_now]=dado;
    vetor->qtd_now+=1;
    return 1;

}

int search(sequencia *vetor, int key){
    int i;
     if(vetor==NULL || vetor->dados == NULL || vetor->qtd_now == 0 )  {
        return 0;
    }
    for(i=0;i<vetor->qtd_now;i++){
        if(vetor->dados[i]==key){
            return key;
        }
        return -1247812;
    }
}

int saca_fora(sequencia *vetor, int elm){
     if(vetor==NULL || vetor->dados == NULL || vetor->qtd_now == 0 )  {
        return 0;
    }
    int i;
    for(i=0;i<vetor->qtd_now;){
        if(vetor->dados[i]==elm){
            vetor->dados[i]=vetor->dados[(vetor->qtd_now)-1];
            vetor->qtd_now-=1;
        }else{
            i++;
        }
    }
    return 1;

}


void main(){
    int tam;
    int dado;
    int log;
    int key;
    int elm;
    int i;
    sequencia *vetor;

    printf("tamanho");
    scanf("%i",&tam);
    vetor=criar(tam);

    for(i=0;i<tam;i++){
        printf("dado");
        scanf("%i",&dado);
        log=insert(vetor,dado);
    }
      for(i=0;i<vetor->qtd_now;i++){
        printf("vet[%i]:%i \n",i+1,vetor->dados[i]);
    }

    printf("busca");
    scanf("%i",&key);

    log=search(vetor,key);
    printf("%i",log);

    printf("destroi");
    scanf("%i",&elm);
    log=saca_fora(vetor,elm);

      for(i=0;i<vetor->qtd_now;i++){
        printf("vet[%i]:%i \n",i+1,vetor->dados[i]);
    }


}
