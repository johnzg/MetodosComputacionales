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
plt.savefig("uniforme.pdf")

# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf
normal= np.random.normal(17.0,5.0,1000) 

plt.figure()
plt.hist(normal)
plt.title("normal")
plt.ylabel("frecuencia")
plt.savefig("gausiana.pdf")

# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 
# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 

cuadrado=np.random.rand(1000,2)*30.5

plt.figure()
plt.scatter(cuadrado[:,0],cuadrado[:,1], c="black",s=2)
plt.title("cuadrado")
plt.savefig("cuadrado.pdf")

circulo=np.random.rand(3000,2)*46.0-23.0
for i in range(3000):
    while (circulo[i,0]**2+circulo[i,1]**2>23.0**2):
        circulo[i,0]=np.random.rand()*46.0-23.0
        circulo[i,1]=np.random.rand()*46.0-23.0
plt.figure()
plt.scatter(circulo[:,0],circulo[:,1], c="black",s=2)
plt.title("circulo")
plt.savefig("circulo.pdf")



# Ejercicio 3 
# Lean sobre caminatas aleatorias.



# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos.


# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25
# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro  

# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf
# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf

caminata1=np.zeros((100,2))
cuadrado1=cuadrado
for i in range (1000):
    for j in range(100):
        normCaminata1=np.random.normal(0,0.25,2)
        cuadrado1[i,:]=normCaminata1+cuadrado1[i,:]
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
plt.figure()
plt.scatter(cuadrado1[:,0],cuadrado1[:,1], c="black",s=2)
plt.title("finales")
plt.savefig("DistCaminata.pdf")

plt.figure()
plt.plot(caminata1[:,0],caminata1[:,1], color="black")
plt.title("camianta de un punto")
plt.savefig("puntoCaminata.pdf")

# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf

caminata2=np.zeros((100,2))
caminata3=np.zeros((100,2))
cuadrado2=np.random.rand(1000,2)*30.5
cuadrado3=np.random.rand(1000,2)*30.5

for i in range (1000):
    for j in range(100):
        normCaminata2=np.random.normal(0,0.00025,2)
        normCaminata3=np.random.normal(0,2.5,2)
        cuadrado2[i,:]=normCaminata2+cuadrado2[i,:]
        cuadrado3[i,:]=normCaminata3+cuadrado3[i,:]   
        
        if (cuadrado2[i,0]<0.0):
            cuadrado2[i,0]+=30.5
        if (cuadrado2[i,0]>30.5):
            cuadrado2[i,0]-=30.5           
        if (cuadrado2[i,1]<0.0):
            cuadrado2[i,1]+=30.5
        if (cuadrado2[i,1]>30.5):
            cuadrado2[i,1]-=30.5
        
        if (cuadrado3[i,0]<0.0):
            cuadrado3[i,0]+=30.5
        if (cuadrado3[i,0]>30.5):
            cuadrado3[i,0]-=30.5           
        if (cuadrado3[i,1]<0.0):
            cuadrado3[i,1]+=30.5
        if (cuadrado3[i,1]>30.5):
            cuadrado3[i,1]-=30.5  
            
        if(i==0):  
            caminata2[j,:]=cuadrado2[i,:]
            caminata3[j,:]=cuadrado3[i,:] 



plt.figure(figsize=(16,9))
plt.subplot(2,2,1)
plt.plot(caminata2[:,0],caminata2[:,1], color="black", label="sigma=0.00025")
plt.title("sigma=0.00025")

plt.subplot(2,2,2)
plt.plot(caminata3[:,0],caminata3[:,1], color="red", label="sigma=2.5")
plt.legend(loc=0)
plt.title("sigma=2.5")
plt.savefig("sigmaCaminata.pdf")

# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.

caminata4=np.zeros((100,2))
cuadrado4=cuadrado
for i in range (1000):
    for j in range(100):
        normCaminata4=np.random.normal(0,0.25,2)
        cuadrado4[i,:]=normCaminata4+cuadrado4[i,:]
        if (cuadrado4[i,0]<0.0 or cuadrado4[i,0]>30.5 or cuadrado4[i,1]<0.0 or cuadrado4[i,1]>30.5):
            cuadrado4[i,0]=-1
            cuadrado4[i,1]=-1
        if(i==0):    
            caminata4[j,:]=cuadrado4[i,:]
final1=[]
final2=[]
finalCaminata1=[]
finalCaminata2=[]
for i in range (1000):
    if (cuadrado4[i,0]!=-1):
        final1.append(cuadrado4[i,0])
        final2.append(cuadrado4[i,1])
j=0        
while(j<100 and caminata4[j,0]!=-1 ):
    finalCaminata1.append(caminata4[j,0])
    finalCaminata2.append(caminata4[j,1])
    j+=1
plt.figure()
plt.scatter(final1,final2,c="black",s=2)
plt.title("finales frontera abierta")
plt.savefig("DistCaminataAbierta.pdf")

plt.figure()
plt.plot(finalCaminata1,finalCaminata2, color="black")
plt.title("camianta de un punto frontera abierta")
plt.savefig("puntoCaminataAbierta.pdf")

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
r1=np.sqrt(230.0)
r2=np.sqrt(2.0)
cafe=np.random.rand(10000,2)*2*r1-r1
crema=np.random.rand(100,2)*2*r2-r2
for i in range(10000):
    while (cafe[i,0]**2+cafe[i,1]**2 > 230):
        cafe[i,0]=np.random.rand()*2*r1-r1
        cafe[i,1]=np.random.rand()*2*r1-r1
for i in range(100):
    while (crema[i,0]**2+crema[i,1]**2 > 2):
        crema[i,0]=np.random.rand()*2*r2-r2
        crema[i,1]=np.random.rand()*2*r2-r2
plt.figure()
plt.scatter(cafe[:,0],cafe[:,1], c="saddlebrown",s=2)
plt.scatter(crema[:,0],crema[:,1], c="khaki",s=3)
plt.title("condiciones iniciales")
plt.savefig("CafeLecheIni.pdf")

#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.
#
#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)

for i in range (10000):
    for j in range(100):
        normCaminata=np.random.normal(0,2.5,2)
        aux=normCaminata+cafe[i,:] 
        while(aux[0]**2+aux[1]**2 > 230):
            normCaminata=np.random.normal(0,2.5,2)
            aux=normCaminata+cafe[i,:]   
        cafe[i,:]=aux
        
for i in range (100):
    for j in range(100):
        normCaminata=np.random.normal(0,2.5,2)
        aux=normCaminata+crema[i,:] 
        while(aux[0]**2+aux[1]**2 > 230):
            normCaminata=np.random.normal(0,2.5,2)
            aux=normCaminata+crema[i,:]   
        crema[i,:]=aux


#
# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf
#

plt.figure()
plt.scatter(cafe[:,0],cafe[:,1], c="saddlebrown",s=2)
plt.scatter(crema[:,0],crema[:,1], c="khaki",s=3)
plt.title("mezcla final")
plt.savefig("CafeLecheFin.pdf")




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



	