/*
	Componentes do Trabalho:
		Carlos Mosselman Cabral Neto
		Fábio da Silva Castro
		Luiz Felipe Brazil Pinto
		Vanessa Machado Araújo

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Dados {
	long long int cpfc, cpft, valor;
	char op;
} dados;

typedef struct No {
	dados conteudo;
	struct No *prox;
} no;

typedef struct Pilha {
	int tamanho;
	no* topo;
} pilha;

pilha* criarpilha() {
	pilha *p=(pilha*)malloc(sizeof(pilha));
	p->topo=NULL;
	p->tamanho=0;
	return p;
}

no* criarno(dados pessoa){
	no *emp=(no*)malloc(sizeof(no));
	emp->conteudo=pessoa;
	return emp;
	}

void empilhar(pilha *p, no *cell){
	cell->prox=p->topo;
	p->topo=cell;
	p->tamanho++;
}

dados desempilhar(pilha *p){
	if(p->topo==NULL){
		printf("Pilha vazia\n");
	}
	no *aux=p->topo;
	dados salvar=p->topo->conteudo;
	p->topo=p->topo->prox;
	aux->prox=NULL;
	free(aux);
	p->tamanho--;
	return(salvar);
}

void destruir(pilha *p){
	while(p->topo!=NULL){
		no *aux1=p->topo;
		p->topo=p->topo->prox;
		aux1->prox=NULL;
		free(aux1);
		p->tamanho--;
		}
	free(p);
	}


int main () {

	long long int i, clientes;
	dados pessoa;

	pilha *g1, *g2, *g3;
	no *aux;
	g1=criarpilha();
	g2=criarpilha();
	g3=criarpilha();

	scanf("%lld",&clientes);

	for(i=0;i<clientes;i++){
		scanf("%lld",&pessoa.cpfc);
		scanf("%lld",&pessoa.cpft);
		scanf(" %c",&pessoa.op);
		scanf("%lld",&pessoa.valor);
		if(i%3==0){
			aux=criarno(pessoa);
			empilhar(g1, aux);
			}
		if(i%3==1){
			aux=criarno(pessoa);
			empilhar(g2, aux);
			}
		if(i%3==2){
			aux=criarno(pessoa);
			empilhar(g3, aux);
			}
	}

	printf("-:| RELATÓRIO PARCIAL |:-\n");

	printf ("3\n");
	printf("Guiche 1: %d\n", g1->tamanho);

	while (g1->tamanho) {
		printf("[%lld, %lld, %c, %lld]\n", g1->topo->conteudo.cpfc,g1->topo->conteudo.cpft, g1->topo->conteudo.op, g1->topo->conteudo.valor);
		desempilhar (g1);
	}

	printf("Guiche 2: %d\n", g2->tamanho);

	while (g2->tamanho) {
		printf("[%lld, %lld, %c, %lld]\n", g2->topo->conteudo.cpfc,g2->topo->conteudo.cpft, g2->topo->conteudo.op, g2->topo->conteudo.valor);
		desempilhar (g2);
	}

	printf("Guiche 3: %d\n", g3->tamanho);

	while (g3->tamanho) {
		printf("[%lld, %lld, %c, %lld]\n", g3->topo->conteudo.cpfc,g3->topo->conteudo.cpft, g3->topo->conteudo.op, g3->topo->conteudo.valor); 
		desempilhar (g3);
	}
	destruir(g1);
	destruir(g2);
	destruir(g3);
}


