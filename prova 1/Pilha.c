typedef struct _stack_{
        int top;//topo da pilha
        int max;//tamanho max da pilha
        void **elm;//vetor
        }Stack;
        
Stack *stkCreate(int max){
      Satck *s;
      s=(Stack*)malloc(sizeof(Stack));
      if(s!=NULL){
                  s->elm=(void**)malloc(sizeof(void*)*max);
                  if(s->elm!=NULL){
                                   s->top=-1;
                                   s->max=max;
                                   return s;
                  }
      }
      return NULL;
}

int stkDestroy(Stack*s){
    if(s!=NULL){
                if(s->elm!=NULL){
                                 free(s->elm);
                                 free(s);
                                 return TRUE;
                }
    }
    return FALSE;
}

int stkPush(Stack *s,void*elm){
    if(s!=NULL){
                if(s->top<s->max){
                                  s->elm[s->top]=elm;
                                  s->top++;
                                  return TRUE;
                }
    }
    return FALSE;
}

Stack *stkPop(Stack*s){
      Stack *elm;
      if(s!=NULL){
                  if(s->top>0){
                               elm=s->elm[s->top-1];
                               s->top--;
                               return elm;
                               }
                  }
      }
      return NULL;
}


                                   
                  
