import matplotlib.pyplot as plt
import random
import math

a = float(input("Введіть початок відрізка a: "))
b = float(input("Введіть кінець відрізка b: "))
f_str = input("Введіть функцію f(x) (наприклад, x**2 + 1, sin(x)): ")
g_str = input("Введіть функцію g(x) (наприклад, x + 3, cos(x)): ")
N = int(input("Введіть кількість точок для методу Монте-Карло (наприклад, 10000): "))

allowed_math = {k: v for k, v in math.__dict__.items() if not k.startswith("__")}

def evaluate_func(func_string, x_val):
    local_vars = {"x": x_val}
    return eval(func_string, {"__builtins__": {}}, {**allowed_math, **local_vars})

num_plot_points = 1000
step = (b - a) / num_plot_points
x_vals = [a + i * step for i in range(num_plot_points + 1)]

f_vals = [evaluate_func(f_str, x) for x in x_vals]
g_vals = [evaluate_func(g_str, x) for x in x_vals]

y_min = min(min(f_vals), min(g_vals))
y_max = max(max(f_vals), max(g_vals))

inside_x = []
inside_y = []
outside_x = []
outside_y = []
inside_count = 0

for _ in range(N):
    rx = random.uniform(a, b)
    ry = random.uniform(y_min, y_max)
    
    fy = evaluate_func(f_str, rx)
    gy = evaluate_func(g_str, rx)
    
    upper_bound = max(fy, gy)
    lower_bound = min(fy, gy)
    
    if lower_bound <= ry <= upper_bound:
        inside_x.append(rx)
        inside_y.append(ry)
        inside_count += 1
    else:
        outside_x.append(rx)
        outside_y.append(ry)

box_area = (b - a) * (y_max - y_min)
area = box_area * (inside_count / N)
print(f"\nОбчислена площа фігури: {area:.4f}")

plt.figure(figsize=(10, 8))

plt.scatter(inside_x, inside_y, color='green', s=2, alpha=0.6, label='Точки у фігурі')
plt.scatter(outside_x, outside_y, color='lightgray', s=2, alpha=0.3, label='Точки зовні')

plt.plot(x_vals, f_vals, color='blue', linewidth=2, label=f'f(x) = {f_str}')
plt.plot(x_vals, g_vals, color='red', linewidth=2, label=f'g(x) = {g_str}')

plt.axvline(x=a, color='black', linestyle='--', linewidth=1.5, label=f'x = {a}')
plt.axvline(x=b, color='black', linestyle='--', linewidth=1.5, label=f'x = {b}')

plt.axhline(y=y_min, color='orange', linestyle='--', linewidth=1.5, label=f'y_min = {y_min:.2f}')
plt.axhline(y=y_max, color='orange', linestyle='--', linewidth=1.5, label=f'y_max = {y_max:.2f}')

plt.xlabel('x')
plt.ylabel('y')
plt.title(f'Метод Монте-Карло (S ≈ {area:.4f})')
plt.legend(loc='upper right')
plt.grid(True, alpha=0.3)
plt.xlim(a - 0.5, b + 0.5)
plt.ylim(y_min - abs(y_max - y_min)*0.1, y_max + abs(y_max - y_min)*0.1)

plt.show()