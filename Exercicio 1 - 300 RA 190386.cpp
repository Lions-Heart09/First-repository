#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
	char cpf[13]; // CPF	do	aluno
	char nome[80]; // nome	do	aluno
	int numaula; // n?mero	do registro	do	tipo	da	aula
}aluno;

typedef struct luta{
	int regaula; //registro do	tipo	de aula
	int qaluno; //registra	a	quantidade	de	alunos	matriculados
	char modalidade[20]; //exemplo: jiu-jitsu, muay	thai,	boxe
	int grau; // [1]iniciante, [2]intermedi?rio, [3]avan?ado
	float valor; //valor da	aula
}luta;

void aloca_luta(luta **p, int qtde);
void cadastra_luta(luta *p, int qtde);
void aloca_aluno(aluno **p, int qtde);
void cadastra_aluno(aluno *p, luta *pL);

main() {
	int op, cont=0;
	luta *pl=NULL;
	aluno *pa=NULL;
	aloca_luta(&pl,3);
	cadastra_luta(pl,3);
	do {
		printf("[1]Matricula\n[2]Encerra matricula\n[3]Sair\nSua opcao ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				aloca_aluno(&pa, cont+1);
				cadastra_aluno(pa+cont, pl);
				
		}
	}while(op!=3);
}

void aloca_luta(luta **p, int qtde) {
	if((*p=(luta *)realloc(*p,qtde*sizeof(luta)))==NULL) {
		printf("Alocacao mal sucedida");
		exit(1);
	}
}

void cadastra_luta(luta *p, int qtde) {
	int i;
	char m1[]="BOX";
	char m2[]="JIU-JITSU";
	char m3[]="KARATE";
	
	for(i=0;i<qtde;i++,p++) {
		if(i==0) {
			strcpy(p->modalidade,m1);
			p->grau = 1;
			p->qaluno = 0;
			p->regaula = 1;
			p->valor = 100.00;
		}
		if(i==1) {
			strcpy(p->modalidade,m2);
			p->grau = 2;
			p->qaluno = 0;
			p->regaula = 2;
			p->valor = 120.00;
		}
		if(i==2) {
			strcpy(p->modalidade,m3);
			p->grau = 3;
			p->qaluno = 0;
			p->regaula = 3;
			p->valor = 110.00;
		}
	}
}

void aloca_aluno(aluno **p, int qtde) {
	if((*p = (aluno *)realloc(*p,qtde*sizeof(aluno)))==NULL) {
		printf("Alocacao mal sucedida");
		exit(1);
	}
}

void cadastra_aluno(aluno *p, luta *pl) {
	char luta[10];
	int i;
	printf("\nDigite seu nome: ");
	gets(p->nome);
	printf("\nDigite seu cpf: ");
	gets(p->cpf);
	printf("\nQual luta deseja: ");
	printf("\nQual modalidade?\nBOX(grau 1)\nJIU-JITSU(grau 2)\nKARATE(grau 3)\nResposta: ");
	gets(luta);
	

}
