
    
import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos1.dat")
x=data[:,0]
foto1=data[:,1]
foto2=data[:,2]
foto3=data[:,3]
foto4=data[:,4]
foto5=data[:,5]

plt.figure()
plt.plot(x,foto1,color="black",label="inicial")
plt.plot(x,foto2,color="red",label="avance 1")
plt.plot(x,foto3,color="green", label="avance 2")
plt.plot(x,foto4,color="yellow", label="avance 3")
plt.plot(x,foto5,color="grey", label= "avance 4")
plt.legend(loc=0)
plt.title("solucion EDP dos extremos fijos")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("EDPOndaDosExtremosFijos.png")

data=np.genfromtxt("datos2.dat")
x=data[:,0]
foto1=data[:,1]
foto2=data[:,2]
foto3=data[:,3]
foto4=data[:,4]
foto5=data[:,5]

plt.figure()
plt.plot(x,foto1,color="black",label="inicial")
plt.plot(x,foto2,color="red",label="avance 1")
plt.plot(x,foto3,color="green", label="avance 2")
plt.plot(x,foto4,color="yellow", label="avance 3")
plt.plot(x,foto5,color="grey", label= "avance 4")
plt.legend(loc=0)
plt.title("solucion EDP un extremo fijo")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("EDPOndaUnExtremoFijo.png")

data=np.genfromtxt("datos3.dat")
x=data[:,0]
foto1=data[:,1]
foto2=data[:,2]
foto3=data[:,3]
foto4=data[:,4]
foto5=data[:,5]

plt.figure()
plt.plot(x,foto1,color="black",label="inicial")
plt.plot(x,foto2,color="red",label="avance 1")
plt.plot(x,foto3,color="green", label="avance 2")
plt.plot(x,foto4,color="yellow", label="avance 3")
plt.plot(x,foto5,color="grey", label= "avance 4")
plt.legend(loc=0)
plt.title("solucion EDP")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("EDPOndaDosExtremoperiodico.png")