int isHeap(Tnode *t){

    if (t!=NULL) {
        /* se houver filho esquerdo */
        if (t->l!=NULL) {
            /* pega o maior valor da subarvore esquerda e compara com o valor do pai */
            maiorL = abMaior(t->l);
            stat = cmp(t->data, maiorL);
            /* se o pai for menor */
            if(stat<0){
                /* retorna FALSE */
                return FALSE;
            }
        }
        /* se houver filho direito */
        if (t->r!=NULL) {
            /* pega o maior valor da subarvore direita e compara com o valor do pai */
            maiorR = abMaior(t->r);
            stat = cmp(t->data, maiorR);
            /* se o pai for menor */
            if (stat < 0) {
                /* retorna FALSE */
                return FALSE;
            }
        }

        /* se não tiver nenhum problema, verifica recursivamente os filhos */
        return isHeap(t->l) && isHeap(t->r);
    }

    /* retorna TRUE se não houver nó */
    return TRUE;
}

int abNNosUmFilho(Tnode *t){
    int nl, nr, i=0;
    if(t!=NULL){

        /* conta recursivamente os nós com um filho das subarvores */
        nl = abNNosUmFilho(t->l);
        nr = abNNosUmFilho(t->r);

        /* se o nó atual for um nó com um filho, adiciona mais um na conta */
        if (t->l!=NULL && t->r == NULL) {
            i = 1;
        }
        else if (t->l == NULL && t->r != NULL) {
            i = 1;
        }
        return i+nl+nr;
    }
    /* se não existir n ó, retorna 0 */
    return 0;
}
