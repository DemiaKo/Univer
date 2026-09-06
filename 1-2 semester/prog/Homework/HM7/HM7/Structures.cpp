#include "Structures.h"

void Student::Input() {
	cin >> name >> age >> av_mark;
}

void Student::Output() const {
	cout << name << " " << age << " " << av_mark << endl;
}

void Worker::Input() {
	cin >> name >> job >> salary >> years;
}
