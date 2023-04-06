#include <stdio.h>
#include <stdlib.h>

void aloca(float **p,int tam);
void leitura(float *p);
void mostra(float *p,int tam);
int media(float *p,int tam,float **pM);

int main()
{
	float *ptr=NULL, *pmaior=NULL;
	int qtde=0, qmaior;
	char op;
	do{
		aloca(&ptr, qtde+1);
		leitura(ptr+qtde);
		qtde++;
		printf("\ndeseja continuar?<S/N> ");
		scanf("%c",&op);
		fflush(stdin);
	}while(op != 'n' && op != 'N' );
	printf("\nnumeros:");
	mostra(ptr,qtde);
	qmaior=media(ptr, qtde, &pmaior);
	printf("\nNum maiores q media:");
	mostra(pmaior,qmaior);
	printf("\n\n");
	system("pause");
}

void aloca(float **p,int tam){
	if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL)
	exit (1);
}

void leitura(float *p){
	printf("\nDigite o numero: ");
	scanf("%f",p);
	fflush(stdin);
}

void mostra(float *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%.2f",*(p+i));
}//mostra


int media(float *p, int tam, float **pM)
{
	int i, qM=0;
	float m=0;
	for(i=0;i<tam;i++)
		m += *(p+i);// explica;ao *(p+i)
	m/= tam;
	printf("\nMedia: %.2f\n\n",m);
	system("pause");
	for(i=0;i<tam;i++)
		if(*(p+i)>m){
			aloca(pM,qM+1);
			*(*pM+qM)= *(p+i);// o que isso faz?
			qM++;
		}
	return qM;
}



