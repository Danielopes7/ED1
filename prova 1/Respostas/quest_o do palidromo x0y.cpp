#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct _stack_{
        int top;
        int max;
        void **elm;
        }Stack;

Stack *stkCreate(int max){
      Stack *s;
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

void *stkPop(Stack*s){
      void *elme;
      if(s!=NULL){
                  if(s->top>0){
                               elme=s->elm[s->top-1];
                               s->top--;
                               return elme;
                               }
                  }
      return NULL;
}





int Palidromo(char *c,int size){
    Stack *s;
    int i=0;
    int cont=0;
    char aux[(size-1)/2];
    char *aux2;
    s=stkCreate(size);
    while(c[i]!='0'){
                     aux[i]=c[i];
                     i++;
                     cont++;
    }
    for(i=0;i<size;i++){

        stkPush(s,&c[i]);
    }
    for(i=0;i<cont;i++){
        aux2=(char*)stkPop(s);
            if(*aux2!=c[i]){
                    return FALSE;
                        }
    }
    return TRUE;
}

int main(){
    char c[50];
    int n;
    printf("digite a string:");
    scanf("%s",&c);
    printf("digite o tamanho:");
    scanf("%d",&n);
    if(Palidromo(c,n)){
                      printf("eh um palindromo");
                      system("pause");
                      return 0;
    }
    else{
         printf("nao eh palindromo");
         system("pause");
         return 0;
    }
}

