int sllcGetNumberOfOcurrences(Sllist *l, void *key, int(*cmp)(void*, void*)){
    Slnode *cur;
    int stat, num = 0;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            stat = cmp(cur->data, key);
            if (stat == TRUE) {
                num++;
            }
            while (cur->next!=l->first) {
                cur = cur->next;
                stat = cmp(cur->data, key);
                if (stat == TRUE) {
                    num++;
                }
            }
            return num;
        }
        return 0;
    }
    return -1;
}

void sllcAppendList(Sllist *l1, Sllist *l2){
    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL && l2->first!=NULL){
            /* procura o último elemento de l1 */
            cur1 = l1->first;
            while (cur1->next!=NULL) {
                cur1 = cur1->next;
            }

            /* concatena l1 com l2 */
            cur2 = l2->first;
            cur1->next = cur2;

            /* procura o último elemento de l2 */
            while (cur2->next!=NULL) {
                cur2 = cur2->next;
            }

            /* transforma a lista concatenada em circular com o último apontando para o primeiro */
            cur2->next = l1->first;
        }
    }
}

Dlnode *dllNoCompartilhado(Dllist *l1, Dllist *l2){

    if (l1!=NULL && l2!=NULL) {
        if(l1->first!=NULL && l2->first!=NULL){
            cur1 = l1->first;
            while (cur1!=NULL) {
                cur2 = l2->first;
                if (cur2 == cur1) {
                    return cur1;
                }
                while (cur2->next!=NULL) {
                    cur2 = cur2->next;
                    if(cur2 == cur1){
                        return cur1;
                    }
                }
                cur1 = cur1->next;

            }
        }
    }
}
