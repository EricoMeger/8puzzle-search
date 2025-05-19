# 8-Puzzle Search

Este repositório contém uma implementação em C++ dos algoritmos de busca em profundidade (DFS) e busca em largura (BFS) para resolver o problema do 8-puzzle.

## Contexto

O 8-puzzle é um quebra-cabeça composto por um tabuleiro 3x3 contendo 8 peças numeradas e um espaço vazio. O objetivo é mover as peças até atingir uma configuração alvo, geralmente ordenada de 1 a 8, com o espaço vazio no final. 

Este projeto tem como foco explorar os algoritmos BFS (Breadth-First Search) e DFS (Depth-First Search) na resolução do 8-puzzle.

## Implementação

O código foi desenvolvido em C++ e está organizado em módulos:

- `Board`: Representa o estado do tabuleiro, implementando funções para verificar se o estado é solucionável, gerar estados de transição e validar o estado objetivo.
- `BFS`: Implementa a busca em largura utilizando uma fila (`queue`) para explorar os estados nível a nível, garantindo o menor caminho para a solução.
- `DFS`: Implementa a busca em profundidade utilizando uma pilha (`stack`), explorando caminhos até o fundo antes de retroceder e tentar outras possibilidades.

### Como funciona

- O estado inicial é definido no código principal (`main.cpp`).
- Antes de iniciar a busca, é feita uma checagem para saber se o tabuleiro inicial é solucionável, usando a contagem de inversões.
- Ambos algoritmos armazenam os estados visitados em um `set` para evitar repetições e usam um `map` para reconstruir o caminho da solução.
- Ao encontrar a solução, o programa exibe o caminho tomado, o número de estados visitados e o tempo de execução.

### Execução

Para compilar e executar o projeto:

Acesse o diretório com o makefile:

```bash
cd main
```

Execute o makefile:

```bash
make
```

Execute o código compilado:

```bash
./puzzle
```

Você pode alterar o estado inicial no arquivo `main.cpp`.

## Referências

### Algoritmos de Busca em Grafos

- [Exploring Graph Search Algorithms Using the 8-Puzzle Game](https://medium.com/@ygordefraga/exploring-graph-search-algorithms-using-the-8-puzzle-game-e8fafb976e4d)
- [GeeksforGeeks - Breadth First Search (BFS) for a Graph](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
- [Baeldung - Introduction to Depth First Search](https://www.baeldung.com/cs/depth-first-search-intro)
- [StackOverflow - Tracing and returning a path in depth first search](https://stackoverflow.com/questions/12864004/tracing-and-returning-a-path-in-depth-first-search)

### Referências sobre o 8-Puzzle

- [Math StackExchange - How to check if a 8-puzzle is solvable](https://math.stackexchange.com/questions/293527/how-to-check-if-a-8-puzzle-is-solvable)
- [GeeksforGeeks - Check if instance of 8 puzzle is solvable](https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/)

### Referências de C++

- [Cplusplus.com - vector](https://cplusplus.com/reference/vector/vector/)
- [Cplusplus.com - set](https://cplusplus.com/reference/set/set/)
- [Cplusplus.com - queue](https://cplusplus.com/reference/queue/queue/)
- [Cplusplus.com - stack](https://cplusplus.com/reference/stack/stack/)
- [en.cppreference.com - Relational operators](https://en.cppreference.com/w/cpp/language/operators#Relational_operators)

### Dúvidas e Exemplos Práticos

- [DigitalOcean - foreach loop in C++](https://www.digitalocean.com/community/tutorials/foreach-loop-c-plus-plus)
- [Cplusplus.com Forum - set operator< overload](https://cplusplus.com/forum/beginner/236407/)
- [StackOverflow - Why are ifndef and define used in C header files?](https://stackoverflow.com/questions/1653958)

---

Autor: [Érico Meger](https://github.com/EricoMeger)