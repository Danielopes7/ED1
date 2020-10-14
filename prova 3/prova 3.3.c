int abNNosMaiores(Tnode *t, int n, int(*cmp)(void*, void*)){
    int nl, nr, i=0, stat;
    if(t!=NULL){

        /* conta recursivamente a quantidade de nós com valor maior que n */
        nl = abNNosMaiores(t->l, n, cmp);
        nr = abNNosMaiores(t->r, n, cmp);

        /* verifica se o nó atual tem o valor maior que n */
        stat = cmp(t->data, (void*)&n);
        /* se tiver, então acrescenta mais um no número */
        if(stat < 0){
            i++;
        }
        return i+nl+nr;
    }
    return 0;
}

int abHeight(Tnode *t){
    if (t!=NULL) {
        return abHeightRec(t);
    }
    return -1;
}

int abHeightRec(Tnode *t){
    int hl, hl;
    if (t!=NULL) {

        /* conta recursivamente a altura dos filhos */
        hl = abHeightRec(t->l);
        hr = abHeightRec(t->r);
        /* pega a altura do maior e soma com 1 */
        if(hl>hr){
            return hl+1;
        }
        else{
            return hr+1;
        }
    }
    return 0;
}
