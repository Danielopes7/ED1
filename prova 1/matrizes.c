#include<stdio.h>
//**Multiplicaçao da matriz por um vetor**//
int multiplicamatriz(int *v1,int *v2,int n)
{

    int i,j,k,temp;
    int *v3;

    v3=(int*)malloc(n*sizeof(int));
    if(v3!=NULL)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp=0;
                for(k=0; k<n; k++)
                {
                    temp=temp+v1[i*n+k]*v2[k];
                }
                v3[i*n+j]=temp;
            }
        }
    }
    return NULL;
}


//** Multiplicaçao de Matrizes**//


int multiplicaMatriz(int *v1,int *v2,int *v3,int n)
{

//20/09/11 00:05

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            temp=0;
            for(k=0; k<n; k++)
            {
                temp=temp+v1[i*n+k]*v2[k*n+j];
            }
            v3[i*n+j]=temp;
        }
    }
    return v3;
}
//** Multiplica pela Trasposta**//

int MultiplicaMatrizPelaTransposta(int *v1,int *v2,int *v3,int n)
{

    int i,j,k,temp;

    if(v1!=NULL && v2!=NULL && v3!=NULL)
    {

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp=0;
                for(k=0; k<n; k++)
                {
                    temp=temp+v1[i*n+k]*v2[j*n+k];
                }
                v3[i*n+j]=temp;
            }
        }
    }
    return NULL;
}
//** Matriz Transposta**//
int Transposta(int *v1,int *v2,int n)
{

    int i,j,*v1t;

    v1t=(int*)malloc(n*sizeof(int));

    if(v1t!=NULL)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                v1t[i*n+j]=v1[j*n+i];
                v2[i*n+j]=v1t[i*n+j];

            }
        }
        return v2;
    }
    return NULL;
}
//**Matriz Simetrica**//


int eSimetrica(int *v1,int n)
{

    int i,j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(v1[i*n+j]!=v1[j*n+i])
            {
                return FALSE;

            }
        }
    }
    return TRUE;
}

//** Matriz Antisimetrica**//

int eAntisimetrica(int *v1,int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(v1[i*n+j]!=-v1[j*n+i])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}


//**Soma de uma Matriz**//


int Soma(int *v1,int *v2,int n)
{
    int i,j;

    v3=(int*)malloc(n*sizeof(int));
    if(v3!=NULL)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                v3[i*n+j]=v1[i*n+j]+v2[i*n+j];
            }
        }

        return v3;
    }
    return NULL;

}

//**Extrai Coluna**//

int ExtraiColuna(int*v,int *vcoluna,int n,int An,int C)
{
    int i,k;
    vcoluna=(void**)calloc(An,sizeof(void*));
    if(vcoluna!=NULL)
    {
        for(i=0; i<An; i++)
        {
            k=i*n+C;
            vcoluna[i]=v[k];
        }
        return TRUE;
    }
    return FALSE;
}


//** int SomaLinhaColuna**//
int somalinhacoluna(int *v1,int *v2,int C,int B,int n)
{
    int i,j,soma=0;
    if(v1!=NULL && v2!=NULL)
    {
        for(i=0; i<n; i++)
        {
            soma=soma+v1[i*n+C];
        }
        for(j=0; j<n; j++)
        {
            soma=soma+v2[B*n+j];
        }
        return soma;
    }
    return 0;
}
