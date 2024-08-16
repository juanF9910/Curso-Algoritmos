def binaria(lista, num): 
    izq, der = 0, len(lista)-1 
    while izq <= der: 
        medio = (izq+der)//2 
        if lista[medio] == num: 
            return True 
        elif lista[medio] < num: 
            izq = medio+1 
        else: 
            der = medio-1 
    return False