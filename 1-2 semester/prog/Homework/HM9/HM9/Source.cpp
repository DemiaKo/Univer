#include "Classes.h"

int main() {
    Processor myCpu("Intel Core i7-13700K", 16, 5.2);
    VideoCard myGpu("NVIDIA GeForce RTX 4070", 12);

    Computer myPc("Asus ROG", myCpu, myGpu);

    cout << myPc;

    myPc.edit();

    cout << myPc;

    Computer myPc2("New PC");
    cout << myPc2;

    return 0;
}