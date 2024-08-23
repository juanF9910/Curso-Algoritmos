from bokeh.plotting import figure, output_file, show

if __name__ == '__main__':
    output_file('grafica.html') #nombre del archivo en el que se guardará la gráfica
    fig = figure() #creamos un objeto de la clase figure
    fig.line([1, 2, 3, 4, 5], [5, 4, 3, 2, 1], line_width=2) #dibujamos una línea
    show(fig)


#el comando para crear un virtual enviroment en python es:
#python -m venv nombre_del_entorno
#el comando para activar el entorno es:
#source nombre_del_entorno\bin\activate
#el comando para instalar las dependencias es:
#pip install -r requirements.txt
#el comando para instalar una dependencia es:
#pip install nombre_de_la_dependencia
#el comando para desactivar el entorno es:
#deactivate
#el comando para eliminar el entorno es:
#rm -rf nombre_del_entorno
