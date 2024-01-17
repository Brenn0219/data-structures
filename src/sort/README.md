**Classificação e Pesquisa**

## Classificação de Dados

A classificação envolve a organização de conjuntos de elementos em uma ordem específica, como ascendente ou descendente. Existem dois tipos principais de algoritmos de classificação:

- **Ordenação por Comparações:**
   - Dependem da comparação entre elementos para estabelecer a ordem.
   - O tempo de execução é, no mínimo, O(n log n).

- **Ordenação Linear:**
   - Operam em tempo proporcional ao número de elementos, ou seja, O(n).
   - Dependem de características específicas nos dados.

## Algoritmos de Classificação Abordados

- **Ordenação por Inserção:**
   - Método simples, eficiente para conjuntos pequenos.
   - Opera in-place, organizando os elementos no próprio local de armazenamento.

- **Quicksort:**
   - Algoritmo in-place, amplamente reconhecido como eficaz para conjuntos médios a grandes.

- **Merge Sort:**
   - Desempenho semelhante ao Quicksort, mas com o dobro dos requisitos de armazenamento.

- **Counting Sort:**
   - Algoritmo estável e linear, adequado para inteiros com um valor máximo conhecido.
   - Usado na implementação de Radix Sort.

- **Radix Sort:**
   - Algoritmo linear que ordena elementos dígito por dígito.
   - Indicado para elementos de tamanho fixo expressíveis como inteiros.

## Pesquisa de Dados

A pesquisa refere-se à tarefa de localizar um elemento em um conjunto de dados. Duas abordagens principais são destacadas:

- **Pesquisa Linear:**
   - Varre o conjunto de dados de um lado ao outro.
   - Usada em estruturas que não suportam bem o acesso aleatório.

- **Pesquisa Binária:**
   - Eficiente para dados ordenados.
   - Divide repetidamente um conjunto de dados, examinando o elemento no meio de cada divisão.