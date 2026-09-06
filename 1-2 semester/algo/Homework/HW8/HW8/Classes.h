#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class CustomSet {
private:
    T* data;
    size_t sz;
    size_t cap;
    void reallocate(size_t);
public:
    CustomSet() : sz(0), cap(2) { data = new T[cap]; }
    CustomSet(const CustomSet&);
    CustomSet& operator=(const CustomSet&);

    bool contains(const T&) const;
    bool insert(const T&);
    bool erase(const T&);
    size_t size() const { return sz; }

    CustomSet<T> unionWith(const CustomSet<T>&) const;
    CustomSet<T> intersectWith(const CustomSet<T>&) const;
    CustomSet<T> differenceWith(const CustomSet<T>&) const;
    CustomSet<T> xorWith(const CustomSet<T>&) const;

    void print(std::ostream&) const;
    ~CustomSet() { delete[] data; }

    friend std::ostream& operator<<(std::ostream& os, const CustomSet& set) {
        set.print(os);
        return os;
    }
};