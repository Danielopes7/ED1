#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int compare (void *a ,void *b);
void Imprimindo (void *l);
int fritadata (void *data);

int main() { 
  SllList *A, *B, *In, *Un, *Di;
  int lista;
  int num, n, pos, ins, op, y, x, j, az;
  
  A = SllCreate ();
  B = SllCreate ();
  if (A != NULL && B != NULL){
  	 	op = False;
    	while (op == False) {
			printf ("\n\n");  
		   	printf ("LISTA A: ");imprimir (A, Imprimindo); printf ("\n");
			//printf ("LISTA A: \n");imprimirCircular (A, Imprimindo); printf ("\n");
            printf ("LISTA B: ");imprimir (B, Imprimindo); printf ("\n");

			printf ("  °¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°\n");
	 		printf ("°¨°");printf ("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");printf ("°?°\n");  		
	 		printf ("°¨°");		printf ("\t1.\tNumeros de elementos da lista");printf (" °?°\n");
	 		printf ("°¨°");  	printf ("\t2.\tInserir");printf ("                       °?°\n");
	 		printf ("°¨°");  	printf ("\t3.\tRemover");printf ("                       °?°\n");
	 		printf ("°¨°");  	printf ("\t4.\tOperacoes de conjuntos");printf ("        °?°\n");
	 		printf ("°¨°");  	printf ("\t5.\tRemover Listas (Sair)");printf ("         °?°\n");
	 		printf ("  °¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°°¨°?°\n\n");
	 		printf (">> "); scanf ("%d", &num);
	 		system ("cls");
	 		
	 		switch (num){
				case 1:
					 
					 printf ("Lista A: "); 	 n = SllNumElms(A);printf ("%d", n);
					 printf ("\nLista B: "); n = SllNumElms(B);printf ("%d", n);
					 getche ();
					 system ("cls");
					 break;
					 
				case 2:
					 x = False;
					 while (x == False){
			   
					  printf ("LISTA A: ");imprimir (A, Imprimindo); printf ("\n");
					  //printf ("LISTA A: ");imprimirCircular (A, Imprimindo); printf ("\n");
                      printf ("LISTA B: ");imprimir (B, Imprimindo); printf ("\n");
					  
					  printf ("Inserir na (1.)lista A ou (2.)lista B\n>> "); scanf ("%d", &lista);
			   	      printf ("1. primeira posicao\n2. ultima posicao\n3. automatica insercao\n4. FILA CIRCULAR\n>> "); scanf ("%d", &pos);
					   
					   if (lista == 1){ 
					 	   if (pos == 1){
								printf ("Inserir o numero: "); scanf ("%d", &ins);/*ins = rand();*/	
							  	if (sllInsertFirstPosition(A ,(void *)ins)== True){
		   							 printf ("Inserido com sucesso");
  							 	}
		   	  	 		   }
		   	  	 		   if (pos == 2) {
								printf ("Inserir o numero: "); scanf ("%d", &ins);/*ins = rand();*/	
						   		if (SllInsLastPosition(A ,(void *)ins)== True){
		   							printf ("Inserido com sucesso");
  						 		}
			   		 		}
			   		 	   if (pos == 3) {
								for (j=0;j<10;j++){
									az = rand()%20;
						   			if (SllInsLastPosition(A ,(void *)az)== True){
		   								printf ("numero: %d inserido com sucesso\n",az);
  						 			}
								}	
			   		 		}
			   		 		if (pos == 4) {
								for (j=0;j<10;j++){
									az = rand()%20;
								//	az = j;
						   			if (Enquere(A ,(void *)az)== True){
		   								
                                           printf ("numero: %d inserido com sucesso\n",az);
		   								
  						 			}
								}
                                sllTakeRepeat(A);	
			   		 		}
	 	   			    }

	 	   			   if (lista == 2){ 
					 	   if (pos == 1){
								printf ("Inserir o numero: "); scanf ("%d", &ins);/*ins = rand();*/	
							  	if (sllInsertFirstPosition(B ,(void *)ins)== True){
		   							 sllTakeRepeat(B);
                                        printf ("Inserido com sucesso");
  							 	}
		   	  	 		   }
		   	  	 		   if (pos == 2) {
								printf ("Inserir o numero: "); scanf ("%d", &ins);/*ins = rand();*/	
						   		if (SllInsLastPosition(B ,(void *)ins)== True){
                                    sllTakeRepeat(B);
		   							printf ("Inserido com sucesso");
  						 		}
			   		 		}
			   		 	   if (pos == 3) {
								for (j=0;j<10;j++){
									az = rand()%20;
						   			if (SllInsLastPosition(B ,(void *)az)== True){
		   								printf ("numero: %d inserido com sucesso\n", az);
  						 			}
								}	
			   		 		}
			   		 		sllTakeRepeat(B);
	 	   			    }
	 	   			    
	 	   			   printf ("\nInserir outro elemento: [1. sim/ 2. nao]\n>> ");scanf ("%d", &y);
	 	   			   
						if (y == 1){
					   	  	 x = False;
					   	  	 system ("cls");
   	  	  			   }
   	  	  			   else {
					   		x = True;
   		  			   } 
					 }
					 system ("cls");
					 break;
				case 3:
					
					 x = False;
					 while (x == False){
			   
					  printf ("LISTA A: ");imprimir (A, Imprimindo); printf ("\n");
					//  printf ("LISTA A: ");imprimirCircular (A, Imprimindo); printf ("\n");
                      printf ("LISTA B: ");imprimir (B, Imprimindo); printf ("\n");
					  					  
					  printf ("Remover na (1.)lista A ou (2.)lista B\n>> "); scanf ("%d", &lista);
			   	      printf ("1. primeira posicao\n2. elemento especifico\n3. remover todos\n4. Remover da FILA CIRCULAR\n>> "); scanf ("%d", &pos);
					   
					   if (lista == 1){
					 	   if (pos == 1){
						   	  	if (SllDelFirstPosition(A) != NULL){
		   							printf ("Removido com sucesso");
  							 	}
		   	  	 		   }
		   	  	 		   if (pos == 2){
								printf ("Numero para ser removido: "); scanf ("%d", &ins);
						   		if (SllDelElm (A, (void *)ins,compare)== True){
									printf ("Removido com sucesso");
  							 	}
			   		 	   }
			   		 	   if (pos == 3){
						   		if (sllRemoveAll(A , fritadata)== True){
		   							 printf ("Removido com sucesso");
  							 	}
			   		 	   }
			   		 	   if (pos == 4){
						   		if (Quere(A)!= NULL){
		   							 printf ("Removido com sucesso");
  							 	}
			   		 	   }
	 	   			   }

					   if (lista == 2){
					 	   if (pos == 1){
						   	  	if (SllDelFirstPosition(B) != NULL){
		   							printf ("Removido com sucesso");
  							 	}
		   	  	 		   }
		   	  	 		   if (pos == 2){
								printf ("Numero para ser removido: "); scanf ("%d", &ins);
						   		if (SllDelElm (B, (void *)ins,compare)== True){
									printf ("Removido com sucesso");
  							 	}
			   		 	   }
			   		 	   if (pos == 3){
						   		if (sllRemoveAll(B , fritadata)== True){
		   							 printf ("Removido com sucesso");
  							 	}
			   		 	   }	   
	 	   			   }

					   printf ("\nRemover outro elemento: [1. sim/ 2. nao]\n>> ");scanf ("%d", &y);
	 	   			   if (y == 1){
					   	  	 x = False;
					   	  	 system ("cls");
   	  	  			   }
   	  	  			   else {
					   		x = True;
   		  			   } 
					 }
					 system ("cls");
					 break;
				case 4:
	
					printf ("LISTA A: ");imprimir (A, Imprimindo); printf ("\n");
					printf ("LISTA B: ");imprimir (B, Imprimindo); printf ("\n");
										
					printf ("\n\n# Intersection: "); In = sllIntersection (A, B, compare);
					imprimir (In, Imprimindo); printf ("\n\n");
					printf ("\n\n# Union: "); Un = sllUnion (A, B, compare);
					imprimir (Un, Imprimindo); printf ("\n\n");
					printf ("\n\n# Diference: "); Di = sllDiference (A, B, compare);
					imprimir (Di, Imprimindo); printf ("\n\n");
					getche ();
					system ("cls");
					break;
				case 5:
					sllRemoveAll(A, fritadata);
					sllRemoveAll(B, fritadata);
					op = True;
					 break;	 
  			}
  			
  		 }// fim do while
	 }//fim do if
}
int compare (void *a ,void *b){
	int x, y;
	
	x = (int) a;
	y = (int) b;
	
	if (x == y){
	   	   return True;
 	}
 	else {
		 return False;
 	}
}

int fritadata (void *data){
	int i;
	
	i = (int ) data;
	i = 0;
	return True;
}

void Imprimindo (void *l){
	 int i;
	 
	 i = (int) l;
	 printf ("\t%d", i);  	 
}
