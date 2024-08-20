##vamos a programar el algoritmo quicksort
#O(n log n)
import random
def quicksort(arreglo):
    if len(arreglo) <= 1:
        return arreglo
    pivote = arreglo[len(arreglo) // 2] #pivote es el elemento del medio
    
    izquierda = [x for x in arreglo if x < pivote] #elementos menores al pivote
    medio = [x for x in arreglo if x == pivote] #elementos iguales al pivote
    derecha = [x for x in arreglo if x > pivote] #elementos mayores al pivote
    return quicksort(izquierda) + medio + quicksort(derecha)

n=20
arreglo = [random.randint(0, 100) for i in range(n)]
print(quicksort(arreglo))  
