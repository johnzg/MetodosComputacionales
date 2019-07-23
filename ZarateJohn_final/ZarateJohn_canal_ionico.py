import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
data=np.genfromtxt("Canal_ionico.txt")
xd=data[:,0]
yd=data[:,1]

def mejor():
    xviejo=5.0
    yviejo=5.0
    rviejo=1.0
 
    for i in range (10000):
        xnuevo=np.random.normal(xviejo,0.5)
        ynuevo=np.random.normal(yviejo,0.5)
        rnuevo=np.random.normal(xviejo,0.3)
        aux=True
        for j in range(len(xd)):
            if ((xd[j]-xnuevo)**2+(yd[j]-ynuevo)**2<=rnuevo**2 or rviejo>rnuevo):
                aux=False
        if(aux):
                xviejo=xnuevo
                yviejo=ynuevo
                rviejo=rnuevo

    return [xviejo,yviejo,rviejo]

best_x=mejor()[0]
best_y=mejor()[1]
best_r=mejor()[2]

plt.figure()
fig, ax = plt.subplots()
plt.axis('equal')

circle1 =plt.Circle((best_x, best_y), best_r, color='r',fill=False)
plt.scatter(xd,yd,color="black",s=2)
ax.add_artist(circle1)
plt.savefig("canal.png")

#fig, ax = plt.subplots()
#plt.axis('equal')
#circle1 = plt.Circle((best_x, best_y), np.max(r_walk), color='r',fill=False)
#ax.add_artist(circle1)
#plt.savefig("lalalalalalala.png")
#plt.close()