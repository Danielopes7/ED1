#include "Sll.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int IdMaq(void* elm, void * teste){
    int *a, *b;
    a=(int *)elm;
    b=(int *)teste;
    if(*a==*b)
        return(TRUE);
    else
        return(FALSE);
}

void Insert (SllHandle *list, void *elm, char opc){
    switch (opc){
        case 'a':
            SllInsFirstPosition(list, elm);
            break;
        case 'b':
            SllInsLastPosition( list, elm );
            break;
        case 'c':
            SllInsOrdered( list,  elm, IdMaq);
            break;
        default:
            printf ("\nOpcao invalida\n");
    }
}

void SllDestroy(SllHandle *list, void (*FreeData)(void *)){
    SllRemoveAll(list,FreeData);
    free(list);
    list=NULL;
}

void FreeInt(void* elm){
    free(elm);
}

void EsvaziaLista(SllHandle *L1, SllHandle *L2, SllHandle *L3, char opc){

		switch(opc){

			case 'a':
				if(L1) {
				    printf("\nLista 1 foi esvaziada\n");
                    SllRemoveAll(L1, FreeInt);
				}
				else printf("\nNao ha lista 1 criada");
				break;
			case 'b':
				if(L2) {
				    printf("\nLista 2 foi esvaziada\n");
				    SllRemoveAll(L2, FreeInt);
				}
				else printf("\nNao ha lista 2 criada");
				break;
			case 'c':
				if(L3) {
                    printf("\nLista 3 foi esvaziada\n");
                    SllRemoveAll(L3, FreeInt);
				}
				else printf("\nNao ha lista 3 criada");
				break;

		}


}

void ImprimeLista(SllHandle *L1, SllHandle *L2, SllHandle *L3, char opc){
	int *aux;
	printf ("\n");
	switch(opc){
		case 'a':
			if (L1!=NULL){
                L1->cur = L1->head;

                while(L1->cur!=NULL){
                    aux=(int*)L1->cur->data;
                    printf("%d\n", *aux);
                    L1->cur=L1->cur->next;
                }
            }
            else    printf ("\nLista 1 nao existe\n");
			break;
		case 'b':
            if (L2!=NULL){

                L2->cur = L2->head;

                while(L2->cur){
                    aux=(int*)L2->cur->data;
                    printf("%d\n", *aux);
                    L2->cur=L2->cur->next;
                }
			}
			else    printf ("\nLista 2 nao existe\n");
			break;
		case 'c':
            if (L1==NULL || L2 == NULL) printf ("\nUma das listas nao existe\n");
            else {
                printf("L1: \n");
                L1->cur = L1->head;
                while(L1->cur){
                    aux=(int*)L1->cur->data;
                    printf("%d\n", *aux);
                    L1->cur=L1->cur->next;
                }

                printf("L2: \n");
                L2->cur = L2->head;
                while(L2->cur){
                    aux=(int*)L2->cur->data;
                    printf("%d\n", *aux);
                    L2->cur=L2->cur->next;
                }
            }
            break;
        case 'd':
            if (L3!=NULL){
                L3->cur = L3->head;

                while(L3->cur!=NULL){
                    aux=(int*)L3->cur->data;
                    printf("%d\n", *aux);
                    L3->cur=L3->cur->next;
                }
            }
            else    printf ("\nLista 3 nao existe\n");
			break;
	}
}

void Diferenca (SllHandle *L1, SllHandle *L2, SllHandle *L3){
    void *dado;
    L1->cur=L1->head;


    while (L1->cur!=NULL){
        L2->cur=L2->head;
        dado = L1->cur->data;
        if ((SllGetElm(L2, dado, IdMaq)==FALSE)&&(SllGetElm(L3,dado,IdMaq)==FALSE)){
            if (L3->head==NULL)
                SllInsFirstPosition(L3, dado);
            else
                SllInsLastPosition(L3, dado);
        }
        L1->cur=L1->cur->next;
    }
}

int TestesIntersectar (SllHandle *L1, SllHandle *L2, SllHandle *L3){
    if (L3!=NULL){
        printf ("\nLista 3 ja existe...\n");
        return 0;
    }
    else{
        if ((L1==NULL)||(L2==NULL)){
            printf ("\nVoce precisa de duas listas para realizar tal operacao\n");
            return 0;
        }
        else{
            return 1;
        }
    }
}

void Intersectar (SllHandle *L1, SllHandle *L2, SllHandle *L3){
    void *dado;

    L1->cur=L1->head;
    while (L1->cur!=NULL){
        L2->cur=L2->head;
        dado = L1->cur->data;
        if ((SllGetElm(L2, dado, IdMaq)!=FALSE)&&(SllGetElm(L3,dado,IdMaq)==FALSE)){
            if (L3->head==NULL)
                SllInsFirstPosition(L3, dado);
            else
                SllInsLastPosition(L3, dado);
        }
        L1->cur=L1->cur->next;
    }


}

void Uniao (SllHandle *L1, SllHandle *L2, SllHandle *L3){
    void* elm;
    if(L1&&L2&&L3){
        L1->cur=L1->head;
        L2->cur=L2->head;
        L3->cur=L3->head;
        while(L1->cur){
            elm=L1->cur->data;
            if (L3->head==NULL)
                    SllInsFirstPosition(L3, elm);
                else
                    SllInsLastPosition(L3, elm);
        L1->cur=L1->cur->next;
        }
        while(L2->cur){
            elm=L2->cur->data;
            if(SllGetElm(L3,elm,IdMaq)==NULL){
               SllInsLastPosition(L3, elm);
            }
        L2->cur=L2->cur->next;
        }
    }


}



void main(){
    SllHandle *L1, *L2, *L3;
    char op;
    int dado;
    int *point;

    L1=NULL;
    L2=NULL;
    L3=NULL;

    while (op!='m'){
        printf ("\n\tMENU\n");
        printf ("a) Criar Lista 1\n");
        printf ("b) Criar Lista 2\n");
        printf ("c) Destruir Lista 1\n");
        printf ("d) Destruir Lista 2\n");
        printf ("e) Destruir Lista 3\n");
        printf ("f) Inserir na Lista 1\n");
        printf ("g) Inserir na Lista 2\n");
        printf ("h) Imprimir Lista\n");
        printf ("i) L1 Uniao L2\n");
        printf ("j) L1 Interseccao L2\n");
        printf ("k) L1 - L2\n");
        printf ("l) Esvaziar Listas\n");
		printf ("m) Sair\n");
        printf ("Digite a opcao desejada: ");
        op=getche();

        switch (op){
            case 'a':
                if (L1==NULL)   L1=SllInit();
                else            printf ("\nLista ja existe\n");
                break;
            case 'b':
                if (L2==NULL)   L2=SllInit();
                else            printf ("\nLista ja existe\n");
                break;
            case 'c':
                if (L1!=NULL){
                    SllDestroy(L1,FreeInt);
                    L1=NULL;
                    }
                else            printf ("\nLista nao existe\n");
                break;
            case 'd':
                if (L2!=NULL){
                    SllDestroy(L2,FreeInt);
                    L2=NULL;
                }
                else            printf ("\nLista nao existe\n");
                break;
            case 'e':
                if (L3!=NULL){
                    SllDestroy(L3,FreeInt);
                    L3=NULL;
                }
                else            printf ("\nLista nao existe\n");
                break;
            case 'f':
                if (L1!=NULL){
                    printf ("\nDeseja inserir o dado em que posicao?\n");
                    printf ("a) Primeira posicao\n");
                    printf ("b) Ultima posicao\n");
                    printf ("c) Ordenada\n");
                    printf ("Digite a opcao desejada: ");
                    op=getche();
                    printf ("\nDigite o dado a ser adicionado a lista: ");
                    scanf ("%d", &dado);
                    point = (int *)malloc(sizeof(int));
                    *point = dado;
                    Insert (L1, (void*) point, op);
                    op = 'f';
                }
                else printf ("\nLista nao existe!\n");
                break;
            case 'g':
                if (L2!=NULL){
                    printf ("\nDeseja inserir o dado em que posicao?\n");
                    printf ("a) Primeira posicao\n");
                    printf ("b) Ultima posicao\n");
                    printf ("c) Ordenada\n");
                    printf ("Digite a opcao desejada: ");
                    op=getche();
                    printf ("\nDigite o dado a ser adicionado à lista: ");
                    scanf ("%d", &dado);
                    point = (int *)malloc(sizeof(int));
                    *point = dado;
                    Insert (L2, (void*) point, op);
                    op = 'g';
                }
                else printf ("\nLista nao existe!\n");
                break;
            case 'h':
                printf ("\nDeseja imprimir o que?\n");
				printf ("a) L1\n");
                printf ("b) L2\n");
                printf ("c) L1 e L2\n");
                printf ("d) L3\n");
				op=getche();
				ImprimeLista(L1, L2, L3, op);
                op = 'h';
				break;
            case 'i':
				if (TestesIntersectar(L1,L2,L3)){
                    L3=SllInit();
                    Uniao(L1,L2,L3);
				}
				op='i';
                break;
            case 'j':
                if (TestesIntersectar(L1, L2, L3)){
                    L3=SllInit();
                    Intersectar (L1,L2,L3);
                }
                op='j';
                break;
            case 'k':
                if (TestesIntersectar(L1, L2, L3)){
                    L3=SllInit();
                    Diferenca (L1,L2,L3);
                }
                op='k';
                break;
            case 'l':
                printf("\nQual lista deseja esvaziar?\n");
				printf("a) L1\n");
				printf("b) L2\n");
				printf("c) L3\n");
				op=getche();
				EsvaziaLista(L1, L2, L3, op);
				op = 'l';
				break;
            case 'm':
				exit(-1);
			default:
                printf ("\nOpcao invalida\n");
                break;
        }
    }
}
