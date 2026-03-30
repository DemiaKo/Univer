#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class SparseMatrix {
public:
	struct Node;
private:
	int scols;
	int srows;
	Node* rows;
	Node* cols;
	Node* get_p_r(int, int) const;
	Node* get_p_c(int, int) const;
	void clear();
	void initEmpty(int, int);
	void checkBounds(int, int) const;
public:
	struct Node {
		Node* up = nullptr;
		Node* left = nullptr;
		int row{};
		int col{};
		T value{};
	};
	SparseMatrix(int r = 2, int c = 2) : scols(c), srows(r) { initEmpty(srows, scols); }
	SparseMatrix(const SparseMatrix&);
	SparseMatrix& operator=(const SparseMatrix&);
	class SM {
	private:
		SparseMatrix& matrix;
		int r;
		int c;
	public:
		SM(SparseMatrix& m, int row, int col = -1): matrix(m), r(row), c(col) {}
		SM operator[](int col) { return SM(matrix, r, col); }
		SM& operator=(const T& v) { matrix.set(r, c, v); return *this; }
		operator T() const { return matrix.get(r, c); }
		friend std::ostream& operator<<(std::ostream& os, const SM& proxy) {
			os << proxy.matrix.get(proxy.r, proxy.c);
			return os;
		}
		friend std::istream& operator>>(std::istream& is, SM m) {
			T temp;
			is >> temp;
			m.matrix.set(m.r, m.c, temp);
			return is;
		}
	};
	SM operator[](int r) { return SM(*this, r); }
	void set(int, int, T);
	T get(int, int) const;
	friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<T>& m) {
		for (int i = 0; i < m.srows; i++) {
			for (int j = 0; j < m.scols; j++) {
				os << m.get(i, j) << "\t";
			}
			os << "\n";
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, SparseMatrix<T>& m) {
		m.clear();
		m.initEmpty(m.srows, m.scols);

		for (int i = 0; i < m.srows; i++) {
			for (int j = 0; j < m.scols; j++) {
				T temp;
				is >> temp;
				if (temp != T{}) {
					m.set(i, j, temp);
				}
			}
		}
		return is;
	}
	~SparseMatrix() { clear(); }
};

