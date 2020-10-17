//essa função insere um elemento no inicio de uma lista duplamente encadeada
int dllInsertFirst(Dllist*l,void*data){
    DlNode*novono;
    if(l!=NULL){
                novono=(DlNode*)malloc(sizeof(DlNode));
                if(novono!=NULL){
                                 novono->data=data;
                                 novono->prev=NULL;
                                 novono->next=l->first;
                                 if(l->first!=NULL){
                                                    l->first->next=novono;
                                 }
                                 l->first=novono;
                                 return TRUE;
                }
    }
    return FALSE;
}

//essa função remove o primeiro de uma lista duplamente encadeada
void* dllRemoveFirst(DlList *l){
      DlNode*prim;
      void* data;
      if(l!=NULL){
                  prim=l->first;
                  if(prim!=NULL){
                                 l->first=prim->next;
                  }
                  if(l->first!=NULL){
                                     l->first->prev=NULL;
                  }
                  data=prim->data;
                  free(prim);
                  return data;
      }
      return NULL;
}

//essa função insere no final de uma lista duplamente encadeada
int dllInsertLast(DlList*l,void*data){
    DlNode*ult;
    DlNode*novono;
    if(l!=NULL){
                ult=l->first;
                while(ult->next!=NULL){
                                       ult=ult->next;
                }
                novono=(DlNode*)malloc(sizeof(DlNode));
                if(novono!=NULL){
                                 novono->data=data;
                                 novono->next=NULL;
                                 novono->prev=ult;
                                 if(ult!=NULL){
                                               ult->next=novono;
                                 }
                                 else{
                                      l->first=novono;
                                 }
                                 return TRUE;
                }
    }
    return FALSE;
}

//essa função retorna o numero de nós de uma lista simplesmente encadeada
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
//esa função remove os impares de uma lista linear simplesmente encadeada e transforma em uma lista circular simplesmente encadeada
int RemoveImpares(sllist *l){
    slnode*prim,*del,*cur;
    if(l!=NULL){
                if(l->first!=NULL){
                                   prim=l->first;
                                   l->first=l->first->next;
                                   cur=l->first;
                                   while(cur->next!=NULL){
                                                          del=cur->next;
                                                          cur->next=del->next;
                                                          free(del);
                                                          cur=cur->next;
                                   }
                                   cur->next=l->first;
                                   free(prim);
                                   return TRUE;
                }
    }
    return FALSE;
}

//essa função remove os impares de lista linear simplesmente encadeada
int RemoveImpares(sllist *l){
    slnode*prim,*del,*cur;
    if(l!=NULL){
                if(l->first!=NULL){
                                   prim=l->first;
                                   l->first=l->first->next;
                                   cur=l->first;
                                   while(cur->next!=NULL){
                                                          del=cur->next;
                                                          cur->next=del->next;
                                                          free(del);
                                                          cur=cur->next;
                                   }
                                   free(prim);
                                   return TRUE;
                }
    }
    return FALSE;
}

//essa função concatena duas listas circulares simplesmente encadeadas e retorna uma outra
//lista circular simplesmente encadeada
sllist* concatena(sllist* l1,sllist* l2){
        sllist* l3;
        slnode* ult;
        if(l1!=NULL && l2!=NULL){
                    l3=slCreate();
                    if(l3!=NULL){
                                 if(l1->first!=NULL){
                                                     if(l2->first!=NULL){
                                                                         ult=l1->first;
                                                                         while(ult->next!=l1->first){
                                                                                                     ult->ult->next;
                                                                         }
                                                                         ult->next=l2->first;
                                                                         ult=ult->next;
                                                                         while(ult->next!=l2->first){
                                                                                                     ult=ult->next;
                                                                         }
                                                                         ult->next=l1->first;
                                                                         l3->first=l1->first;
                                                                         l1->first=NULL;
                                                                         l2->first=NULL;
                                                     }
                                                     else{
                                                          l3->first=l1->first;
                                                          l1->first=NULL;
                                                     }
                                 else{
                                      l3->first=l2->first;
                                      l2->first=NULL;
                                 }
                                 return l3;
                    }
        }
        return NULL;
}

//essa função concatena duas listas linear simplesmente encadeadas e retorna uma outra
//lista linear simplesmente encadeada
sllist* concatena(sllist* l1,sllist* l2){
        sllist* l3;
        slnode* ult;
        if(l1!=NULL && l2!=NULL){
                    l3=slCreate();
                    if(l3!=NULL){
                                 if(l1->first!=NULL){
                                                     if(l2->first!=NULL){
                                                                         ult=l1=first;
                                                                         while(ult->next!=NULL){
                                                                                                     ult->ult->next;
                                                                         }
                                                                         ult->next=l2->first;
                                                                         ult=ult->next;
                                                                         while(ult->next!=NULL){
                                                                                                     ult=ult->next;
                                                                         }
                                                                         l3->first=l1->first;
                                                                         l1->first=NULL;
                                                                         l2->first=NULL;
                                                     }
                                                     else{
                                                          l3->first=l1->first;
                                                          l1->first=NULL;
                                                     }
                                 else{
                                      l3->first=l2->first;
                                      l2->first=NULL;
                                 }
                                 return l3;
                    }
        }
        return NULL;
}

//essa função realiza a interseção entre duas listas linear simplesmente encadeadas                    
int sllIntersect(sllist* l1,sllist* l2,sllist* l3){
    slnode* elm1;
    slnode* prev;
    slnode* elm2;
    slnode* aux;
    int stat;
    if(l1!=NULL && l2!=NULL && l3!=NULL){
                if(l1->first!=NULL && l2->first!=NULL){
                                   elm1=l1->first;
                                   prev=NULL;
                                   while(elm1!=NULL){
                                                     elm2=l2->first;
                                                     stat=FALSE;
                                                     while(elm2!=NULL && stat==FALSE){
                                                                      if(cmp(elm1->data,elm2->data)==TRUE){
                                                                                                           aux=elm1;
                                                                                                           elm1=elm1->next;
                                                                                                           stat=TRUE;
                                                                                                           if(l1->first==aux){
                                                                                                                              l1->first=aux->next;
                                                                                                           }
                                                                                                           else{
                                                                                                                prev->next=elm1;
                                                                                                           }
                                                                                                           if(l3->first==NULL){
                                                                                                                               l3->first=aux;
                                                                                                                               aux->next=NULL;
                                                                                                           }
                                                                                                           else{
                                                                                                                               aux->next=l3->first;
                                                                                                                               l3->first=aux;
                                                                                                           }
                                                                      }
                                                                      elm2=elm2->next;
                                                     }
                                                     if(stat==FALSE){
                                                                     prev=elm1;
                                                                     elm1=elm1->next;
                                                     }
                                   }
                                   return l3;
                }
    }
    return NULL;
}

//essa função inverte uma lista linear simplesmente encadeada 1º metodo
sllist *Inverte(sllist *l1){
       sllist *l2;
       slnode *ult;
       slnode *penult;
       slnode *aux;
       if(l1!=NULL){
                    if(l1->first!=NULL){
                                        l2=sllCreate();
                                        if(l2!=NULL){
                                                     while(l1->first==NULL){
                                                                            ult=l1->first;
                                                                            penult=NULL;
                                                                            while(ult->next!=NULL){
                                                                                                   penult=ult;
                                                                                                   ult=ult->next;
                                                                            }
                                                                            if(ult==l1->first){
                                                                                               l1->first=NULL;
                                                                            }
                                                                            else{
                                                                                 penult->next=NULL;
                                                                            }
                                                                            if(l2->first==NULL){
                                                                                                l2->first=ult;
                                                                            }
                                                                            else{
                                                                                 aux=l2->first;
                                                                                 while(aux->next!=NULL){
                                                                                                        aux=aux->next;
                                                                                 }
                                                                                 aux->next=ult;
                                                                            }
                                                     }
                                                     return l2;
                                        }
                    }
       }
       return NULL;
} 
//essa função inverte uma lista linear simplesmente encadeada 2º metodo
sllist *Inverte(sllist *l1){
       sllist *l2;
       slnode *aux;
       if(l1!=NULL){
                    if(l1->first!=NULL){
                                        l2=sllCreate();
                                        if(l2!=NULL){
                                                     while(l1->first!=NULL){
                                                                            aux=l1->first;
                                                                            l1->first=aux->next;
                                                                            if(l2->first==NULL){
                                                                                                l2->first=aux;
                                                                                                aux->next=NULL;
                                                                            }
                                                                            else{
                                                                                 aux->next=l2->first;
                                                                                 l2->first=aux;
                                                                            }
                                                     }
                                                     return l2;
                                        }
                    }
       }
       return NULL;
}                                                      
                           
//essa função remove o spec especificado e o seguinte de uma lista linear duplamente encadeada 
int RemoveSpecESpecNext(dllist *l1,void *key, int(*cmp)(void*,void*)){
    dlnode *spec;
    if(l!=NULL){
                if(l->first!=NULL){
                                   if(l->first->next!=NULL){
                                                            spec=l->first;
                                                            while(cmp(spec->data,key)==TRUE && spec->next!=NULL){
                                                                                            spec=spec->next;
                                                            }
                                                            if(cmp(spec->data,key)==TRUE){
                                                                                          if(spec->next!=NULL){
                                                                                                               if(l->first==spec){
                                                                                                                                  l->first=spec->next->next;
                                                                                                                                  l->first->prev=NULL;
                                                                                                               }
                                                                                                               else{
                                                                                                                    spec->prev->next=spec->next->next;
                                                                                                                    spec->next->next->prev=spec->prev;
                                                                                                               }
                                                                                                               free(spec->next);
                                                                                                               free(spec);
                                                                                                               return TRUE;
                                                                                          }
                                                            }
                                   }
                }
    }
    return FALSE;
}
  
//essa função remove o k-esimo nó de uma lista linear simplesmente encadeada

void* Removek(sllist *l, int k){
      slnode *aux, *ant;
      void *data;
      if(l!=NULL){
                  if(l->first!=NULL){
                                     aux=l->first;
                                     ant=NULL;
                                     while(aux!=NULL && k==0){
                                                     ant=aux;
                                                     aux=aux->next;
                                                     k--;
                                     }
                                     if(k==0){
                                              data=aux->data;
                                              if(aux==l->first){
                                                                l->first=aux->next;
                                              }
                                              else{
                                                   ant->next=aux->next;
                                              }
                                              free(aux);
                                              return data;
                                     }
                  }
      }
      return NULL;
}
//essa função remove o k-esimo nó de uma lista linear duplamente encadeada
void* Removek(dllist *l, int k){
      slnode *aux;
      void *data;
      if(l!=NULL){
                  if(l->first!=NULL){
                                     aux=l->first;
                                     while(aux!=NULL && k==0){
                                                     aux=aux->next;
                                                     k--;
                                     }
                                     if(k==0){
                                              data=aux->data;
                                              if(aux==l->first){
                                                                l->first=aux->next;
                                                                aux->next->prev=NULL;
                                              }
                                              else{
                                                   aux->prev->next=aux->next;
                                                   aux->next->prev=aux->prev;
                                              }
                                              free(aux);
                                              return data;
                                     }
                  }
      }
      return NULL;
}

//essa função remove spec e os seus vizinhos, ou seja, remove spec, o seu anterior e o seu posterior de uma 
//lista linear simplesmente encadeada
int RemoveOCaraEOsVizinhos(sllist *l, void *key, int (*cmp)(void*,void*)){
    slnode *antant, *ant, *spec;
    if(l!=NULL){
                if(l->first!=NULL){
                                   antant=NULL;
                                   ant=NULL;
                                   spec=l->first;
                                   while(cmp(spec->data,key)!=TRUE && spec->next!=NULL){
                                                                   antant=ant;
                                                                   ant=spec;
                                                                   spec=spec->next;
                                   }
                                   if(cmp(spec->data,key)==TRUE){
                                                                 if(ant!=NULL && spec->next!=NULL){
                                                                              if(ant==l->first){
                                                                                                l->first=spec->next->next;
                                                                              }
                                                                              else{
                                                                                   antant->next=spec->next->next;
                                                                              }
                                                                              return TRUE:
                                                                 }
                                   }
                }
    }
    return FALSE;
}

//essa função remove spec e os seus vizinhos, ou seja, remove spec, o seu anterior e o seu posterior de uma 
//lista linear duplamente encadeada
int RemoveOCaraEOsVizinhos(dllist *l, void *key, int (*cmp)(void*,void*)){
    dlnode *ant, *spec;
    if(l!=NULL){
                if(l->first!=NULL){
                                   ant=NULL;
                                   spec=l->first;
                                   while(cmp(spec->data,key)!=TRUE && spec->next!=NULL){
                                                                   ant=spec;
                                                                   spec=spec->next;
                                   }
                                   if(cmp(spec->data,key)==TRUE){
                                                                 if(ant!=NULL && spec->next!=NULL){
                                                                              if(ant==l->first){
                                                                                                l->first=spec->next->next;
                                                                                                l->first->prev=NULL;
                                                                              }
                                                                              else{
                                                                                   ant->prev->next=spec->next->next;
                                                                                   spec->next->next->prev=ant-prev;
                                                                              }
                                                                              return TRUE:
                                                                 }
                                   }
                }
    }
    return FALSE;
}
//a primeria                                                                                      
int Trasforma(dllist* l){
    dlnode*aux;
    if(l!=NULL){
                if(l->first!=NULL){
                                   aux=l->first;
                                   while(aux->next!=l->first){
                                                              aux->prev=NULL;
                                                              aux=aux->next;
                                   }
                                   aux->next=NULL;
                                   return TRUE;
                }
    }
    return FALSE;
}

//a segunda
int DividirLista(sllist *l1,sllist*l2){
    slnode*cur1,*cur2;
    if(l2!=NULL){                 
                 if(l1!=NULL){
                             if(l1->first!=NULL){
                                                cur1=l->first;
                                                l2->first=cur1->next;
                                                cur2=l2->first;
                                                while(cur1->next!=NULL){
                                                          cur1->next=cur1->next->next;
                                                          cur1=cur1->next;
                                                          cur2->next=cur1->next;
                                                          cur2=cur2->next;
                                                }
                                                return TRUE;
                             }
                 }
    }
    return FALSE;
}
