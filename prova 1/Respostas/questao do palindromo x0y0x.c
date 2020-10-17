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

int Palidromo(char *s,int size){
    int i=0;
    int cont=0;
    char aux[(size-2)/3],*aux2;  //(size-2)/3 --> é o tamanho de x. ex: para a entrada 12101210121, x sera 3. é só fazer as contas, sempre da certo.
    Stack *p;
    p=stkCreate(size);
    while(s[i]!='0'){
        aux[i]=s[i];
        i++;
    }
    i=0;
    while(cont!=2){
        stkPush(p,&s[i]);
        if(s[i]=='0'){
            cont++;
            if(cont==2){
                stkPop(p);
            }
        }
        i++;
    }
    cont=0;
    for(i=0;i<(size-2)/3;i++){
        aux2=(char *)stkPop(p);
        if(*aux2==s[i]){
            cont++;
        }
    }
    if(cont==(size-2)/3){
        cont=0;
        for(i=0;i<(size-2)/3;i++){
            if(s[(((2*size)-4)/3)+2+i]==aux[i]){   // esse pog aki (((2*size)-4)/3)+2 --> é o indice do PRIMEIRO caracter do SEGUNDO x.
                cont++;                            // exemplo: x0y0x -> 121 0 121 0 '1'21
            }                                      //                    x  0  y  0   x
        }
    }
    if(cont==((size-2)/3)){
        return TRUE;
    }
    else{
    return FALSE;
    }
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
