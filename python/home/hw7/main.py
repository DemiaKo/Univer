import numpy as np
import time
   
def timer(func):
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        result = func(*args, **kwargs)
        end = time.perf_counter()
        print(f"Час виконання {func.__name__}: {end - start:.6f} сек")
        return result
    return wrapper

class Matrix:
    def __init__(self, data):
        self.data = np.array(data, dtype=float)
        self._iter_index = 0

    @classmethod
    def from_input(cls):
        print(f"\nВведення матриці")
        rows = int(input("Кількість рядків: "))
        cols = int(input("Кількість стовпців: "))

        print(f"Введіть {rows} рядків по {cols} чисел через пробіл:")
        matrix_data = []
        for i in range(rows):
            while True:
                row = list(map(float, input(f"Рядок {i + 1}: ").strip().split()))
                if len(row) != cols:
                    print(f"Очікується {cols} елементів. Спробуйте ще раз.")
                    continue
                matrix_data.append(row)
                break
        return cls(matrix_data)
    
    def __add__(self, other):
        return Matrix(self.data + other.data)

    def __sub__(self, other):
        return Matrix(self.data - other.data)

    def __mul__(self, other):
        return Matrix(self.data @ other.data)

    def __invert__(self):
        return Matrix(self.data.T)
    
    def __iter__(self):
        self._iter_index = 0
        return self

    def __next__(self):
        if self._iter_index < self.data.size:
            val = self.data.flat[self._iter_index]
            self._iter_index += 1
            return val
        raise StopIteration

    def __str__(self):
        return str(self.data)


def spiral_traverse(matrix):
    m = matrix.data.copy()
    while m.size > 0:
        for x in m[0]:
            yield x.item()
        m = m[1:]
        if m.size == 0: break

        for x in m[:, -1]:
            yield x.item()
        m = m[:, :-1]
        if m.size == 0: break

        for x in m[-1][::-1]:
            yield x.item()
        m = m[:-1]
        if m.size == 0: break

        for x in m[::-1, 0]:
            yield x.item()
        m = m[:, 1:]


@timer
def inverse_matrix(matrix):
    return Matrix(np.linalg.inv(matrix.data))

@timer
def solve_linear_system(a, b):
    return Matrix(np.linalg.solve(a.data, b.data))

@timer
def find_eigen(matrix):
    eigenvalues, eigenvectors = np.linalg.eig(matrix.data)
    return eigenvalues, Matrix(eigenvectors)

@timer
def matrix_norm(matrix):
    return np.linalg.norm(matrix.data)

A = Matrix.from_input()

while True:
    print("\nДоступні операції:")
    print("1. Додавання (A + B)")
    print("2. Віднімання (A - B)")
    print("3. Множення (A * B)")
    print("4. Транспонування (~A)")
    print("5. Обернена матриця")
    print("6. Розв'язання СЛАР (A * x = b)")
    print("7. Власні значення та вектори")
    print("8. Норма матриці")
    print("9. Послідовний обхід (ітератор)")
    print("10. Спіральний обхід (генератор)")
    print("0. Вихід")
    
    choice = input("\nОберіть дію: ")
    if choice == '1':
        B = Matrix.from_input()
        print("Результат:\n", A + B)
    elif choice == '2':
        B = Matrix.from_input()
        print("Результат:\n", A - B)
    elif choice == '3':
        B = Matrix.from_input()
        print("Результат:\n", A * B)
    elif choice == '4':
        print("Результат:\n", ~A)
    elif choice == '5':
        print("Результат:\n", inverse_matrix(A))
    elif choice == '6':
        print("Для рівняння A * x = b потрібно ввести вектор-стовпець b.")
        b = Matrix.from_input()
        print("Вектор x:\n", solve_linear_system(A, b))
    elif choice == '7':
        vals, vecs = find_eigen(A)
        print(f"Власні значення: {vals}")
        print(f"Власні вектори:\n{vecs}")
    elif choice == '8':
        print(f"Норма: {matrix_norm(A):.4f}")
    elif choice == '9':
        print("Елементи послідовно:", [x.item() for x in A])
    elif choice == '10':
        print("Спіральний обхід:", list(spiral_traverse(A)))
    elif choice == '0':
        print("Вихід з програми.")
        break
    else:
        print("Невідома команда.")