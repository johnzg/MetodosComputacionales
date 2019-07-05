
    
import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos.txt")
x=data[:,1]
t=data[:,0]
plt.figure()

plt.plot(t,x, label="posicion",color="red")
plt.legend(loc=0)
plt.xlabel("t")
plt.ylabel("x(t)")
plt.savefig("ZarateJohnResorte.png")