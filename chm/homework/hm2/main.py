import sympy as sp

def newton_method(f, df, x0, eps=1e-6, max_iter=100):
    x = x0
    for i in range(max_iter):
        fx = f(x)
        if abs(fx) < eps:
            return x, i
            
        dfx = df(x)
        x = x - fx / dfx
        
    return x, max_iter

def secant_method(f, x0, x1, eps=1e-6, max_iter=100):
    for i in range(max_iter):
        fx0 = f(x0)
        fx1 = f(x1)
        
        if abs(fx1) < eps:
            return x1, i
            
        if fx1 - fx0 == 0:
            return None, i
            
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
        
        x0 = x1
        x1 = x2
        
    return x1, max_iter

x = sp.Symbol('x')

func_str = input("Введіть функцію f(x) (наприклад, x**2 - 2 або sin(x) - 0.5): ")
    
f_expr = sp.sympify(func_str)

df_expr = sp.diff(f_expr, x)
print(f"\nАналітична похідна f'(x) = {df_expr}\n")

f = sp.lambdify(x, f_expr, 'math')
df = sp.lambdify(x, df_expr, 'math')

x0 = float(input("Введіть початкове наближення x0 (для обох методів): "))
x1 = float(input("Введіть друге наближення x1 (для методу січних): "))

print("\n--- Метод Ньютона ---")
root_newton, iters_newton = newton_method(f, df, x0)
print(f"Корінь: {root_newton}, знайдено за {iters_newton} ітерацій")
print("\n--- Метод січних ---")
root_secant, iters_secant = secant_method(f, x0, x1)
print(f"Корінь: {root_secant}, знайдено за {iters_secant} ітерацій")