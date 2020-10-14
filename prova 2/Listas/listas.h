/*
**       Sll.h:   Definicoes para lista linear simplesmente encadeada
**
**       Autor : Anselmo C. de Paiva  (ACP)
**       Data  : Outubro/2000
**
*/

#ifndef _SLL_H
#define _SLL_H

#define True 1
#define False 0

  
 typedef struct _sllnode_ Node;
 typedef struct _sllhadle SllList;
    
SllList *SllCreate ();
int SllNumElms (SllList *);
int sllRemoveAll (SllList *, int (*) (void *));
void *sllQueryElms (SllList *, void *,int (*)(void *, void *));
int sllInsertFirstPosition (SllList *,void *);
int SllInsLastPosition (SllList *, void *);
int sllInsodered (SllList *, void *, void *, int (*)(void*, void*));
void *SllDelFirstPosition (SllList *);
void *SllDelLastPosition (SllList *, void *);
int SllDelElm (SllList *l, void *key, int (*Id)(void *, void *));
//void *sllElmIdentification(SllList *l,QueryTypekey, void *elm);
SllList *sllIntersection (SllList *, SllList *, int (*)(void * , void *));
SllList *SllUnion (SllList *,SllList *, int (*)(void *, void *));
SllList *sllDiference (SllList *, SllList *, int (*)(void *, void *));
void imprimir (SllList *, int (*)(void *));
#endif
     

