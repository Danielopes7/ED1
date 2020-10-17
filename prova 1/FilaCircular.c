typedef strucy _queue_{
        int first;//primeiro da fila
        int end;//ultimo da fila
        int max;//tamanho max da fila
        int nelms;//numero de elementos na fila
        void **elm;//vetor
        }Queue;
        
Queue* qCreate(int max){
       Queue *q;
       q=(Queue*)malloc(sizeof(Queue));
       if(q!=NULL){
                   q->elm=(void**)malloc(sizeof(int*)*max);
                   if(q->elm!=NULL){
                                    q->first=0;
                                    q->end=0;
                                    q->max=max;
                                    q->nelms=0;
                                    return q;
                   }
       }
       return NULL;
}

int qEnqueue(Queue *q,void *elm){
    if(q!=NULL){
                if(q->nelms<q->max){
                                    q->elm[q->end]=elm;
                                    if(q->end==q->max-1){
                                                         q->end=0;
                                    }
                                    else{
                                         q->end++;
                                    }
                                    q->nelms++;
                                    return TRUE;
                                    
                }
    }
    return FALSE;
}

Queue* qDesqueue(Queue *q){
    Queue *elm;
    if(q!=NULL){
                if(q->nelms>0){
                               elm=q->elm[q->first];
                               if(q->first==q->max-1){
                                                      q->first=0;
                               }
                               else{
                                    q->first++;
                               }
                               q->nelms--;
                               return elm;
                }
    }
    reurn NULL;
}

int qDestroy(Queue *q){
    if(q!=NULL){
                if(q->elm!=NULL){
                                 free(q->elm);
                                 free(q);
                                 reurn TRUE;
                }
    }
    return FALSE;
}
                               
                               
       
       
