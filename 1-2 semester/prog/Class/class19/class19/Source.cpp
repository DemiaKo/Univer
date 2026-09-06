#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	string name;
	int age;
	float mark;
	Student(string n = "", int a = 0, float m = 0) : name(n), age(a), mark(m) {};
};


bool porivn(int a, int b) {
	return a > b;
}


int main() {
	vector<Student> group = { Student("ccc",18,5), Student("aaa",17,3), Student("bbb",16,4) };
	for (auto el : group) {
		cout << el.name << " " << el.age << " " << el.mark << endl;
	}
 
	sort(group.begin(), group.end(), [](Student& a, Student& b) {return a.name > b.name; });
	for (auto el : group) {
		cout << el.name << " " << el.age << " " << el.mark << endl;
	}

	vector<int> v = { 1, -5, 3, 8, 0, 3 };
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	auto it1 = v.begin();
	it1 += 3;

	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	int arr[] = { 1, 6, 3, 0, 9, 2, 7 };
	for (int i = 0; i < 7; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	sort(arr, arr + 7, porivn);

	for (int i = 0; i < 7; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int k = count_if(group.begin(), group.end(), [](Student a) {return a.name == "aaa"; });
	cout << "count " << k << endl;

	auto it2 = find(v.begin(), v.end(), -5);
	if (it2 != v.end()) cout << "-5 yes" << *it2 << endl;

	auto it3 = find_if(v.begin(), v.end(), [](int a) {return a % 2 == 0; });
	if (it3 != v.end()) cout << "yes" << *it3 << endl;
	
	auto it4 = find_if(group.begin(), group.end(), [](Student a) {return a.mark > 4; });
	if (it4 != group.end())
		cout << "yes" << endl;

	auto it5 = find_if_not(v.begin(), v.end(), [](int a) {return a % 2 == 0; });
	if (it5 != v.end())
		cout << "yes" << *it5 << endl;

	vector<int>v2;
	for (int i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	copy(v.begin() + 3, v.end() - 1, back_inserter(v2));
	for (int i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	vector<Student> group2;
	copy_if(group.begin(), group.end(), back_inserter(group2), [](Student& a) {return a.mark >= 4; });
	for (auto el : group2)
	{
		cout << el.name << " " << el.age << " " << el.mark << endl;
	}
}

