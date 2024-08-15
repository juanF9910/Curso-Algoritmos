/*
En este código trabajamos las colas como listas, con las funciones enqueue, dequeue y display, no como punteros
*/

#include <stdio.h>
#define SIZE 5
int values[SIZE], front = -1, rear = -1; //front y rear son los índices de la cola, que ambos sean -1 significa que la cola está vacía
/*el tamaño de la cola es fijo*/

//values, front y rear son variables globales
void enqueue(int value) { //insertar un valor en la cola
    if (rear == SIZE - 1) { //si rear es igual al tamaño de la cola - 1, la cola está llena
        printf("La cola está llena\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++; //rear es el valor del índice del último valor ingresado a la cola
        values[rear] = value; //se inserta el valor en la cola
        printf("Se insertó el valor %d correctamente\n", value);
    }
}

void dequeue() { //eliminar un valor de la cola
    if (front == -1) {
        printf("La cola está vacía\n");
    } else {
        printf("Se eliminó el valor %d correctamente\n", values[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}


void display() {
    if (front == -1) {
        printf("La cola está vacía\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", values[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(3);
    enqueue(1);
    enqueue(4);
    enqueue(2);
    display();
    dequeue();
    display();
    return 0;
}