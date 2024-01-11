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
