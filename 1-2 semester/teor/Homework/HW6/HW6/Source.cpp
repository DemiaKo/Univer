#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

enum class OpCode { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT };
enum class AddrMode { LITERAL, DIRECT, INDIRECT };

struct Instruction {
    OpCode op;
    AddrMode mode;
    int operand;
};

class RAMMachine {
private:
    vector<Instruction> program;
    map<int, int> memory;
    vector<int> input_tape;
    vector<int> output_tape;
    int pc;
    int input_head;

    int getValue(AddrMode mode, int operand) {
        if (mode == AddrMode::LITERAL) return operand;
        if (mode == AddrMode::DIRECT) return memory[operand];
        if (mode == AddrMode::INDIRECT) return memory[memory[operand]];
        return 0;
    }

    int getAddress(AddrMode mode, int operand) {
        if (mode == AddrMode::DIRECT) return operand;
        if (mode == AddrMode::INDIRECT) return memory[operand];
        throw runtime_error("Недопустимий тип адресації для операції запису");
    }

    string getInstructionString(const Instruction& instr) {
        string opStr;
        switch (instr.op) {
        case OpCode::LOAD:  opStr = "LOAD "; break;
        case OpCode::STORE: opStr = "STORE"; break;
        case OpCode::ADD:   opStr = "ADD  "; break;
        case OpCode::SUB:   opStr = "SUB  "; break;
        case OpCode::MULT:  opStr = "MULT "; break;
        case OpCode::DIV:   opStr = "DIV  "; break;
        case OpCode::READ:  opStr = "READ "; break;
        case OpCode::WRITE: opStr = "WRITE"; break;
        case OpCode::JUMP:  opStr = "JUMP "; break;
        case OpCode::JGTZ:  opStr = "JGTZ "; break;
        case OpCode::JZERO: opStr = "JZERO"; break;
        case OpCode::HALT:  return "HALT";
        }

        string modeStr = "";
        if (instr.mode == AddrMode::LITERAL) modeStr = "=";
        else if (instr.mode == AddrMode::INDIRECT) modeStr = "*";

        return opStr + " " + modeStr + to_string(instr.operand);
    }

public:
    RAMMachine() { reset(); }

    void reset() {
        memory.clear();
        output_tape.clear();
        pc = 0;
        input_head = 0;
        memory[0] = 0;
    }

    void setInput(const vector<int>& in_tape) {
        input_tape = in_tape;
        input_head = 0;
    }

    vector<int> getOutput() const {
        return output_tape;
    }

    void loadProgramFromFile(const string& filename) {
        program.clear();
        ifstream file(filename);

        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл: " + filename);
        }

        string line;
        int lineNum = 0;
        while (getline(file, line)) {
            lineNum++;
            if (line.empty()) continue;

            stringstream ss(line);
            string opStr, argStr;
            ss >> opStr;

            Instruction instr;
            instr.operand = 0;

            if (opStr == "LOAD") instr.op = OpCode::LOAD;
            else if (opStr == "STORE") instr.op = OpCode::STORE;
            else if (opStr == "ADD") instr.op = OpCode::ADD;
            else if (opStr == "SUB") instr.op = OpCode::SUB;
            else if (opStr == "MULT") instr.op = OpCode::MULT;
            else if (opStr == "DIV") instr.op = OpCode::DIV;
            else if (opStr == "READ") instr.op = OpCode::READ;
            else if (opStr == "WRITE") instr.op = OpCode::WRITE;
            else if (opStr == "JUMP") instr.op = OpCode::JUMP;
            else if (opStr == "JGTZ") instr.op = OpCode::JGTZ;
            else if (opStr == "JZERO") instr.op = OpCode::JZERO;
            else if (opStr == "HALT") {
                instr.op = OpCode::HALT;
                instr.mode = AddrMode::LITERAL;
                program.push_back(instr);
                continue;
            }
            else {
                throw runtime_error("Невідома команда '" + opStr + "' на рядку " + to_string(lineNum));
            }

            if (ss >> argStr) {
                if (argStr[0] == '=') {
                    instr.mode = AddrMode::LITERAL;
                    instr.operand = stoi(argStr.substr(1));
                }
                else if (argStr[0] == '*') {
                    instr.mode = AddrMode::INDIRECT;
                    instr.operand = stoi(argStr.substr(1));
                }
                else {
                    instr.mode = AddrMode::DIRECT;
                    instr.operand = stoi(argStr);
                }
            }

            program.push_back(instr);
        }
    }

    void run() {
        pc = 0;
        int step = 0;

        cout << "\n--- ПОЧАТОК ВИКОНАННЯ ---" << endl;

        while (pc >= 0 && pc < program.size()) {
            int current_pc = pc;
            Instruction instr = program[pc];
            int val = 0;

            if (instr.op != OpCode::READ && instr.op != OpCode::JUMP &&
                instr.op != OpCode::JGTZ && instr.op != OpCode::JZERO && instr.op != OpCode::HALT) {
                if (instr.op != OpCode::STORE) val = getValue(instr.mode, instr.operand);
            }

            switch (instr.op) {
            case OpCode::LOAD:  memory[0] = val; pc++; break;
            case OpCode::STORE: memory[getAddress(instr.mode, instr.operand)] = memory[0]; pc++; break;
            case OpCode::ADD:   memory[0] += val; pc++; break;
            case OpCode::SUB:   memory[0] -= val; pc++; break;
            case OpCode::MULT:  memory[0] *= val; pc++; break;
            case OpCode::DIV:
                if (val == 0) throw runtime_error("Ділення на нуль!");
                memory[0] /= val;
                pc++; break;
            case OpCode::READ:
                if (input_head < input_tape.size()) {
                    memory[getAddress(instr.mode, instr.operand)] = input_tape[input_head++];
                }
                else {
                    memory[getAddress(instr.mode, instr.operand)] = 0;
                }
                pc++; break;
            case OpCode::WRITE:
                output_tape.push_back(getValue(instr.mode, instr.operand));
                pc++; break;
            case OpCode::JUMP:  pc = instr.operand; break;
            case OpCode::JGTZ:  if (memory[0] > 0) pc = instr.operand; else pc++; break;
            case OpCode::JZERO: if (memory[0] == 0) pc = instr.operand; else pc++; break;
            case OpCode::HALT:
                cout << "Крок " << ++step << " | PC: " << current_pc << " | " << getInstructionString(instr) << " -> ЗУПИНКА\n";
                return;
            }

            string mem_state = "";
            for (const auto& pair : memory) {
                mem_state += "r" + to_string(pair.first) + "=" + to_string(pair.second) + " ";
            }

            cout << "Крок " << ++step << " | PC: " << current_pc
                << " | " << getInstructionString(instr)
                << "\t | Пам'ять: " << mem_state << endl;
        }
    }
};

vector<int> readArrayFromConsole() {
    vector<int> tape;
    int val;
    cout << "Вводьте числа через пробіл або Enter (введіть 0 для завершення): ";
    while (cin >> val) {
        tape.push_back(val);
        if (val == 0) break;
    }
    return tape;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    RAMMachine ram;
    int choice = -1;

    while (true) {
        cout << "\n===================================" << endl;
        cout << "       ЕМУЛЯТОР РАМ-МАШИНИ       " << endl;
        cout << "===================================" << endl;
        cout << "1. Завдання 2 (n^n)" << endl;
        cout << "2. Завдання 3 (Баланс 1 і 2)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Оберіть опцію: ";

        cin >> choice;

        if (choice == 0) {
            cout << "Завершення роботи..." << endl;
            break;
        }

        if (choice < 1 || choice > 2) {
            cout << "Невідома опція, спробуйте ще раз." << endl;
            continue;
        }

        try {
            ram.reset();

            if (choice == 1) {
                ram.loadProgramFromFile("task2.txt");
                cout << "Введіть число n (наприклад, 4): ";
                int n;
                cin >> n;

                ram.setInput({ n });
                ram.run();

                vector<int> out = ram.getOutput();
                if (!out.empty()) cout << "\nРЕЗУЛЬТАТ: " << n << "^" << n << " = " << out[0] << endl;
            }
            else if (choice == 2) {
                ram.loadProgramFromFile("task3.txt");
                vector<int> inputStr = readArrayFromConsole();

                ram.setInput(inputStr);
                ram.run();

                vector<int> out = ram.getOutput();
                if (!out.empty()) cout << "\nРЕЗУЛЬТАТ (1-допуск, 0-відхилення): " << out[0] << endl;
            }
        }
        catch (const exception& e) {
            cerr << "\nПОМИЛКА: " << e.what() << endl;
        }
    }

    return 0;
}