#include <stdio.h>
#include <stdlib.h>

int comparadorInt(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

int comparadorFloat(const void *a, const void *b){
    if(*(const float*)a < *(const float*)b)
        return -1;
    return *(const float*)a > *(const float*)b;
}


int main(){

    int opcao, nInteiro, nReal;
    int *vInteiro;
    float *vReal;

    printf("Qual tipo de numero sera utilizado?  1 - inteiro  2 - real \n");
    scanf("%d",&opcao);


    switch(opcao){
    case 1:
        printf("Qual o tamanho do vetor? \n");
        scanf("%d",&nInteiro);

        vInteiro = (int*)malloc(sizeof(int)*nInteiro);

        if(vInteiro == NULL){
            return 0;
        }
        for(int i=0;i<nInteiro;i++){
            printf("Insira um elemento ao vetor \n");
            scanf("%d",&vInteiro[i]);
        }

        qsort(vInteiro,nInteiro,sizeof(int),comparadorInt);

        printf("\n");

        for(int i=0;i<nInteiro;i++){
            printf("%d  ",vInteiro[i]);
        }


    break;

    case 2:
        printf("Qual o tamanho do vetor? \n");
        scanf("%d",&nReal);

        vReal = (float *)malloc(sizeof(float)*nReal);
        if(vReal == NULL){
            return 0;
        }
        for(int i=0;i<nReal;i++){
            printf("Insira um elemento ao vetor \n");
            scanf("%f",&vReal[i]);
        }

        qsort(vReal,nReal,sizeof(float),comparadorFloat);

        printf("\n");

        for(int i=0;i<nReal;i++){
            printf("%.2f  ",vReal[i]);
        }

    }

    return 0;
}
