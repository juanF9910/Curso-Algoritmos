##vamos a programar el algoritmo quicksort

def quicksort(arreglo):
    if len(arreglo) <= 1:
        return arreglo
    pivote = arreglo[len(arreglo) // 2] #pivote es el elemento del medio
    izquierda = [x for x in arreglo if x < pivote]
    medio = [x for x in arreglo if x == pivote]
    derecha = [x for x in arreglo if x > pivote]
    return quicksort(izquierda) + medio + quicksort(derecha)

arreglo = [5, 3, 4, 1, 2]
print(quicksort(arreglo))  # [1, 2, 3, 4, 5]
