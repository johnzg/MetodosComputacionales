#Ejercicio 0
#Lean el capitulo 5 del Landau (ver el programa del curso).

#Ejercicio 1
# Usando los generadores de numeros aleatorios de numpy (https://docs.scipy.org/doc/numpy-1.15.1/reference/routines.random.html):
# a) Genere 1000 numeros aleatorios que sigan una distribucion uniforme y esten entre -10 y 10. Haga un histograma y guardelo sin mostrarlo en un archivo llamado uniforme.pdf
import numpy as np
import matplotlib.pylab as plt

unif=np.random.rand(1000)*20-10
plt.figure()
plt.hist(unif)
plt.title("uniforme")
plt.ylabel("frecuencia")
plt.savefig("uniforme.png")

# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf
normal=5.0 * np.random.randn(1000) + 17.0

plt.figure()
plt.hist(normal)
plt.title("normal")
plt.ylabel("frecuencia")
plt.savefig("gausiana.png")

# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 
# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 

cuadrado=np.random.rand(1000,2)*30.5

plt.figure()
plt.scatter(cuadrado[:,0],cuadrado[:,1], c="black",s=2)
plt.title("cuadrado")
plt.savefig("cuadrado.png")

circulo=np.random.rand(3000,2)*46.0-23.0
for i in range(3000):
    while (circulo[i,0]**2+circulo[i,1]**2>23.0**2):
        circulo[i,0]=np.random.rand()*46.0-23.0
        circulo[i,1]=np.random.rand()*46.0-23.0
plt.figure()
plt.scatter(circulo[:,0],circulo[:,1], c="black",s=2)
plt.title("circulo")
plt.savefig("circulo.png")



# Ejercicio 3 
# Lean sobre caminatas aleatorias.



# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos.


# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25
# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro  

# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf
# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf

# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf

# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.
caminata1=np.zeros((100,2))
cuadrado1=cuadrado
caminata1[0,:]=cuadrado1[0,:]

for i in range (1000):
    for j in range(100):
        unifCaminata1=np.random.randn(2)*0.25
        cuadrado1[i,:]=unifCaminata1+cuadrado1[i,:]
        if (cuadrado1[i,0]<0.0):
            cuadrado1[i,0]+=30.5
        if (cuadrado1[i,0]>30.5):
            cuadrado1[i,0]-=30.5           
        if (cuadrado1[i,1]<0.0):
            cuadrado1[i,1]+=30.5
        if (cuadrado1[i,1]>30.5):
            cuadrado1[i,1]-=30.5     
        if(i==0):    
            caminata1[j,:]=cuadrado1[i,:]

caminata2=np.zeros((100,2))
caminata3=np.zeros((100,2))
caminata2[0,:]=np.random.rand(2)*30.5
caminata3[0,:]=np.random.rand(2)*30.5            
            
for j in range(100):
    unifCaminata2=np.random.randn(2)*0.00025
    unifCaminata3=np.random.randn(2)*2.5
    caminata2[j,:]=unifCaminata2+caminata2[j,:]
    caminata3[j,:]=unifCaminata3+caminata3[j,:]   
    if (caminata2[j,0]<0.0):
        caminata2[j,0]+=30.5
    if (caminata2[j,0]>30.5):
        caminata2[j,0]-=30.5             
    if (caminata2[j,1]<0.0):
        caminata2[j,1]+=30.5
    if (caminata2[j,1]>30.5):
        caminata2[j,1]-=30.5    
    if (caminata3[j,0]<0.0):
        caminata3[j,0]+=30.5
    if (caminata3[j,0]>30.5):
        caminata3[j,0]-=30.5             
    if (caminata3[j,1]<0.0):
        caminata3[j,1]+=30.5
    if (caminata3[j,1]>30.5):
        caminata3[j,1]-=30.5  

plt.figure()
plt.scatter(cuadrado[:,0],cuadrado1[:,1], c="black",s=2)
plt.title("finales")
plt.savefig("DistCaminata.png")

plt.figure()
plt.plot(caminata1[:,0],caminata1[:,1], color="black")
plt.title("camianta de un punto")
plt.savefig("puntoCaminata.png")

plt.figure()
plt.plot(caminata2[:,0],caminata2[:,1], color="black", label="sigma=0.00025")
plt.plot(caminata3[:,0],caminata3[:,1], color="red", label="sigma=2.5")
plt.legend(loc=0)
plt.title("camianta de un punto con distintos sigmas")
plt.savefig("sigmaCaminata.png")



# Si le queda tiempo puede:

##################################################################################################################################################################
############################################################ Ejercicio  ##########################################################################
##################################################################################################################################################################

#difusion: una gota de crema en un Cafe.
#
#Condiciones iniciales:
#Cafe: 10000 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 230
#Crema: 100 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 2
#
#Nota: si su codigo se esta demorando mucho en correr, puede usar 1000 particulas de cafe en vez de 10000.
#
# 1) Haga una grafica de las condiciones iniciales donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheIni.pdf
#
#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.
#
#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)
#
# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf
#

import numpy as np
import matplotlib.pylab as plt


#Una posible implementacion de condiciones de frontera. Trate de hacer la suya propia sin usar esta. 
#Si usa esta (obtiene menos puntos) debe comentar cada una de las lineas explicando en palabras que hace el codigo. Debe tambien naturalmente usar los nombres de variables que uso en el resto de su codigo propio.
#indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>230)
#indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>230)
#while(len(indexcafe[0])>1):
#	xcafenuevo[indexcafe]=xcafe[indexcafe] + np.random.normal(0,sigma)
#	ycafenuevo[indexcafe]=ycafe[indexcafe] + np.random.normal(0,sigma)
#	indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>=230)
#while(len(indexcrema[0])>1):
#	xcremanuevo[indexcrema]=xcrema[indexcrema] + np.random.normal(0,sigma)
#	ycremanuevo[indexcrema]=ycrema[indexcrema] + np.random.normal(0,sigma)
#	indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>=230) 



	
