import numpy as np


class Matrix:
    def __init__(self, data):
        if isinstance(data, int):
            self.ar = np.zeros((data, data), dtype=int)
        else:
            self.ar = np.matr

    def __add__(self, n):
        return self.ar + n.ar

    def __sub__(self, n):
        return self.ar - n.ar

    def __mul__(self, n):
        return self.ar * n.ar

    def __div__(self, n):
        return self.ar / n.ar

    def __str__(self):
        return str(self.ar.tolist())


m = [[1, 2], [3, 4]]
mm = Matrix(m)
mmm = Matrix([[1,2],[2,3]])
print(mm)
mm += mmm
print(mm)
mm -= mmm
print(mm)