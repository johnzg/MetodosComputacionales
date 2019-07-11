import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d


data=np.genfromtxt("difusionfijas.dat")
x=data[:,0]
y=data[:,1]
X, Y = np.meshgrid(x, y)
foto1=data[:,2:103]
foto2=data[:,103:204]
foto3=data[:,204:305]

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto1, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('t=0')
plt.savefig("difusionFijas0.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto2, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('t=100')
plt.savefig("difusionFijas100.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto3, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('t=2500')
plt.savefig("difusionFijas2500.png")

