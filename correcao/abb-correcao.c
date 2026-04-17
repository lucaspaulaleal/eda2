#include <stdio.h>


// TAD Tipo abstrato de Dado
enum cor{VERMELHO, PRETO};

typedef struct celula {
    int dado;
    enum cor cor;
    struct celula *esq, *dir;
} celula;


// Funções auxiliares
int ehVerm(celula *no)
{
    if (no != NULL)
        return no->cor == VERMELHO;
    else
        return 0;
}

int ehPreto(celula *no)
{
    if (no != NULL)
        return no->cor == PRETO;
    else
        return 1;
}


// Operações de correção
// 1. Subida de cor
void sobe_cor(celula *r) {
    r->cor=VERMELHO;
    r->esq->cor=r->dir->cor=PRETO;
}

// 2. Rotação à esquerda
celula *rotacao_a_esquerda(celula *r) {
    celula *a = r->dir;
    a->cor = r->cor;
    r->cor = VERMELHO;
    celula *beta = a->esq;
    a->esq = r;
    r->dir = beta;
    return a;
}

// 3. Rotação à direita
celula *rotacao_a_direita(celula *r) {
    celula *a = r->esq;
    a->cor = r->cor;
    r->cor = VERMELHO;
    celula *beta = r->esq;
    a->dir = r;
    r->esq = beta;
    return a;
}




int main() {


    return 0;
}