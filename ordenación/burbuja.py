def burbuja(lista):
    n=len(lista)

    for i in range(n):
        for j in range(n -i- 1):
            if lista[j] > lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
    return lista

lista=[5, 3, 4, 1, 2]
print(burbuja(lista))  # [1, 2, 3, 4, 5] 
