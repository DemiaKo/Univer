#include "Classes.h"

int Table::hash(std::string key) const {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) sum += (int)key[i];
    return(sum % size);
}

void Table::resize() {
    int old_size = size;
    size *= 2;

    Cell** new_cells = new Cell * [size];
    for (int i = 0; i < size; i++) {
        new_cells[i] = nullptr;
    }

    for (int i = 0; i < old_size; i++) {
        Cell* cur = cells[i];

        while (cur != nullptr) {
            Cell* next_cell = cur->next;
            int new_ind = hash(cur->key);
            cur->next = new_cells[new_ind];
            new_cells[new_ind] = cur;
            cur = next_cell;
        }
    }

    delete[] cells;
    cells = new_cells;
}

Table::Table(const Table& other) {
    size = other.size;
    real_size = other.real_size;

    cells = new Cell * [size];

    for (int i = 0; i < size; ++i) {
        cells[i] = nullptr;
        Cell* otherCur = other.cells[i];
        Cell* tail = nullptr;

        while (otherCur != nullptr) {
            Cell* newCell = new Cell;
            newCell->key = otherCur->key;
            newCell->value = otherCur->value;
            newCell->next = nullptr;

            if (cells[i] == nullptr) {
                cells[i] = newCell;
                tail = newCell;
            }
            else {
                tail->next = newCell;
                tail = newCell;
            }

            otherCur = otherCur->next;
        }
    }
}

Table& Table::operator=(const Table& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < size; i++) {
        Cell* cur = cells[i];
        while (cur != nullptr) {
            Cell* del = cur;
            cur = cur->next;
            delete del;
        }
    }
    delete[] cells;

    size = other.size;
    real_size = other.real_size;
    cells = new Cell * [size];

    for (int i = 0; i < size; ++i) {
        cells[i] = nullptr;
        Cell* otherCur = other.cells[i];
        Cell* tail = nullptr;

        while (otherCur != nullptr) {
            Cell* newCell = new Cell;
            newCell->key = otherCur->key;
            newCell->value = otherCur->value;
            newCell->next = nullptr;

            if (cells[i] == nullptr) {
                cells[i] = newCell;
                tail = newCell;
            }
            else {
                tail->next = newCell;
                tail = newCell;
            }
            otherCur = otherCur->next;
        }
    }

    return *this;
}

void Table::insert(std::string key, int val) {
    int ind = hash(key);
    Cell* cur = cells[ind];

    while (cur != nullptr) {
        if (cur->key == key) {
            cur->value = val;
            return;
        }
        cur = cur->next;
    }

    Cell* newCell = new Cell;
    newCell->key = key;
    newCell->value = val;

    newCell->next = cells[ind];
    cells[ind] = newCell;

    real_size++;

    if (real_size > size * 0.75) {
        resize();
    }
}

int Table::get(std::string key) const {
    int ind = hash(key);
    Cell* cur = cells[ind];

    while (cur != nullptr) {
        if (cur->key == key) {
            return cur->value;
        }
        cur = cur->next;
    }

    throw std::out_of_range("Помилка: Ключ '" + key + "' не знайдено в таблиці");
}

void Table::remove(std::string key) {
    int ind = hash(key);
    Cell* cur = cells[ind];
    Cell* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            if (prev == nullptr) {
                cells[ind] = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            delete cur;
            real_size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    throw std::out_of_range("Помилка видалення: Ключ '" + key + "' не існує");
}

int& Table::operator[](std::string key) {
    int ind = hash(key);
    Cell* cur = cells[ind];

    while (cur != nullptr) {
        if (cur->key == key) {
            return cur->value;
        }
        cur = cur->next;
    }

    insert(key, 0);
    ind = hash(key);

    return cells[ind]->value;
}

void Table::print(std::ostream& os) const {
    for (int i = 0; i < size; i++) {
        Cell* cur = cells[i];
        while (cur != nullptr) {
            os << "Key: " << cur->key << ", value: " << cur->value << std::endl;
            cur = cur->next;
        }
    }
}

Table::~Table() {
    for (int i = 0; i < size; i++) {
        Cell* cur = cells[i];
        while (cur != nullptr) {
            Cell* del = cur;
            cur = cur->next;
            delete del;
        }
    }
    delete[] cells;
}

std::ostream& operator<<(std::ostream& os, const Table& t) {
    t.print(os);
    return(os);
}
