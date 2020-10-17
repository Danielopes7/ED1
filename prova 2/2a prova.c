
/*anselmo reclamou de nao ter o teste de qndo a lista tem menos de 3 no's
bota uns if's pra testar se aux1 e aux2 sao NULL, acho q isso resolve*/
int RemoveOCaraEOsVizinhos(CDllist *l, void *key, int(*cmp)(void*, void*)){

	DllNode *spec, *aux1, *aux2;
	
	spec = dllGetNode(l, key, cmp);//funcao simples q  percorre a lista ate' retornar o no' especificado; retorna NULL se a key nao for encontrada
	
	if(spec != NULL){
		
		spec->prev->next = spec->next;
		spec->next->prev = spec->prev;
		aux1 = spec->prev;
		aux2 = spec->next;
		
		aux1->prev->next = aux1->next;
		aux1->next->prev = aux1->prev;
		
		aux2->prev->next = aux2->next;
		aux2->next->prev = aux2->prev;
		
		if(spec == l->first || aux1 == l->first || aux2 == l->first){
			l->first = aux2->next;
			free(spec);
			free(aux1);
			free(aux2);
			return TRUE;
		}
	}
	return FALSE;
	
	
}


Dllist *dlCorrigeLista(Dllist *l){
	
	Dllnode *cur, *prev;
	
	if(l != NULL){
		cur = l->first;
		if(l->first != NULL){
			while(cur->next != l->first){//percorre a lista toda e para no ultimo no'
				prev = cur;
				cur = cur->next;
				cur->prev = prev;//o campo .prev passa a apontar pro no' anterior
			}
			l->first->prev = cur;//ajusta o .prev do 1o elemento; tem q ser feito fora do while
			return l;
		}
	}
	return NULL;

}


Sllist *PromoveElem(Sllist *l, int n){

	SllNode *cur, *prev, *aux;
	int i, count = 0;
	
	if(l != NULL){
		if(l->first != NULL){
			cur = l->first;
			while(cur->next != NULL){//percorre a lista toda e para no ultimo no'
				prev = cur;
				cur = cur->next;
				count++;//numero de no's percorridos
			}
			prev->next = NULL;//faz o .next do penultimo no' apontar pra NULL, prev sera' o novo ultimo no'
			aux = cur;
			count = count - n;
			if(count < 0){//se o numero de posicoes for maior q o numero de no's, aux sera' o 1o no'
				aux->next = l->first;
				l->first = aux;
			}
			else{
				cur = l->first;
				for(i = 0; i < count, i++){
				
					prev = cur;
					cur = cur->next;
				}
				prev->next = aux;//ajusta os ponteiros fora do for
				aux->next = cur;
			}
		}
	}
}