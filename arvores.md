
# Estruturas de Dados

## Árvores

### Conceitos Fundamentais
- Definição e propriedades
- Terminologia (raiz, nó, folha, altura, profundidade)
- Tipos de árvores

```
    A
   /|\
  B C D
 / \   |
E   F  G
```

### Árvores Binárias
- Estrutura e características
- Percursos (pré-ordem, in-ordem, pós-ordem)
- Árvores Binárias de Busca (BST)

```
        A
       / \
      B   C
     / \ / \
    D  E F  G
   / \
  H   I
```

**Terminologia:**
- Os nós do nível abaixo de x que estejam ligados a x são seus descendentes ou filhos.
- O nó do nível acima de x que possui ligação com ele é dito o pai de x.
- O nó sem pai é a raiz.
- Nós sem filhos são chamados de folhas.

### Árvores Binárias Duplamente Chaveadas

- Definição: árvore binária onde cada nó interno possui duas chaves e dados associados
- Estrutura: nó com até 2 chaves, dados correspondentes e até 3 filhos
- Propriedade: chaves e dados ordenados da esquerda para a direita

```
    [30:d1|60:d2]
       /      |      \
    [15:d0] [45:d3] [75:d4|90:d5]
```
- Implementação
``` 
typedef struct celula {
    int dado;
    struct celula *esq, *dir;
} celula;
```

### Árvores Balanceadas
- AVL
- Árvores Rubro-Negras
- B-Trees

### Aplicações
- Busca e ordenação
- Heap e filas de prioridade
- Sistemas de arquivos

### QuickSelect
- Implementação

```c
int particiona(int *v, int l, int r) {
    int pivo = v[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (v[j] <= pivo) {
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
        }
    }
    int tmp = v[i];
    v[i] = v[r];
    v[r] = tmp;
    return i;
}

int quickselect(int *v, int l, int r, int k) {
    if (l == r) return v[l];
    int p = particiona(v, l, r);
    if (k == p) return v[k];
    if (k < p) return quickselect(v, l, p - 1, k);
    return quickselect(v, p + 1, r, k);
}
```

## Anotações de Aula

**Data:** 

**Tópico:** 

**Conceitos-chave:**
- 

**Exemplos:**
```
```

**Dúvidas:**
- 

