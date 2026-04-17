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
        
        enum cor {vermelho,preto};
        typedef struct celula {
            int dado;
            struct celula *esq, *dir;
            enum cor;
        } celula;

        celula *cria_abb(int x) {
            celula *raiz = malloc(sizeof(celula));
            raiz->dado = x;
            raiz->esq = raiz->dir = NULL;
            raiz->cor = vermelho;
            return raiz;
        }    
    - Condições de correção
    - Operações de correção

- 
    