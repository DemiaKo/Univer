import matplotlib.pyplot as plt

def solve_gauss(A, B):
    n = len(B)
    
    for i in range(n):
        max_el = abs(A[i][i])
        max_row = i
        for k in range(i + 1, n):
            if abs(A[k][i]) > max_el:
                max_el = abs(A[k][i])
                max_row = k
                
        A[i], A[max_row] = A[max_row], A[i]
        B[i], B[max_row] = B[max_row], B[i]
        
        for k in range(i + 1, n):
            factor = -A[k][i] / A[i][i]
            for j in range(i, n):
                if i == j:
                    A[k][j] = 0
                else:
                    A[k][j] += factor * A[i][j]
            B[k] += factor * B[i]
            
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = B[i] / A[i][i]
        for k in range(i - 1, -1, -1):
            B[k] -= A[k][i] * x[i]
            
    return x

def build_spline(x_nodes, y_nodes):
    n = len(x_nodes) - 1
    num_vars = 4 * n
    
    A = [[0.0] * num_vars for _ in range(num_vars)]
    B = [0.0] * num_vars
    
    row = 0 
    
    for i in range(n):
        idx_a = 4 * i
        A[row][idx_a] = 1.0
        B[row] = y_nodes[i]
        row += 1
        
    for i in range(n):
        h = x_nodes[i+1] - x_nodes[i]
        idx_a = 4 * i
        
        A[row][idx_a] = 1.0
        A[row][idx_a + 1] = h
        A[row][idx_a + 2] = h**2
        A[row][idx_a + 3] = h**3
        B[row] = y_nodes[i+1]
        row += 1
        
    for i in range(n - 1):
        h = x_nodes[i+1] - x_nodes[i]
        idx_b_curr = 4 * i + 1
        idx_b_next = 4 * (i + 1) + 1
        
        A[row][idx_b_curr] = 1.0
        A[row][idx_b_curr + 1] = 2.0 * h
        A[row][idx_b_curr + 2] = 3.0 * (h**2)
        A[row][idx_b_next] = -1.0
        B[row] = 0.0
        row += 1
        
    for i in range(n - 1):
        h = x_nodes[i+1] - x_nodes[i]
        idx_c_curr = 4 * i + 2
        idx_c_next = 4 * (i + 1) + 2
        
        A[row][idx_c_curr] = 2.0
        A[row][idx_c_curr + 1] = 6.0 * h
        A[row][idx_c_next] = -2.0
        B[row] = 0.0
        row += 1
        
    A[row][2] = 2.0
    B[row] = 0.0
    row += 1
    
    h_last = x_nodes[-1] - x_nodes[-2]
    idx_c_last = 4 * (n - 1) + 2
    
    A[row][idx_c_last] = 2.0
    A[row][idx_c_last + 1] = 6.0 * h_last
    B[row] = 0.0
    
    coeffs_flat = solve_gauss(A, B)
    
    a = [coeffs_flat[4*i] for i in range(n)]
    b = [coeffs_flat[4*i + 1] for i in range(n)]
    c = [coeffs_flat[4*i + 2] for i in range(n)]
    d = [coeffs_flat[4*i + 3] for i in range(n)]
    
    return a, b, c, d, x_nodes

def evaluate_spline(val, coeffs):
    a, b, c, d, x = coeffs
    n = len(x) - 1
    
    idx = 0
    for i in range(n):
        if x[i] <= val <= x[i+1]:
            idx = i
            break
    else:
        if val < x[0]: idx = 0
        elif val > x[-1]: idx = n - 1

    dx = val - x[idx]
    return a[idx] + b[idx] * dx + c[idx] * (dx**2) + d[idx] * (dx**3)

x_nodes = [-2, -1, 0, 1, 1.5, 2, 3]
y_nodes = [3, 1, 1, 2, 3, 1, 4]

spline_coeffs = build_spline(x_nodes, y_nodes)
print(spline_coeffs)

num_points = 100
step = (x_nodes[-1] - x_nodes[0]) / (num_points - 1)
x_smooth = [x_nodes[0] + i * step for i in range(num_points)]
y_smooth = [evaluate_spline(xi, spline_coeffs) for xi in x_smooth]

plt.figure(figsize=(8, 5))
plt.plot(x_nodes, y_nodes, 'ro', label='Вузли')
plt.plot(x_smooth, y_smooth, 'b-', label='Кубічний сплайн')
plt.title('Кубічний сплайн')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.grid(True)
plt.show()