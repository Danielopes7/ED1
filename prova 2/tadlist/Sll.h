
/*
**       Sll.h:   Definicoes para lista linear simplesmente encadeada
**
**       Autor : Anselmo C. de Paiva  (ACP)
**       Data  : Outubro/2000
**
*/

#ifndef _SLL_H
#define _SLL_H

typedef struct _nodesll
{
 struct _nodesll *next;
 void *data;
} NodeSll;

typedef struct _sllhandle
{
 NodeSll *head;
 NodeSll *cur;
} SllHandle;

  typedef enum {FIRST,NEXT} QueryType;

  SllHandle *SllInit( void );
  int SllNumElms(SllHandle *list);
  void SllRemoveAll(SllHandle *list, void (*FreeData)(void *));
  void *SllGetElm(SllHandle *list, void *key, int (*Identify)(void *, void *));
  int SllQueryElm(SllHandle *list, QueryType qry, void *elm);
  int SllInsFirstPosition( SllHandle *list, void *elm );
  int SllInsLastPosition( SllHandle *list, void *elm );
  int SllInsOrdered( SllHandle *list,  void *elm, int (*Compare)(void *, void *));
  int SllDelFirstPosition( SllHandle *list );
  int SllDelLastPosition( SllHandle *list);
  int SllDelElm( SllHandle *list,  void *elm, int (*Compare)(void *, void *));


#endif
