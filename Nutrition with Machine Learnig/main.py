import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.api as sm
import seaborn
plt.style.use("seaborn-dark")
from sklearn.linear_model import LinearRegression
from sklearn.feature_selection import f_regression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

def ReadCSV():
    data = pd.read_csv("A01022382_BasedeDatos.csv")
    #print(data)
    return data

def Regression(data, y, x1):
    print(" ")
    print("------------------------------------------------------------------------------------")
    print("Resultados de la regresión con statsmodel")
    print(" ")
    print(" ") 
    x = sm.add_constant(x1)
    results = sm.OLS(y,x).fit()
    print(results.summary())  
    print(" ")
    print("------------------------------------------------------------------------------------")


def RegressionSKL(data, y, x):
    print(" ")
    print("------------------------------------------------------------------------------------")
    print("Resultados de la regresión con Sklearn")
    print(" ")
    print(data.describe())
    # Hacemos la regresión
    reg = LinearRegression()
    reg.fit(x, y)
    print(" ")
    # Imprimrimos los coeficientes
    print(f"Coeficientes de Carbohidratos, Grasa y Proteina: {reg.coef_}")
    # b
    print(" ")
    print(f"Interceptor (b): {round(reg.intercept_, 3)}") 
    # Calcular R-cuadrada
    print(" ")
    r2 = reg.score(x, y)
    print(f"Score o R-cuadrada: {round(r2, 2)}")

    # Calcular  R-cuadrada ajustada
    print(" ")
    n = x.shape[0]
    p = x.shape[1]
    adj_r = 1-(1-r2)*((n-1)/(n-p-1))
    print(f"R-cuadrada ajustada: {round(adj_r, 2)}")

    print(" ")
    print("Ecuación de regresión lineal multiple")
    print(f"Calorías = {round(reg.intercept_, 3)} + ({round(reg.coef_[0],2)})*Carbohidratos + ({round(reg.coef_[1],2)})*Grasas + ({round(reg.coef_[2],2)})*Proteinas")

    # Feature Selection
    print(" ")
    p_values = f_regression(x, y)[1]
    print(f"P-valor para los Carbohidratos, Grasa y Proteina: {p_values}")

    # Resumen en un DataFrame
    print(" ")
    reg_sumary = pd.DataFrame(data=x.columns.values, columns=['Features'])
    reg_sumary['Coeficientes'] = reg.coef_
    reg_sumary['P-valor'] = p_values.round(5)
    print(reg_sumary)
    print(" ")
    print("------------------------------------------------------------------------------------")
    


def Graph(data, y, x1):
    for param in ['figure.facecolor', 'axes.facecolor', 'savefig.facecolor']:
        plt.rcParams[param] = '#212946'  # Color del fondo, toda la figura
    for param in ['text.color', 'axes.labelcolor', 'xtick.color', 'ytick.color']:
        plt.rcParams[param] = 'white'  # Color de las etiquetas y números de los ejes

    fig, ax = plt.subplots()
    colors = [
    '#08F7FE',  # teal/cyan
    '#FE53BB',  # pink
    '#F5D300',  # yellow
    '#00ff41',  # matrix green
    ]

    df1 = pd.DataFrame({'Carbs': x1['Carbohidratos (g)']})
    df2 = pd.DataFrame({'Fat': x1['Lípidos (g)']})
    df3 = pd.DataFrame({'Protein': x1['Proteína (g)']})
    
    df1.plot(marker='o', color='#08F7FE', ax=ax)  #Aqui podemos cambiar el color de las línea y marcadores
    df2.plot(marker='o', color='#FE53BB', ax=ax)  #Aqui podemos cambiar el color de las línea y marcadores
    df3.plot(marker='o', color='#00ff41', ax=ax)  #Aqui podemos cambiar el color de las línea y marcadores
    
    n_shades = 5
    diff_linewidth = 1.05
    alpha_value = 0.3 / n_shades
    for n in range(1, n_shades+1): #Glow de las líneas
        df1.plot(marker='o',
                linewidth=2+(diff_linewidth*n),
                alpha=alpha_value,
                legend=False,
                ax=ax,
                color='#08F7FE')
        df2.plot(marker='o',
                linewidth=2+(diff_linewidth*n),
                alpha=alpha_value,
                legend=False,
                ax=ax,
                color='#FE53BB')
        df3.plot(marker='o',
                linewidth=2+(diff_linewidth*n),
                alpha=alpha_value,
                legend=False,
                ax=ax,
                color='#00ff41')
        
     
    for column, color in zip(df1, colors): #Llenado del área bajo las líneas
        ax.fill_between(x=df1.index,
                        y1=df1[column].values,
                        y2=[0] * len(df1),
                        color='#08F7FE',
                        alpha=0.1)
    
    for column, color in zip(df2, colors):
        ax.fill_between(x=df2.index,
                        y1=df2[column].values,
                        y2=[0] * len(df2),
                        color='#FE53BB',
                        alpha=0.1)
    
    for column, color in zip(df3, colors):
        ax.fill_between(x=df3.index,
                        y1=df3[column].values,
                        y2=[0] * len(df3),
                        color='#00ff41',
                        alpha=0.1)
    
    ax.grid(color='#F5D300', alpha = 0.3)  # Cambiar el grid
    font = {'fontname' : 'AppleMyungjo'} # Cambiar el tipo de fuente
    for tick in ax.get_xticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje X
    for tick in ax.get_yticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje Y
    

    size = len(df1)
    plt.ylim(0, 410)
    plt.xticks(range((size-size)-5, size+5, 10), size = 10)
    plt.yticks(size = 10)
    plt.title('Macronutrientes en el semestre', size = 30, fontstyle='oblique', **font)
    plt.ylabel("Gramos", size = 20, fontstyle ='oblique', **font)
    plt.xlabel("Dia", size = 20, fontstyle='oblique', **font)
    print(" ")
    plt.show()

def GraphCals(y):
    df = y
    for param in ['figure.facecolor', 'axes.facecolor', 'savefig.facecolor']:
        plt.rcParams[param] = '#212946'  # Color del fondo, toda la figura
    for param in ['text.color', 'axes.labelcolor', 'xtick.color', 'ytick.color']:
        plt.rcParams[param] = 'white'  # Color de las etiquetas y números de los ejes
    fig,ax = plt.subplots()
    colors = [
    '#08F7FE',  # teal/cyan
    '#FE53BB',  # pink
    '#F5D300',  # yellow
    '#00ff41',  # matrix green
    ]

    df.plot(marker='o', color='#08F7FE', ax=ax)  #Aqui podemos cambiar el color de las línea y marcadores
    n_shades = 5
    diff_linewidth = 1.05
    alpha_value = 0.3 / n_shades
    for n in range(1, n_shades+1):
        df.plot(marker='o',
                linewidth=2+(diff_linewidth*n),
                alpha=alpha_value,
                legend=False,
                ax=ax,
                color='#08F7FE')
        
    ax.grid(color='#F5D300', alpha = 0.3)  # Cambiar el grid
    font = {'fontname' : 'AppleMyungjo'} # Cambiar el tipo de fuente
    for tick in ax.get_xticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje X
    for tick in ax.get_yticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje Y
    size = len(df)
    plt.ylabel("Calorias", size = 20, fontstyle ='oblique', **font)
    plt.xticks(range((size-size)-5, size+5, 10), size = 10)
    plt.xlabel("Dia", size = 20, fontstyle='oblique', **font)
    print(" ")
    plt.show()


def GraphM(data, y, x1, opcion):
    for param in ['figure.facecolor', 'axes.facecolor', 'savefig.facecolor']:
        plt.rcParams[param] = '#212946'  # Color del fondo, toda la figura
    for param in ['text.color', 'axes.labelcolor', 'xtick.color', 'ytick.color']:
        plt.rcParams[param] = 'white'  # Color de las etiquetas y números de los ejes
    fig,ax = plt.subplots()
    
    if(opcion == 5):
        X_mult = pd.DataFrame({'Carbs': x1['Carbohidratos (g)']})
        xlabel = 'Carbohidratos'
        color = 'white'
    if(opcion == 6):
        X_mult = pd.DataFrame({'Fat': x1['Lípidos (g)']})
        xlabel = 'Grasas'
        color = '#FE53BB'
    if(opcion == 7):
        X_mult = pd.DataFrame({'Protein': x1['Proteína (g)']})
        xlabel = 'Proteinas'
        color = '#F5D300'
    
    ts = 0.10
    X_mult_train, X_mult_test, y_mult_train, y_mult_test = train_test_split(X_mult, y, test_size = ts, random_state = 21)
   
    reg1 = LinearRegression()
    reg1.fit(X_mult_train, y_mult_train)
    y_pred1 = reg1.predict(X_mult_test)
    font = {'fontname' : 'AppleMyungjo'} # Cambiar el tipo de fuente
    plt.scatter(X_mult_train, y_mult_train, c=color)
    plt.xlabel(xlabel, size = 20, fontstyle ='oblique', **font)
    plt.ylabel("Calorias", size = 20, fontstyle ='oblique', **font)
    plt.title("Modelo usando datos de entrenamiento y prueba", size = 20, fontstyle='oblique', **font)
    for tick in ax.get_xticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje X
    for tick in ax.get_yticklabels():
        tick.set_fontname('AppleMyungjo') # Cambiar el tipo de fuente del eje Y
    plt.plot(X_mult_test, y_pred1, color = '#08F7FE', linewidth = 3)
    ax.grid(color='#F5D300', alpha = 0.3)
    print(" ")
    plt.show()
    print(" ")
    print("------------------------------------------------------------------------------------")
    print(f"Resultados utlizando un tamaño de entrenamiento de {((1-ts))*100} % ")
    print(f"Coeficiente: {reg1.coef_}")
    print(f"Interceptor (b): {reg1.intercept_}")
    print(f"Error: {np.sqrt(mean_squared_error(y_mult_test, y_pred1))}")  
    print(f"Score: {reg1.score(X_mult_test, y_mult_test)}")
    print("------------------------------------------------------------------------------------")
    print(" ") 


def main():
    print(" ")
    print("------------------------------------------------------------------------------------")
    print("Proyecto Final : Matemáticas y Ciencia de Datos")
    print(" ")
    print("Pablo Yamamoto Magaña")
    print(" ")
    print("------------------------------------------------------------------------------------")
    print(" ") 
    
    data = ReadCSV()
    y = data['Calorias (kcal)']
    x1 = data[['Carbohidratos (g)',  'Lípidos (g)',  'Proteína (g)']]
    
    while(True):
        print("------------------------------------------------------------------------------------")
        print("Menú")
        print(" ")
        print("Opción 1: Datos de la regresión utilizando el módulo statsmodel")
        print("Opción 2: Datos de la regresión utilizando sklearn")
        print("Opción 3: Gráfica de Macronutrientes vs Tiempo")
        print("Opción 4: Gráfica de Calorías vs Tiempo")
        print("Opción 5: Gráfica de Carbohidratos")
        print("Opción 6: Gráfica de Grasas")
        print("Opción 7: Gráfica de Proteína")
        print("Opción 8: Terminar el programa")
        print(" ")
        print("------------------------------------------------------------------------------------")
        print(" ")
        opcion = int(input("Introduce el número de opción: "))
        if(opcion == 1):
            Regression(data, y, x1)
        elif(opcion == 2):
            RegressionSKL(data, y, x1)
        elif(opcion == 3):
            Graph(data, y, x1)
        elif(opcion == 4):
            GraphCals(y)
        elif(opcion == 5 or opcion == 6 or opcion == 7):
            GraphM(data, y, x1, opcion)
        elif(opcion == 8):
            print(" ")
            print("------------------------------------------------------------------------------------")
            print("Programa finalizado")
            print("------------------------------------------------------------------------------------")
            print(" ")
            break
        else:
            print(" ")
            print("------------------------------------------------------------------------------------")
            print("Parece que seleccionaste una opción no disponible, intentalo denuevo")
            print("------------------------------------------------------------------------------------")
            print(" ")
            
main()