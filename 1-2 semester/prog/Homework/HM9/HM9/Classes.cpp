#include "Classes.h"

void Processor::print(ostream& os) const {
    os << "  [CPU] Model: " << model
        << " | Cores: " << cores
        << " | Frequency: " << frequency << " GHz\n";
}

void Processor::edit() {
    cout << "=========Processor==========\n";
    cout << "Input model: "; 
    getline(cin >> ws, model);
    cout << "Input cores: ";
    cin >> cores;
    cout << "Input frequency: ";
    cin >> frequency;
}

void VideoCard::print(ostream& os) const {
    os << "  [GPU] Model: " << model
        << " | VRAM: " << memory << " GB\n";
}

void VideoCard::edit() {
    cout << "=========VideoCard==========\n";
    cout << "Input model: ";
    getline(cin >> ws, model);
    cout << "Input memory: ";
    cin >> memory;
}


void Computer::print(ostream& os) const {
    os << "=== " << brand << " specs ===\n";
    cpu.print(os);
    gpu.print(os);
    os << "=========================================\n\n";
}

void Computer::edit() {
    cout << "=========PC==========\n";
    cout << "Input brand: ";
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

ostream& operator<<(ostream& os, VideoCard& gp) {
    gp.print(os);
    return(os);
}

ostream& operator<<(ostream& os, Processor& cp) {
    cp.print(os);
    return(os);
}