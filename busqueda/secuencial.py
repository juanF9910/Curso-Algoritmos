def secuencial(lista, num): 
    for i in lista: 
        if i==num: 
            return True
    return False 

if __name__ == "__main__": 
    lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 
    num = 5
    print(secuencial(lista, num))