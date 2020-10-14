
/* questão 1 */
int multiplicaMat(int *v1, int *v2, int *v3, int n){

    if (v1!=NULL && v2!=NULL && v3!=NULL && n>0) {
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                /* v3[i][j] = 0; */
                v3[i*n+j] = 0;
                for(k=0; k<n; k++){
                    /* v3[i][j] += v1[i][k] * v2[k][j] */
                    v3[i*n+j] += v1[i*n+k] * v2[k*n+j];
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}

/* questão 2 */
void cqOrganiza(Cqueue *cq){

    if(cq!=NULL){
        if(cq->nelm>0){
            while (cq->beg>0) {
                pos = cq->beg;
                decrPos = cqDecrCircular(pos, cq->max);
                aux = cq->elm[cq->end];
                while(decrPos!=cq->end){
                    cq->elm[decrPos] = cq->elm[pos];
                    decrPos = pos;
                    pos = cqIncrCircular(pos, cq->max);
                }
                cq->beg = cqDecrCircular(cq->beg, cq->max);
                cq->end = cqDecrCircular(cq->end, cq->max);
                cq->elm[cq->end] = aux;
            }
        }
    }
}

/* questão 3 */

void stkRemoveEnquantoMaior(stack *stk, void *key){

    if(stk!=NULL){
        if(key!=NULL){
            if(stk->top>=0){
                if ((int*)*(stk->elm[stk->top])>(int*)*key) {
                    stat = TRUE;
                }else{
                    stat = FALSE;
                }
                while (stk->top>=0 && stat==TRUE) {
                    stk->top--;
                    if ((int*)*(stk->elm[stk->top])>(int*)*key) {
                        stat = TRUE;
                    }else{
                        stat = FALSE;
                    }
                }
            }
        }
    }
}
