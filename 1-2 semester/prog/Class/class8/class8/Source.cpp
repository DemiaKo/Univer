#include <iostream>

struct list
{
	int data;
	list* next;
};

int main() {
	list* l = new list;
	l->data = 1;
	l->next = new list;
	l->next->data = 2;
	l->next->next = nullptr;
	while (l) {
		std::cout << l->data << std::endl;
		l = l->next;
	}
}