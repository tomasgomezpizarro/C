import matplotlib.pyplot as plt
import pickle

with open("data.dat", "rb") as f:
    data = pickle.load(f)[:-1]
    data = [i*10-d for i, d in enumerate(data)]

mins = [(i*10, data[i]) for i in range(1,len(data)-1) if data[i] < data[i-1] and data[i] < data[i+1]] 
maxs = [(i*10, data[i]) for i in range(1,len(data)-1) if data[i] > data[i-1] and data[i] > data[i+1]]

print(list(map(lambda x: x[0], mins)))
print(list(map(lambda x: x[0], maxs)))
print(mins)

plt.plot(range(1,len(data)*10,10), data)
plt.scatter(*zip(*mins), color='red')
plt.scatter(*zip(*maxs), color='green')
# plt.plot(data[:-1])
plt.show()