// a pilha dupla na verdade é apenas um vetor que armazena duas estruturas de pilhas, sendo dois top, um em cada extremidade
typedef struct _pilha_dupla_{
        int top1;
        int top2;
        int maxItens;
        void** elm;
        }Stack;
        
//cria a pilha com dois top
Stack* stkCreate(int max){
       s=(Stack*)malloc(sizeof(Stack));
       if(s!=NULL){
                   s->elm=(void**)malloc(sizeof(void*)*max);
                   if(s->elm!=NULL){
                                    s->top1=-1;
                                    s->maxItens=max;
                                    s->top2=s->maxItens;
                                    return s;
                   }
       }
       return NULL;
}
//insere no top1
int stkPush1(Stack*s,void*elm){
    if(s!=NULL){
                if(s->top1==s->top2-1){
                                      return FALSE;
                }
                else{
                     s->elm[s->top1]=elm;
                     s->top1++;
                     return TRUE;
                }
}
//insere no top2
int stkPush2(Stack *s,void*elm){
    if(s!=NULL){
                if(s->top1==s->top2-1){
                                       return FALSE;
                }
                else{
                     s->elm[s->top2]=elm;
                     s->top2--;
                     return TRUE;
                }
    }
    return NULL;
}
//remove do top1
Stack *stkPop1(Stack*s){
      Stack*elm;
      if(s!=NULL){
                  if(s->top1>0){
                                elm=s->elm[s->top1];
                                s->top--;
                                return elm;
                  }
      }
      return NULL;
}
//remove do top2
Stack *stkPop2(Stack *s){
      Stack *elm;
      if(s!=NULL){
                  if(s->top<s->maxItens){
                                         elm=s->elm[s->top2];
                                         s->top++;
                                         return elm;
                  }
      }
      return NULL;
}
//destroi a pilha dupla
int stkDestroy(Stack *s){
    if(s!=NULL){
                if(s->elm!=NULL){
                                 free(s->elm);
                                 free(s);
                                 return TRUE;
                }
    }
    return NULL;
}
