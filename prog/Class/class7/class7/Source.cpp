#include "structures.h"

int main() {
	Decart x(3, 4);
	Polar y = x.toPolar();
	y.Output();

	return(0);
}