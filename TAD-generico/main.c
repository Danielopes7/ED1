#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

typedef struct Aguaviva{
    char nome[100];
    int registro;
    float localizacao;
    char raca[100];
}Aguaviva;

int cmp(void *elm, void *key){

    Aguaviva *pAguaviva = (Aguaviva *)elm;
    int *pkey = (int *)key;
    if(pAguaviva->registro == pkey){
      
        return 1;
    }else{
        return 0;
    };

};

void listar (void *elm){
    Aguaviva *pAguaviva = (Aguaviva *)elm;
    printf("nome:%s  registro:%d  localizacao:%.2f  raca:%s \n", pAguaviva->nome,pAguaviva->registro,pAguaviva->localizacao,pAguaviva->raca);
}



int main(){
    int menu;


    do{
        printf("-------AQUARIO DE AGUA-VIVA--------\n");
        printf("1 - Criar aquario\n");
        printf("2 - Adicionar agua-viva\n");
        printf("3 - Rastrear agua-viva\n");
        printf("4 - Listar agua-vivas\n");
        printf("5 - Remover agua-viva\n");
        printf("6 - Apagar aquario\n");
        printf("7 - Sair\n");

        scanf("%d",&menu);
        
        Colecao *cofoAguaviva;
        int tam_cofo;
        int quantAgua;
        int *key;
        Aguaviva *aguaviva;
        int *remover_aguaviva;
        int escombros;

        switch(menu){
            case 1:
                printf("Diga quantas agua-vivas vc quer no aquario\n");
                scanf("%d",&tam_cofo);
                cofoAguaviva = criar(tam_cofo);
            break;
            case 2:
                if(cofoAguaviva == NULL){
                  printf("vc precisa criar o aquario antes de inserir agua-viva\n");
                  break;
                }
                printf("Quantas agua-vivas deseja adicionar?\n");
                scanf("%d",&quantAgua);

                for(int i=0;i<quantAgua;i++){
                    aguaviva = (Aguaviva*)malloc(sizeof(Aguaviva));
                    printf("Qual o nome da sua agua-viva?\n");
                    scanf("%s",aguaviva->nome);
                    printf("Qual o numero de registro da sua agua-viva?\n");
                    scanf("%d",&aguaviva->registro);
                    printf("Qual a localizacao (a primeira cordenada) onde a sua agua-viva foi encontrada?\n");
                    scanf("%f",&aguaviva->localizacao);
                    printf("Qual a raca da sua agua-viva?(soberana,barril,caravela,lua,luminescente)\n");
                    scanf("%s",&aguaviva->raca);
                    

                    inserir(cofoAguaviva,aguaviva);
                }
            break;
            case 3:
              printf("digite o registro da agua-viva:\n");
              scanf("%d",&key);

              int result = procurar(cofoAguaviva,key,cmp);
              if(result == key){
                printf("Essa agua-viva esta no aquario!!\n");
              }else{
                printf("Essa agua-viva NAO esta no aquario!!!\n");
              }

            break;
            case 4:
              printarElementos(cofoAguaviva,listar);
            break;
            case 5:
              
              printf("Digite a agua-viva que deseja remover:\n");
              scanf("%d", &remover_aguaviva);

              remover(cofoAguaviva,remover_aguaviva,cmp);
            break;
            case 6:
              escombros = destruir(cofoAguaviva);
              if(escombros = 1){
                printf("O aquario foi destruido\n");
              }else
              {
                printf("O aquario não pode ser destruido\n");
              }
              
            break;
            case 7:
            break;
            default:
              printf("Esta opcao nao existe!");
            }
            }while(menu!=7);
  return 0;
}