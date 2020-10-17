
/*
**       Sll.h:   Definicoes para lista linear simplesmente encadeada
**
**       Autor : Anselmo C. de Paiva  (ACP)
**       Data  : Outubro/2000
**
*/

#ifndef _SLL_H
#define _SLL_H

  typedef struct _slNode_ {
          void * data;
          struct _slNode_ * next;
          } SLLNode;

  typedef struct _sllist_{
          SLNode * first;
  } SLList;        

  void *SllInit( void );
  int SllNumElms(void *list);
  void SllRemoveAll(void *list, void (*FreeData)(void *));
  void *SllQueryElm(SLList *l, void *key, int (*IdMaq)(void *, void *));
  int SllInsFirstPosition( SLList * l, void * data );
  int SllInsLastPosition( SLList *l, void *data );
  int SllInsOrdered( void *list,  void *elm, void (*Compare)(void *, void *));
  int SllDelFirstPosition( SLList *l );
  int SllDelLastPosition( SLList * l );
  int SllDelElm( void *list,  void *elm, void (*Compare)(void *, void *));


#endif
