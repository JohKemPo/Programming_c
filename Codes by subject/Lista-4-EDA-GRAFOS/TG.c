#include "TG.h"

TG* TG_inicializa(){
  return NULL;
}


void TG_imprime(TG *g){
  while(g){
    printf("Vizinhos do No %d:\n", g->id_no);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d ", v->id_viz);
      v = v->prox_viz;
    }
    printf("\n");
    g = g->prox_no;
  }
}

void TG_imprime_cor(TG *g){
  while(g){
    printf("Vizinhos do No %d com cor %d:\n", g->id_no, g->cor);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d ", v->id_viz);
      v = v->prox_viz;
    }
    printf("\n");
    g = g->prox_no;
  }
}

void TG_imp_rec(TG *g){
  if(g){
    printf("%d:\n", g->id_no);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d ", v->id_viz);
      v = v->prox_viz;
    }
    TG_imp_rec(g->prox_no);
  }
}

void TG_libera_viz(TVIZ *v){
  while(v){
    TVIZ *temp = v;
    v = v->prox_viz;
    free(temp);
  }
}

void TG_libera_viz_rec(TVIZ *v){
  if(!v) return;
  TG_libera_viz_rec(v->prox_viz);
  free(v);
}

void TG_libera(TG *g){
  while(g){
    TG_libera_viz(g->prim_viz);
    TG *temp = g;
    g = g->prox_no;
    free(temp);
  }
}

void TG_libera_rec(TG *g){
  if(g){
    TG_libera_viz(g->prim_viz);
    TG_libera_rec(g ->prox_no);
    free(g);
  }
}

TG* TG_busca_no(TG* g, int x){
  if((!g) || (g->id_no == x)) return g;
  return(TG_busca_no(g->prox_no, x));
}

TVIZ* TG_busca_aresta(TG *g, int no1, int no2){
  TG *p1 = TG_busca_no(g,no1), *p2 = TG_busca_no(g,no2);
  if((!p1) || (!p2)) return NULL;
  TVIZ *resp = p1->prim_viz;
  while((resp) && (resp->id_viz != no2)) resp = resp->prox_viz;
  return resp;
}

TG* TG_ins_no(TG *g, int x){
  TG *p = TG_busca_no(g, x);
  if(!p){
    p = (TG*) malloc(sizeof(TG));
    p->id_no = x;
    p->prox_no = g;
    p->prim_viz = NULL;
    g = p;
  }
  return g;
}

TG* TG_ins_no_cor(TG *g, int x, int cor){
  TG *p = TG_busca_no(g, x);
  if(!p){
    p = (TG*) malloc(sizeof(TG));
    p->id_no = x;
    p->prox_no = g;
    p->prim_viz = NULL;
    p->cor = cor;
    g = p;
  }
  return g;
}

void TG_ins_um_sentido(TG *g, int no1, int no2){
  TG *p = TG_busca_no(g, no1);
  TVIZ *nova = (TVIZ *) malloc(sizeof(TVIZ));
  nova->id_viz = no2;
  nova->prox_viz = p->prim_viz;
  p->prim_viz = nova;
}

void TG_ins_aresta(TG *g, int no1, int no2){
  TVIZ *v = TG_busca_aresta(g, no1, no2);
  if(v) return;
  TG_ins_um_sentido(g, no1, no2);
  TG_ins_um_sentido(g, no2, no1);
}

void TG_retira_um_sentido(TG *g, int no1, int no2){
  TG *p = TG_busca_no(g, no1);
  if(!p) return;
  TVIZ *ant = NULL, *atual = p->prim_viz;
  while((atual)&&(atual->id_viz != no2)){
    ant = atual;
    atual = atual->prox_viz;
  }
  if(!ant) p->prim_viz = atual->prox_viz;
  else ant->prox_viz = atual->prox_viz;
  free(atual);
}

void TG_retira_aresta(TG *g ,int no1, int no2){
  TVIZ* v = TG_busca_aresta(g,no1,no2);
  if(!v) return;
  TG_retira_um_sentido(g,no1,no2);
  TG_retira_um_sentido(g,no2,no1);
}

TG* TG_retira_no(TG *g, int no){
  TG *p = g, *ant = NULL;
  while((p)&& (p->id_no != no)){
    ant = p;
    p = p->prox_no;
  }
  if(!p) return g;
  while(p->prim_viz) TG_retira_aresta(g, no, p->prim_viz->id_viz);
  if(!ant) g = g->prox_no;
  else ant->prox_no = p->prox_no;
  free(p);
  return g;
}

int nn(TG *g){
  if((!g)) return 0;
  return 1 + nn(g->prox_no);
}

int na(TG *g){
  int count = 0;
  if(g){
    TVIZ *v = g->prim_viz;
    while(v){
      v = v->prox_viz;
      count++;
    }
    return count + na(g->prox_no);
  }  
}

int ig(TG *g1, TG *g2){
  if(!g1 && !g2) return 1;
  if(!g1 || !g2) return 0;

  TG *aux_1 = g1, *aux_2 = g2;

  if(aux_1->id_no == aux_2->id_no){
    TVIZ *v1 = aux_1->prim_viz, *v2 = aux_2->prim_viz;
    while(v1 || v2){
      if(v1->id_viz != v2->id_viz)return 0;
      v1 = v1->prox_viz;
      v2 = v2->prox_viz;
    }
  }else return 0;
  
  return ig(aux_1->prox_no, aux_2->prox_no); 
}

int testek(TG *g, int k){

}

int cor_aux(TG *g, TG* aux, int cor){
  if(aux){
    TG *no_atual;
    TVIZ *v = aux->prim_viz;
    while(v){ 
      no_atual = TG_busca_no(g, v->id_viz);
      if(aux->cor == no_atual->cor)return 0;
      v = v->prox_viz;
    }
    return cor_aux(g, aux->prox_no, aux->cor);
  }
  return 1;
}


int nao_tem_mesma_cor(TG *g){
  if(!g) return 0;
  return cor_aux(g, g, g->cor);
}