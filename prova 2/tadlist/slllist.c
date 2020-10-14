/*
**	Sll - Tipo Abstrato de Dados para listas lineares simplemente
**        encadeada
**
**	Comentários:
**	---------------------------------------------------------------
**
**	Este TAD pode ser usado para gerenciar várias listas ao mesmo
**  tempo. Os clientes do TAD indicam a lista que estão trabalhando
**  através  de uma etiqueta que é obtida durante a inicializacao
**  através de uma chamada a SllInit()
**
**	---------------------------------------------------------------
**
**	versao:	0-001
**
**	historico:	Criado    Outubro/2000	Anselmo Paiva
*/

/*
**	---------------------------------------------------------------
**	variaveis globais e simbolos
*/

#include <stdio.h>
#include <malloc.h>
#include "Sll.h"
#ifndef  FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

/*
** --------------------------------------------------------------------
** Variaveis e simbolos locais
*/



/*
**	---------------------------------------------------------------
**	Funcoes Locais (privativas):
*/



/*=========================  SllInit  =========================*/
/*     pré-condição: nenhuma
**     pós-condição: retorna um ponteiro para uma etiqueta
**                   (descritor) da lista
**     Esta função aloca memória para a etiqueta da lista,
**     inicializa a etiqueta, e retorna essa etiqueta para o
**     cliente, de modo que ele pode chamar outras funções do
**     TAD Sll para realizar operações sobre a lista
*/
SllHandle *SllInit( void )
{
    SllHandle *list;
    list=(SllHandle *)malloc(sizeof(SllHandle));
    if (list!=NULL){
       list->head=NULL;
       return list;
    }
    return NULL;
}



/*=========================  SllNumElms  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
**     pós-condição: retorna o número de elementos na lista ( n>= 0)
**     Esta função conta o número de elementos da lista. Se a lista
**     está vazia retorna um número negativo(-1), de outro modo
**     retorna o número de elementos.
*/
int SllNumElms(SllHandle *list)
{
    int cont;
    //Verifica se existe uma etiqueta válida
    if(list){
        //Posiciona cur na primeira posição
        list->cur=list->head;
        //Repete a contagem até que a última posição da lista
        while((list->cur)->next!=NULL){
            cont++;
        }
        return(cont);
    }
    return(-1);
    }

/*=========================  SllRemoveAll  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
**   pós-condição: a etiqueta é um descritor de uma lista sem nenhum
**                 elementos.
**   Esta função remove todos os elementos da lista. Remover significa
**   liberar a memória usada por cada um dos elementos da lista, e
**   liberar a memória usada pelos data da lista. Ao final a etiqueta
**   da lista representa a de uma lista vazia.
*/
void SllRemoveAll(SllHandle *list, void (*FreeData)(void *))
{
	NodeSll *prev, *aux;
	if(list!=NULL){
		aux=list->head;  //aux recebe o endereço do primeiro elemento da lista
		if(list->head){
			while(aux->next){  //o laço se quebra quando não houver mais nós
				prev=aux;  //prev recebe o endereço do aux que é o endereço de tal nó da lista (do primeiro nó quando entra no laço)
				FreeData(aux->data); //libera memória ocupada pelo campo data
				aux=aux->next;  //aux recebe o endereço do próximo nó armazenado no campo next
				free(prev);  //libera a memória ocupada pelo nó anterior ao que o aux se refere atualmente
			}
			FreeData(aux->data);
			free(prev);
			free(aux);
			list->head=NULL;
		}
	}
}

/*=========================  SllQueryElm  =========================*/
/*
     pré-condição: existe uma etiqueta de lista válida
     pós-condição: retorna um endereço de um elemento da lista, se
                   ele for encontrado ou NULL caso contrário

     Esta função retorna o endereço do nó da lista cujos dados
     associados estão identificados através da função passada como
     parâmetro(Identify) e da chave de identificação (key).
*/
void *SllGetElm(SllHandle *list, void *key, int (*Identify)(void *, void *))
{
    //Verifica se a lista existe
    if (list!=NULL){
        //Verifica se a lista possui algum elemento
        if (list->head!=NULL){
            //Current recebe o primeiro da lista
            list->cur=list->head;
            //A condição quebra se não houver mais elementos na lista ou se Identify retornar TRUE
            while ((list->cur!=NULL)&&((Identify (key, list->cur->data))!=TRUE)){
                list->cur=list->cur->next;
            }
            if (list->cur!=NULL){
                if (Identify (key, list->cur->data)==TRUE){
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

/*=========================  SllInsFirstPosition  =========================*/
/*
     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional em seu início,
                   retorna verdadeiro ou falso.

    Esta função insere um elemento no início da lista.
*/
int SllInsFirstPosition( SllHandle *list, void *elm )
{
    NodeSll *newnode;
    //Verifica se a etiqueta existe
    if(list){
        //Aloca um novo elemendo para a lista
        newnode = (NodeSll*) malloc(sizeof(NodeSll));
        //Verifica se o elemento foi alocado
        if(newnode){
            //liga o novo nó ao elemento
            newnode->data = elm;
            //liga o novo nó primeiro da lista
            newnode->next = list->head;
            //define o novonó como o primeiro da lista
            list->head = newnode;
            return(TRUE);

        }
    }
return(FALSE);
}


/*=========================  SllInsLastPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional em seu final,
                   retorna verdadeiro ou falso.

    Esta função insere um elemento no final da lista. Se a lista está vazia
    ele é inserido na primeira posição
*/
int SllInsLastPosition( SllHandle *list, void *elm )
{
	NodeSll *newnode; //cria novo nó
	NodeSll *last;  //variável pra receber endereço dos nós e chegar na ultima pos
	if (list){
        newnode=(NodeSll*)malloc(sizeof(NodeSll));
        if (newnode!=NULL){
            newnode->next=NULL; // o campo next do último nó da lista deve receber NULL
            newnode->data=elm; // campo data recebe os dados
            if (list->head){
                last=list->head; //last recebe endereço do primeiro nó
                while(last->next!=NULL){  //laço que passa de nó em nó até chegar ao último e para quando não houver mais nós
                    last=last->next;
                }
            last->next=newnode; //quando encontra o último nó o laço se quebra e o campo next do último nó recebe o endereço do novo nó
            }
            else{
                list->head=newnode; // se a lista estiver vazia newnode é o primeiro nó
            }
            return TRUE;
        }
	}
	return FALSE;
}

/*=========================  SllInsOrdered  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional, inserido de
                   maneira que a mesma continue ordenada, retorna
                   verdeiro ou falso

     Esta função insere um elemento na lista, de acordo com a ordem
     especificada pela função de comparação passada como parâmetro.
     O elemento vai ser inserido antes do primeiro elemento cuja
     comparação com elm for falsa.
*/
int SllInsOrdered( SllHandle *list,  void *elm, int (*Compare)(void *, void *))
{
    NodeSll *newelm, *q;
    //Verifica existencia da lista
    if (list!=NULL){
        //Aloca o novo elemento da lista
        newelm = (NodeSll *)malloc(sizeof(NodeSll));
        //Verifica a criação do novo elemento
        if (newelm!=NULL){
            //Caso a lista esteja vazia, o primeiro recebe newelm.
            if (list->head==NULL){
                list->head = newelm;
                newelm->next = NULL;
            }
            else{
            //Caso a lista não esteja vazia, existe ainda duas possibilidades, estas relacionadas
            //à função de comparação.
                list->cur=list->head;
                q=NULL;
                //O algoritmo sairá da estrutura de repetição se Current chegar ao ultimo elemento
                //ou se a comparação retorna TRUE
                while (((list->cur->next!=NULL)&&(Compare (elm, list->cur->data)!=TRUE))){
                    q=list->cur;
                    list->cur=list->cur->next;
                }
                //Se a comparação retornou TRUE, é preciso fazer o elemento anterior ao Current
                //apontar para o novo. Em seguida, o novo deve apontar para o Current.
                if (Compare (elm, list->cur->data)==TRUE){
                    q->next = newelm;
                    newelm->next = list->cur;
                }
                //Se a comparação não retornou TRUE, logo a lista chegou ao fim, insere-se newelm
                //como ultimo elemento.
                else{
                    list->cur->next = newelm;
                    newelm->next = NULL;
                }
            }
            //Agora que newelm foi colocado na lista, é hora de pendurar seus dados.
            newelm->data = elm;
            return TRUE;
        }
    }
    return FALSE;
}

/*=========================  SllDelFirstPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menos em seu início,
                   retorna verdadeiro ou falso.

     Esta função remove o primeiro elemento da lista, se ele existir, e
     retorna verdadeiro. Caso contrário não faz nada e retorna Falso.
*/
int SllDelFirstPosition( SllHandle *list)
{
    //Váriavel auxiliar, para receber o valor do nó a ser deletado
    NodeSll *first;
    //Verifica se a lista existe
    if(list){
        //Verifica se a lista não está vazia, ou seja, se head é diferente de NULL
        if(list->head){
            //guarda o primeiro nó na variavel auxiliar
            first=list->head;
            //verifica se a lista não possui um único elemento
             if(list->head->next){
                 //"despluga" a handle do primeiro elemento
                 list->head=list->head->next;
             }
             //libera o dado (ui)
             free(first->data);
             //libera o nó
             free(first);
             return(TRUE);
        }

    }
    return(FALSE);
}

/*=========================  SllDelLastPosition  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menosl em seu final,
                   retorna verdadeiro ou falso.

    Esta função remove o último elemento da lista, se a lista não estiver
    vazia, e retorna verdadeiro.Caso contrário  não faz nada e retorna Falso.
*/
int SllDelLastPosition( SllHandle *list )
{
	NodeSll *last; // variável de "controle" pra receber o endereço dos nós e chegar na última pos
	if(list!=NULL){
		if(list->head != NULL){
			last=list->head; //last recebe endereço do primeiro nó
			while(last->next != NULL){   //laço que passa de nó em nó até chegar ao último e para quando não houver mais nós
				last=last->next;
			}
			free(last->data);  //libera os dados do último nó
			free(last);  //libera o último nó
			return TRUE;
		}
		return FALSE;
    }
    return FALSE;

}

/*=========================  SllDelElm  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menos se o elemento
                   especificado estava na lista, retorna verdeiro ou
                   falso

     Esta função remove o elemento da lista identificado através
     da função passada como parâmetro (Identify) e da chave de
     identificação (key). Retorna verdaeiro se o elemento foi
     encontrado na lista e falso caso contrário.
*/
int SllDelElm( SllHandle *list,  void *elm, int (*Compare)(void *, void *))
{
    NodeSll *q;
    //verifica se a lista existe
    if (list!=NULL){
        //Verifica se a lista está vazia
        if (list->head!=NULL){
            list->cur=list->head;
            q=NULL;
            //Estrutura de Repetição
            //Condições de Quebra: Chegar ao fim da lista ou encontrar o valor (key) em algum dos
            //elementos da lista.
            while ((list->cur->next!=NULL)&&(Compare(elm, list->cur->data)!=TRUE)){
                q=list->cur;
                list->cur=list->cur->next;
            }
            //Caso o valor (key) for encontrado...
            if (Compare(elm, list->cur->data)==TRUE){
                //Se q=NULL, significa que key foi encontrado no primeiro elemento da lista,
                //portanto, list->head deve receber o endereço do segundo da lista.
                //Caso contrário, q deve apontar para o elemento posterior a Current.
                if (q==NULL)
                    list->head=list->cur->next;
                else
                    q->next=list->cur->next;
                free (list->cur);
                return (TRUE);
            }
        }
    }
    return FALSE;
}

/*=========================  SllQueryElm  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: retorna um elemento da lista de acordo com o
                   tipo de consulta solicitado


    Esta função consulta os elementos da lista. A primeira vez
    que é chamada (com  QueryType igual a FIRST) a função retorna o
    primeiro elemento da lista. Em chamadas subsequentes ( com QueyType
    igual a NEXT) os elementos subsequentes da lista são devolvidos
    um a um. A função sempre retorna Verdadeiro se ainda existem
    elementos a consultar, e retorna falso se todos os elementos foram
    consultados. Se a função for chamada com lista vazia, ou depois
    que todos os elementos foram consultados com QueyType NEXT, a
    função retorna FALSO e o valor do ponteiro elm volta como NULL.
*/
int SllQueryElm( SllHandle *list,  QueryType qry, void *elm)
{
    //verifica se lista não está vazia
    if(list->head){
        //verifica se todos os elementos ainda não foram acessados
        if(list->cur){
            //Acho esses ifs desnecessários, mas o manoles pode mandar um
            //first mais de uma vez por acidente né?
            if(qry==FIRST){
                //guarda o valor do primeiro em elm
                elm=list->head->data;
                //"incrementa" o cur da lista :D
                list->cur=list->cur->next;
            }
            if(qry==NEXT){
                //guarda o valor do elemento corrente em elm
                elm=list->cur->data;
                //"incrementa" o cur da lista
                list->cur=list->cur->next;
            }
            return(TRUE);
        }
    }
    //Caso a lista se encerre, seta elm em Null como especificado
    elm=NULL;
    return(FALSE);
}
