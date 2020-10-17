int EhInversa(Sllist *l1, Sllist *l2, int (*cmp)(void*, void*)){
    int total1 = 0, total2 = 0;
    if(l1!=NULL && l2!=NULL){
        cur1 = l1->first;
        while (cur1!=NULL) {
            total1++;
        }
        cur2 = l2->first;
        while (cur2!=NULL) {
            total2++;
        }
        if(total1<total2){
            return -1;
        }
        else if(total1>total2){
            return 0;
        }
        else{
            cur1 = l->first;
            while (cur1->next!=NULL) {
                cur = cur->next;
            }
            last1 = cur1;

            cur2 = l2->first;
            stat = cmp(last->data, cur2->data);
            while (total1>1 && stat!=TRUE) {
                cur1 = l1->first;
                while (cur1->next!=last) {
                    cur1 = cur1->next;
                }
                last1 = cur1;

                cur2 = cur2->next;
                stat = cmp(last->data, cur2->data);
                total--;
            }
            if(stat == TRUE){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int dllRemoveSpecAndNeightbors(Dllist *l, void *key, int(*cmp)(void*, void*)){
    Dlnode *prev, *cur, *next;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            prev = l->first;
            cur = prev->next;
            next = cur->next;
            stat = cmp(cur->data, key);
            while (cur!=l->first && stat!=TRUE) {
                prev = cur;
                cur = next;
                next = next->next;
                stat = cmp(cur->data, key);
            }
            if(stat == TRUE){
                if(next->next == prev){
                    l->first = NULL;
                }
                else{
                    l->first = next->next;
                }
                prev->prev->next = next->next;
                next->next->prev = prev->prev;
                free(prev);
                free(cur);
                free(next);
                return TRUE;
            }
        }
    }
    return FALSE;
}
