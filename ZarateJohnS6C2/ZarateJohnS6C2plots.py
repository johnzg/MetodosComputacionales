
    
import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos.txt")
x=data[:,0]
foto1=data[:,1]
foto2=data[:,2]
foto3=data[:,3]
foto4=data[:,4]
foto5=data[:,5]

plt.figure()
plt.plot(x,foto1,color="black")
plt.plot(x,foto2,color="red")
plt.plot(x,foto3,color="green")
plt.plot(x,foto4,color="yellow")
plt.plot(x,foto5,color="grey")
plt.title("solucion EDP")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("ZarateJohnEDPOnda.png")