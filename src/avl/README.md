# Árvore de Busca Binária

Árvores binárias de pesquisa são estruturas organizadas especialmente para facilitar operações de busca. Ao procurar um nó em uma árvore de pesquisa binária, o processo inicia na raiz e desce nível por nível até localizar o nó desejado. Se o nó desejado for menor que o nó atual, a busca continua pela subárvore à esquerda; se for maior, a busca direciona-se para a subárvore à direita. Caso um ramo seja alcançado sem encontrar o nó desejado, concluímos que o nó não está presente na árvore.

A eficiência da busca em uma árvore binária depende da inserção ordenada dos nós. Para inserir um nó, iniciamos na raiz, descendo nível por nível e movendo para a esquerda ou direita conforme necessário. A inserção ocorre ao final de um ramo. É importante destacar que chaves duplicadas não são permitidas nesse processo, mantendo a integridade da estrutura da árvore. Esse método proporciona uma maneira organizada e eficaz de realizar operações de busca e inserção em uma árvore binária de pesquisa

## AVL

Uma árvore AVL (Adel'son-Vel'skii e Landis) é uma variação especial de árvore binária que incorpora informações adicionais em cada nó, conhecidas como fatores de equilíbrio. O fator de equilíbrio de um nó é calculado como a diferença entre a altura da subárvore à esquerda e a altura da subárvore à direita. Durante a inserção de nós, uma árvore AVL é ajustada para garantir que todos os fatores de equilíbrio permaneçam em +1, -1 ou 0. Um nó com fator de equilíbrio +1 é considerado "left-heavy", enquanto um nó com fator de equilíbrio -1 é considerado "right-heavy". Subárvores com fator de equilíbrio 0 são consideradas balanceadas. Ao manter as subárvores quase equilibradas, a árvore AVL mantém um equilíbrio global.

O processo de pesquisa e inserção em uma árvore AVL segue o método convencional. No entanto, durante a inserção, é necessário considerar as mudanças nos fatores de equilíbrio resultantes. Se algum fator de equilíbrio atingir ±2, a árvore é reequilibrada a partir desse ponto usando uma operação chamada rotação. Isso é crucial para garantir a manutenção do equilíbrio geral da árvore AVL, proporcionando um desempenho eficiente e consistente em operações de busca e inserção.

### Rotações em Árvores AVL

Uma rotação reequilibra parte de uma árvore AVL reorganizando os nós enquanto preserva a relação em que a subárvore à esquerda é menor que o pai e o pai é menor que a subárvore à direita, essencial para manter a árvore como uma árvore de busca binária. Após a rotação, os fatores de equilíbrio de todos os nós na subárvore rotacionada são +1, -1 ou 0.

Existem apenas quatro tipos de rotações a serem realizadas: *LL (rotação à esquerda-esquerda)*, *LR (rotação à esquerda-direita)*, *RR (rotação à direita-direita)* e *RL (rotação à direita-esquerda)*.

Para entender quando aplicar cada rotação, considere x como o nó recém-inserido em sua posição adequada em uma árvore AVL e A como o ancestral mais próximo de x cujo fator de equilíbrio mudou para ±2.

* **Rotação LL (Esquerda-Esquerda):** Realizada quando x está na subárvore esquerda da subárvore esquerda de A.
A rotação envolve ajustar os ponteiros para reequilibrar a árvore.

* **Rotação LR (Esquerda-Direita):** Realizada quando x está na subárvore direita da subárvore esquerda de A.
Envolve ajustes nos ponteiros para garantir o equilíbrio da árvore.

* **Rotação RR (Direita-Direita):** Realizada quando x está na subárvore direita da subárvore direita de A.
Simétrica à rotação LL, mantendo o equilíbrio após reorganizar os ponteiros.

* **Rotação RL (Direita-Esquerda):** Realizada quando x está na subárvore esquerda da subárvore direita de A.
Simétrica à rotação LR, garantindo que a árvore permaneça equilibrada após os ajustes.
Essas rotações são essenciais para preservar a estrutura balanceada da árvore AVL durante operações de inserção, garantindo eficiência e consistência em sua busca e inserção.