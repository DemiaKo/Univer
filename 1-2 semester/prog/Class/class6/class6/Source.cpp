#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int** ar = new int* [5];
	for (int i = 0; i < 5; i++) {
		ar[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ar[i][j] = rand() % 10;
		}
	}
	ofstream fout;
	ifstream fin("text2.txt");
	string d, dd;
	fout.open("text.csv");
	fin >> d;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fout << "dewded, dewdewdew,dewdew,dewe";
		}
		fout << endl;
	}
	fout.close();


	return(0);
}