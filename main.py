import matplotlib.pyplot as plt
import numpy as np
import random
import subprocess


x=[round(float((random.randint(-32768,32768)))/14,2) for x in range(1,11*11+1)]
with open("date.txt",'w') as g:
    g.write("11"+'\n')
    for i in x:
        g.write(str(i)+'\n')

subprocess.run([r"C:\Users\Mario\OneDrive\Documente\Cursuri+Seminare+Tutoriate\Algerba liniara\Tema deteremianti\Gauss.exe"])
subprocess.run([r"C:\Users\Mario\OneDrive\Documente\Cursuri+Seminare+Tutoriate\Algerba liniara\Tema deteremianti\Clasic.exe"])
with open("clasic_rez.txt",'r') as f:
    date_clasic=[float(x) for x in f.readline().split()][4:]
with open("gauss_rez.txt",'r') as f:
    date_gauss=[float(x) for x in f.readline().split()][4:]

#print(date_clasic)
#print(len(date_gauss))

xlist=np.linspace(5,11,num=6)
plt.figure(num=0,dpi=200)
plt.plot(xlist,date_clasic,label="Metoda clasica")
plt.plot(xlist,date_gauss,label="Metoda Gauss")
plt.xlabel("Ordinul Matricei")
plt.ylabel("Timp Executie(secunde)")
plt.legend()
plt.show()