import sympy as sp

def get_lagrange_expression(x_values, y_values):
    x = sp.Symbol('x')
    n = len(x_values)
    polynomial = 0
    
    for i in range(n):
        L_i = 1
        for j in range(n):
            if i != j:
                L_i *= (x - x_values[j]) / (x_values[i] - x_values[j])
        
        polynomial += y_values[i] * L_i
        
    return sp.expand(polynomial)

X, Y = [], []
while True:
    t = input("Точка у форматі X Y: ")
    if t == "":
            break
    x, y = t.split()
    X.append(float(x))
    Y.append(float(y))
print(X, Y)
func_expr = get_lagrange_expression(X, Y)

print("Інтерполяційний поліном Лагранжа:")
print(f"P(x) = {func_expr}")