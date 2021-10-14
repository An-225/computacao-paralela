# Exemplo Pthreads

## Detalhes do ambiente:

* gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0

## Compilação e execução:

* Os parâmetros passados para a execução em ordem são:
    * Quantidade de threads
    * N máximo

```
gcc pi.c -pthread -o pi
./pi 2 100000000
```
