#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tree.c"

int cmp(void* elm, void * teste){
    int *a, *b;
    a=(int *)elm;
    b=(int *)teste;
    if(*a<*b)
        return -1;
    else{
        if (*a==*b) return 0;
        else        return 1;
    }
}

void visit (void *elm){
    int *a;
    a=(int *)elm;
    printf ("%d ",*a);
}

int main(){
    int i=1, key1=0, key, folhas=0;
    int alt=0, nos=0, h, nNos=0,hno,g1=0;
    int *point, *vet;
    tree *t, *t2, *t3;
    char op;
    vet=NULL;
    t=abpCreate();
    (t!=NULL)? printf ("Deu certo Arvore 1!\n"):printf ("Ferrou Arvore 1\n");
    /*t2=abpCreate();
    (t2!=NULL)? printf ("Deu certo Arvore 2!\n"):printf ("Ferrou Arvore 2\n");*/
    while (op!='0'){
        printf("\nMENU\n");
        printf("a) Inserir na Arvore\n");
        printf("b) Remover da Arvore\n");
        printf("c) Consultar Arvore\n");
        printf("d) Visitar Arvore\n");
        printf("e) Visitar Nao-Folhas Simetricamente\n");
        printf("f) Dados da Arvore\n");
        printf("g) Testar se e' Arvore de pesquisa\n");
        printf("h) Altura do No\n");
        printf("i) Remove Maiores Dados\n");
        printf("j) Fundir Arvores 1 e 2\n");
        printf("l) Altura da Arvore\n");
        printf("m) Numeros de nos\n");
        printf("n) Numeros de nos de Altura h\n");
        printf("o) Numeros de nos de Grau 1\n");        
        printf("p) Numeros de nos > que a Key\n");
        printf("q) isHeap ?\n");  
        printf("r) Numeros de folhas\n");
        printf("0) Sair\n\n");
        printf ("Opcao: ");
        op=getche();
        i=1;
        printf ("\n");

        switch (op){
            case 'a':
                while (i){
                    printf ("Digite o numero que deseja inserir na arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                  /*  printf ("Inserir em qual arvore? 1 ou 2?\ndetalhe: se voce digitar 5, vai adicionar na 2 xD\n");
                    if (getche()=='1')*/
                        t->root=abpInsert(t->root, (void*)point, cmp);
                  /* else
                        t2->root=abpInsert(t2->root, (void*)point, cmp);
                    printf("\n");*/
                }
                break;
            case 'b':
                while (i){
                    printf ("Digite o numero que deseja remover da arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    t->root=abpRemove(t->root, (void*)point, cmp);
                    //t->root=removeKey(t->root,(void*)point);
                }
                break;
            case 'c':
                while (i){
                    printf ("Digite o numero que deseja consultar da arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    if (abpQueryNode(t->root,cmp, (void*)point)!=NULL)
                        printf ("Encontrado %d!!\n", *point);
                }
                break;
            case 'd':
                while (i){
                    printf ("Escolha o modo de visita: \n")/
                    printf ("(1) preOrdem, (2) posOrdem, (3) Simetrica, (0) Sair\n");
                    scanf ("%d", &i);
                    if (i==1){
                        abppreOrdem(t->root, visit);
                        printf("\n");
                    }
                    else{
                        if (i==2){
                            abpposOrdem(t->root, visit);
                            printf("\n");
                        }
                        if (i==3){
                            abpSimetrico(t->root, visit);
                            printf("\n");
                        }
                    }
                }
                break;
            case 'e':
                abpnFolhaSimetrico(t->root, visit);
                break;
            case 'f':
                vet=(int *)malloc(sizeof(int)*7);
                for (i=0; i<7; i++) vet[i]=0;

                dadosArvore(t->root, vet);
                printf("\n\nDados da Arvore\n");
                printf("Numero de Nos: %d\n", vet[0]);
                printf("Numero de Folhas: %d\n", vet[1]);
                printf("Numero de Nao Folhas: %d\n", vet[2]);
                printf("Numero de Nos com 2 filhos: %d\n", vet[3]);
                printf("Numero de Nos com 1 filho: %d\n", vet[4]);
                printf("Numero de Nos com filho esq: %d\n", vet[5]);
                printf("Numero de Nos com filho dir: %d\n\n", vet[6]);
                i=1;
                break;
            case 'g':
               if (abpTeste(t->root,cmp)==1)
                //if (testaABB(t->root,cmp)==1)
                //if(isABP(t->root)==1)  
                    printf("E' arvore de pesquisa!\n");
                else
                    printf("Nao e' arvore de pesquisa\n");
                break;
            case 'h':
                    printf ("Digite o numero que deseja procurar na arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    printf ("A altura do no e' %d\n", abpAlturaNo(t->root,(void*) point, cmp)-1);
                    break;
            case 'i':
                    abpRemoveMaiorData(t->root);
                    break;
            case 'j':
                    printf ("Imprimindo Arvores da Fusao!\n");
                    t3=abpCreate();
                    t3->root=abpFusao(t3->root,t->root, t2->root, cmp);
                    abpSimetrico(t3->root, visit);
                    printf ("\n");
                    break;
            case'l':
                    printf("Imprimindo altura da arvore!\n");
                    alt = altura(t->root); 
                    printf("%d", alt);
                    break;   
            case'm':
                    printf("Imprimindo quantidade de nos presente na Arvore!\n");
                    nos=numNos(t->root);
                    printf("%d", nos);
                    break;      
            case'n':
                    printf("Entre com a altura: ");
                    scanf("%d", &h);
                    nNos=nNosAlth(t->root,h,-1);
                    printf("%d", nNos);    
                    break;
            case'o':
                    printf("Numero de nos de grau 1:\n");
                    g1= grau1(t->root);                  
                    printf("%d", g1);
                    break;
            case'p':
                    printf("Entre com a key:\n");
                    scanf("%d", &key);
                    key1=nosMaiorKey(t->root,key);
                    printf("Numero de nos maior que a key: %d", key1);
                    break;
            case'q':
                     (isHeap(t->root)) ? printf("E uma Heap"): printf("Nao e uma Heap");
                     break;     
            case'r':
                    printf("Numero de Folhas:\n");
                    folhas= contarFolhas(t->root);                  
                    printf("%d", folhas);
                    break;            
                    
        }
        
    }
}
