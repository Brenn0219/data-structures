# Compressão de Dados
A compressão de dados é o processo de reduzir o número de bits usados para representar informações, sendo um resultado importante da teoria da informação. Ela envolve dois estágios: compressão, onde os dados são codificados para ocupar menos espaço, e descompressão, onde são decodificados de volta ao seu estado original.

A compressão é viável devido à representação de dados com mais bits do que o necessário, conforme sugerido pela entropia, uma medida da informação contida nos dados. A eficácia da compressão é avaliada pela taxa de compressão, que é a relação entre o tamanho dos dados comprimidos e o tamanho original.

Existem dois tipos principais de compressão de dados: lossy e lossless. Na compressão lossy, há uma perda de precisão em troca de maior compressão, enquanto na lossless, os dados originais são reproduzidos exatamente durante a descompressão.

A compressão lossless é dividida em codificação com mínima redundância e métodos baseados em dicionário. A primeira reduz a redundância codificando símbolos frequentes com menos bits, enquanto a segunda substitui frases redundantes por tokens.

## Huffman
A codificação de Huffman é um algoritmo de compressão de dados baseado em codificação com mínima redundância. Ela visa representar símbolos mais frequentes com menos bits do que os menos frequentes. Isso é possível devido à entropia dos dados, que mede a quantidade de informação contida. A codificação de Huffman envolve a construção de uma árvore de Huffman, onde cada símbolo é associado a um código binário.

### Entropia e Mínima Redundância
A entropia de um símbolo é calculada usando a fórmula Sz = -lg(Pz), onde Pz é a probabilidade do símbolo ocorrer nos dados. A codificação de Huffman busca aproximar a representação ótima dos dados com base em sua entropia.

### Construção de uma Árvore de Huffman
A árvore de Huffman é construída mesclando-se os símbolos mais frequentes em uma estrutura de árvore binária. Cada símbolo é associado a um código binário único na árvore, permitindo a compressão e descompressão eficientes dos dados.

### Compressão e Descompressão de Dados
Para comprimir dados usando a árvore de Huffman, cada símbolo é substituído por seu código correspondente na árvore. Na descompressão, os códigos binários são percorridos na árvore para reconstruir os dados originais.

### Eficácia da Codificação de Huffman
A eficácia da codificação de Huffman é determinada pela comparação entre o tamanho dos dados comprimidos e o tamanho original. Embora não seja a forma mais eficiente de compressão, a codificação de Huffman é rápida tanto na compressão quanto na descompressão de dados.