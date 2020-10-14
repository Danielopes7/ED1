void dllRemoveMenores(Dllist *l, void *spec, int (*menor)(void*,void*)){
    Dlnode *cur, *next;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            while (cur!=NULL) {
                stat = menor(cur->data, spec);
                next = cur->next;
                if(stat == TRUE){
                    /* se cur é menor que spec */
                    /* se cur for o primeiro elemento */
                    if(cur->prev == NULL){
                        /* o primeiro passa a ser o próximo */
                        l->first = next;
                        if(next!=NULL){
                            next->prev = NULL;
                        }
                    }
                    /* se cur não for o primeiro */
                    else{
                        /* remove o cur da lista */
                        cur->prev->next = next;
                        if(next!=NULL){
                            next->prev = cur->prev;
                        }
                    }
                    /* libera o cur */
                    free(cur);
                }
                /* o cur passa a ser o próximo */
                cur = next;
            }
        }
    }
}


void *sllRemoveAnterior(Sllist *l, void *spec, int (*cmp)(void*, void*)){
    Slnode *pprev, prev, cur;
    void *data;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
             if(l->first->next!=NULL){
                 /* o atual é o segundo e o anterior é o primeiro */
                 pprev = NULL;
                 prev = l->first;
                 cur = l->first->next;
                 stat = cmp(cur->data, spec);
                 /* enquanto o atual não for o procurado e ainda exista coisa na lista */
                 while (stat!=TRUE && cur->next!=NULL) {
                     /* todos vão uma casa a frente */
                     pprev = prev;
                     prev = cur;
                     cur = cur->next;
                     stat = cmp(cur->data, spec);
                 }
                 /* se encontrou o procurado */
                 if (stat == TRUE) {
                     /* se o procurado for o segundo */
                     if(pprev == NULL){
                         /* o procurado passa a ser o primeiro */
                         l->first = cur;
                     }
                     else{
                         /* senão, o segundo-anterior passa a apontar para o procurado*/
                         pprev->next = cur;
                     }
                     data = prev->data;
                     free(prev);
                     return data;
                 }
             }

        }
    }
    return NULL;
}

void sllComunsDasListas(Sllist *l1, Sllist *l2, Sllist *l3, int(*cmp)(void*, void*)){
    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL && l2->first!=NULL){
            cur1 = l1->first;
            prev1 = NULL;
            while (cur1!=NULL) {
                cur2 = l2->first;
                prev2 = NULL;
                stat = cmp(cur1->data, cur2->data);
                while (stat!=TRUE && cur2->next!=NULL) {
                    prev2 = cur2;
                    cur2 = cur2->next;
                    stat = cmp(cur1->data, cur2->data);
                }
                /* se encontrou um igual */
                if(stat==TRUE){
                    /* retira de l1 */
                    if(prev1 == NULL){
                        l1->first = cur1->next;
                    }
                    else{
                        prev1->next = cur1->next;
                    }

                    /* retira de l2 */
                    if(prev2 == NULL){
                        l2->first = cur2->next;
                    }
                    else{
                        prev2->next = cur2->next;
                    }
                    free(cur2);

                    /*insere em l3 */
                    if (l3->first == NULL) {
                        l3->first = cur1;
                        cur3 = cur1;
                    }
                    else{
                        cur3->next = cur1;
                        cur3 = cur3->next;
                    }
                else{
                    /* se não retirou nada de l1, o prev incrementa */
                    prev1 = cur1;
                }
                    /* cur1 é icrementado sempre */
                    cur1 = cur1->next;
                }
            }
            cur3->next = NULL;
            return TRUE;
        }
    }
    return FALSE;
}
