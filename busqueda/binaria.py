def binaria(lista, num): 
    izq, der = 0, len(lista)-1 
    while izq <= der: 
        medio = (izq+der)//2 #el simbolo // es para división entera, es decir, redondea hacia abajo
        if lista[medio] == num: 
            return True 
        elif lista[medio] < num: 
            izq = medio+1 
        else: 
            der = medio-1 
    return False

def binaria_recursiva(lista, num, izq, der): 
    if izq > der: 
        return False 
    medio = (izq+der)//2 
    if lista[medio] == num: 
        return True 
    elif lista[medio] < num: 
        return binaria_recursiva(lista, num, medio+1, der) 
    else: 
        return binaria_recursiva(lista, num, izq, medio-1)