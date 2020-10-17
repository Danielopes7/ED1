//essa funcao organiza a fila circular colocando o primeiro elemento na primeira posicao do vetor
void OrganizaFilaPrimeiro(Queue*q)
{
    void *aux;
    int i;
    int prev;
    if(q->nelm>0)
    {
        if(q->nelm<q->max-1)
        {
            while(q->beg!=0)
            {
                aux=q->elm[q->end];
                i=q->beg;
                while(i!=q->end)
                {
                    if(i==0)
                    {
                        prev=q->max-1;
                    }
                    else
                    {
                        prev=i-1;
                    }
                    q->elm[prev]=q->elm[i];
                    if(i==q->max-1)
                    {
                        i=0;
                    }
                    else
                    {
                        i++;
                    }
                }
                q->elm[i]=aux;
                q->beg--;
                if(q->end==0)
                {
                    q->end=q->max-1;
                }
                else
                {
                    q->end--;
                }
            }
        }
    }
}

//essa funcao organiza uma fila circular colocando o ultimo elemento na ultima posição do vetor
void OrganizaFilaUltimo(Queue *q)
{
    void*aux;
    int i;
    int prev;
    if(q->nelm>0)
    {
        if(q->nelm<q->max-1)
        {
            while(q->end!=q->max-1)
            {
                aux=q->elm[q->beg];
                i=q->end;
                while(i!=q->beg)
                {
                    if(i==q->max-1)
                    {
                        prev=0;
                    }
                    else
                    {
                        prev=i-1;
                    }
                    q->elm[prev]=q->elm[i];
                    if(i==0)
                    {
                        i=q->max-1;
                    }
                    else
                    {
                        i--;
                    }
                }
                q->elm[i]=aux;
                q->end++;
                if(q->beg==q->max-1)
                {
                    q->beg=0;
                }
                else
                {
                    q->beg++;
                }
            }
        }
    }

//essa funcao pune uma pilha n posicoes
    void PunePilha(Stack*s,int n)
    {
        void*aux;
        int i;
        if(s->top>0)
        {
            i=s->top;
            aux=q->elm[s->top];
            do
            {
                s->elm[i]=s->elm[i+1];
                i--;
            }
            while(i<n);
            s->elm[i+1]=aux;
        }
    }

//essa funcao promove o ultimo elemento de uma fila circular e o coloca no meio da fila!!! fura fila
    void PromoveFuraFila(Queue *q)
    {
        int p,ij;
        void*aux;
        if(q->nelm>0)
        {
            p=q->end;
            j=q->end;
            i=((q->nelm)/2);
            aux=q->elm[q->end];
            while(i!=0)
            {
                if(p==0)
                {
                    p=q->max-1;
                }
                else
                {
                    p--;
                }
                q->elm[j]=q->elm[p];
                if(j==0)
                {
                    j=q->max-1;
                }
                else
                {
                    j--;
                }
                i--;
            }
            q->elm[j]=aux;
        }
    }

//essa funcao puni o primeiro elemento de uma fila circular e o coloca no meio da fila!!! fura fila

    void PuneFuraFila(Queue*q)
    {
        int p,i,j;
        void*aux;
        if(q->nelm>0)
        {
            p=q->beg;
            j=q->beg;
            i=((q->nelm)/2);
            aux=q->elm[q->beg];
            while(i!=0)
            {
                if(p==q->max-1)
                {
                    p=0;
                }
                else
                {
                    p++;
                }
                q->elm[j]=q->elm[p];
                if(j==q->max-1)
                {
                    j=0;
                }
                else
                {
                    j++;
                }
                i--;
            }
            q->elm[j]=aux;
        }
    }

//essa funcao promove o ultimo elemento de uma fila circular e o coloca na primeira posiçao da fila!!! fura fila
    void PromoveUltimoFila(Queue *q)
    {
        int p,ij;
        void*aux;
        if(q->nelm>0)
        {
            p=q->end;
            j=q->end;
            i=q->nelm;
            aux=q->elm[q->end];
            while(i!=0)
            {
                if(p==0)
                {
                    p=q->max-1;
                }
                else
                {
                    p--;
                }
                q->elm[j]=q->elm[p];
                if(j==0)
                {
                    j=q->max-1;
                }
                else
                {
                    j--;
                }
                i--;
            }
            q->elm[j]=aux;
        }
    }

//essa funcao puni o primeiro elemento de uma fila circular e o coloca na ultima posiçao da fila!!! fura fila

    void PuneFuraFila(Queue*q)
    {
        int p,i,j;
        void*aux;
        if(q->nelm>0)
        {
            p=q->beg;
            j=q->beg;
            i=q->nelm;
            aux=q->elm[q->beg];
            while(i!=0)
            {
                if(p==q->max-1)
                {
                    p=0;
                }
                else
                {
                    p++;
                }
                q->elm[j]=q->elm[p];
                if(j==q->max-1)
                {
                    j=0;
                }
                else
                {
                    j++;
                }
                i--;
            }
            q->elm[j]=aux;
        }
    }


//essa função insere no inicio da fila!!
    int FuraFila(Queue* q,void* elm)
    {
        if(q->nelm<q->max-1)
        {
            if(q->beg==0)
            {
                q->beg=q->max-1;
            }
            else
            {
                q->beg--;
            }
            q->elm[q->beg]=elm;
            return TRUE;
        }
        return FALSE;
    }

//essa função inverte uma fila utilizando uma pilha
    int InverteFila(Queue* q)
    {
        Stack* s;
        int i;
        void* key;
        i=q->nelm;
        if(q->nelm>0)
        {
            s=stkCreate(i);
            while(i!=0)
            {
                key=Dequeue(q);
                stkPush(s,key);
                i--;
            }
            while(s->top!=-1)
            {
                key=Pop(s);
                Enqueue(key);
            }
            return TRUE;
        }
        return FALSE;
    }

//essa função remove todos os elemntos de uma pila até encontrar o elemento que foi passado na função
    int RemoveTodosAteElm(Stack* s,int elm)
    {
        if(s->top1->0)
        {
            while(q->elm[s->top]!=elm && s->top1->-1)
            {
                s->top--;
            }
            return TRUE;
        }
        return FALSE;
    }





