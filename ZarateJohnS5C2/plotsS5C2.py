    
import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos.txt")
x=data[:,0]
euler=data[:,1]
runge=data[:,2]
plt.figure()
plt.plot(x,euler, label="metodo de Euler",color="red")
plt.plot(x,runge, label="metodo de Runge Kutta",color="black")
plt.legend(loc=0)
plt.xlabel("X")
plt.ylabel("Y")
plt.savefig("S5C2PLOT.png")