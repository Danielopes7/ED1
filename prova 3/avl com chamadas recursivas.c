void InsertAVL ( AVLNode *root, void *elm, void (*Compare)(void *a, void *b))
{
   int level; //controle dos nós visitados até a insersão e direções 
   int inserted = FALSE;
   char direction[MAX];//controle das direções até chegar ao nó inserido
   AVLNode path[MAX], *t;//controle dos nós visitados até a insersão
    if ( root == NULL ) {
          root = NewNode( elm );
          return;
    }
    level = 0;
	direction[level] = 'L'; 
    path[level] = root; 
	t = root;
    while (inserted == FALSE) {
       if ( Compare(t, elm) < 0 ) {
            level++;  
			path[level] = t;//aloca o nó visitado no vetor path
            direction[level] = 'L';//aloca a direção correta 
            if( t->left != NULL ) {
                   t = t->left;
             } 
			 else {
                 new = NewNode(elm);
                 t->left = new;
                 inserted = TRUE;
             }
       } 
	     else if(Compare(t,elm) >=0 ) {
            level++;  
			path[level] = t;
            direction[level] = 'R';
            if( t->right != NULL ) {
                   t = t->right;
             } else {
                 new = NewNode(elm);
                 t->right = new;
                 inserted = TRUE;
             } /* fi */
         }  /* elihw */   
      UpdateBalancing(root, direction, path, level, 
                                  Compare);
} 


void UpdateBalancing ( char  *direction , AVLNode*path,       
                                int level, void (*comp)(void *, void *))
{
   int mark = 0, i = level, found=FALSE;
   AVLNode *x, *y; 
   char d;
   while(i>0 && found == FALSE){
      if(path[i]->bf != Balanced) {//se o balanceamento for L ou R
         mark = i;
		 found = TRUE;
      } /* fi */
      i--;
   } /* elihw */
   for (i=mark+1; i<level; i++) {
     if(comp(path[i]->data, elm) <0) {
         path[i]->bf = LeftHeavy;
     } 
	 else{
         path[i]->bf = RightHeavy;
     }
   }
   if ( mark = 0 ) {
        return;
   } 
   else {
          d = direction[mark];
          x = path[mark];
          y = path[mark+1];
          if ( x->bf != d ) {
              x->bf = Balanced;
              return;
          }
          if ( y->bf == d ) {
            BalanceCase1( x, y, path[mark-1] );
            return;
         }
         BalanceCase2(x, y, path[mark-1] );
    } /* fi mark=0 */

}

void BalanceCase1 ( AVLNode *x, AVLNode *y, AVLNode *father, char direction)
{
   if (direction == 'L') {
     x->left = y->right;
     y->right = x;
   } 
   else {
     x->right = y;
     y->left  = x;
   }
   x->bf = y->bf = 'B';
   if ( x = father->left ) {
      father->left = y;
   } else {
      father->right = y;
   }
}


void BalanceCase2 ( AVLNode *x, AVLNode *y, AVLNode *father, char direction)
{
   AVLNode *z;
   if (direction == 'L') {
     z = y->right;
     y->right = z->left;
     z->left = y;
     x->left = z->right;
     z->right = x;
   } else {
     z = y->right;
     y->left  = z;
     z->right = y;
     x->right = z->left;
     z->left = x;
   }
   if ( x = father->left ) {
      father->left = z;
   } else {
      father->right = z;
   }
   if ( z->bf == direction ) {
        y->bf = z->bf = 'B';
        if ( direction = 'L' ) {
             x->bf = 'R';
        } else {
             x->bf = 'L';
        }
   } else {
        if ( z->bf = 'B') { 
           x->bf = y->bf =z->bf = 'B';
        } else {
           x->bf = z->bf = 'B';
           y->bf = direction;
        }
   }
}

/*Funcao Recursiva*/

struct AvlNode
        {
            void* Element;
            AvlTree*  Left;
            AvlTree*  Right;
            int      Height;
        };

        AvlTree* MakeEmpty( AvlTree* T )
        {
            if( T != NULL )
            {
                MakeEmpty( T->Left );
                MakeEmpty( T->Right );
                free( T );
            }
            return NULL;
        }

        Position*
        Find( void* X, AvlTree* T, int(*cmp)(void*, void*) )
        {
            if( T == NULL )
                return NULL;
            if(cmp(X, T->Element) == MENOR)
                return Find( X, T->Left, cmp );
            else
            if(cmp(X, T->Element) == MAIOR)
                return Find( X, T->Right, cmp );
            else
                return T;
        }

        Position*
        FindMin( AvlTree* T )
        {
            if( T == NULL )
                return NULL;
            else
            if( T->Left == NULL )
                return T;
            else
                return FindMin( T->Left );
        }

        Position*
        FindMax( AvlTree* T )
        {
            if( T != NULL )
                while( T->Right != NULL )
                    T = T->Right;

            return T;
        }

/* START: fig4_36.txt */
        static int
        Height( Position* P )
        {
            if( P == NULL )
                return -1;
            else
                return P->Height;
        }
/* END */

        static int
        Max( int Lhs, int Rhs )
        {
            return Lhs > Rhs ? Lhs : Rhs;
        }

/* START: fig4_39.txt */
        /* This function can be called only if K2 has a left child */
        /* Perform a rotate between a node (K2) and its left child */
        /* Update heights, then return new root */

        static Position*
        SingleRotateWithLeft( Position* K2 )
        {
            Position* K1;

            K1 = K2->Left;
            K2->Left = K1->Right;
            K1->Right = K2;

            K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
            K1->Height = Max( Height( K1->Left ), K2->Height ) + 1;

            return K1;  /* New root */
        }
/* END */

        /* This function can be called only if K1 has a right child */
        /* Perform a rotate between a node (K1) and its right child */
        /* Update heights, then return new root */

        static Position*
        SingleRotateWithRight( Position* K1 )
        {
            Position* K2;

            K2 = K1->Right;
            K1->Right = K2->Left;
            K2->Left = K1;

            K1->Height = Max( Height( K1->Left ), Height( K1->Right ) ) + 1;
            K2->Height = Max( Height( K2->Right ), K1->Height ) + 1;

            return K2;  /* New root */
        }

/* START: fig4_41.txt */
        /* This function can be called only if K3 has a left */
        /* child and K3's left child has a right child */
        /* Do the left-right double rotation */
        /* Update heights, then return new root */

        static Position*
        DoubleRotateWithLeft( Position* K3 )
        {
            /* Rotate between K1 and K2 */
            K3->Left = SingleRotateWithRight( K3->Left );

            /* Rotate between K3 and K2 */
            return SingleRotateWithLeft( K3 );
        }
/* END */

        /* This function can be called only if K1 has a right */
        /* child and K1's right child has a left child */
        /* Do the right-left double rotation */
        /* Update heights, then return new root */

        static Position*
        DoubleRotateWithRight( Position* K1 )
        {
            /* Rotate between K3 and K2 */
            K1->Right = SingleRotateWithLeft( K1->Right );

            /* Rotate between K1 and K2 */
            return SingleRotateWithRight( K1 );
        }


/* START: fig4_37.txt */
        AvlTree*
        Insert( void* X, AvlTree* T, int(*cmp)(void*, void*) )
        {
            if( T == NULL )
            {
                /* Create and return a one-node tree */
                T = malloc( sizeof( struct AvlNode ) );
                if( T == NULL )
                    FatalError( "Out of space!!!" );
                else
                {
                    T->Element = X; T->Height = 0;
                    T->Left = T->Right = NULL;
                }
            }
            else
            if(cmp(X, T->Element) == MENOR)
            {
                T->Left = Insert( X, T->Left, cmp );
                if( Height( T->Left ) - Height( T->Right ) == 2 )
                    if( cmp(X, T->Left->Element) == MENOR )
                        T = SingleRotateWithLeft( T );
                    else
                        T = DoubleRotateWithLeft( T );
            }
            else
            if(cmp(X, T->Element) == MAIOR)
            {
                T->Right = Insert( X, T->Right, cmp );
                if( Height( T->Right ) - Height( T->Left ) == 2 )
                    if( cmp(X, T->Right->Element) == MAIOR )
                        T = SingleRotateWithRight( T );
                    else
                        T = DoubleRotateWithRight( T );
            }
            /* Else X is in the tree already; we'll do nothing */

            T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
            return T;
        }
/* END */



/**************************************************/

//teste da funcao com chamadas recursivas

avltree = Insert((void*)50, &NULL, cmp){
        
		if(t == NULL){
		    t->data = 50;
			t->height = 0;
			t->left = t->right = NULL;
		}
		 
		t->height = Max(Height(NULL), Height(NULL)) +1; //height == 0
        return &50;

}

Insert((void*)40, &50, cmp)
{

     else if (cmp(40, 50) < 0){
	     &50->left = Insert(40, &50->left/*&50->left == NULL*/, cmp)/*&50->left = &40*/
		             {
		                if(t == NULL){
		                t->data = 40;
			            t->height = 0;
			            t->left = t->right = NULL;
		                }
		 
		                &40->height = Max(Height(NULL), Height(NULL)) +1; //height == 0  
		                return &40;
	                 }//END &40
	 if(Height(&40) - Height(NULL) == 2)//falso, Height(&40) - Height(NULL) == 1
	 &50->height = Max(Height(&40), Height(NULL)) +1; //height == 1
	 return &50;

}

Insert((void*)20, &50, cmp)
{
     else if (cmp(20, 50) < 0)
	 {
	     &50->left = Insert(20, &50->left/&40*/, cmp)
		             {
	                      else if (cmp(20, 40) < 0)
						  {
	                          &40->left = Insert(20, &40->left/*&40->left == NULL*/, cmp)//&40->left = &20
		                                  {
		                                      if(t == NULL){
		                                      t->data = 20;
			                                  t->height = 0;
			                                  t->left = t->right = NULL;
		                                      }
										      &20->height = Max(Height(NULL), Height(NULL)) +1;//20->height == 0
										      return &20;
									     }//END Insert &20		 
		                      if(Height(&20) - Height(NULL) == 2)//falso, Height(&20) - Height(NULL) == 1
							  }//end else if
		                  &40->height = Max(Height(&20), Height(NULL)) +1; //&40->height == 1
		                  return &40;
	                 }//END Insert &40
		if(Height(&40) - Height(NULL) == 2)//verdadeiro, Height(&40) - Height(NULL) == 2
		{
		    if(cmp( 20,&50->left->data/*40*/ ) < 0)
			{
			    t = SingleRotateWithLeft(t/*&50*/)
				    {
				        AVLNode *newroot;
						
						newroot = &50->left;//&40
						&50->left = newroot->right;//NULL
						newroot->right = &50;
						
						t->height/*&50*/ = Max(Height(t->left/*NULL*/)/*-1*/, Height(t->right/*NULL*/)/*-1*/) +1;//&50->height == 0
						newroot->height = Max(Height(newroot->left/*&20*/)/*0*/, Height(newroot->right/*&50*/)/*0*/) +1;//&40->height == 1
				    }//END SingleRotateWithLeft(&50)
			}//end if cmp(data, t->left->data)
		}//end if(height() - height())
	 }//end else if
	    &40->height = Max(Height(&20)/*0*/, Height(&50)/*0*/) +1;//&40->height = 1

}

Insert((void*)55, &40, cmp)
{
     else if(cmp(55, 40) > 0)
	 {
	     &40->right = Insert(55, &50, cmp)
		              {
		                  else if(cmp(55, 50) > 0)
						  {
						      &50->right = Insert(55, &50->right/*NULL*/, cmp)//&50->right = &55
							               {
										        if(t == NULL)
												{
		                                        t->data = 55;
			                                    t->height = 0;
			                                    t->left = t->right = NULL;
		                                        }
										      &55->height = Max(Height(NULL), Height(NULL)) +1;//55->height == 0
										      return &55;
										   }//END Insert #3
							  if( Height( &50->right/*&55*/ )/*0*/ - Height( &50->left/*NULL*/ )/*-1*/ == 2 )
						  }//end else if #2
						  &50->height = Max(Height(NULL), Height(&55)) +1;//&50->height = 1
		              }//END Insert #2
		 if( Height( &50 )/*1*/ - Height( &20 )/*0*/ == 2 )//1 == 2, false
	 }//end else if #1
	 
	 &40->height = Max( Height( &20 )/*0*/, Height( &50 )/*1*/ ) + 1;//&40->height == 2
	 return &40;
}//END MOR


Insert((void*)60, &40, cmp)
{
    else if(cmp(60, 40) > 0)
	{
	    &40->right = Insert(60, &40->right/*&50*/, cmp)
		             {
		                  else if(cmp(60, 50) > 0)
						  {
						      &50->right = Insert(60, &50->right/*&55*/, cmp)
							               {
										       else if(cmp(60, 55) > 0)
											   {
											       &55->right = Insert(60, &55->right/*NULL*/, cmp)
												                {
												                    if(t == NULL)
												                    {
		                                                                t->data = 60;
			                                                            t->height = 0;
			                                                            t->left = t->right = NULL;
		                                                            }
										                            &60->height = Max(Height(NULL), Height(NULL)) +1;//60->height == 0
										                            return &60;
												                }//END Insert #4
												   if( Height( &55->right/*&60*/ )/*0*/ - Height( &55->left/*NULL*/ )/*-1*/  == 2 )//FALSE
											   }//end else if #3
											   &55->height = Max( Height( &55->left/*NULL*/ )/*-1*/, Height( &55->right/*&60*/ ) ) + 1;//&55->height = 1
                                               return &55;
										   }//END Insert #3
							  if( Height( &50->right/*&55*/ )/*1*/ - Height( &50->Left/*NULL*/ ) == 2 )//TRUE
							  {
							      if(cmp(60, &50->right->data/*55*/) > 0)
								  {
								      t = SingleRotateWithRight(t/*&50*/)
									  {
									      AVLNode *newroot;
										  
										  newroot = &50->right;/*&55*/
										  &50->right = &55->left;/*NULL*/
										  &55->left = &50;
										  
										  &50->height = Max(Height(NULL), Height(NULL)) +1;//&50->height = 0
										  &55->height = Max(Height(&50), Height(&60)) +1;//&55->height = 1
									  }// END SingleRotateWithRight()
								  }//end if(cmp())
							  }//end if (Height() - Height())
						  }//end else if #2
						  &55->height = Max( Height( &50/*0*/ ), Height( &60 /*0*/) ) + 1;//&55->height = 1
                          return &55;
		             }//END Insert #2
		if( Height( &40->right/*&55*/ )/*1*/ - Height( &40->left/*&20*/ )/*0*/ == 2 )//FALSE
	}//end else if #1
	
	&40->height = Max( Height( &40->left/*&20*/ )/*0*/, Height( &40->right/*&55*/ )/*1*/ ) + 1;//&40->height = 2
    return &40;
	
}//END MOR

Insert((void*)45, &40, cmp)
{
    else if(cmp(45, 40) > 0)
	{
	    Insert(45, &40->right/*&55*/, cmp)
		{
		    else if(cmp(45, 55) < 0)
			{
			    Insert(45, &55->left/*&50*/, cmp)
				{
				    else if(cmp(45, 50) < 0)
					{
					    Insert(45, &50->left/*NULL*/, cmp)
						{
						    if(t == NULL)
						    {
		                        t->data = 45;
			                    t->height = 0;
			                    t->left = t->right = NULL;
		                    }
		                    &45->height = Max(Height(NULL), Height(NULL)) +1;//&45->height == 0
		                    return &45;
						}//END Insert #4
						if(Height(&50->left/*&45*/)/*0*/ - Height(&50->right/*NULL*/)/*-1*/ == 2){/*(FALSE)*/}//end if(Height(), Height()) LEFT #2
					}//end else if #3
					&50->height = Max(Height(&50->left/*&45*/)/*0*/, Height(NULL)/*-1*/) +1;//&50->height = 1
					return &50;
				}//END Insert #3
				if(Height(&55->left/*&50*/)/*1*/ - Height(&55->right/*&60*/)/*0*/ == 2){/*FALSE*/}//end if(Height(), Height()) LEFT #1
			}//end else if #2
			&55->height = Max(Height(&50)/*1*/, Height(&60)/*0*/) +1;//&55->height = 2
	        return &55;
		}//END Insert #2
		if(Height(&40->right/*&55*/)/*2*/ - Height(&40->left/*&20*/)/*0*/ == 2)
		{
		    if(cmp(45, &40->right->data/*55*/) > 0){/*FALSE*/}//end if(cmp()) RIGHT #1
			else
			{
			    /*&40*/t = DoubleRotateWithRight(&40)
				           {
				               &40->right = SingleRotateWithLeft(&40->right/*&55*/)//&40->right = &45
							                {
											    AVLNode *newroot;
												
												newroot = &55->left;/*&50*/
												&55->left =  newroot->right;/*&->right == NULL*/
												newroot->right = &55;
												
												&55->height = Max(Height(&50->left/*NULL*/)/*-1*/, Height(&50->right/*&55*/)/*0*/) +1;//&55->height = 1
												newroot->height/*&50*/ = Max(Height(&50->left/*&45*/)/*0*/, Height(&45->right/*NULL*/)/*1*/) +1;//&45->right = 2
												
												return &50;
											}//END SingleRotateWithLeft()
							   return SingleRotateWithRight(&40)
							          {
									      AVLNode * newroot;
										  
										  newroot = &40->right;/*&50*/
										  &40->right = newroot->left;/*&45*/
										  newroot->left = &40;
										  
										  &40->height = Max(Height(&20)/*0*/, Height(&45)/*0*/) +1;//&40->height = 1
										  &50->height = Max(Height(&40)/*1*/, Height(&55)/*1*/) +1;//&50->height = 2
										  return &50;
									  }//SingleRotateWithRight()
				           }//END DoubleRotateWithRight()
			}//end else RIGHT #1
		}//end if(Height(), Height()) RIGHT #1
	}//end else if #1
	&50->height = Max(Height(&40)/*1*/, Height(&55)/*1*/) +1;//&50->height = 2
	return &50;
}//END MOR


























