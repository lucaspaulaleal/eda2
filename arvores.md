
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
    struch celula *esq, *dir;
}
```

### Árvores Balanceadas
- AVL
- Árvores Rubro-Negras
- B-Trees

### Aplicações
- Busca e ordenação
- Heap e filas de prioridade
- Sistemas de arquivos

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

