#con este algoritmo de optimización queremos encontrar la mejor combinación de elementos
# que podemos llevar en una mochila, de acuerdo a su peso

def morral(tamannio_morral, pesos, valores, n):

    #siempre que se quiera implementar una función recursiva,
    # se debe tener en cuenta el caso base, es decir, 
    # el caso en el que la función no se llama a sí misma

    if n == 0 or tamannio_morral == 0: #ya no hay más elementos o ya no hay más espacio en la mochila
        return 0
    
    #si el peso del elemento es mayor al tamaño del morral
    #no se puede llevar ese elemento
    if pesos[n - 1] > tamannio_morral:#se supone que la lista de pesos está ordenada de menor a mayor
        #si el elemento es mayor que la capacidad entonces tratamos de introducir al morral un elemento más pequeño
        return morral(tamannio_morral, pesos, valores, n - 1)
    
    return max(valores[n - 1] + 
               morral(tamannio_morral - pesos[n - 1], pesos, valores, n - 1),
                 morral(tamannio_morral, pesos, valores, n - 1))


if __name__ == "__main__":
    valores=[60, 100, 120] #cada peso tiene un valor asociado
    pesos = [10, 20, 30]
    tamannio_morral = 5  #el peso máximo que puede soportar la mochila
    n=len(valores)
    print(morral(tamannio_morral, pesos, valores, n))  # imprime el valor 
    #máximo que se puede llevar en la mochila