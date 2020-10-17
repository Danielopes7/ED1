/*
13/06

Trabalho:

-Fazer um programa que l� uma string com a 
representa��o de uma arvore em parenteses 
e cria a arvore na mem�ria.

-Qual o n�mero de folhas em uma �rvore bin�ria dado o n�mero de n�s de grau 2?
-Para uma �rvore bin�ria completa de altura h:
	Qual o n�mero de n�s? (Estritamente completa)
	Qual o n�mero de folhas? (Estritamente completa)
	Qual a altura de uma �rvore bin�ria completa com h n�s?



OBS:
Para a �rvore (A(B(D(H))(E(I)))(C(F(J)G(L)))
preOrdem: ABDHEICFJGL
posOrdem: HDIEBJFLGCA
simetrica: HDBIEAFJCGL


Pesquisar �rvore bin�ria completa e estritamente completa


-Fa�a um algoritmo de visita��o que visite todas as folhas de uma �rvore bin�ria.
-Fa�a um algoritmo que visite todos os n�s n�o folhas de uma �rvore bin�ria.
-Fa�a um algoritmo que conte:
 a)Os n�s
 b)As folhas
 c)Os n�o folhas
 d)Os n�s com 2 filhos
 e)Os n�s com 1 filho
 f)Os n�s s� com filho esquerdo
 g)Os n�s s� com filho direito
 
 _____________________________________________________________________________________________________________
 
 15/06
 
 �RVORES BIN�RIAS DE PESQUISA:
 -Todos os n�s da subarvore esquerda tem valor menor que a ra�z
 -Todos os n�s da subarvore direita tem valor maior ou igual que a ra�z
 -Para todo n� da �rvore
 
 20/06
 
 Exerc�cio: Fa�a um algoritmo que recebe uma �rvore bin�ria e retorna T se ela � ABP e F
 se ela n�o �:
 
 IsABP(TNode *t, int(*cmp)(void *, void *));

22/06

 Exerc�cio: Fa�a um algoritmo que receba uma arvore binaria de pesquisa e uma chave e retorna a altura do n� identificado pela chave.
 int abpAlturadoNo(TNode *t, void *key, int(*cmp)(void*, void*));

 Fa�a um algoritmo que remove todas as folhas de uma arvore binaria de pesquisa.
 Fa�a um algoritmo que remove o menor da de uma arvore de pesquisa.
 Fa�a um algoritmo que remove o maior data de uma arvore de pesquisa.
 Fa�a um algoritmo que calcule a media de todas as alturas dos n�s de uma �rvore.
 
____________________________________________________________________________________________________________________________________________ 
 -�rvores Balanceadas:
	Um n� � balanceado se:
	 hl -> altura da sub-�rvore esquerda
	 hr -> altura da sub-�rvore direita
	 |he-hr| <= 1
	 
	Uma �rvore � balanceada se todos os n�s s�o balanceados.
	
	Exerc�cio: Fa�a um algoritmo que retorne TRUE se a �rvore � balanceada e FALSE se n�o.
 	
	
 */

Inser��o ABP:


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
Remo��o na ABP:
1-N� � folha - Coloca NULL onde estava o n�.
2-Tem 1 s� filho - O fiho fica no lugar do n�.
3-Tem 2 filhos - Coloca no lugar dele o menor da sub-�rvore direita. Remove o menor da sub-arvore direita.
*/

Remove(t, data, cmp){
	n�=acha n�
	se n� � folha
		removeFolha()
	senao
		removeFilho()
	senao
		menorN�=menor(sub-arvore direita)
		n�=menorN�
		Remove(N�->right, menorN�->data)
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

