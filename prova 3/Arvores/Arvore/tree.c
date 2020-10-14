#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree * abpCreate (){
    tree *t;
    t = (tree *)malloc(sizeof(tree));
    if (t!=NULL){
        t->root=NULL;
        return (t);
    }
    return NULL;
}

tnode * abpInsert (tnode *t, void *data, int (*cmp)(void *, void*)){
    tnode *novo;
    int stat;
    if (t!=NULL){
        stat=cmp(data, t->data);
        if (stat<0){
            t->left=abpInsert(t->left, data, cmp);
        }
        else{
            t->right=abpInsert(t->right, data, cmp);
        }
        return t;
    }
    else{
        novo = (tnode *)malloc(sizeof (tnode));
        if (novo!=NULL){
            novo->left=NULL;
            novo->right=NULL;
            novo->data=data;
        }
        return novo;
    }
}

void * abpQueryNode (tnode *t, int (*cmp)(void*, void*), void *key){
    int stat;
    if (t!=NULL){
        stat=cmp(key, t->data);
        if (stat==0){
            return t->data;
        }
        else{
            if (stat==-1){
                return (abpQueryNode(t->left, cmp, key));
            }
            else{
                return (abpQueryNode(t->right,cmp, key));
            }
        }
    }
    return NULL;
}

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

void *  abpGetMenorData (tnode *t){
    if (t!=NULL){
        if (t->left!=NULL){
            return abpGetMenorData(t->left);
        }
        else{
            return t->data;
        }
    }
    return NULL;
}

void abppreOrdem (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        visit (t->data);
        abppreOrdem(t->left, visit);
        abppreOrdem(t->right, visit);
    }
}

void abpposOrdem (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpposOrdem(t->left, visit);
        abpposOrdem(t->right, visit);
        visit (t->data);
    }
}

void abpSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpSimetrico(t->left, visit);
        visit (t->data);
        abpSimetrico(t->right, visit);
    }
}

void abpnFolhaSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpnFolhaSimetrico(t->left, visit);
        if ((t->left!=NULL)||(t->right!=NULL)) visit (t->data);
        abpnFolhaSimetrico(t->right, visit);
    }
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

int abpAlturaNo (tnode *t, void *key, int (*cmp)(void*, void*)){
    int i = 0;
    if (t!=NULL){
        i+=abpAlturaNo(t->left, key, cmp);
        if (i>0)                    return i+1;
        if (cmp(t->data,key)==0)    return 1;
        i+=abpAlturaNo(t->right, key, cmp);
    }
    return 0;
}

void * abpRemoveMaiorData (tnode *t){
    if (t->right!=NULL)
        t->right=abpRemoveMaiorData(t->right);
    else{
        free (t->data);
        free (t);
        return NULL;
    }
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
        
                

int contarNos(tnode *root){
   if(root == NULL)
        return 0;
   else
        return 1 + contarNos(root->left) + contarNos(root->right);
}

int contarFolhas(tnode *root){
   if(root == NULL)
        return 0;
   else
        if(root->left==NULL && root->right==NULL)
                            return 1;
        else                  
                return 0 + contarFolhas(root->left) + contarFolhas(root->right);
}

int isABP(tnode *t){
    int a,b;
    int menor,maior;
    
    if(t!=NULL){
         a=isABP(t->left);
         b=isABP(t->right);
         menor=getMenor(t->right);       
         maior=getMaior(t->left);
         if((menor>(int)(t->data)) && (maior <=(int)(t->data)) && (a==1) && (b==1)){    // problema na comparação entre menor e t->data / maior e t->data
                          return 1;
                          }else{
                                return 0;
                                }
                                } return 1; }
                                
int getMenor(tnode *t){
    int min;
    int minL, minR;
    
    if(t!=NULL){
                min=(int)t->data;
                minL=getMenor(t->left);
                minR=getMenor(t->right);
                if(minL<min){
                             min=minL;
                             }
                if(minR<min){
                             min=minR;
                             }
                return min;
                }
                return 32.922;
                }
                                                                                     
int getMaior(tnode *t){
    int max;
    int maxL, maxR;
    
    if(t!=NULL){
                max=(int)t->data;
                maxL=getMaior(t->left);
                maxR=getMaior(t->right);
                if(maxL>max){
                             max=maxL;
                             }
                if(maxR>max){
                             max=maxR;
                             }
                return max;
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
                        }else{
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

int nNosAlth(tnode *t, int h, int hno){
    int nnos=0;
    
    if(t==NULL) { nnos=0; }
    else{                        
    hno=hno+1;
    if(hno==h)  nnos=1;
                                
    nnos+=nNosAlth(t->left,h,hno);
    nnos+=nNosAlth(t->right,h,hno);
    }
    return nnos;
}                                                                    
                                   
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
    
int nosMaiorKey(tnode *t, int key){

    int nnos=0;
    
     if(t!=NULL){  
               if((int)(t->data)>= key) nnos=1;
               
               nnos = nnos+nosMaiorKey(t->left,key);
               nnos = nnos+nosMaiorKey(t->right,key);
               return nnos;    
               }
               return 0;   
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
                                             
                                                      
int numNos(tnode *root){
    int no=0;
    
    if(root!=NULL){
                no=1;
                no=no+numNos(root->left);
                no=no+numNos(root->right);
                return no;
                }else{
                      return 0; 
                      }
                      
}    
                
                                                                                 
