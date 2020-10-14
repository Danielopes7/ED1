int isAbp(Tnode *t, int(*cmp)(void*, void*)){
    int statl, statr;

    /* se o nó existir */
    if(t!=NULL){

        /* verifica o filho esquerdo */
        if(t->l!=NULL){
            statl = cmp(abMaior(t->l, cmp), t->data);

            /* se o filho esquerdo for maior que ele, então não é abp */
            if(stat > 0){
                return FALSE;
            }
        }

        /* verifica o filho direito */
        if (t->r!=NULL) {
            statr = cmp(abMaior(t->r, cmp), t->data);

            /* se o filho direito for menor ou igual a ele, então não é abp */
            if (stat == 0 || stat < 0) {
                return FALSE;
            }
        }

        /* se nenhum dos filhos está no lugar errado, verifica recursivamente se
        as subarvores são abp, retorna TRUE se ambas forem, caso só uma seja, retorna
        FALSE */
        return isAbp(t->l, cmp) && isAbp(t->r, cmp);
    }

    /* se o nó não existir, retorna TRUE por padrão */
    return TRUE;
}

void* abMaior(Tnode* t, int(*cmp)(void*, void*)){
    void *maiorL, *maiorR;
    int *cur, *pl, *pr;
    if(t!=NULL){
        if(t->l == NULL && t->r == NULL){
            return t->data;
        }
        else {
            if (t->l!=NULL) {
                maiorL = abMaior(t->l, cmp);
            }
            if(t->r!=NULL){
                maiorR = abMaior(t->r, cmp);
            }
            stat1 = cmp(maiorL, maiorR);
            if(stat1 == 0 || stat1 > 0){
                stat1 = cmp(t->data, maiorL);
            }
            else {
                stat1 = cmp(t->data, maiorR);
            }
            if (stat1 >= 0) {
                return t->data;
            }
            else {
                return maiorR;
            }
        }
    }
    return NULL;
}



int isHeap(Tnode *t, int(*cmp)(void*, void*)){
    void *maiorL, *maiorR;
    if(t!=NULL){
        if (t->l!=NULL) {
            maiorL = abMaior(t->l, cmp);
            stat = cmp(t->data, maiorL);
            if(stat<0){
                return FALSE;
            }
        }
        if (t->r!=NULL) {
            maiorR = abMaior(t->r, cmp);
            stat = cmp(t->data, maiorR);
            if (stat<0){
                return FALSE;
            }
        }
        return isHeap(t->l, cmp) && isHeap(t->r, cmp);
    }
    return TRUE;
}
