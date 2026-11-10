from math import * 
import matplotlib.pyplot as plt

print("Введіть параметричні рівняння базової кривої L:")
x_str = input("x(t) [за замовчуванням cos(t)]: ") or "cos(t)"
y_str = input("y(t) [за замовчуванням sin(t)]: ") or "sin(t)"

print("\nВведіть функцію збурення g(t) (амплітуда):")
g_str = input("g(t) [за замовчуванням 0.1 * sin(20 * t)]: ") or "0.1 * sin(20 * t)"

t_min = 0.0
t_max = 2 * pi
steps = 3000
dt = (t_max - t_min) / steps
delta = 1e-6 

x_vals, y_vals = [], []
x_new_vals, y_new_vals = [], []

for i in range(steps + 1):
    t_cur = t_min + i * dt
    
    t = t_cur
    x = eval(x_str)
    y = eval(y_str)
    g = eval(g_str)
    
    t = t_cur + delta
    x_next = eval(x_str)
    y_next = eval(y_str)
    
    dx = (x_next - x) / delta
    dy = (y_next - y) / delta
    
    norm_length = hypot(dx, dy)  
    nx = -dy / norm_length
    ny = dx / norm_length
    
    x_new = x + g * nx
    y_new = y + g * ny
    
    x_vals.append(x)
    y_vals.append(y)
    x_new_vals.append(x_new)
    y_new_vals.append(y_new)
        
plt.figure(figsize=(8, 8))
plt.plot(x_vals, y_vals, '--', color='gray', alpha=0.7)
plt.plot(x_new_vals, y_new_vals, color='blue')

plt.xlabel('x')
plt.ylabel('y')
plt.axis('equal')
plt.grid(True)
plt.show()