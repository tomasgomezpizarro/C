import subprocess
import pickle
import matplotlib.pyplot as plt

def cambiar_len(i):
    # print("CAMBIANDO LENGTH...")
    with open("sort.h", "r") as f:
        a = f.readlines()
        a[9] = f"#define LENGTH {i}u\n"
    with open("sort.h", "w") as f:
        f.writelines(a)                

def count():
    # print("CONTANDO LINEAS...")
    with open("sorted.out", "r") as f:
        return (len(f.readlines()))

def correr():
    # print("CORRIENDO PROGRAMA...")
    return not subprocess.run("run.cmd").returncode

step = 10

length = 2195
data = [None] * (length // step)

for i in range(1, length+1,step):
    cambiar_len(i)
    if correr():
        data[(i//step)-1] = count()
        print(f"lenght->{i} ---- lineas->{data[(i//step)-1]}         ", end="\r")

print(data)

with open("data.dat","wb") as f:
    pickle.dump(data, f)


