import matplotlib.pyplot as plt
import numpy as np
import random

xs = []
ys = []
N = int(input())

for i in range(N):
    xs.append(random.random())
    ys.append(random.random())

plt.scatter(np.array(xs, dtype=float), np.array(ys, dtype=float))
plt.show()