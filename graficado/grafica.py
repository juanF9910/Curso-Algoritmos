from bokeh.plotting import figure, output_file, show

if __name__ == '__main__':
    output_file('grafica.html') #nombre del archivo en el que se guardará la gráfica
    fig = figure() #creamos un objeto de la clase figure
    fig.line([1, 2, 3, 4, 5], [5, 4, 3, 2, 1], line_width=2) #dibujamos una línea
    show(fig)