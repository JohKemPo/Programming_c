#include "TG.c"



int main(void){
  TG *g = TG_inicializa(), *h = TG_inicializa();

  int n;
  do{
    printf("Digite o no: ");
    scanf(" %d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
    h = TG_ins_no(g, n);
  }while(1);

  TG_imprime(g);
  
  int m;
  do{
    printf("insercao das arestas x y: ");
    scanf("%d%d", &n, &m);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m);
    TG_ins_aresta(h, n, m);
  }while(1);
  
  TG_imprime(g);
  TG_imprime(h);
  
  // char op;
  // printf("Digite n ou a para retirar nos ou arestas...\n");
  // do{
  //   prtinf("OP: ");
  //   scanf("%c", &op);
  //   if(op == 'n'){
  //     scanf("%d", &n);
  //     g = TG_retira_no(g, n);
  //     TG_imprime(g);
  //   }
  //   else if(op == 'a'){
  //     scanf("%d%d", &n, &m);
  //     TG_retira_aresta(g, n, m);
  //     TG_imprime(g);
  //   }
  //   else break;
  // }while(1);
  printf("\nQuantidade de nos: %d", nn(g));
  printf("\nQuantidade de aresta: %d", nn(g));
  printf("\nSao iguais: %d", ig(g,h));
  TG_libera(g);
  return 0;
}

