import matplotlib.pyplot as plt
import numpy as np

a = float(input())

def f(x, y):
    return a * x - y

def g(x, y):
    return x + a * y

x = 1
y = 1
t = 0
T = 100
dt = 1e-2

x_coords = [x]
y_coords = [y]

while t < T:
    xn = x + dt * f(x, y)
    yn = y + dt * g(x, y)
    x_coords.append(xn)
    y_coords.append(yn)
    x = xn
    y = yn
    t += dt

xs = np.array(x_coords, dtype=float)
ys = np.array(y_coords, dtype=float)

plt.plot(xs, ys)
plt.show()
    
