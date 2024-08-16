import time
import sys

def factorial(n):
    resp=1
    if n==0:
        return 1
    while(n>1):
        resp*=n
        n-=1
    return resp

def factorial_r(n): ##la recursividad es más rápida que el ciclo
    if n == 0:
        return 1
    return n * factorial_r(n - 1)

if __name__ == "__main__": #se usa para que el código dentro de este if solo se ejecute si se corre este archivo
    ##no si se importa como módulo
    numero_limite = 10**6
    sys.setrecursionlimit(numero_limite) #cambia el límite de recursión
    n = 100000
    start = time.time()
    factorial(n)
    end = time.time()
    print(f"Tiempo de ejecución no recursivo: {end - start} segundos")

    start = time.time()
    factorial_r(n)
    end = time.time()
    print(f"Tiempo de ejecución recursivo: {end - start} segundos")