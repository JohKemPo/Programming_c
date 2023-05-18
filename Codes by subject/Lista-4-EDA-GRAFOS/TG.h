#include <stdlib.h>
#include <stdio.h>

typedef struct viz {
	int id_viz;
	struct viz *prox_viz;
}TVIZ;

typedef struct grafo{
	int id_no, cor;
	TVIZ *prim_viz;
	struct grafo *prox_no;
}TG;


TG* TG_inicializa();
void TG_imprime(TG *g);
void TG_libera(TG *g);
TG* TG_busca_no(TG* g, int x);
TVIZ* TG_busca_aresta(TG *g, int no1, int no2);
TG* TG_ins_no(TG *g, int x);
void TG_ins_aresta(TG *g, int no1, int no2);
void TG_retira_aresta(TG *g ,int no1, int no2);
TG* TG_retira_no(TG *g, int no);
int nn(TG *g);
int na(TG *g);
int ig(TG *g1, TG *g2);
int testek(TG *g, int k);
int nao_tem_mesma_cor(TG *g);
TG* TG_ins_no_cor(TG *g, int x, int cor);
void TG_imprime_cor(TG *g);
int cor_aux(TG *g, TG* aux, int cor);