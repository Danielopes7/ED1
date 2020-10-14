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
**	historico:	Criado    Junho/2011	Felipe Arag�o e Luciana Mendes
*/

/*
**	---------------------------------------------------------------
**	variaveis globais e simbolos
*/

#include <stdio.h>
#include "listas.h"


/*
** --------------------------------------------------------------------
** Variaveis e simbolos locais
*/
 typedef struct _sllhadle{
        Node *first;
        Node *cur;
        }Sll;

typedef struct _sllnode_{
         struct _sllnode_*next;
         void  *data;
         }Slln;
/*
**	---------------------------------------------------------------
**	Funcoes Locais (privativas):
*/



/*=========================  SllCreate  =========================*/
/*     pré-condição: nenhuma
**     pós-condição: retorna um ponteiro para uma etiqueta
**                   (descritor) da lista
**     Esta função aloca memória para a etiqueta da lista, 
**     inicializa a etiqueta, e retorna essa etiqueta para o 
**     cliente, de modo que ele pode chamar outras funções do 
**     TAD Sll para realizar operações sobre a lista
*/     
SllList *SllCreate() {
 		  SllList *l;
 		  
 		  l = (SllList *)malloc (sizeof (SllList));
 		  if (l != NULL){
		  	 	l->first = NULL;
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
int SllNumElms(SllList *list) {
	Node *aux;
	int cont = 0;
	
 	if (list != NULL){
	   	  if (list->first != NULL){
	 		   aux = list->first;
			   while (aux != NULL){
			   		 aux = aux->next;
			   		 cont++;
   		 	   }
	 	   	   return cont;
  		  }
  	}
  	return -1;
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
int sllRemoveAll(SllList *l, int (*freedata)(void*)) {
	Node *aux, *atual;
 	 
 	 if (l != NULL){
	 	if (l->first != NULL){
		   atual = l->first;
		   while (atual != NULL){
		   		 aux = atual;
				 atual = atual->next;
				 if (freedata(aux->data) == True){/*falta fazer a fun��o freedata */
		   		 	free (aux);
 	   			 }
				 else {
				 	return False;
	 	  		 }
	  	   }
	  	   l->first = NULL;
		   return True;  
	  	}
   	 }
	 return False;
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
void *sllQueryElms(SllList *l, void *key,int (*Id)(void *, void *)) {
	 Node *ult;
	 
	 if (l != NULL){
	 	   if (l->first != NULL){
	  			ult = l->first;
	  			while (Id (ult->data, key) == False || ult->next != NULL){
					  ult = ult->next;
  				}
  				if (Id (ult->data, key) == True){
				   	   return ult->data;
   	  			}
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
  int sllInsertFirstPosition(SllList *l,void *data) {
  Node *newnode;
  if (l != NULL){
  	 	newnode = (Node *) malloc (sizeof (Node));
  	 	if (newnode != NULL){
  			newnode->data = data;
  			newnode->next = l->first;
  			l->first = newnode;
  			return True;
 	  	}
  }
  return False;
}

/*=========================  SllInsLastPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional em seu final, 
                   retorna verdadeiro ou falso.
     
    Esta função insere um elemento no final da lista. Se a lista está vazia 
    ele é inserido na primeira posição
*/   
int SllInsLastPosition(SllList *list, void *data ) {
   Node *elem, *ult;
   
   if (list != NULL){
 		elem = (Node *)malloc (sizeof (Node));
 		if (elem != NULL){
		   elem->data = data;
		   elem->next = NULL;
		   if (list->first != NULL){
		   	  ult = list->first;
		   	  while (ult->next != NULL){
			  		ult = ult->next;
		   	  }
  	   		  ult->next = elem;
	  	   }
	  	   else {
		   		list->first = elem;
  		   }
		   return True;
	  	}
   }
   return False;
}
   
/*=========================  SllInsOrdered  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento adicional, inserido de
                   maneira que a mesma continue ordenada, retorna 
                   verdeiro ou falso

     Esta função insere um elemento na lista, de acordo com a ordem 
     especificada pela função de comparação passada como parâmetro. 
     O elemento vai ser inserido antes do primeiro elemento cuja 
     comparação com elm for falsa.?????????????????????????????????????????
*/    
int sllInsodered(SllList *l, void *data, void *key, int (*compare)(void*, void*)) {
	Node *elem, *ult, *prev;
	
	if (l != NULL){
	   	  elem = (Node *)malloc (sizeof (Node));
	   	  if (elem != NULL){
		  	 	   elem->data = data;
 	 	   	 if (l->first != NULL){
	 		 		ult = l->first;
	 		 		prev = NULL;
					  while (ult->next != NULL && compare (key, ult->data) == False){
					  		prev = ult;
					  		ult = ult->next;
			  		  }
					  if (compare (key, ult->data) == True){
 	 		  		  	 if (prev != NULL){
						 	elem->next = ult;
							prev->next = elem;	 
  	  					 }
  	  					 else {
						 	elem->next = l->first;
  							l->first = elem; 
			 	   		 }
			 	   		 return True;
		  	 		  }  
  			 }
 		  }   	  
 	}
 	return False;
}    

/*=========================  SllDelFirstPosition  =========================*/
/*   pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menos em seu início, 
                   retorna verdadeiro ou falso.
     
     Esta função remove o primeiro elemento da lista, se ele existir, e 
     retorna verdadeiro. Caso contrário não faz nada e retorna Falso.
*/    
void *SllDelFirstPosition(SllList *l) {
	Node * elem;
	void *data;
	
	if (l != NULL){
	   	  if (l->first != NULL){
	 		   elem = l->first;
			   data = elem->data;
	 		   l->first = elem->next;
			   free (elem);
			   return data;
 		  }
 	}
  
} 
   
/*=========================  SllDelLastPosition  =========================*/
/*     pré-condição: existe uma etiqueta de lista válida
     pós-condição: a lista possui um elemento a menosl em seu final, 
                   retorna verdadeiro ou falso.

    Esta função remove o último elemento da lista, se a lista não estiver 
    vazia, e retorna verdadeiro.Caso contrário  não faz nada e retorna Falso.
*/

/*    //SllDelFirstPosition
void *SllDelLastPosition(SllList *l, void *data) {
  Node *elem, *ult, *penult;
   
   if (l != NULL){
 	  if (l->first != NULL){
		   ult = l->first;
		   penult  = NULL;
		   while (ult->next != NULL){
  		   		 penult = ult;
				 ult = ult->next;
		   }
		   if (penult != NULL){
 		   	  penult->next = NULL;
	  	   }
	  	   else {
		   		l->first = NULL;
  		   }
  		   
  		   data = ult->data;
  		   free (ult);
  		   return data;
	  	}
   } 		 
   return NULL;
} 
  */     
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
int SllDelElm (SllList *l, void *key, int (*Id)(void *, void *)){
    Node *prev, *cont;
    void *data;
    if (l != NULL){
        if (l->first != NULL){
            
			prev = NULL;
            cont = l->first;
            
			while (Id (cont->data, key) != True && cont->next != NULL){
                prev = cont;
                cont = cont->next;
            }
            
			if (Id (cont->data, key) == True){
                if (prev == NULL){
                    l->first = cont->next;
                }
                else {
                    prev->next = cont->next;
                }
                data = cont->data;
                free (cont);
                return True;
	  		}
        }
    }
    return False;
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
    ??????????????????
*/
//int SllQueryElm( void *list,  QueryType qry, void *elm) {
	
  
//}      
SllList *sllIntersection (SllList *list1, SllList *list2, int (*Id)(void * , void *)) {
	   SllList *list3;
	   Node *ult, *aux;
	   void *data;
	   
	   if (list1 != NULL && list2 != NULL){
	   	  		 if (list1->first != NULL && list2->first != NULL){
		  				  list3 = SllCreate();
		  				  if (list3 != NULL){
	  	 		 		  	 	ult = list1->first;
								while (ult->next != NULL){							  
									  aux = list2->first;
									  while (Id(aux->data, ult->data)!=True && aux->next != NULL){
									  		aux = aux->next;
							  		  }
							  		  if (Id(aux->data, ult->data)==True){
  	 				 				  	 	if (SllInsLastPosition(list3, aux->data)!= True){
											   	return NULL;
											}	
						  	 		  }
							  	ult = ult->next;	  
						  		}
								return list3;	
 	 					  }
 	 			 }
  	   }
  	   return NULL;
}

SllList *sllUnion (SllList *list1, SllList *list2, int (*Id)(void *, void *)){
	   SllList *list3;
	   Node *ult, *aux, *cont;
	   void *data;

	   if (list1 != NULL && list2 != NULL){
	   	  		 if (list1->first != NULL && list2->first != NULL){
		  				  list3 = SllCreate();
		  				  if (list3 != NULL){
	  	 		 		  	 	ult = list1->first;
	  	 		 		  	 	
								while (ult != NULL){
									data = ult->data;  
									if (SllInsLastPosition (list3, data)!= True){//colocando os elementos da lista 1 na lista 3
   			   						   return NULL;
   			   						}
									ult = ult->next;  
	  	 		   				}
	  	 		   				
	  	 		   				cont = list2->first;
	  	 		   				while (cont != NULL){
									  aux = list3->first;
									  while (aux->next != NULL && Id(aux->data,cont->data)== False){ //para veritivar se existe elemento igual na lista
									  		aux = aux->next;
							  		  }
							  		  if (aux->next == NULL){
									  	 	data = cont->data;
											if (SllInsLastPosition(list3, data) != True){//colocando os elementos da lista 2 na lista 3
											   	 return NULL; 
			   	  							}
						  	 		  }
						  	 		  cont = cont->next;
  	 		   					}
  	 		   					return list3;
 	 					  }
 	 			 }
  	   }
  	   return NULL;
}

SllList *sllDiference (SllList *list1, SllList *list2, int (*Id)(void *, void *)){
	   SllList *list3;
	   Node *ult, *aux;
	   void *data;
	   
	   if (list1 != NULL && list2 != NULL){
	   	  		if (list1->first != NULL && list2->first != NULL){
		  				list3 = SllCreate();
		  				  if (list3 != NULL){
	  	 		 		  	 	ult = list1->first;
								while (ult->next != NULL){							  
									  aux = list2->first;
									  while (Id(aux->data, ult->data)!=True && aux->next != NULL){
									  		aux = aux->next;
							  		  }
							  		  if (Id(aux->data, ult->data)!=True){
  	 				 				  	 	if (SllInsLastPosition(list3, ult->data)!= True){
											   	return NULL;
											}	
						  	 		  }
							  	ult = ult->next;	  
						  		}
								return list3;	
						}
				}
	  }
				 return NULL;
}

void imprimir (SllList *l, int (*Id)(void *)){
	 Node *elem;
	 
	 if (l != NULL){
  	 	if (l->first != NULL){
			  elem = l->first;
	 	      while (elem != NULL){
			 	   Id (elem->data);
			 	   elem = elem->next;
  			 }
	 	}		  	 
  	 }
}

void imprimirCircular (SllList *l, int (*Id)(void *)){
	 Node *elem;
	 
	 if (l != NULL){
  	 	if (l->first != NULL){
			  elem = l->first;
	 	      do{
			 	   Id (elem->data);
			 	   elem = elem->next;
  			 }while (elem != l->first);
	 	}		  	 
  	 }
}

int Enquere (SllList *l, void *data){ /*CrazyList �h o msm de SllList, que aser� usado no probrama de conjunto para teste*/
    Node *aux, *novo;
    
    if (l != NULL){
        novo = (Node *)malloc (sizeof(Node));
        if (novo != NULL){
            novo->data = data;
            if (l->first == NULL){
                l->first = novo;
                aux = l->first;
                novo->next = aux;
                return True;
            }
            else{
                aux = l->first;
                novo->next = aux->next;
                aux->next = novo;
                l->first = novo;
                return True;
            }
        }
    }
    return False;
}

void *Quere (SllList *l){
    void *data;
    Node *aux, *ult;
    if (l != NULL){
        if (l->first != NULL){
            aux = l->first;
            if (l->first != aux->next){
                ult = aux->next;
                aux->next = ult->next;
                data = ult->data;
                free (ult);
            }
            else {
                data = aux->data;
                free(aux);
            }
            return data;
        }
    }    
    return NULL;
}

SllList *sllTakeRepeat(SllList *l){
       Node *cur, *cur2;
       SllList *newl;
       if(l!=NULL){
                   if(l->first!=NULL){
                                      newl=SllCreate();
                                      cur=l->first;
                                      SllInsLastPosition(newl,cur->data);
                                      cur2=newl->first;
                                      while(cur!=NULL){
                                                       while(cur2->next!=NULL && cur->data!=cur2->data){
                                                                              cur2=cur2->next;
                                                       }
                                                       if(cur->data==cur2->data){
                                                                                 cur=cur->next;
                                                                                 cur2=newl->first;
                                                       }
                                                       else{
                                                            SllInsLastPosition(newl,cur->data);
                                                            cur=cur->next;
                                                            cur2=newl->first;
                                                       }
                                      }
                                      return newl;
                   }
       }
       return NULL;
}
