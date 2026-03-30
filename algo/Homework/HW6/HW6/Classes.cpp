#include "Classes.h"
#include <string>

template<typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix& other) {
	scols = other.scols;
	srows = other.srows;
	initEmpty(srows, scols);
	for (int i = 0; i < srows; i++) {
		Node* curr = other.rows[i].left;
		while (curr != &other.rows[i]) {
			this->set(curr->row, curr->col, curr->value);
			curr = curr->left;
		}
	}
}

template<typename T>
SparseMatrix<T>& SparseMatrix<T>::operator=(const SparseMatrix& other) {
	if (this == &other) {
		return *this;
	}
	clear();

	srows = other.srows;
	scols = other.scols;
	initEmpty(srows, scols);
	for (int i = 0; i < srows; i++) {
		Node* curr = other.rows[i].left;
		while (curr != &other.rows[i]) {
			this->set(curr->row, curr->col, curr->value);
			curr = curr->left;
		}
	}
	return *this;
}

template <typename T>
void SparseMatrix<T>::set(int r, int c, T v) {
	checkBounds(r, c);
	Node* pr = get_p_r(r, c);
	Node* pc = get_p_c(r, c);
	if (pr->left == pc->up) {
		pr->left->value = v;
	}
	else {
		Node* node = new Node;
		node->row = r;
		node->col = c;
		node->value = v;
		node->left = pr->left;
		pr->left = node;
		node->up = pc->up;
		pc->up = node;
	}
}

template <typename T>
T SparseMatrix<T>::get(int r, int c) const {
	checkBounds(r, c);
	Node* pr = get_p_r(r, c);
	Node* pc = get_p_c(r, c);

	if (pc->up == pr->left) {
		return pc->up->value;
	}
	return T{};
}

template <typename T>
void SparseMatrix<T>::checkBounds(int r, int c) const {
	if (r < 0 || r >= srows || c < 0 || c >= scols) {
		throw std::out_of_range("Помилка: Індекс виходить за межі матриці!");
	}
}

template <typename T>
typename SparseMatrix<T>::Node* SparseMatrix<T>::get_p_r(int i, int j) const {
	Node* p = &this->rows[i];
	while (true) {
		if (p->left->col <= j) return p;
		p = p->left;
	}
}

template <typename T>
typename SparseMatrix<T>::Node* SparseMatrix<T>::get_p_c(int i, int j) const {
	Node* p = &this->cols[j];
	while (true) {
		if (p->up->row <= i) return p;
		p = p->up;
	}
}

template<typename T>
void SparseMatrix<T>::clear() {
	for (int i = 0; i < srows; i++) {
		Node* curr = rows[i].left;
		while (curr != &rows[i]) {
			Node* next = curr->left;
			delete curr;
			curr = next;
		}
	}
	delete[] rows;
	delete[] cols;
}

template<typename T>
void SparseMatrix<T>::initEmpty(int r, int c) {
	if (r <= 0 || c <= 0) {
		throw std::invalid_argument("Помилка: Розміри матриці мають бути більшими за 0!");
	}
	rows = new Node[r];
	cols = new Node[c];
	for (int i = 0; i < r; i++) {
		rows[i].left = &rows[i];
		rows[i].col = -1;
	}
	for (int i = 0; i < c; i++) {
		cols[i].up = &cols[i];
		cols[i].row = -1;
	}
}

template class SparseMatrix<int>;
template class SparseMatrix<double>;
template class SparseMatrix<std::string>;