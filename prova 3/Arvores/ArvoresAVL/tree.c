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
            novo->estado='b';
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

int avlAtualiza (tnode *t){
    int AltL, AltR, fator;
    AltL=0;
    AltR=0;
    if (t==NULL)    return -1;
    else{
        AltL=avlAtualiza(t->left)+1;
        AltR=avlAtualiza(t->right)+1;
        fator = AltL - AltR;
        if ((t->left!=NULL)&&(t->right!=NULL)){
            if ((t->left->estado=='C')||(t->right->estado=='C')){
                t->estado='C';
                return -999;
            }
        }
        if (fator==0){
            t->estado='B';
            return AltL;
        }
        else{
            if (fator==1){
                t->estado='L';
                return AltL;
            }
            else{
                if (fator==-1){
                    t->estado='R';
                    return AltR;
                }
                else{
                    t->estado='C';
                    return -999;
                }
            }
        }
    }
}
