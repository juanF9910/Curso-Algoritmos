import turtle

tortuga=turtle.Turtle()
win=turtle.Screen()

def dibujar_espiral(tortuga, longitud_linea):
    if longitud_linea > 0:
        tortuga.forward(longitud_linea)
        tortuga.right(90)
        dibujar_espiral(tortuga, longitud_linea - 5)



dibujar_espiral(tortuga, 100)
win.exitonclick()

