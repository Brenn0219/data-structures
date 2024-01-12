# Grafo

Grafos são compostos por dois tipos de elementos: vértices e arestas. Vértices representam objetos, e arestas estabelecem relações ou conexões entre esses objetos. 

Os grafos podem ser direcionados ou não direcionados. Em um grafo direcionado, as arestas vão de um vértice para outro em uma direção específica, representadas visualmente por círculos para os vértices e setas para as arestas. Às vezes, as arestas de um grafo direcionado são chamadas de arcos. Em um grafo não direcionado, as arestas não têm direção; portanto, são representadas por linhas em vez de setas.

Formalmente, um grafo é um par G = (V, E), onde V é um conjunto de vértices e E é uma relação binária em V. Em um grafo direcionado, se uma aresta vai do vértice u para o vértice v, E contém o par ordenado (u, v). Em um grafo não direcionado, como uma aresta (u, v) é o mesmo que (v, u), apenas uma dessas arestas é listada em E.

## Conceitos em Grafos

### Adjacência e Incidência
- **Adjacência:** Relação entre dois vértices. Se um grafo contém a aresta (u, v), o vértice v é adjacente ao vértice u. Em um grafo não direcionado, isso implica que o vértice u também é adjacente ao vértice v.
- **Incidência:** Relação entre um vértice e uma aresta. Em um grafo direcionado, a aresta (u, v) é incidente no vértice u e incidência no vértice v. Em um grafo não direcionado, a incidência de uma aresta (u, v) é nos vértices u e v.

### Caminhos e Ciclos
- **Caminho:** Sequência de vértices percorridos seguindo as arestas entre eles. Um caminho de u a v é uma sequência de vértices onde u é o primeiro e v é o último.
- **Ciclo:** Um caminho que inclui o mesmo vértice duas ou mais vezes. Em um grafo direcionado, um ciclo é formado se uma aresta deixa um vértice e outra entra nele.

### Conectividade e Componentes Fortemente Conectadas
- **Conectividade:** Um grafo não direcionado é conectado se todo vértice é alcançável a partir de qualquer outro através de algum caminho. Em um grafo direcionado, se isso é verdade, é chamado de fortemente conectado.
- **Componentes Fortemente Conectadas:** Seções de um grafo direcionado que são fortemente conectadas, mesmo que o grafo como um todo não seja fortemente conectado.

### Pontos de Articulação e Pontes
- **Pontos de Articulação:** Vértices cuja remoção desconecta o grafo ou componente. Podem ser identificados em grafos não direcionados.
- **Pontes:** Arestas cuja remoção desconecta o grafo. Importantes em grafos não direcionados.

## Métodos de Busca

Buscar em um grafo significa visitar seus vértices um de cada vez em uma ordem específica. Existem dois métodos de busca importantes dos quais muitos algoritmos de grafos são derivados: busca em largura e busca em profundidade.

### Busca em Largura
A busca em largura explora um grafo visitando todos os vértices adjacentes a um vértice antes de explorar o grafo mais profundamente. Essa busca é útil em diversas aplicações, incluindo a busca por árvores de abrangência mínima e caminhos mais curtos. Para iniciar, selecionamos um vértice inicial e o marcamos como cinza. Todos os outros vértices são marcados como brancos. O vértice inicial é então colocado sozinho em uma fila. O algoritmo procede da seguinte forma: para cada vértice na fila, observamos o vértice na frente da fila e exploramos cada vértice adjacente a ele. Conforme cada vértice adjacente é explorado, sua cor será branca se ainda não foi descoberto. Nesse caso, o marcamos como cinza, indicando que foi descoberto, e o colocamos no final da fila. Se sua cor não for branca, ele já foi descoberto, e a busca prossegue para o próximo vértice adjacente. Após explorar todos os vértices adjacentes, removemos o vértice no início da fila e o marcamos como preto, indicando que terminamos com ele. Esse processo continua até que a fila esteja vazia, momento em que todos os vértices alcançáveis a partir do vértice inicial estão pretos.

Além de simplesmente visitar vértices, a busca em largura pode ser usada para manter informações úteis. Por exemplo, podemos registrar o número de vértices percorridos antes de chegar a cada vértice, o que acaba sendo o caminho mais curto para cada vértice em grafos cujas arestas não são ponderadas.