#include "Class.h"

Table::Table(const Table& other)
{
    this->rows = other.rows;
    this->cols = other.cols;
    this->ar = new float[this->rows * this->cols];
    for (int i = 0; i < rows * cols; i++)
        this->ar[i] = other.ar[i];
}

Table::Tb Table::operator[](int r)
{
    if (r < 0 || r >= rows) {
        throw std::out_of_range("Out of rows");
    }
    int rr = r * cols;
    return Table::Tb(ar, rr, cols);
}

void Table::clear()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ar[i*cols+j] = 0;
        }
    }
}

void Table::print(std::ostream& os) const
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            os << ar[i * cols + j] << " ";
        }
        os << std::endl;
    }
}

void Table::input(std::istream& is)
{   
    for (int i = 0; i < rows * cols; i++) {
        is >> ar[i];
    }
}

void Table::resize(int r, int c)
{
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Negative or zero argum");
    }
    float* a = new float[r * c];
    for (int i = 0; i < rows && i < r; i++) {
        for (int j = 0; j < cols && j < c; j++) {
            a[i * c + j] = ar[i * cols + j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = cols; j < c; j++) {
            a[i * c + j] = 0;
        }
    }
    for (int i = rows; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i * c + j] = 0;
        }
    }
    delete[] ar;
    ar = a;
    rows = r;
    cols = c;
}

Table& Table::operator=(const Table& other)
{
    if (this == &other) return *this;
    delete[] this->ar;
    this->rows = other.rows;
    this->cols = other.cols;
    this->ar = new float[this->rows * this->cols];
    for (int i = 0; i < rows * cols; i++)
        this->ar[i] = other.ar[i];
    return *this;
}

float& Table::Tb::operator[](int col)
{
    if (col < 0 || col >= co) {
        throw std::out_of_range("Out of cols");
    }
    return a[ro+col];
}

std::ostream& operator<<(std::ostream& os, const Table& t)
{
    t.print(os);
    return(os);
}

std::istream& operator>>(std::istream& is, Table& t)
{
    t.input(is);
    return(is);
}
