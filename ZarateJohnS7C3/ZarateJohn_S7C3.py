#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
data=np.genfromtxt("resorte.dat")

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por 

# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

def modelo(a, gamma, omega, t):
    return a*np.exp(-gamma*t)*np.cos(omega*t)



# 2b.) Definir una funcion que retorne la funcion de verosimilitud
def likelihood(a1,gamma1,omega1,obs,tiempos):
    xiCuad=np.sum((obs-modelo(a1,gamma1,omega1,tiempos))**2)
    return np.exp(-0.5*xiCuad)
    
# 2c.) Caminata

def estimadorBayesiano(a0,gamma0,omega0,tiempos, pos, pasos):
    sigmaA=0.1
    sigmaGamma=0.1
    sigmaOmega=0.1
    
    L0=likelihood(a0,gamma0,omega0,pos,tiempos)
    
    a=np.zeros(pasos)
    gamma=np.zeros(pasos)
    omega=np.zeros(pasos)
    L=np.zeros(pasos)
    
    a[0]=a0
    gamma[0]=gamma0
    omega[0]=omega0
    L[0]=L0   
    
    for i in range(pasos-1):
        
        aviejo=a[i]
        gammaviejo=gamma[i]
        omegaviejo=omega[i]
        Lviejo=L[i]
        
        anuevo=np.random.normal(aviejo,sigmaA)
        gammanuevo=np.random.normal(gammaviejo,sigmaGamma)
        omeganuevo=np.random.normal(omegaviejo,sigmaOmega)
        Lnuevo=likelihood(anuevo,gammanuevo,omeganuevo,pos,tiempos)
        alpha=Lnuevo/Lviejo
        if(alpha>=1):
                a[i+1]=anuevo
                gamma[i+1]=gammanuevo
                omega[i+1]=omeganuevo
                L[i+1]=Lnuevo
            
        else:
            beta=np.random.rand(1)
            if (beta<alpha):
                a[i+1]=anuevo
                gamma[i+1]=gammanuevo
                omega[i+1]=omeganuevo
                L[i+1]=Lnuevo
            else:
                a[i+1]=aviejo
                gamma[i+1]=gammaviejo
                omega[i+1]=omegaviejo
                L[i+1]=Lviejo

    r=np.argmax(L)    
    return [a[r],gamma[r],omega[r]] 

#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2

#numero de pasos
iteraciones=100000


# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."
estimacion=estimadorBayesiano(aini,gammaini,omegaini,data[:,0], data[:,1], iteraciones)
aOptimo=estimacion[0]
gammaOptimo=estimacion[1]
omegaOptimo=estimacion[2]
print("LOS MEJORES PARAMETROS SON a=",aOptimo," ... gamma=",gammaOptimo,"... Y omgega=...",omegaOptimo)
# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf

t=np.linspace(0,5,10000)
plt.figure()
plt.plot(t,modelo(aOptimo,gammaOptimo,omegaOptimo,t),color="black")
plt.scatter(data[:,0],data[:,1],c="blue",s=2)
plt.xlabel("tiempo")
plt.ylabel("posicion")
plt.title("modelo con parametros estimados")
plt.savefig("Resorte.pdf")

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

print("No es posible usar este metodo para calcular K y m de manera individual porque hay infinitos numeros cuyo cociente maximiza la funcion de verosimilitud ocasionando que se estanque en cualquiera de estos. Es decir si omega es 10 podriamos tener k=100 m=1 o bien k=0.1 m=0.001")


