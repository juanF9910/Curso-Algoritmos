#con bubble sort podemos garantizar que el elemento más grande se coloca en la última posición
#la complejidad deste algoritmo es O(n^2)
def burbuja(lista):
    n=len(lista)

    for i in range(n):
        for j in range(n -i- 1):
            if lista[j] > lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j] #operación de intercambio o swap
    return lista

if __name__ == "__main__":
    lista=[5, 3, 4, 1, 2]
    print(burbuja(lista))  # [1, 2, 3, 4, 5]
