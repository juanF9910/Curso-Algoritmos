def reverse(lista):
    if len(lista) == 0:
        return []
    return [lista[-1]] + reverse(lista[:-1])

lista = [5, 3, 4, 1, 2]
print(reverse(lista))  # [2, 1, 4, 3, 5]
