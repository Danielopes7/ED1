/* questão 1 */

int abAltura(Tnode *t){
    if(t!=NULL){
        return abAlturaRec(t);
    }
    return -1;
}

int abAlturaRec(Tnode *t){
    int hl, hr;
    if(t!=NULL){
        hl = abAlturaRec(t->l);
        hr = abAlturaRec(t->r);
        if(hl>hr){
            return hl+1;
        }
        else{
            return hr+1;
        }
    }
    return 0;
}

/* questão 2 */

int abNNosAlturaIguais(Tnode *t, int n){
    if(t!=NULL){
        return abNNosAlturaIguaisRec(t, n, 0);
    }
    return -1;
}

int abNNosAlturaIguaisRec(Tnode *t, int n, int h){
    int nl, nr, i=0;
    if (t!=NULL) {
        nl = abNNosAlturaIguaisRec(t->l, n, h+1);
        nr = abNNosAlturaIguaisRec(t->r, n, h+1);
        if (h==n) {
            i = 1;
        }
        return i+nl+nr;
    }
    return 0;
}

/* questão 3 */
