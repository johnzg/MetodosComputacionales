
    
import numpy as np
import matplotlib.pylab as plt

data=np.genfromtxt("datos.txt")
x=data[:,1]
t=data[:,0]
plt.figure()

plt.plot(t,x,color="black")
plt.title("Posicion Vs tiempo")
plt.xlabel("t (segundos)")
plt.ylabel("x(t) (metros)")
plt.savefig("ZarateJohnResorte.png")