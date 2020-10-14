int dllInverte(Dllist *l1, Dllist *l2){
    Dlnode *cur, *cur2;
    if(l1!= NULL && l2!=NULL){
        if(l1->first!=NULL){
            /* enquanto houver nós em l1 */
            while(l1->first!=NULL){

                /* busca o último elemento de l1 */
                cur = l1->first;
                while(cur->next!=NULL){
                    cur = cur->next;
                }

                /* remove o último elemento de l1 */
                if(cur->prev!=NULL){
                    cur->prev->next = NULL;
                }

                /* se l2 estiver vazia */
                if(l2->first==NULL){
                    /* coloca o cur como o primeiro elemento de l2 */
                    l2->first = cur;
                    cur->prev = NULL;
                    cur2 = cur;
                }
                /* senão */
                else{
                    /* coloca o cur como o último elemento de l2 */
                    cur2->next = cur;
                    cur->prev = cur2;
                    cur2 = cur2->next;
                }
            }
        }
    }
}

int sllRemoveImpares(Sllist *l){
    if(l!=NULL){
        if(l->first!=NULL){
            /*  */
            cur = l->first;
            next = cur->next;
            /* enquanto nenhuma das duas variáveis não alcançar o final da lista */
            while (cur!=NULL && next!=NULL) {

                /* se cur for o primeiro */
                if (cur == l->first) {
                    /* retira o primeiro */
                    l->first = next;
                    free(cur);
                    /* move o cur pra frente */
                    cur = next;
                }

                /* se o cur não for o primeiro */
                else{
                    /* cur necessariamente será de ordem par, portanto deve ser removido o next */
                    cur->next = next->next;
                    free(next);
                    /* move o cur pra frente */
                    cur = cur->next;
                }

                /* move o next pre frente */
                if(cur!=NULL){
                    next = cur->next;
                }

            }
            return TRUE;
        }
    }
    return FALSE;
}
