#include "Classes.h"
#include <string>

template <typename T>
void CustomSet<T>::reallocate(size_t new_cap) {
    T* new_data = new T[new_cap];
    for (size_t i = 0; i < sz; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    cap = new_cap;
}

template<typename T>
CustomSet<T>::CustomSet(const CustomSet& other) {
    this->sz = other.sz;
    this->cap = other.cap;
    data = new T[cap];
    for (size_t i = 0; i < sz; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
CustomSet<T>& CustomSet<T>::operator=(const CustomSet& other) {
    if (this != &other) {
        delete[] data;
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
bool CustomSet<T>::contains(const T& val) const {
    for (size_t i = 0; i < sz; ++i) {
        if (data[i] == val) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool CustomSet<T>::insert(const T& val) {
    if (contains(val)) {
        return false;
    }
    if (sz == cap) {
        reallocate(cap * 2);
    }
    data[sz] = val;
    sz++;
    return true;
}

template<typename T>
bool CustomSet<T>::erase(const T& val) {
    for (size_t i = 0; i < sz; ++i) {
        if (data[i] == val) {
            data[i] = data[sz - 1];
            sz--;
            return true;
        }
    }
    throw std::invalid_argument("Елемент не знайдено у множині!");
}

template<typename T>
CustomSet<T> CustomSet<T>::unionWith(const CustomSet<T>& other) const {
    CustomSet<T> result(*this);
    for (size_t i = 0; i < other.sz; ++i) {
        result.insert(other.data[i]);
    }
    return result;
}

template<typename T>
CustomSet<T> CustomSet<T>::intersectWith(const CustomSet<T>& other) const {
    CustomSet<T> result;
    for (size_t i = 0; i < sz; ++i) {
        if (other.contains(data[i])) {
            result.insert(data[i]);
        }
    }
    return result;
}

template<typename T>
CustomSet<T> CustomSet<T>::differenceWith(const CustomSet<T>& other) const {
    CustomSet<T> result;
    for (size_t i = 0; i < sz; ++i) {
        if (!other.contains(data[i])) {
            result.insert(data[i]);
        }
    }
    return result;
}

template<typename T>
CustomSet<T> CustomSet<T>::xorWith(const CustomSet<T>& other) const {
    CustomSet<T> diff1 = this->differenceWith(other);
    CustomSet<T> diff2 = other.differenceWith(*this);
    return diff1.unionWith(diff2);
}

template<typename T>
void CustomSet<T>::print(std::ostream& os) const {
    os << "{ ";
    for (size_t i = 0; i < sz; ++i) {
        os << data[i];
        if (i < sz - 1) os << ", ";
    }
    os << " }\n";
}

template class CustomSet<int>;
template class CustomSet<char>;
template class CustomSet<double>;
template class CustomSet<std::string>;