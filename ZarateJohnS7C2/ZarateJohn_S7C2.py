# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2.0))/((x-x_0)**2.0 + a**2.0)*10000

# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 

def metropolisHastings(pasos,sigma):
    
    xviejo=np.random.rand(1)*8.0-4.0
    xnuevo=np.random.normal(xviejo,sigma)
    res=np.ones(pasos)
    for i in range(pasos):
        alpha=mifun(xnuevo)/mifun(xviejo)
        if(alpha>=1):
            res[i]=xnuevo    
        else:
            beta=np.random.rand(1)
            if (beta<alpha):
                res[i]=xnuevo
            else:
                res[i]=xviejo
                xnuevo=xviejo
        xviejo=xnuevo
        xnuevo=np.random.normal(xviejo,sigma)
        
    return res            
def sumaDeRectangulos(M):
    M=int(M)
    x=np.linspace(-4,4,M)
    h=(8)/(M-1)
    aprox=h*np.sum(mifun(x))
    return aprox

x=np.linspace(-4.0,4.0,10000)
fx=mifun(x)/sumaDeRectangulos(10000)
    
# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 
plt.figure()
plt.hist(metropolisHastings(100000,5.0),100, density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 5, pasos =100000")
plt.ylabel("frecuencia")
plt.savefig("histograma_5_100000.png")
# sigma = 0.2, pasos =100000 
plt.figure()
plt.hist(metropolisHastings(100000,0.2),100, density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 0.2, pasos =100000")
plt.ylabel("frecuencia")
plt.savefig("histograma_0.2_100000.png")
# sigma = 0.01, pasos =100000 
plt.figure()
plt.hist(metropolisHastings(100000,0.01), density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 0.01, pasos =100000")
plt.ylabel("frecuencia")
plt.savefig("histograma_0.01_100000.png")
# sigma = 0.1, pasos =1000 
plt.figure()
plt.hist(metropolisHastings(1000,0.1),100, density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 0.1, pasos =1000")
plt.ylabel("frecuencia")
plt.savefig("histograma_0.1_1000.png")
# sigma = 0.1, pasos =100000 
plt.figure()
plt.hist(metropolisHastings(100000,0.1),100, density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 0.1, pasos =100000")
plt.ylabel("frecuencia")
plt.savefig("histograma_0.1_100000.png")
# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 
plt.figure()
plt.hist(metropolisHastings(500000,0.1),100, density=True)
plt.plot(x,fx,color="black")
plt.title("sigma = 0.1, pasos =500000")
plt.ylabel("frecuencia")
plt.savefig("histograma_0.1_500000.png")

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
