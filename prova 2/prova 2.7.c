int dllcToSll(Dllist *l){
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            cur->prev = NULL;
            while (cur->next!=l->first) {
                cur = cur->next;ç
                cur->prev = NULL;
            }
            cur->next = NULL;
            return TRUE;
        }
    }
    return FALSE;
}
