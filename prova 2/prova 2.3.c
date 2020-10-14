int sllcInsertBeforeSpec(Sllst *l, void *data, void *key, int(*cmp)(void*, void*)){
    Slnode *cur, *prev, *newnode;
    int stat;
    if(l!=NULL){
        if(l->first!=NULL){
            prev = l->first;
            //prev = pprev->next;
            cur = prev->next;
            stat = cmp(cur->data, key);
            while (stat!=TRUE && cur!=l->first) {
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }
            if(stat == TRUE){
                newnode = (Slnode*)malloc(sizeof(Slnode));
                newnode->data = data;
                newnode->next = cur;
                prev->next = newnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *sllRemoveK(Sllist *l, int k){
    Slnode *cur, *prev;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            prev = NULL;
            cur = l->first;
            while (k>1 && cur->next!=NULL) {
                prev = cur;
                cur = cur->next;
                k--;
            }
            if(prev == NULL){
                l->first = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            data = cur->data;
            free(cur)
            return data;
        }
    }
}

int sllcIntercal(Sllist *l1, Sllist *l2){
    Slnode *cur1, *cur2, next1, next2;
    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL){
            cur1 = l1->first;
            cur2 = l2->first;
            next1 = cur1->next;
            next2 = cur2->next;
            while (next1 != l1->first) {

                cur1->next = cur2;
                cur2->next = next1;
                cur1 = next1;
                cur2 = next2;
                next1 = next1->next;
                next2 = next2->next;

            }
        }
    }
}
