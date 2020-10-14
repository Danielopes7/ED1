#include "sll.h"
#include <stdlib.h>
#include <stdio.h>


int sllUnion(SLList *l1, SLList *l2) {
    SLList *uniao;
    SLNode *jog;
    int aux;
    
    if (l1!=NULL) {
        if (l2!=NULL) {
            if (l1->first!=NULL) {
               if (l2->first!=NULL) {
                  uniao=sllInit();
                 if(uniao!=NULL){ 
                  jog=l1->first;
                  while (jog->next!=NULL)
                      SllInsFirstPosition( uniao, jog->data );                                                   
                      jog=jog->next;
                  }
                  jog=l2->first;
                  while (jog->next!=NULL) {
                        aux=SllQueryElm(uniao, jog->data, int (*IdMaq)(void *, void *));
                        if (aux==NULL) {
                            SllInsLastPosition( uniao, jog->data);
                        }
                        jog=jog->next;
                  }
                  return(intersec);
                 }
               }
            }
        }
    }  
    return NULL;
}

SLList * sllIntersection (SLList *l1, SLList *l2) {
    
    SLList *inters;
    SLNode *jog;
    int aux;
    
    
    if (l1!=NULL) {
        if (l2!=NULL) {
            if (l1->first!=NULL) {
               if (l2->first!=NULL) {
                    inters=sllInit();
                    if (inters!=NULL) {
                       jog=l1->first;
                       while (jog->next!=NULL){
                           aux=SllQueryElm(l2, jog->data, int (*IdMaq)(void *, void *));                                
                           if (aux!=NULL) {
                              SllInsFirstPosition(inters, jog->data );
                           }
                           jog=jog->next;
                       } 
                       return(inters);                    
                    } 
               }
            }
        }
    }
    return NULL;                                  
}

SLList * sllNaoContem (SLList *l1, SLList *l2) {
       
       SLList * l3;
       SLNode jog;
       int aux
       
       if (l1!=NULL) {
          if (l2!=NULL) {
            if (l1->first!=NULL) {
               if (l2->first!=NULL) {
                    l3=sllInit();
                    if (l3!=NULL) {
                       jog=l1->first;
                       while (jog->next!=NULL) {
                           aux=SllQueryElm(l2, jog->data, int (*IdMaq)(void *, void *));                                
                           if (aux==NULL) {    
                                SllInsFirstPosition(l3, jog->data );
                           }
                           jog=jog->next;
                       } 
                       return(l3);   
                    }
               }
            }
          }
       }
       return NULL;
}
