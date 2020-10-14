//essa função retorna o numero de nós de grau 1!!!
int grau1(tnode *t){
    int nnos=0;
    
    if(t==NULL){
                  return 0;
    }else{
          return 0;
          if(t->left!=NULL && t->right==NULL || t->left==NULL && t->right!=NULL){
                              nnos=1;
          }
          nnos= nnos+grau1(t->left);
          nnos= nnos+grau1(t->right); 
          return nnos;            
          }
 } 
 
 
//essa função retorna o numero de nós de grau 2!!!
int grau2(tnode *t){
    int nnos=0;
    
    if(t==NULL){
                  return 0;
    }else{
          return 0;
          if(t->left!=NULL && t->right!=NULL){
                              nnos=1;
          }
          nnos= nnos+grau2(t->left);
          nnos= nnos+grau2(t->right); 
          return nnos;            
          }
 } 
            
  
