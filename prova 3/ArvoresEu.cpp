#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//essa função cria uma arvore
tree * abpCreate (){
    tree *t;
    t = (tree *)malloc(sizeof(tree));
    if (t!=NULL){
        t->r=NULL;
        t->l=NULL;
        return (t);
    }
    return NULL;
}
//essa função insere um nó em uma arvore binaria de pesquisa
TNode * abpInsert (TNode *t, void *data, int (*cmp)(void *, void*)){
    TNode *novo;
    int stat;
    if (t!=NULL){
        stat=cmp(data, t->data);
        if (stat<=0){
            t->l=abpInsert(t->l, data, cmp);
        }
        else{
            t->r=abpInsert(t->r, data, cmp);
        }
        return t;
    }
    else{
        novo = (TNode *)malloc(sizeof (TNode));
        if (novo!=NULL){
            novo->l=NULL;
            novo->r=NULL;
            novo->data=data;
        }
        return novo;
    }
    return NULL;
}
//essa função busca o nó em uma arvore binaria de pesquisa
void * abpBuscaNo (TNode *t, int (*cmp)(void*, void*), void *key){
    int stat;
    if (t!=NULL){
        stat=cmp(key, t->data);
        if (stat==0){
            return t->data;
        }
        else if (stat>0){
             return (abpBuscaNo(t->r,cmp, key));
        }
        else{
             return (abpBuscaNo(t->l, cmp, key));
            }
        }
    }
    return NULL;
}
//essa função retorna o numero de nó de uma arvore binaria                                                      
int numNos(TNode *t){
    int no=0;
    
    if(t!=NULL){
                no=1;
                no=no+numNos(t->l);
                no=no+numNos(t->r);
                return no;
    }else{
          return 0; 
    }
                      
}    
//função visita(imprime) os nós não folha em ordem simetrico                
void abpnFolhaSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpnFolhaSimetrico(t->left, visit);
        if ((t->left!=NULL)||(t->right!=NULL)){
                                                visit (t->data);
        }
        abpnFolhaSimetrico(t->right, visit);
    }
}

//função visita(imprime) os nós folha em ordem simetrico                
void abpnFolhaSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpnFolhaSimetrico(t->left, visit);
        if ((t->left==NULL)&&(t->right==NULL)){
                                                visit (t->data);
        }
        abpnFolhaSimetrico(t->right, visit);
    }
}
//essa função retorna o menor nó de uma arvore binaria de pesquisa, ou seja, aquele que tah mais a esquerda
void *  abpGetMenorNo (TNode *t){
    if (t!=NULL){
        if (t->l!=NULL){
            return abpGetMenorNo(t->l);
        }
        else{
            return t->data;
        }
    }
    return NULL;
}
//essa função retorna os elementos em pre-ordem
void abppreOrdem (TNode *t, void (*visit)(void*)){
    if (t!=NULL){
        visit (t->data);
        abppreOrdem(t->l, visit);
        abppreOrdem(t->r, visit);
    }
}
//essa função retorna os elementos em pos-ordem
void abpposOrdem (TNode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpposOrdem(t->l, visit);
        abpposOrdem(t->r, visit);
        visit (t->data);
    }
}
//essa função retorna os elementos em ordem simetrico
void abpSimetrico (TNode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpSimetrico(t->l, visit);
        visit (t->data);
        abpSimetrico(t->r, visit);
    }
}


//essa função retorna a altura do nó especificado
int abpAlturaNo (tnode *t, void *key, int (*cmp)(void*, void*)){
    int i = 0;
    if (t!=NULL){
        i=i+abpAlturaNo(t->left, key, cmp);
        if (i>0){
                 return i+1;
        }
        if (cmp(t->data,key)==0){
                                 return 1;
        }
        i=i+abpAlturaNo(t->right, key, cmp);
        return i;
    }
    return 0;
}
//essa função remove o maior de uma arvore binaria de pesquisa, ou seja, aquele mais a direita
void * abpRemoveMaior (TNode *t){
    void* data; 
    if (t->r!=NULL)
        t->r=abpRemoveMaior(t->r);
    else{
        data=t->data; 
        free (t);
        return data;
    }
}

//essa função remove o menor de uma arvore binaria de pesquisa, ou seja, aquele mais a esquerda
void * abpRemoveMenor (TNode *t){
    void* data; 
    if (t->l!=NULL)
        t->l=abpRemoveMenor(t->r);
    else{
        data=t->data; 
        free (t);
        return data;
    }
}

                
//essa função retorna o numero de nós de uma arvore
int contarNos(TNode *t){
   if(t == NULL)
        return 0;
   else{
        return 1 + contarNos(t->l) + contarNos(t->r);
        }
}
//essa função retorna o numero de folhas de uma arvore
int contarFolhas(TNode *t){
   if(t == NULL)
        return 0;
   else
        if(t->l==NULL && t->r==NULL)
                            return 1;
        else{                  
                return 0 + contarFolhas(t->l) + contarFolhas(t->r);
        }
}

//essa função retorna o numero de nós de grau 1 , ou seja, aqueles que só tem um filho                                   
int grau1(tnode *t){
    int nnos=0;
    
    if(t!=NULL){
                  if(t->left!=NULL && t->right==NULL || t->left==NULL && t->right!=NULL)   nnos=1;
                
                   nnos= nnos+grau1(t->left);
                   nnos= nnos+grau1(t->right); 
                   return nnos;                  
  
    }else{
          return 0;
          }
 }
//essa função retorna o numero de nós de uma determinada altura
int hno=1;
int nNosAlth(tnode *t, int h, int hno){
    int nnos=0;
    
    if(t==NULL){
                nnos=0; 
                }
    else{                        
    hno=hno+1;
    if(hno==h){
               nnos=1;
               }          
    nnos=nnos + nNosAlth(t->left,h,hno);
    nnos=nnos + nNosAlth(t->right,h,hno);
    }
    return nnos;
}                                                                    
//essa função retorna o numero de nós de uma determinada altura, outro metodo
int abNumNosH(Tnode *t, int h){
    int hl=0;
    if(t!=NULL){
                if(h==hl){
                          return 1;
                }
                else{
                     n1=abSimetricoH(t->l,t->r);
                     n2=abSimetricoH(t->l,t->r);
                     return n1+n2;
                } 
    }
    return 0;
}
int abSimetricoH(TNode *t, int h, int hl){
    if(t!=NULL){
                hl++;
                if(h==hl){
                          return 1;
                }
                else(hl<h){
                     n1=abSimetricoH(t->l,h,hl);
                     n2=abSimetricoH(t->r,h,hl);
                     return n1+n2;
                }
    }
    return 0;
}

//essa função retorna se duas arvores são topologicamente igual
int abTopoIgual(TNode *t1, TNode *t2){
    if(t1!=NULL && t2!=NULL){
                return abTopoIgual(t1->l,t2->l) && abTopoIgual(t1->r,t2->r);
    }
    else if(t1==NULL && t2==NULL){
         return TRUE;
    }
    else{
         return FALSE;
    }
}

//essa função retorna se duas arvores são igual
int Igual(TNode *t1, TNode *t2, int (*cmp)(void*,void*)){
    if(t1!=NULL && t2!=NULL){
                if(cmp(t1->data,t2->data)==TRUE){
                                                 return abIgual(t1->l,t2->l,cmp) && abIgual(t1->r,t2->r,cmp);
                }
                else{
                     return FALSE;
                }
    }
    else if(t1==NULL && t2==NULL){
         return TRUE;
    }
    else{
         return FALSE;
    }
}
                     
//esssa função retorna o numero maior que a chave    
int nosMaiorKey(tnode *t, void* key,int(*cmp)(void*,void*)){

    int nnos=0;
    
     if(t!=NULL){  
               if(cmp(t->data,key)>0){
                                      nnos=1;
               }
               nnos = nnos+nosMaiorKey(t->left,key,cmp);
               nnos = nnos+nosMaiorKey(t->right,key,cmp);
               return nnos;    
     }
     return FALSE;   
} 

//esssa função retorna o numero menor que a chave    
int nosMenorKey(tnode *t, void* key,int(*cmp)(void*,void*)){

    int nnos=0;
    
     if(t!=NULL){  
               if(cmp(t->data,key)<0){
                                      nnos=1;
               }
               nnos = nnos+nosMenorKey(t->left,key,cmp);
               nnos = nnos+nosMenorKey(t->right,key,cmp);
               return nnos;    
     }
     return FALSE;   
}
//essa função retorna a soma dos nós
void* nosSoma(tnode *t){

    void* nnos=0;
    
     if(t!=NULL){  
               nnos=t->data;
               nnos = nnos+nosSoma(t->left);
               nnos = nnos+nosSoma(t->right);
               return nnos;    
     }
     return 0;   
}                       
  
void *removeKey(tnode *t,void *key){
     tnode *aux;
     static int data;
     int localdata;
     
     if(t!=NULL){
          if(key!=t->data){
               if(key<t->data){
                       t->left=(void*)removeKey(t->left,key);
                       return t;
               }else{
                    t->right=(void*)removeKey(t->right,key);
                    return t;
                    }
         }else{
           data=(int)t->data;
           if(t->left==NULL){
                 if(t->right!=NULL){
                          aux=t->right;
                          free(t);
                          return aux;
                 }else{
                       free(t);
                       return NULL;
                       }
           }else{
                 if(t->right!=NULL){
                       localdata=(int)t->data;
                       t->data=(void*)getMenor(t->right);
                       t->right=(void*)removeKey(t->right,t->data);
                       data=localdata;
                       return t;
                 }else{
                       aux=t->left;
                       free(t);
                       return aux;
                       }
                 }
           }
     }
      return NULL;      
}

int testaABB(tnode *t, int (*cmp)(void *, void *)){
    int arvE=1, arvD=1;
    int flag;
    flag=cmp(t->data,t->left->data);
    if(t==NULL){
                return 1;
                }
    if((t->left==NULL) && (t->right==NULL)){
                    return 1; 
                    }
    if(t->left!=NULL){
             if(flag==-1){
                        return 0;
             }
             else{
                  arvE=testaABB(t->left,cmp);
             }
    }
    flag=cmp(t->data,t->right->data);         
    if(t->right!=NULL){
             if(flag==1){
                       return 0;
                       }else{
                             arvD=testaABB(t->right,cmp);
                             }
                       } 
    if((arvE==0) || (arvD==0))
                 return 0;
    else                                                                
        return 1;
}                       

        
/*
int isHeap(tnode* t){
    
    if(t!=NULL){
         if(isHeap(t->left) && isHeap(t->right)){
                            if(t->left!=NULL && t->right!=NULL){
                                             if((t->left->data < t->data) && (t->left->data < t->data)){
                                                          return 1;
                                             }else{
                                                   return 0;
                                    }               }
                            if ((t->left==NULL && t->right!=NULL) || (t->left!=NULL && t->right==NULL)){
                                         if((t->left->data < t->data) || (t->left->data < t->data)) {
                                                       return 1;
                                         }else{
                                               return 0;
                                     }         }
                            else return 1;
         }else{
               return 0;
               }
    }     
}      */           
                                                                            
int isHeap(tnode* t){
    
    if(t!=NULL){
         if(isHeap(t->left)){
              if(isHeap(t->right)){                  
                            if(t->left!=NULL && t->right==NULL){
                                          if(cmp(t->left->data,t->data)<0){
                                                          return 1;       }
                                                               }
                                           
                            if(t->left==NULL && t->right!=NULL){
                                         if(cmp(t->right->data,t->data)<0){
                                                       return 1;          }
                                                               }
                            if(t->left!=NULL && t->right!=NULL){     
                                             if(cmp(t->left->data,t->data)<0){                 
                                                   if(cmp(t->right->data,t->data)<0){  
                                                           return 1;
                                                                                    }
                                                                             }
                                                               }
                            if(t->left==NULL && t->right==NULL) {
                                                 return 1;
                                                                }
                                  }
                             }
                    return 0;
              }
         return 1;
    }
/*    
int IsMaxHeap(Tnode *root){
    
    int maiorL;
    int maiorR;
    int *data;
    int d;
    if(root != NULL){
            data = (int *)root->data;
            d = *data;
            maiorL = PegaMaiordeArvBin(root->l);
            maiorR = PegaMaiordeArvBin(root->r);
            if(d > maiorL && d > maiorR){
                    return (IsMaxHeap(root->l)&& IsMaxHeap(root->r));
            }
            else{
                    return FALSE;
                 }
         }
     return TRUE;   
}

int IsMaxHeap(Tnode *root){
    
    int maiorL;
    int maiorR;
    int *data;
    int d;
    if(root != NULL){
            data = (int *)root->data;
            d = *data;
            maiorL = PegaMaiordeArvBin(root->l);
            maiorR = PegaMaiordeArvBin(root->r);
            if(d > maiorL && d > maiorR){
                    return (IsMaxHeap(root->l)&& IsMaxHeap(root->r));
            }
            else{
                    return FALSE;
                 }
         }
     return TRUE;   
}

int PegaMenordeArvBin(Tnode *t)
{   
    int min;
    int minL;
    int minR;
    int *data;
    
    if(t != NULL)
    {
         data=(int *)t->data;
         min = *data;
         minL = PegaMenordeArvBin(t->l);
         minR = PegaMenordeArvBin(t->r);
         if(minL < min)
         {
                 min = minL;
         } 
         if(minR < min)
         {
             min = minR;
         }
         return min;
    }
    return 65535;
}

int PegaMaiordeArvBin(Tnode *t)
{
    int max,maxR,maxL;
    int *data;
    
    if(t != NULL)
    {
         data=(int *)t->data;
         max = *data;
         maxL = PegaMaiordeArvBin(t->l);
         maxR = PegaMaiordeArvBin(t->r);
         if(maxL > max)
         {
                 max = maxL;
         }
         if(maxR > max)
         {
                 max = maxR;
         }
         return max;
     }
    return 0; 
}
    */
                                             
  
void * abpRemove (tnode *t, void *key, int (*cmp)(void *, void *)){
    tnode *filho;
    if (t!=NULL){
        if (cmp(t->data, key)==0){
            if ((t->left==NULL)&&(t->right==NULL)){
                free (t->data);
                free (t);
                return NULL;
            }
            else{
                if ((t->left==NULL)&&(t->right!=NULL)){
                    filho=t->right;
                    free (t->data);
                    free (t);
                    return filho;
                }
                else{
                    if ((t->left!=NULL)&&(t->right==NULL)){
                        filho=t->left;
                        free (t->data);
                        free (t);
                        return filho;
                    }
                    else{
                        t->data=abpGetMenorData(t->right);
                        t->right=abpRemove(t->right,t->data,cmp);
                        return t;
                    }
                }
            }
        }
        else{
            if (cmp(key, t->data)<0){
                t->left=abpRemove(t->left, key, cmp);
            }
            else{
                t->right=abpRemove(t->right, key, cmp);
            }
        }
    }
    return NULL;
}
                                                                               
void dadosArvore(tnode *t, int *vet){
    //Em cada posição do vetor, serão guardados os seguintes valores:
    //0 - Numero de Nós, 1 - Numero de Folhas, 2 - Nós não Folhas
    //3 - Nós com 2 fil, 4 - Nós com 1 filho,  5 - Nós com filho esquerdo
    //6 - Nós com filho direito
    if (t!=NULL){
        dadosArvore(t->left, vet);
        //Incrementa numero de nós
        vet[0]++;
        //Se for folha, increments
        if ((t->left==NULL)&&(t->right==NULL)) {
            vet[1]++;
        }
        else{
            //Já não é folha, então...
            vet[2]++;
            //Vamos ver se tem 2 filhos...
            if ((t->left!=NULL)&&(t->right!=NULL)){
                vet[3]++;
            }
            else{
                //Se chegou aqui, é óbvio que tem um, então...
                vet[4]++;
            }
            if (t->left!=NULL)  vet[5]++;
            if (t->right!=NULL) vet[6]++;
        }
        dadosArvore(t->right, vet);
    }
}

int abpTeste (tnode *t, int (*cmp)(void*, void*)){
    if (t!=NULL){
        if (abpTeste(t->left,cmp) && abpTeste(t->right,cmp)){
            if ((t->left==NULL)&&(t->right==NULL)){
                return 1;
            }
            else{
                if ((t->left==NULL)&&(t->right!=NULL)){
                    if (cmp(t->right->data, t->data)>=0)    return 1;
                    else                                    return 0;
                }
                else{
                    if ((t->left!=NULL)&&(t->right==NULL)){
                        if (cmp(t->left->data, t->data)==-1)    return 1;
                        else                                    return 0;
                    }
                    else{
                        if ((cmp(t->left->data, t->data)==-1)&&(cmp(t->right->data, t->data)>=0)){
                            return 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
        return 0;
    }
    return 1;
}
tnode * abpCopy (tnode *t3, tnode *t,int (*cmp)(void *, void*), void* first ){
    tnode *firstcopied;
    if (t!=NULL){
        t3=abpInsert(t3, t->data, cmp);
        abpCopy(t3, t->left, cmp, first);
        abpCopy(t3, t->right, cmp, first);
        if (cmp(first,t->data)==0)   return t3;
    }
}

tnode * abpFusao (tnode *t3, tnode *t1, tnode *t2, int (*cmp)(void *, void*)){
        if (t1!=NULL){
            t3=abpCopy(t3, t1, cmp, t1->data);
        }
        if (t2!=NULL){
            t3=abpCopy(t3, t2, cmp, t2->data);
        }
        return t3;
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(tnode *root){
   if((root == NULL) || (root->left == NULL && root->right == NULL))
       return 0;
   else
       return 1 + maior(altura(root->left), altura(root->right));
}

int alturaT(tnode *t){
    int altD=0, altE=0;
    
    if(t==NULL) return -1;
    else
        altE=alturaT(t->left);
        altD=alturaT(t->right);
        
        if(altE<altD) return altD+1;
        else return altE+1;
    }
//o que diaxo isso tem haver aki
//menor?
//maior?        
int isABP(tnode *t,int(*cmp)(void*,void)){
    if(t!=NULL){
                isABP(t->left);
                isABP(t->right);
                if(cmp(t->data,t->l->data)>=0)&&cmp(t->data,t->r->data)<0){
                          return TRUE;
                }else{
                      return FALSE;
                }
    } 
    return TRUE; 
}
                                
void* getMenor(TNode *t,int(*cmp)(void*,void*)){
    void* min;
    void* minL, minR;
    
    if(t!=NULL){
                min=t->data;
                minL=getMenor(t->l,cmp);
                minR=getMenor(t->r,cmp);
                if(cmp(minL,min)<0){
                             min=minL;
                }
                if(cmp(minR,min)<0){
                             min=minR;
                }
                return min;
    }
    return 0;
}
                                                                                     
void* getMaior(TNode *t,int(*cmp)(void*,void*)){
    void* max;
    void* maxL, maxR;  
    if(t!=NULL){
                max=t->data;
                maxL=getMaior(t->l,cmp);
                maxR=getMaior(t->r,cmp);
                if(cmp(maxL,max)>0){
                             max=maxL;
                }
                if(cmp(maxR,max)>0){
                             max=maxR;
                }
                return max;
    }
    return 0;
}
