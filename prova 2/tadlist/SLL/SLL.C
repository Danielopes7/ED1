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
#include "SLL.h"
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

  typedef struct _slNode_ {
          void * data;
          struct _slNode_ * next;
          } SLLNode;

  typedef struct _sllist_{
          SLNode * first;
  } SLList;

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
SLList * sllInit( void )
{
       SLList *l;
       
       l=(SLList *)malloc(sizeof(SLList));
       if (l!=NULL) {
                    l->first=NULL;
                    return l;
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
int SllNumElms(void *list);

{


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
void SllRemoveAll(void *list, void (*FreeData)(void *))
{
  
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
void *SllQueryElm(SLList *l, void *key, int (*IdMaq)(void *, void *))
{
     SLNode * jog;
     
     if (l!=NULL) {
         if (l->first!=NULL) {
             jog=l->first;
             while(IdMaq(key,jog->data)!=TRUE&&jog->next!=NULL) {
                  jog=jog->next;
             }
             if(IdMaq(key,jog->data)==TRUE)
                return (jog->data);
         }
     }
     return NULL;                                                                          
  
}

/*=========================  SllInsFirstPosition  =========================*/
/*
     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional em seu início, 
                   retorna verdadeiro ou falso.
     
    Esta função insere um elemento no início da lista. 
*/   
int SllInsFirstPosition( SLList * l, void * data )
{
    SLNode * newelm;
    
    if (l!=NULL) {
        newelm=(SLNode *)malloc(sizeof(SLNode));
        if (newelm!=NULL) {
             newelm->data=data;
             newelm->next=l->first;
             l->first=newelm;
             return TRUE;
        }
    }
    return FALSE;                      
  
} 

/*=========================  SllInsLastPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional em seu final, 
                   retorna verdadeiro ou falso.
     
    Esta função insere um elemento no final da lista. Se a lista está vazia 
    ele é inserido na primeira posição
*/   
int SllInsLastPosition( SLList *l, void *data )
{
  SLNode * newnode;
  SLNode *ult;
  
  if (l!=NULL) {
      newnode=(SLNode *)malloc(sizeof(SLNode));
      if (newnode!=NULL) {
          newnode->next=NULL;
          newnode->data=data;
          if(l->first!=NULL) 
             ult=l->first;   
          while (ult->next!=NULL) {
                ult=ult->next;
          }
          ult->next=newnode;
      }else{
            l->first=newnode;
      }
      return TRUE;
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
int SllInsOrdered( void *list,  void *elm, void (*Compare)(void *, void *))
{
  
}    

/*=========================  SllDelFirstPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menos em seu início, 
                   retorna verdadeiro ou falso.
     
     Esta função remove o primeiro elemento da lista, se ele existir, e 
     retorna verdadeiro. Caso contrário não faz nada e retorna Falso.
*/    
void * SllDelFirstPosition( SLList *l )
{
    SLNode *aux;
    void *data;
    
    if (l!=NULL){
       if(l->first!=NULL) {
          aux=l->first;
          l->first=aux->next;
          data=aux->data;
          free(aux);
          return data;
       }
    }
    return NULL;                          
  
} 
   
/*=========================  SllDelLastPosition  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menosl em seu final, 
                   retorna verdadeiro ou falso.

    Esta função remove o último elemento da lista, se a lista não estiver 
    vazia, e retorna verdadeiro.Caso contrário  não faz nada e retorna Falso.
*/
int SllDelLastPosition( SLList * l)
{
    SLNode *ult,*penult;
    void * data;
    
    if(l!=NULL) {
       if(l->first!=NULL) {
           penult=NULL;
           ult=l->first;
           while (ult->next!=NULL) {
                 penult=ult;
                 ult=ult->next;
           }
           if (penult!=NULL)
             penult->next=NULL;
           else
             l->first=NULL
           data=ult->data
           free(ult);
           return data;
       } 
    }                              
    return NULL;
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
int SllDelElm( SLList *l,  void *key, void (*IdMaq)(void *, void *))
{
    void *data;
    SLNode *atual, *prev;
    
    if (l!=NULL){
       if(l->first!=NULL) {
           atual=l->first;
           prev=NULL;
           while(IdMaq(atual->data,key)!=TRUE && atual->next!=NULL) {
                 prev=atual;
                 atual=atual->next;
           }
           if(IdMaq(atual->data,key)==TRUE) {
                 data=atual->data;
                 if(prev!=NULL)
                   prev->next=atual->next;
                 else
                   l->first=atual->next;
                  free(atual);
                  return TRUE;
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
int SllQueryElm( void *list,  QueryType qry, void **elm)
{
  
}      
