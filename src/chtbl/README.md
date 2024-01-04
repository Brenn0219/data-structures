# Tabela Hashing

As tavelas hashing dão apoio a um dos mais eficientes tipos de pesquisa, o *hashing*. Fudamentalmente, uma tabela hashing consite em um arry, no qual dados são acessados através de um índice especial denominado *chave*. A idéia principal das tabelas hashing é estabelecer um mapeamento entre o conjunto de todas as chaves possíveis e posições no array, usando funções hashing. Uma função hashing aceita uma chave e retorna o seu código hashing ou valor hashing. As chaves variam quanto ao tipo, porém códigos hashing são sempre inteiros. 

Como tanto o cálculo de um valor hash quanto a indexação em um array podem ser realizados em tempo constante, o
A beleza do hash é que podemos usá-lo para realizar pesquisas em tempo constante. Quando uma função hash pode
garantir que duas chaves não gerem a mesma codificação hash, a tabela hash resultante é considerada
diretamente abordado. Isto é ideal, mas o endereçamento direto raramente é possível na prática.

Normalmente, o número de entradas em uma tabela hash é pequeno em relação ao universo de chaves possíveis.
Conseqüentemente, a maioria das funções hash mapeia algumas chaves para a mesma posição na tabela. Quando duas chaves
mapear para a mesma posição, eles colidem. Uma boa função hash minimiza colisões, mas ainda devemos
esteja preparado para lidar com eles.

## Tabela Hashing Encadeada

Uma tabela hash encadeada consiste fundamentalmente em um array de listas encadeada. Cada lista forma um partição no qual
são colocados todos os elementos com hash relacionados a uma posição específica no array. Para inserir um elemento, primeiro passamos sua chave para uma função hash em um processo chamado hash da chave. Isso nos diz em qual partição o
elemento pertence. Em seguida, inserimos o elemento no início da lista apropriada. Para procurar ou remover um
elemento, fazemos hash de sua chave novamente para encontrar seu partição e, em seguida, percorremos a lista apropriada até encontrarmos o elemento que procuramos. Como cada bucket é uma lista encadeada, uma tabela hash encadeada não está limitada a um número fixo de elementos. No entanto, o desempenho será prejudicado se a tabela ficar muito cheia.

### Tabela Hashing de Endereçamento Aberto

Nas tabelas de endereçamento aberto, todos os elementos residem na própria tabela, o que é importante para aplicações que requerem um tamanho fixo. No entanto, para lidar com colisões, essas tabelas utilizam sondagem, onde posições são probedas até encontrar uma vaga para inserção. O número de sondagens depende do fator de carga da tabela e da uniformidade na distribuição dos elementos. A eficácia do processo também está vinculada à escolha de uma função de hash adequada, sendo que para a sondagem linear, uma função h(k,i) = (h'(k)+i) mod m é frequentemente utilizada, mas pode resultar em clustering primário.