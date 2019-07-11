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
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(Celcius)')
ax.set_title('frontera fija t=0')
plt.savefig("difusionFijas0.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto2, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(Celcius)')
ax.set_title('frontera fija t=100')
plt.savefig("difusionFijas100.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto3, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(celcius)')
ax.set_title('frontara fija t=2500')
plt.savefig("difusionFijas2500.png")

data=np.genfromtxt("difusionfijastprom.dat")
t=data[:,0]
temp=data[:,1]
plt.figure()
plt.plot(t,temp,color="black")
plt.xlabel("tiempo(s)")
plt.ylabel("temperatura(celcius)")
plt.title("temperatura promedio (frontera fija)")
plt.savefig("temperaturaPromedioFronteraFiija.png")

data=np.genfromtxt("difusionlibres.dat")
x=data[:,0]
y=data[:,1]
X, Y = np.meshgrid(x, y)
foto1=data[:,2:103]
foto2=data[:,103:204]
foto3=data[:,204:305]

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto1, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(Celcius)')
ax.set_title('frontera libre t=0')
plt.savefig("difusionLibres0.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto2, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(Celcius)')
ax.set_title('frontera libre t=100')
plt.savefig("difusionLibres100.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(Y, X, foto3, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x(m)')
ax.set_ylabel('y(m)')
ax.set_zlabel('T(celcius)')
ax.set_title('frontara libre t=2500')
plt.savefig("difusionLibres2500.png")

data=np.genfromtxt("difusionlibrestprom.dat")
t=data[:,0]
temp=data[:,1]
plt.figure()
plt.plot(t,temp,color="black")
plt.xlabel("tiempo(s)")
plt.ylabel("temperatura(celcius)")
plt.title("temperatura promedio (frontera libre)")
plt.savefig("temperaturaPromedioFronteraLibre.png")
