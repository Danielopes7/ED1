/* 
 * File:   binarySearchTree.h
 * Author: Pablo
 *
 * Created on 10 de Dezembro de 2010, 02:55
 */

#ifndef BINARYSEARCHTREE_H
#define	BINARYSEARCHTREE_H



typedef struct node_s TNode;

typedef struct qnode_s qnode;

typedef struct queue_s queue;

TNode* abpNewNode(void* data);

TNode* abpSearch(TNode *root, void *data, int(*cmp)(void*, void*));

TNode* abpInsert(TNode *t, void* data, int(*cmp)(void*, void*));

TNode* abpRemove(TNode *t, void* key, int(*cmp)(void*, void*));

void destroy_tree(TNode *n);

void preorder(TNode *n, void (*f)(void*));

void inorder(TNode *n, void (*f)(void*));

void postorder(TNode *n, void (*f)(void*));

void levelorder(TNode *t, void(*f)(void*));

void enqueue(queue* q, TNode *t);

TNode *dequeue(queue* q);

int queue_empty(queue* q);



#endif	/* BINARYSEARCHTREE_H */

