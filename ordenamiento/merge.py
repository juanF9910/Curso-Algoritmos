##este algoritmo consiste en dividir la lista en partes más pequeñas y ordenarlas
#siguiendo la filosofía de divide y vencerás 
#la complejidad de este algoritmo es O(n log n)

def merge(lista):

    if len(lista) > 1:
        medio = len(lista) // 2
        izquierda = lista[:medio] #desde el inicio hasta la mitad
        derecha = lista[medio:] #desde la mitad hasta el final

        merge(izquierda) #llamada recursiva en la parte izquierda
        merge(derecha) #llamada recursiva en la parte derecha
        #lo anterior se ejecuta hasta que solo tengamos listas de un elemento
        i = j = k = 0
        #k es el iterador para la lista principal
        while i < len(izquierda) and j < len(derecha):
            if izquierda[i] < derecha[j]:
                lista[k] = izquierda[i]
                i += 1
            else:
                lista[k] = derecha[j]
                j += 1
            k += 1

        while i < len(izquierda):
            lista[k] = izquierda[i]
            i += 1
            k += 1

        while j < len(derecha):
            lista[k] = derecha[j]
            j += 1
            k += 1

    return lista