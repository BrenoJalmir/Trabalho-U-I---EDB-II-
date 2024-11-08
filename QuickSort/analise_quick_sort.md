# Quicksort Iterativo
```
Função PARTICIONAR(vetor, inicio, fim)
    pivo <- vetor[fim]
    i <- inicio - 1

    PARA j de inicio ATÉ fim - 1 FAÇA
        SE vetor[j] <= pivo ENTÃO
            i <- i + 1
            Trocar vetor[i] com vetor[j]
        FIM SE
    FIM PARA

    Trocar vetor[i + 1] com vetor[fim]
    RETORNAR i + 1

Fim PARTICIONAR

Função QUICKSORT_ITERATIVO(vetor, inicio, fim)
    Criar pilha auxiliar com tamanho [fim - inicio + 1]
    topo <- -1

    Empilhar inicio e fim na pilha
    topo <- topo + 1
    pilha[topo] <- inicio
    topo <- topo + 1
    pilha[topo] <- fim

    ENQUANTO topo >= 0 FAÇA
        fim <- pilha[topo]
        topo <- topo - 1
        inicio <- pilha[topo]
        topo <- topo - 1

        pivo <- PARTICIONAR(vetor, inicio, fim)

        SE pivo - 1 > inicio ENTÃO
            topo <- topo + 1
            pilha[topo] <- inicio
            topo <- topo + 1
            pilha[topo] <- pivo - 1
        FIM SE

        SE pivo + 1 < fim ENTÃO
            topo <- topo + 1
            pilha[topo] <- pivo + 1
            topo <- topo + 1
            pilha[topo] <- fim
        FIM SE
    FIM ENQUANTO

Fim QUICKSORT_ITERATIVO
```

## Melhor caso (Ω)
O melhor caso ocorre quando o pivô selecionado divide o vetor de forma balanceada, ou seja, ao meio, consecutivamente. Nesse caso, o tamanho dos subvetores reduz pela metade em cada passo da iteração.

Número de divisões: Em cada nível da divisão, temos $2^k$ subproblemas, onde cada subproblema tem aproximadamente $\frac{n}{2^k}$ elementos. O que nos resulta no número de divisões sendo $log(n)$.

Complexidade de cada divisão: Para cada divisão, o particionamento ocorre em tempo $n$, pois cada elemento do vetor precisa ser comparado com o pivô uma vez para ser movido.

Assim, o tempo total é $n*log(n)$.

Complexidade no melhor caso: $Ω(nlog(n))$.

## Pior caso (Big O)
O pior caso ocorre quando o pivô escolhido é o menor ou o maior elemento do vetor, o que resulta em uma divisão extremamente desigual (por exemplo, uma partição com um elemento e outra com $n−1$ elementos). Nessa situação, o algoritmo se comporta como se estivesse ordenando um vetor sequencialmente, resultando em um número de operações bem maior.

Número de divisões: Em cada divisão, um elemento é separado como pivô, restando $n−1$ elementos para a próxima divisão, e assim por diante, até chegar ao último elemento. Nesse caso, o número de divisões será $n$, pois cada divisão diminui o tamanho do vetor em apenas 1.

Complexidade de cada divisão: Cada divisão ainda tem custo $n$ devido à passagem pelo particionamento.

O tempo total é, portanto, $n*n$.

Complexidade no pior caso: $O(n^2)$.

## Caso médio (θ)
Não ocorre, visto que o melhor e o pior caso não coincidem.

# Quicksort Recursivo
```
Função PARTICIONAR(vetor, inicio, fim)
    pivo <- vetor[fim]
    i <- inicio - 1

    PARA j de inicio ATÉ fim - 1 FAÇA
        SE vetor[j] <= pivo ENTÃO
            i <- i + 1
            Trocar vetor[i] com vetor[j]
        FIM SE
    FIM PARA

    Trocar vetor[i + 1] com vetor[fim]
    RETORNAR i + 1

Fim PARTICIONAR

Função QUICKSORT_RECURSIVO(vetor, inicio, fim)
    SE inicio < fim ENTÃO
        pivo <- PARTICIONAR(vetor, inicio, fim)

        QUICKSORT_RECURSIVO(vetor, inicio, pivo - 1)

        QUICKSORT_RECURSIVO(vetor, pivo + 1, fim)
    FIM SE

Fim QUICKSORT_RECURSIVO
```

## Recorrências

Pela análise feita sobre o algoritmo, é possível perceber certa semelhança com a sua versão iterativa, da qual, utilizando suas explicações, derivamos essas fórmulas:

Melhor caso: $T(n)=T(n−1)+n$

Pior caso: $T(n)=2T(\frac{n}{2})+n$

## Métodos de resolução

Agora para achar as notações de complexidade:

### Árvore de recursão

Ao analisar as chamadas do quicksort, um padrão de árvore binária em ordem simétrica se torna reconhecível:
```
               O
             /   \
            O     O
          /  \   /  \
         O    O  O   O
```
Nele, temos que cada nó é o pivô de sua chamada, posto ao centro, com valores menores à esquerda e maiores à direita. Seus filhos, por sua vez, são os pivôs das próximas chamadas nos subvetores.

Portanto, cada chamada divide o tamanho do problema em dois $(n, \frac{n}{2}, \frac{n}{4}, \frac{n}{8}...\frac{n}{2^i})$

O que significa que o número de nós por nível duplica $(1, 2, 4, 8 ... 2^i)$

E como a recursão só termina quando o tamanho de cada subvetor for 1 (elemento):

$\frac{n}{2^i}=1$

$n=2^i$

$\log_{2}n=\log_{2}2^i$

$\log_{2}n=i$

$\sum_{i=0}^{\log_{2}n} (\frac{n}{2^i}\times 2^i) = \sum_{i=0}^{\log_{2}n} (n) = n\log_{2}n $

### Teorema mestre

> Regras do método mestre
> $$T(n) = aT\left( \frac{n}{b} \right) + \Theta(n^k)$$
> 1. Se $a>b^k$, então T(n) é $\Theta(n^{\log_{b}a})$
> 2. Se $a=b^k$, então T(n) é  $\Theta(n^k\log n)$
> 3. Se $a<b^k$, então T(n) é $\Theta(n^k)$

Como o pior caso não tem forma aplicável para o teorema mestre temos, portanto, que para o melhor caso:

$$
T(n) = 2T\left( \frac{n}{2} \right) + n 
\\
\\
\begin{cases}
  a=2 \\
  b=2 \\
  k=1
\end{cases}
$$

$2=2^1$, logo T(n) é $\Theta(n\log n)$.
