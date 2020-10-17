int dllIntercal(Dllist *l1, Dllist *l2){

    if(l1!=NULL && l2!=NULL){
        if(l1->first!=NULL && l2->first != NULL){
            cur1 = l1->first;
            cur2 = l2->first;
            next1 = cur1->next;
            next2 = cur2->next;
            while (next1!=NULL && next2!=NULL) {
                cur1->next = cur2;
                cur2->prev = cur1;
                cur2->next = next1;
                if(next1!=NULL){
                    next1->prev = cur2;
                }
                cur1 = next1;
                cur2 = next2;
                next1 = cur1->next;
                next2 = cur2->next;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int sllQPuneLastPromoveFirst(SllQueue *q, int n){
    Slnode *cur, *last, *next;
    int total, until;
    if(q!=NULL){
        if(q->front!=NULL && q->rear!=NULL){
            cur = q->front;
            last = q->rear;
            total = 1;
            while(cur!=last){
                cur=cur->next;
                total++;
            }

            /* transforma o penúltimo em último */
            while (cur->next!=last) {
                cur = cur->next;
            }
            q->rear = cur;
            cur->next = NULL;

            cur = q->front;

            until = (total-n)-1;
            if(until>0){
                for(i=1; i<until; i++){
                    cur = cur->next;
                }
                last->next = cur->next;
                cur->next = last;
            }
            else {
                last->next = cur;
                q->front = last;
            }

            /* pune first */
                cur = q->front; /* deixa cur no início */
                next = cur->next; /* next é o segundo */
                q->front = next; /* coloca o next como primeiro */
                cur->next = next->next; /* faz o cur apontar pro terceiro */
                next->next = cur; /* o next (primeiro) aponta pro cur (segundo) */
            }


            return TRUE;
        }
    }
    return FALSE;
}
