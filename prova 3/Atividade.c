/*
13/06

Trabalho:

-Fazer um programa que lê uma string com a 
representação de uma arvore em parenteses 
e cria a arvore na memória.

-Qual o número de folhas em uma árvore binária dado o número de nós de grau 2?
-Para uma árvore binária completa de altura h:
	Qual o número de nós? (Estritamente completa)
	Qual o número de folhas? (Estritamente completa)
	Qual a altura de uma árvore binária completa com h nós?



OBS:
Para a árvore (A(B(D(H))(E(I)))(C(F(J)G(L)))
preOrdem: ABDHEICFJGL
posOrdem: HDIEBJFLGCA
simetrica: HDBIEAFJCGL


Pesquisar árvore binária completa e estritamente completa


-Faça um algoritmo de visitação que visite todas as folhas de uma árvore binária.
-Faça um algoritmo que visite todos os nós não folhas de uma árvore binária.
-Faça um algoritmo que conte:
 a)Os nós
 b)As folhas
 c)Os não folhas
 d)Os nós com 2 filhos
 e)Os nós com 1 filho
 f)Os nós só com filho esquerdo
 g)Os nós só com filho direito
 
 _____________________________________________________________________________________________________________
 
 15/06
 
 ÁRVORES BINÁRIAS DE PESQUISA:
 -Todos os nós da subarvore esquerda tem valor menor que a raíz
 -Todos os nós da subarvore direita tem valor maior ou igual que a raíz
 -Para todo nó da árvore
 
 20/06
 
 Exercício: Faça um algoritmo que recebe uma árvore binária e retorna T se ela é ABP e F
 se ela não é:
 
 IsABP(TNode *t, int(*cmp)(void *, void *));

22/06

 Exercício: Faça um algoritmo que receba uma arvore binaria de pesquisa e uma chave e retorna a altura do nó identificado pela chave.
 int abpAlturadoNo(TNode *t, void *key, int(*cmp)(void*, void*));

 Faça um algoritmo que remove todas as folhas de uma arvore binaria de pesquisa.
 Faça um algoritmo que remove o menor da de uma arvore de pesquisa.
 Faça um algoritmo que remove o maior data de uma arvore de pesquisa.
 Faça um algoritmo que calcule a media de todas as alturas dos nós de uma árvore.
 
____________________________________________________________________________________________________________________________________________ 
 -Árvores Balanceadas:
	Um nó é balanceado se:
	 hl -> altura da sub-árvore esquerda
	 hr -> altura da sub-árvore direita
	 |he-hr| <= 1
	 
	Uma árvore é balanceada se todos os nós são balanceados.
	
	Exercício: Faça um algoritmo que retorne TRUE se a árvore é balanceada e FALSE se não.
 	
	
 */

Inserção ABP:


 void *abpQueryNode(TNode *t, void *key, int(*cmp)(void *, void *)){
	int stat;
	if(t!=NULL){
		stat = cmp(key, t->data) == 0
		if(stat == 0){
			return t->data;
		}
		else{
			if(stat == -1){
				return abpQueryNode(t->left, key, cmp);
			}
			else{
				if(stat == 1){
					return abpQueryNode(t->right, key, cmp);
				}
			}
		}
	}
	return NULL;
 }
 
 
 TNode *abpInsert((TNode *t, void *data, int (*cmp)(void *, void *)){
	TNode *newnode;
	if(t!=NULL){
		stat=cmp(data, t->data);
		if(stat<0){
			t->left = abpInsert(t->left, data, cmp);
		}
		else{
			t->right = abpInsert(t->right, data, cmp);
		}
		return t;
	}
	else{
		newndoe=(TNode*)malloc(sizeof(TNode));
		if(newnode!=NULL){
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
		}
		return newnode;
	}
	
 }
 
/*
Remoção na ABP:
1-Nó é folha - Coloca NULL onde estava o nó.
2-Tem 1 só filho - O fiho fica no lugar do nó.
3-Tem 2 filhos - Coloca no lugar dele o menor da sub-árvore direita. Remove o menor da sub-arvore direita.
*/

Remove(t, data, cmp){
	nó=acha nó
	se nó é folha
		removeFolha()
	senao
		removeFilho()
	senao
		menorNó=menor(sub-arvore direita)
		nó=menorNó
		Remove(Nó->right, menorNó->data)
}

TNode *abpRemove(TNode *t, void *data, int (*cmp)(void *, void *)){
		TNode *filho;
		if(t!=NULL){
			if(cmp(t->data, key) == 0){
				if(t->left == NULL && t->right == NULL){
					free(t);
					return NULL;
				}
				else{
					if(t->left == NULL && t->right != NULL){
						filho=t->right;
						free(t);
						return filho;
					}
				}
					else{
						if(t->left != NULL && t->right == NULL){
							filho=t->left;
							free(t);
							return filho;
						}
						else{
							t->data = abpGetMenor(t->right);
							t->right = abpRemove(t->right, t->data, cmp);
							return t;
						}
					}
			}
			else{
				if(cmp(t->data, key)<0){
					t->left=abpRemove(t->left, key, cmp);
					return t;
				}
				else{
					t->right abpRemove(t->right, key, cmp);
					return t;
				}
			}
		}
}

TNode *abpGetMenorData(TNode *t){
	if(t!=NULL){
		if(t->left!= NULL){
			return abpGetMenorData(t->left);
		}
		else{
			return t->data;
		}
	}
	return NULL;
}

