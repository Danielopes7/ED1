#include <stdlib.h>
#include <stdio.h>

typedef struct _Colecao_ Colecao;


Colecao *criar( int tam); //cria uma coleção generica 
int inserir(Colecao *cofo, void *dado); //insere um dado na colecao
void *procurar(Colecao *cofo, void *key, int(*cmp)(void*,void*)); //pesquisa um dado dentro da colecao
void *remover(Colecao *cofo, void *key, int (*cmp)(void*,void*)); //remove um dado da colecao
int destruir (Colecao *cofo); //destroi a colecao caso ela esteja vazia
void *printarElementos(Colecao *cofo, void (*listar)(void* elm));
