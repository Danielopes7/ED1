/*
**	Sll - Tipo Abstrato de Dados para listas lineares simplemente
**        encadeada
**
**	Coment�rios:
**	---------------------------------------------------------------
**
**	Este TAD pode ser usado para gerenciar v�rias listas ao mesmo
**  tempo. Os clientes do TAD indicam a lista que est�o trabalhando
**  atrav�s  de uma etiqueta que � obtida durante a inicializacao
**  atrav�s de uma chamada a SllInit()
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
/*     pr�-condi��o: nenhuma
**     p�s-condi��o: retorna um ponteiro para uma etiqueta
**                   (descritor) da lista
**     Esta fun��o aloca mem�ria para a etiqueta da lista,
**     inicializa a etiqueta, e retorna essa etiqueta para o
**     cliente, de modo que ele pode chamar outras fun��es do
**     TAD Sll para realizar opera��es sobre a lista
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
/*     pr�-condi��o: existe uma etiqueta de lista v�lida
**     p�s-condi��o: retorna o n�mero de elementos na lista ( n>= 0)
**     Esta fun��o conta o n�mero de elementos da lista. Se a lista
**     est� vazia retorna um n�mero negativo(-1), de outro modo
**     retorna o n�mero de elementos.
*/
int SllNumElms(SllHandle *list)
{
    int cont;
    //Verifica se existe uma etiqueta v�lida
    if(list){
        //Posiciona cur na primeira posi��o
        list->cur=list->head;
        //Repete a contagem at� que a �ltima posi��o da lista
        while((list->cur)->next!=NULL){
            cont++;
        }
        return(cont);
    }
    return(-1);
    }

/*=========================  SllRemoveAll  =========================*/
/*   pr�-condi��o: existe uma etiqueta de lista v�lida
**   p�s-condi��o: a etiqueta � um descritor de uma lista sem nenhum
**                 elementos.
**   Esta fun��o remove todos os elementos da lista. Remover significa
**   liberar a mem�ria usada por cada um dos elementos da lista, e
**   liberar a mem�ria usada pelos data da lista. Ao final a etiqueta
**   da lista representa a de uma lista vazia.
*/
void SllRemoveAll(SllHandle *list, void (*FreeData)(void *))
{
	NodeSll *prev, *aux;
	if(list!=NULL){
		aux=list->head;  //aux recebe o endere�o do primeiro elemento da lista
		if(list->head){
			while(aux->next){  //o la�o se quebra quando n�o houver mais n�s
				prev=aux;  //prev recebe o endere�o do aux que � o endere�o de tal n� da lista (do primeiro n� quando entra no la�o)
				FreeData(aux->data); //libera mem�ria ocupada pelo campo data
				aux=aux->next;  //aux recebe o endere�o do pr�ximo n� armazenado no campo next
				free(prev);  //libera a mem�ria ocupada pelo n� anterior ao que o aux se refere atualmente
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
     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: retorna um endere�o de um elemento da lista, se
                   ele for encontrado ou NULL caso contr�rio

     Esta fun��o retorna o endere�o do n� da lista cujos dados
     associados est�o identificados atrav�s da fun��o passada como
     par�metro(Identify) e da chave de identifica��o (key).
*/
void *SllGetElm(SllHandle *list, void *key, int (*Identify)(void *, void *))
{
    //Verifica se a lista existe
    if (list!=NULL){
        //Verifica se a lista possui algum elemento
        if (list->head!=NULL){
            //Current recebe o primeiro da lista
            list->cur=list->head;
            //A condi��o quebra se n�o houver mais elementos na lista ou se Identify retornar TRUE
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
     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento adicional em seu in�cio,
                   retorna verdadeiro ou falso.

    Esta fun��o insere um elemento no in�cio da lista.
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
            //liga o novo n� ao elemento
            newnode->data = elm;
            //liga o novo n� primeiro da lista
            newnode->next = list->head;
            //define o novon� como o primeiro da lista
            list->head = newnode;
            return(TRUE);

        }
    }
return(FALSE);
}


/*=========================  SllInsLastPosition  =========================*/
/*   pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento adicional em seu final,
                   retorna verdadeiro ou falso.

    Esta fun��o insere um elemento no final da lista. Se a lista est� vazia
    ele � inserido na primeira posi��o
*/
int SllInsLastPosition( SllHandle *list, void *elm )
{
	NodeSll *newnode; //cria novo n�
	NodeSll *last;  //vari�vel pra receber endere�o dos n�s e chegar na ultima pos
	if (list){
        newnode=(NodeSll*)malloc(sizeof(NodeSll));
        if (newnode!=NULL){
            newnode->next=NULL; // o campo next do �ltimo n� da lista deve receber NULL
            newnode->data=elm; // campo data recebe os dados
            if (list->head){
                last=list->head; //last recebe endere�o do primeiro n�
                while(last->next!=NULL){  //la�o que passa de n� em n� at� chegar ao �ltimo e para quando n�o houver mais n�s
                    last=last->next;
                }
            last->next=newnode; //quando encontra o �ltimo n� o la�o se quebra e o campo next do �ltimo n� recebe o endere�o do novo n�
            }
            else{
                list->head=newnode; // se a lista estiver vazia newnode � o primeiro n�
            }
            return TRUE;
        }
	}
	return FALSE;
}

/*=========================  SllInsOrdered  =========================*/
/*     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento adicional, inserido de
                   maneira que a mesma continue ordenada, retorna
                   verdeiro ou falso

     Esta fun��o insere um elemento na lista, de acordo com a ordem
     especificada pela fun��o de compara��o passada como par�metro.
     O elemento vai ser inserido antes do primeiro elemento cuja
     compara��o com elm for falsa.
*/
int SllInsOrdered( SllHandle *list,  void *elm, int (*Compare)(void *, void *))
{
    NodeSll *newelm, *q;
    //Verifica existencia da lista
    if (list!=NULL){
        //Aloca o novo elemento da lista
        newelm = (NodeSll *)malloc(sizeof(NodeSll));
        //Verifica a cria��o do novo elemento
        if (newelm!=NULL){
            //Caso a lista esteja vazia, o primeiro recebe newelm.
            if (list->head==NULL){
                list->head = newelm;
                newelm->next = NULL;
            }
            else{
            //Caso a lista n�o esteja vazia, existe ainda duas possibilidades, estas relacionadas
            //� fun��o de compara��o.
                list->cur=list->head;
                q=NULL;
                //O algoritmo sair� da estrutura de repeti��o se Current chegar ao ultimo elemento
                //ou se a compara��o retorna TRUE
                while (((list->cur->next!=NULL)&&(Compare (elm, list->cur->data)!=TRUE))){
                    q=list->cur;
                    list->cur=list->cur->next;
                }
                //Se a compara��o retornou TRUE, � preciso fazer o elemento anterior ao Current
                //apontar para o novo. Em seguida, o novo deve apontar para o Current.
                if (Compare (elm, list->cur->data)==TRUE){
                    q->next = newelm;
                    newelm->next = list->cur;
                }
                //Se a compara��o n�o retornou TRUE, logo a lista chegou ao fim, insere-se newelm
                //como ultimo elemento.
                else{
                    list->cur->next = newelm;
                    newelm->next = NULL;
                }
            }
            //Agora que newelm foi colocado na lista, � hora de pendurar seus dados.
            newelm->data = elm;
            return TRUE;
        }
    }
    return FALSE;
}

/*=========================  SllDelFirstPosition  =========================*/
/*   pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento a menos em seu in�cio,
                   retorna verdadeiro ou falso.

     Esta fun��o remove o primeiro elemento da lista, se ele existir, e
     retorna verdadeiro. Caso contr�rio n�o faz nada e retorna Falso.
*/
int SllDelFirstPosition( SllHandle *list)
{
    //V�riavel auxiliar, para receber o valor do n� a ser deletado
    NodeSll *first;
    //Verifica se a lista existe
    if(list){
        //Verifica se a lista n�o est� vazia, ou seja, se head � diferente de NULL
        if(list->head){
            //guarda o primeiro n� na variavel auxiliar
            first=list->head;
            //verifica se a lista n�o possui um �nico elemento
             if(list->head->next){
                 //"despluga" a handle do primeiro elemento
                 list->head=list->head->next;
             }
             //libera o dado (ui)
             free(first->data);
             //libera o n�
             free(first);
             return(TRUE);
        }

    }
    return(FALSE);
}

/*=========================  SllDelLastPosition  =========================*/
/*     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento a menosl em seu final,
                   retorna verdadeiro ou falso.

    Esta fun��o remove o �ltimo elemento da lista, se a lista n�o estiver
    vazia, e retorna verdadeiro.Caso contr�rio  n�o faz nada e retorna Falso.
*/
int SllDelLastPosition( SllHandle *list )
{
	NodeSll *last; // vari�vel de "controle" pra receber o endere�o dos n�s e chegar na �ltima pos
	if(list!=NULL){
		if(list->head != NULL){
			last=list->head; //last recebe endere�o do primeiro n�
			while(last->next != NULL){   //la�o que passa de n� em n� at� chegar ao �ltimo e para quando n�o houver mais n�s
				last=last->next;
			}
			free(last->data);  //libera os dados do �ltimo n�
			free(last);  //libera o �ltimo n�
			return TRUE;
		}
		return FALSE;
    }
    return FALSE;

}

/*=========================  SllDelElm  =========================*/
/*     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: a lista possui um elemento a menos se o elemento
                   especificado estava na lista, retorna verdeiro ou
                   falso

     Esta fun��o remove o elemento da lista identificado atrav�s
     da fun��o passada como par�metro (Identify) e da chave de
     identifica��o (key). Retorna verdaeiro se o elemento foi
     encontrado na lista e falso caso contr�rio.
*/
int SllDelElm( SllHandle *list,  void *elm, int (*Compare)(void *, void *))
{
    NodeSll *q;
    //verifica se a lista existe
    if (list!=NULL){
        //Verifica se a lista est� vazia
        if (list->head!=NULL){
            list->cur=list->head;
            q=NULL;
            //Estrutura de Repeti��o
            //Condi��es de Quebra: Chegar ao fim da lista ou encontrar o valor (key) em algum dos
            //elementos da lista.
            while ((list->cur->next!=NULL)&&(Compare(elm, list->cur->data)!=TRUE)){
                q=list->cur;
                list->cur=list->cur->next;
            }
            //Caso o valor (key) for encontrado...
            if (Compare(elm, list->cur->data)==TRUE){
                //Se q=NULL, significa que key foi encontrado no primeiro elemento da lista,
                //portanto, list->head deve receber o endere�o do segundo da lista.
                //Caso contr�rio, q deve apontar para o elemento posterior a Current.
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
/*     pr�-condi��o: existe uma etiqueta de lista v�lida
     p�s-condi��o: retorna um elemento da lista de acordo com o
                   tipo de consulta solicitado


    Esta fun��o consulta os elementos da lista. A primeira vez
    que � chamada (com  QueryType igual a FIRST) a fun��o retorna o
    primeiro elemento da lista. Em chamadas subsequentes ( com QueyType
    igual a NEXT) os elementos subsequentes da lista s�o devolvidos
    um a um. A fun��o sempre retorna Verdadeiro se ainda existem
    elementos a consultar, e retorna falso se todos os elementos foram
    consultados. Se a fun��o for chamada com lista vazia, ou depois
    que todos os elementos foram consultados com QueyType NEXT, a
    fun��o retorna FALSO e o valor do ponteiro elm volta como NULL.
*/
int SllQueryElm( SllHandle *list,  QueryType qry, void *elm)
{
    //verifica se lista n�o est� vazia
    if(list->head){
        //verifica se todos os elementos ainda n�o foram acessados
        if(list->cur){
            //Acho esses ifs desnecess�rios, mas o manoles pode mandar um
            //first mais de uma vez por acidente n�?
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
