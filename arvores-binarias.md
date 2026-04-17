# Árvores Binárias de busca Autobalanceáveis
- Uma ABB pode se tornar desbalanceada, o que pode levar a uma performance ruim. Para evitar isso, utilizamos árvores binárias de busca autobalanceáveis.
- É uma ABB que se reorganiza depois de uma inserção ou remoção para que permaneça balanceada.

- Há vários tipos de ABBs autobalanceáveis:
    - Árvore 2-3
    - AVL
    - Árvores Rubro-Negras
    - entre outras.

## ABB Rubro-negra Esquerdista
- É uma árvore que cumpre os seguintes requisitos:
    1. Todo nó é vermelho ou preto
    2. A raiz é preta
    3. As folhas são NULL, de cor preta
    4. Se um nó é vermelho:
        - Seus filhos são pretos
        - É filho esquerdo de seu pai
    5. Todo caminho da raiz até uma folha descendente tem o mesmo número de nós pretos
        - não se conta o próprio nó
        - essa propriedade chama-se <u>altura negra</u> de um nó.

- Inserção:
    - Quando inserirmos um novo nó, atribuímos a este nó a cor vermelha, de forma a conservar a altura negra da árvore. Em contra partida, podemos infringir  a regra de existência de um nó vermelho (regra 4). Por isso, consideramos todas as possibilidades ao inserir um novo nó:
    1. Caso 1: O filho direito é vermelho e o esquerdo é preto: rotaciona para a esquerda
    2. Caso 2: O filho esquerdo é vermelho e o neto esquerdo é vermelho: rotaciona para a direita
    3. Caso 3: Ambos os filhos são vermelhos: inverte as cores

- Implementação
        
        ```c
        enum cor {vermelho, preto};

        typedef struct celula {
            int dado;
            struct celula *esq, *dir;
            enum cor cor;
        } celula;

        int eh_vermelho(celula *h) {
            if (h == NULL) return 0;
            return h->cor == vermelho;
        }

        celula *rotaciona_esquerda(celula *h) {
            celula *x = h->dir;
            h->dir = x->esq;
            x->esq = h;
            x->cor = h->cor;
            h->cor = vermelho;
            return x;
        }

        celula *rotaciona_direita(celula *h) {
            celula *x = h->esq;
            h->esq = x->dir;
            x->dir = h;
            x->cor = h->cor;
            h->cor = vermelho;
            return x;
        }

        void inverte_cores(celula *h) {
            h->cor = vermelho;
            h->esq->cor = preto;
            h->dir->cor = preto;
        }

        celula *insere(celula *h, int dado) {
            if (h == NULL) {
                celula *novo = malloc(sizeof(celula));
                novo->dado = dado;
                novo->esq = novo->dir = NULL;
                novo->cor = vermelho;
                return novo;
            }

            if (dado < h->dado) h->esq = insere(h->esq, dado);
            else if (dado > h->dado) h->dir = insere(h->dir, dado);

            // Condições de correção
            if (eh_vermelho(h->dir) && !eh_vermelho(h->esq))      h = rotaciona_esquerda(h); // Caso 1
            if (eh_vermelho(h->esq) && eh_vermelho(h->esq->esq)) h = rotaciona_direita(h);   // Caso 2
            if (eh_vermelho(h->esq) && eh_vermelho(h->dir))      inverte_cores(h);          // Caso 3

            return h;
        }
        ```