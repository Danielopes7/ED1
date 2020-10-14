int sllPuneFirst(Sllist *l){
    Slnode *cur, *first;
    if(l!=NULL){
        if(l->first!=NULL){
            first = l->first;
            cur = first;
            while (cur->next!=NULL) {
                cur = cur->next;
            }
            cur->next = first;
            l->first = first->next;
            first->next = NULL;
            return TRUE;
        }
    }
    return FALSE;
}
