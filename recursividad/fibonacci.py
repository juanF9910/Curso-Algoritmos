def fibonacci(n):
    if n==0 or n==1: ##caso base
        return 1
    return fibonacci(n-1)+fibonacci(n-2) ##llamada recursiva

#la complejidad de este algoritmo es O(2^n), potencialmente muy costoso

