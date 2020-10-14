#include <stdlib.h>
#include "binarySearchTree.h"

#define MENOR -1
#define IGUAL 0
#define MAIOR 1

struct node_s
{
    void* data;
    struct node_s* left;
    struct node_s* right;
};



TNode* abpNewNode(void* data)
{

    TNode *newnode;
    newnode = malloc(sizeof(TNode));
    if(newnode != NULL)
    {
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    return NULL;
}

/*TNode* abpSearch(TNode *root, void *data, int(*cmp)(void*, void*))
 {
    TNode *node = root;
    while (node != NULL) {
        int compare_result = cmp(data, node->data);
        if (compare_result < 0)
            node = node->left;
        else if (compare_result > 0)
            node = node->right;
        else
            break;
    }
    return node;
}*/


TNode* abpInsert(TNode *t, void* data, int(*cmp)(void*, void*))
{

    if(t != NULL)
    {
        if(cmp(data, t->data) == MENOR)
        {
            if(t->left != NULL)
            {
                abpInsert(t->left, data, cmp);
            }
            else
            {
                t->left = abpNewNode(data);
            }
        }
        if(cmp(data, t->data) == MAIOR)
        {
            if(t->right != NULL)
            {
                abpInsert(t->right, data, cmp);
            }
            else
            {
                t->right = abpNewNode(data);
            }
        }
        return t;
    }
    return abpNewNode(data);
}



TNode* abpRemove(TNode *t, void* key, int(*cmp)(void*, void*))
{

    TNode *aux;
    if(t != NULL)
    {
        if(cmp(key, t->data == IGUAL))
        {
            if(t->left == NULL && t->right == NULL)
            {
                free(t);
                return NULL;
            }
            else if(t->left != NULL && t->right == NULL)
            {
                aux = t->left;
                return aux;
            }
            else if(t->left == NULL && t->right != NULL)
            {
                aux = t->right;
                return aux;
            }
            else if(t->left != NULL && t->right != NULL)
            {
                t->data = abpGetMenor(t->right);
                abpRemove(t->right, t->data, cmp);
                return t;
            }
        }
        else if(cmp(key, t->data) == MENOR)
        {
            t->left = abpRemove(t->left, key, cmp);
            return t;
        }
        else if(cmp(key, t->data) == MAIOR)
        {
            t->right = abpRemove(t->right, key, cmp);
            return t;
        }
    }
    return NULL;
}


void* abpGetMenor(TNode *t)
{

    if (t->left != NULL)
        abpGetMenor(t->left);
    return t->data;

}




void destroy_tree(TNode *n)
{
    if (n->left)
        destroy_tree(n->left);
    if (n->right)
        destroy_tree(n->right);
    free(n);
}

/*root, left, right*/
void preorder(TNode *n, void (*f)(void*))
{
    f(n->data);
    if (n->left)
        preorder(n->left, f);
    if (n->right)
        preorder(n->right, f);
}


/*left, root, right*/
void inorder(TNode *n, void (*f)(void*))
{
    if (n->left)
        inorder(n->left, f);
    f(n->data);
    if (n->right)
        inorder(n->right, f);
}


/*left, right, root*/
void postorder(TNode *n, void (*f)(void*))
{
    if (n->left)
        postorder(n->left, f);
    if (n->right)
        postorder(n->right, f);
    f(n->data);
}

/* helper queue for levelorder */
struct qnode_s
{
    struct qnode_s* next;
    TNode *data;
};



struct queue_s
{
    qnode *begin;
    qnode *end;
};

void enqueue(queue* q, TNode *t)
{
    qnode *node;
    node = malloc(sizeof(qnode));
    node->data = t; //Recebe o TNode
    node->next = NULL; //Ultimo da fila, o proximo ptr aponta p/ NULL
    if (q->end)//Se existe algum elemento na fila
        q->end->next = node;//node vai p/ o ultimo lugar da fila
    else
        q->begin = node;// Se a fila estiver vazia,
    q->end = node;    // node será o 1o e ultimo elemento da fila
}

TNode *dequeue(queue* q)
{
    TNode *tmp;
    tmp = q->begin->data; //tmp recebe o 1o elemento da fila
    qnode *second;
    second = q->begin->next; //second recebe o 2o elemento da lista
    free(q->begin);
    q->begin = second;//second passa a ser o 1o da lista
    if (!q->begin) // caso a fila esteja vazia
        q->end = NULL;
    return tmp;
}

int queue_empty(queue* q)
{
    return !q->begin;//retorna 0 (falso), se q->begin não estiver vazia e não-zero(verdadeiro),
    //  se a fila estiver vazia
}

void levelorder(TNode *t, void(*f)(void*))
{
    queue nodequeue = {};
    enqueue(&nodequeue, t);
    while (!queue_empty(&nodequeue))// Caso a fila nao esteja vazia
    {
        TNode *next;
        next = dequeue(&nodequeue);//next recebe o 1o elemento da fila
        f(next->data);//a funcao auxiliar e' chamada
        if (next->left)//Se next->left existir,
            enqueue(&nodequeue, next->left);// ele sera' enfileirado em nodequeue
        if (next->right)//Se next->right existir,
            enqueue(&nodequeue, next->right);// ele sera' enfileirado em nodequeue
    }
}



/*int main()
{
  node *n = tree(1,
                tree(2,
                     tree(4,
                          tree(7, 0, 0),
                          0),
                     tree(5, 0, 0)),
                tree(3,
                     tree(6,
                          tree(8, 0, 0),
                          tree(9, 0, 0)),
                     0));

  printf("preorder:    ");
  preorder(n, print);
  printf("\n");

  printf("inorder:     ");
  inorder(n, print);
  printf("\n");

  printf("postorder:   ");
  postorder(n, print);
  printf("\n");

  printf("level-order: ");
  levelorder(n, print);
  printf("\n");

  destroy_tree(n);

  getchar();
  return 0;
}
*/
