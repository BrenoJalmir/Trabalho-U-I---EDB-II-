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

```
