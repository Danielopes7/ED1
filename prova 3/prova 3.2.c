int abNSheet(Tnode *t){
    int nl=0, nr=0, i = 0;
    if (t->l!=NULL) {
         nl = abNSheet(t->l);
    }
    if(t->r!=NULL){
        nr = abNSheet(t->r);
    }
    if (t->l == NULL && t->r == NULL) {
        i =1;
    }
    return i+nl+nr;
}

void visit(Tnode *t) {
    char *c;
    if(t!=NULL){
        visit(t->l);
        visit(t->r);
        c = (char*)t->data;
        printf("%s\n", *c);
    }
}
