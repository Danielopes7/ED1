/*
**       tree.h:   Definicoes para Arvore Binaria de Pesquisa
**
**       Autor : Sidney Araujo Melo
**       Data  : Julho/2011
**
*/

#ifndef _DLL_H
#define _DLL_H
#define TRUE 1
#define FALSE 0

typedef struct _tnode_{
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
} tnode;

typedef struct _tree_{
    tnode *root;
} tree;

tree * abpCreate ();
void * abpQueryNode (tnode *t, int (*cmp)(void*, void*), void *key);
tnode * abpInsert (tnode *t, void *data, int (*cmp)(void *, void*));
void * abpRemove (tnode *t, void *key, int (*cmp)(void *, void *));
void * removeKey(tnode *t,void *key);
void * abpGetMenorData (tnode *t);
void abppreOrdem (tnode *t, void (*visit)(void*));
void abpposOrdem (tnode *t, void (*visit)(void*));
void abpSimetrico (tnode *t, void (*visit)(void*));
void abpnFolhaSimetrico (tnode *t, void (*visit)(void*));
void dadosArvore (tnode *t, int *vet);
int abpTeste (tnode *t, int (*cmp)(void*, void*));
int abpAlturaNo (tnode *t, void *key, int (*cmp)(void*, void*));
void * abpRemoveMaiorData (tnode *t);
tnode * abpFusao (tnode *t3, tnode *t1, tnode*t2, int (*cmp)(void *, void*));
tnode * abpCopy (tnode *t3, tnode *t,int (*cmp)(void *, void*), void *first);
int maior(int a, int b);
int altura(tnode *root);
int alturaT(tnode *t);
int contarNos(tnode *root);
int contarFolhas(tnode *root);
int isABP(tnode *t);
int getMenor(tnode *t);
int getMaior(tnode *t);
int testaABB(tnode *t,int (*cmp)(void *, void *));
int nNosAlth(tnode *t, int h, int hno);
int grau1(tnode *t);
int nosMaiorKey(tnode *t, int key);
int isHeap(tnode* t);
int numNos(tnode *root);
#endif
