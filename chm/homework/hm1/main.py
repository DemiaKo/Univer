import random

def generate_diagonally_dominant_system(n_vars):
    system = []
    for i in range(n_vars):
        row = []
        sum_of_other_elements = 0
        
        for j in range(n_vars):
            if i == j:
                row.append(0)
            else:
                val = random.choice([x for x in range(-10, 11) if x != 0])
                row.append(val)
                sum_of_other_elements += abs(val)
                
        diag_val = sum_of_other_elements + random.randint(1, 10)
        
        row[i] = diag_val * random.choice([-1, 1])
        
        free_member = random.randint(-50, 50)
        row.append(free_member)
        
        system.append(row)
        
    return system

def print_system(a):
    print("Згенерована система рівнянь:")
    n = len(a)
    for row in a:
        eq_str = ""
        for j in range(n):
            val = row[j]
            if j == 0:
                eq_str += f"{val:>4}*x{j+1}"
            else:
                sign = "+" if val >= 0 else "-"
                eq_str += f" {sign} {abs(val):>2}*x{j+1}"
                
        eq_str += f" = {row[-1]:>4}"
        print(eq_str)
    print("-" * 40)

def gauss_seidel_precision(a, eps=0.0001, max_iterations=1000):
    n = len(a)
    x = [0.0] * n 
    
    for step in range(max_iterations):
        x_old = x.copy()
        
        for i in range(n):
            s = sum(a[i][j] * x[j] for j in range(n) if j != i)
            x[i] = (a[i][-1] - s) / a[i][i]
            
        max_diff = max(abs(x[i] - x_old[i]) for i in range(n))
        
        formatted_x = [f"{val:8.5f}" for val in x]
        print(f"Ітерація {step + 1:2}: x = [{', '.join(formatted_x)}] | Похибка = {max_diff:.6f}")
        
        if max_diff <= eps:
            print(f"\n✅ Задану точність ({eps}) досягнуто на ітерації {step + 1}.")
            return x
            
    print(f"\n⚠️ Метод не зійшовся за {max_iterations} ітерацій.")
    return x 

random_system = [[3, 1, 5], [1, 2, 5]]

print_system(random_system)

gauss_seidel_precision(random_system, eps=0.0001)