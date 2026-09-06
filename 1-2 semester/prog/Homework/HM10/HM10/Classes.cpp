#include "Classes.h"

void Processor::print(ostream& os) const {
    os << "  [CPU] Модель: " << model
        << " | Ядра: " << cores
        << " | Частота: " << frequency << " GHz\n";
}

void Processor::edit() {
    cout << "=========Процесор==========\n";
    cout << "Введіть модель: ";
    getline(cin >> ws, model);
    cout << "Введіль кількість ядер: ";
    cin >> cores;
    cout << "Введіть частоту: ";
    cin >> frequency;
}

void VideoCard::print(ostream& os) const {
    os << "  [GPU] Модель: " << model
        << " | VRAM: " << memory << " GB\n";
}

void VideoCard::edit() {
    cout << "=========Відеокарта==========\n";
    cout << "Введіть модель: ";
    getline(cin >> ws, model);
    cout << "Введіть пам'ять: ";
    cin >> memory;
}


void Computer::print(ostream& os) const {
    cpu.print(os);
    gpu.print(os);
}

void Computer::edit() {
    cout << "=========PC==========\n";
    cout << "Введіть бренд: ";
    getline(cin >> ws, brand);
    cout << endl;
    cpu.edit();
    cout << endl;
    gpu.edit();
    cout << endl;
}

ostream& operator<<(ostream& os, Computer& pc) {
    pc.print(os);
    return(os);
}

int fromFile(ifstream& f, Computer**& ar) {
    delete[] ar;
    int n; f >> n;
    ar = new Computer * [n];
    for (int i = 0; i < n; i++) {
        char type; f >> type;
        switch (type)
        {
            case'L' :{
                string br;
                getline(f >> ws, br, '|');
                string pr;
                getline(f >> ws, pr, '|');
                int c; f >> c;
                int fr; f >> fr;
                string v;
                getline(f >> ws, v, '|');
                int mem; f >> mem;
                int b; f >> b;
                ar[i] = new Laptop(br, Processor(pr, c, fr), VideoCard(v, mem), b);
                break;
            }
            case'D': {
                string br;
                getline(f >> ws, br, '|');
                string pr;
                getline(f >> ws, pr, '|');
                int c; f >> c;
                int fr; f >> fr;
                string v;
                getline(f >> ws, v, '|');
                int mem; f >> mem;
                string fo;
                getline(f >> ws, fo);
                ar[i] = new Desktop(br, Processor(pr, c, fr), VideoCard(v, mem), fo);
                break;
            }
        default:
            break;
        }
    }
    return(n);
}

void Laptop::print(ostream& os) const {
	os << "--- Характеристики Ноутбука " << brand << "--- \n";
	Computer::print(os);
	os << "Ємність батареї: " << battery << " mAh\n";
}

void Laptop::edit() {
    Computer::edit();
    cout << "=========Ноутбук==========\n";
    cout << "Введіть ємність батареї: ";
    cin >> battery;
    cout << endl;
}

void Desktop::print(ostream& os) const {
	os << "--- Характеристики Комп'ютера "<< brand << " --- \n";
	Computer::print(os);
	os << "Форм-фактор корпусу: " << formFactor << "\n";
}

void Desktop::edit() {
    Computer::edit();
    cout << "=========Комп'ютер==========\n";
    cout << "Введіть формфактор: ";
    getline(cin >> ws, formFactor);
    cout << endl;
}