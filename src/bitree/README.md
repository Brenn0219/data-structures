## Árvores Binárias

Uma árvore binária é uma estrutura hierárquica composta por nós, onde cada nó pode ter até dois nós imediatamente abaixo, chamados de filhos. O nó acima de cada filho é conhecido como pai. Além disso, os nós podem ter irmãos, descendentes e ancestrais. Os irmãos de um nó são os outros filhos do mesmo pai, enquanto os descendentes são todos os nós que se ramificam abaixo dele. Os ancestrais são os nós ao longo do caminho entre o nó e a raiz. O desempenho de uma árvore é frequentemente discutido em termos de altura, que é o número de níveis nos quais os nós residem.

Cada nó em uma árvore binária possui três partes: um membro de dados e dois ponteiros chamados esquerda e direita. Utilizando essa estrutura, formamos a árvore binária, definindo os ponteiros esquerdo e direito de cada nó para apontar para seus filhos. Se um nó não tem um filho à esquerda ou direita, o ponteiro correspondente é definido como NULL, marcando o final de um ramo. Uma ramificação é uma sequência de nós que começa na raiz e termina em um nó folha. Os nós folha são aqueles ao longo da borda da árvore que não possuem filhos. Em situações em que várias árvores são utilizadas simultaneamente, costuma-se dizer que essas árvores formam uma floresta.

### Métodos de travessia
Atravessar uma árvore binária significa visitar seus nós, um de cada vez, em uma ordem específica. Comparado com
algumas estruturas de dados vinculadas, como listas encadeadas, como percorrer os nós de uma árvore binária pode não
ser imediatamente aparente. Na verdade, há muitas maneiras pelas quais podemos proceder. Normalmente, um dos
quatro tipos de travessias são usados: *pré-ordem*, *ordem interna*, *pós-ordem* ou ordem de *nível*.

Atravessar uma árvore é particularmente simples se pensarmos recursivamente na árvore como sendo composta de muitos
subárvores menores. Embora essas travessias sejam apresentadas no
contexto de árvores binárias, cada uma também pode ser generalizada para outros tipos de árvores.

* **Travessia Pré-Ordenada:** Na travessia pré-ordenada de uma árvore binária, exploramos os nós seguindo a ordem raiz, subárvore esquerda e subárvore direita. Essa abordagem oferece uma visão inicial da raiz e, em seguida, explora recursivamente as subárvores, proporcionando insights valiosos sobre a hierarquia da árvore.

* **Travessia Inordenada:** Ao realizar uma travessia inordenada, percorremos a subárvore esquerda primeiro, seguida pela raiz e, finalmente, pela subárvore direita. Essa abordagem resulta em uma ordenação dos elementos da árvore, sendo especialmente útil para árvores de busca binária, onde os elementos são organizados em ordem crescente.

* **Travessia Pós-Ordenada:** Na travessia pós-ordenada, a exploração inicia-se na subárvore esquerda, seguida pela subárvore direita e conclui na raiz. Essa abordagem é valiosa para compreender as relações de descendência e proporciona uma visão inversa da travessia pré-ordenada.

* **Travessia em Nível:** A travessia em nível percorre a árvore nível a nível, visitando os nós da esquerda para a direita em cada nível. Essa abordagem é eficaz para uma exploração abrangente da árvore, revelando a organização estruturada dos elementos em diferentes camadas.

## Balanceamento

Balancear uma árvore é o processo de mantê-la o mais curta possível para um determinado número de nós. Esse
significa garantir que um nível da árvore esteja completamente cheio antes de permitir a existência de um nó no
próximo nível. Formalmente, uma árvore é balanceada se todos os nós folhas estão no mesmo nível ou, se não, todos os nós folhas estão nos dois últimos níveis e o penúltimo nível está cheio. Uma árvore balanceada é balanceada à esquerda se todas as folhas ocupam apenas as posições mais à esquerda no último nível.