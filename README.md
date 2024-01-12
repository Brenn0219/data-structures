# Dominando Algoritmos com C

Este repositório contém implementações em C de diversas estruturas de dados e algoritmos, baseadas no livro [Mastering Algorithms with C](https://everythingcomputerscience.com/books/Mastering-Algorithms-with-C-Loudon.pdf). Antes de explorar as implementações específicas, é crucial entender alguns conceitos fundamentais que são amplamente utilizados nas soluções apresentadas.

## Algoritmos e Estruturas de Dados

Algoritmos são procedimentos bem definidos para resolver problemas, essenciais na computação. Assim como uma oficina utiliza a ferramenta certa para uma tarefa, um bom algoritmo é crucial para a eficiência computacional. As estruturas de dados, por sua vez, são fundamentais por três razões:

* **Eficiência**: Organizam dados para tornar algoritmos mais eficientes.
* **Abstração**: Apresentam uma visão mais compreensível dos dados, oferecendo abstração na resolução de problemas.
* **Reutilização**: Modularidade e liberdade de contexto facilitam a reutilização de estruturas de dados.

## Implementação
Cada arquivo de cabeçalho (.h) contém uma explicação da estrutura ou algoritmo correspondente, oferecendo uma visão geral rápida de suas funcionalidades.

Embora não sejam estruturas de dados em si, a manipulação de ponteiros e o uso de recursividade desempenham papéis cruciais na implementação eficiente das estruturas de dados em C. Os algoritmos e estruturas a seguir farão amplo uso desses conceitos.

### Ponteiros

* **Alocação de Memória**: Reservar espaço na memória é essencial para evitar ponteiros inválidos e vazamentos de memória.

* **Agregados e Aritmética de Ponteiros**: Regras para cálculos com ponteiros são fundamentais ao lidar com estruturas e arrays, sendo essenciais para estruturas de dados mais complexas.

* **Ponteiros como Parâmetros de Funções**: A simulação de passagem por referência em C, comum para arrays e estruturas grandes, é crucial para manipular dados eficientemente.

* **Ponteiros para Ponteiros**: Muito usados como parâmetros de funções, proporcionam flexibilidade adicional, especialmente em estruturas de dados complexas.

* **Ponteiros Genéricos e Conversões**: Mecanismos que contornam o sistema de tipos em C, permitindo maior flexibilidade na manipulação de dados temporariamente.

* **Ponteiros de Função**: Permitem apontar para código executável ou informações necessárias, sendo úteis na implementação dinâmica de estruturas de dados.

### Recursividade
* **Recursividade Básica**: Permite definir problemas em termos de instâncias menores de si mesmos, sendo valiosa na implementação de algoritmos e estruturas de dados.

* **Recursividade de Cauda**: Forma otimizada de recursividade reconhecida por compiladores modernos, útil para problemas eficientemente resolvidos sem consumir excesso de espaço na pilha.

## Estruturas

* [Listas encadeadas](src/list/README.md) ([simples](src/list/list.c), [duplas](src/dlist/dlist.c) e [circulares](src/clist/clist.c)).
* [Pilhas](src/stack/stack.c) e [Filas](src/queue/README.md).
* [Conjuntos](src/set/README.md) e a matemática fundamental associada.
* [Tabelas hash encadeadas](src/chtbl/README.md) e de [endereçamento aberto](src/ohtbl/othbl.c).
* [Árvores binárias](src/bitree/README.md) e [AVL](src/avl/README.md), com [métodos de travessia](src/bitree/traverse.c).
* [Heaps](src/heaps/README.md) e [Filas de Prioridade](src/pqueue/README.md).
* [Grafos](src/graph/README.md) e os algoritmos fundamentais de [busca em largura](src/graph/example/bfs.c) e [profundidade](src/graph/example/dfs.c).

## Algoritmos

* Algoritmos de ordenação (inserção, quicksort, merge sort, counting sort, radix sort) e busca binária.
* Métodos numéricos, incluindo interpolação polinomial, estimação de mínimos quadrados e solução de equações por método de Newton.
* Algoritmos de compressão de dados, como codificação Huffman e LZ77.
* Algoritmos de criptografia DES e RSA.
* Algoritmos de grafos, incluindo Prim para árvores de abrangência mínima e Dijkstra para caminhos mais curtos.
* Algoritmos geométricos, abordando interseção de segmentos de linha, cálculo de cascos convexos e comprimento de arcos em superfícies esféricas.

## Licença

* [MIT License](LICENSE)