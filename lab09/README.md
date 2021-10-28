# Exemplo openMP trapézio

## Detalhes do ambiente:

* gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0

## Compilação e execução:

* O parâmetro passado para a execução é a quantidade de threads.
* As variáveis solicitadas após a execução representam:
  * a é o ponto inicial do eixo x
  * b é o ponto final do eixo x
  * n é a quantidade de trapezoides  

```
gcc Trap.c -g -Wall -fopenmp -lm -o Trap
./Trap 4
```
## Obs

* Solução para o problema undefined reference to exp:
https://www.linuxquestions.org/questions/programming-9/undefined-reference-to-%60exp%27-4175649934/