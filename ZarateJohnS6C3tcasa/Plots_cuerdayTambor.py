import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d
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

data=np.genfromtxt("tambor.dat")
x=data[:,0]
y=data[:,1]
X, Y = np.meshgrid(x, y)
foto1=data[:,2:203]
foto2=data[:,203:404]
foto3=data[:,404:605]
foto4=data[:,605:806]
foto5=data[:,806:1007]
fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, foto1, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('surface')
plt.savefig("tambor1.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, foto2, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('surface')
plt.savefig("tambor2.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, foto3, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('surface')
plt.savefig("tambor3.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, foto4, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('surface')
plt.savefig("tambor4.png")

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, foto5, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('surface')
plt.savefig("tambor5.png")