#include "../Lista-1-EDA - AB/TAB.c"

TAB *TAB_copy(TAB *ab){
    TAB *aux = TAB_inicializa();
    if(ab){
        TAB_copy(ab->esq);
        TAB_copy(ab->dir);
        aux = TAB_cria(ab->info, ab->esq, ab->dir);
    }
    return aux;
}
TAB *TAB_espelha(TAB *ab){
    TAB *aux = TAB_inicializa();
    if(ab){
        TAB_copy(ab->esq);
        TAB_copy(ab->dir);
        aux = TAB_cria(ab->info, ab->dir, ab->esq);
    }
    return aux;
}
TAB *TAB_retira_par(TAB *ab){
    if(!ab)return ab;
    TAB_retira_par(ab->dir);
    TAB_retira_par(ab->esq);
    
    if(ab->info%2 == 0 ){
        if(!ab->esq && !ab->dir){

        }
    }
         
}

int main(int argc, char const *argv[])
{
    TAB *ab = TAB_inicializa();
    ab = TAB_cria(1, TAB_cria(2, NULL, NULL), NULL);

    TAB_imp_ident(ab);
    TAB_imp_ident(TAB_copy(ab));
    TAB_imp_ident(TAB_espelha(ab));
    return 0;
}
