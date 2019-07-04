import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos.txt")
x=data[:,0]
der=data[:,2]
fun=data[:,1]
plt.figure()
plt.plot(x,der, label="derivada",color="red")
plt.plot(x,fun, label="coseno",color="black")
plt.legend(loc=0)
plt.xlabel("X")
plt.ylabel("Y")
plt.savefig("S5C1PLOT.png")