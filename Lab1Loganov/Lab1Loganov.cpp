
#include "windows.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
using namespace std;

bool pipeExist = false;
bool ksExist = false;


struct Pipe
{
    int length = 0, diameter = 0;
    bool repair;
};
struct KS
{
    string name = "unnamed";
    int AmountAll = 0, AmountWork = 0, Effect = 0;
};





int Number()
{
    int a;
    while (!(cin >> a))
    {

        cout << "Введите число: ";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());




    }
    return a;


}
void InputPipe(Pipe& p) {
    cout << "\nВведите длину трубы: ";
    p.length = Number();
    cout << "\nВведите диаметр трубы: ";
    p.diameter = Number();
    int i;
    do {
        cout << "\nСостояние трубы\nВ ремонте (1)\nНе в ремонте(0)\n";
        i = Number();
        if (i == 1 || i == 0) {
            p.repair = i;
            break;
        }
    } while (true);
    pipeExist = true;


}

void InputKS(KS& q) {
    cout << "\nВведите имя КС: ";
    getline(cin >> ws, q.name);
    cout << "\nКоличество цехов: ";
    q.AmountAll = Number();
    do {
        cout << "\nЦехов в работе: ";
        q.AmountWork = Number();
    } while (q.AmountAll < q.AmountWork);
    cout << "\nВведите эффективность: ";
    q.Effect = Number();
    ksExist = true;

}

void PrintAll(Pipe& p, KS& k) {
    if (pipeExist == true) {
        std::cout << "\nДлина трубы: " << p.length;
        std::cout << "\nДиаметр трубы: " << p.diameter;
        if (p.repair == 1) {
            std::cout << "\nСостояние трубы: в ремонте";
        }
        else if (p.repair == 0) {
            std::cout << "\nСостояние трубы: не в ремонте";
        }
    }
    if (ksExist == true) {
        std::cout << "\nИмя КС: " << k.name;
        std::cout << "\nКоличество цехов: " << k.AmountAll;
        std::cout << "\nЦехов в работе: " << k.AmountWork;
        std::cout << "\nЭффективность: " << k.Effect;

    }




}

void RedactPipe(Pipe& p) {
    int i;
    if (p.repair == 1) {
        std::cout << "\nСостояние трубы: в ремонте";
    }
    else if (p.repair == 0) {
        std::cout << "\nСостояние трубы: не в ремонте";
    }
    do {
        cout << "\nСостояние трубы\nВ ремонте (1)\nНе в ремонте(0)\n";
        i = Number();
        if (i == 1 || i == 0) {
            p.repair = i;
            break;
        }
    } while (true);
}

void RedactKS(KS& k) {

    int choice;
    std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    do {
        std::cout << "\nВыбери действие?\n1. Запустить цех\n2. Остановить цех\n";
        choice = Number();
    } while (choice > 2 || choice <= 0);
    if (choice == 1 && k.AmountAll > k.AmountWork) {
        k.AmountWork += 1;
        std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    }
    else if (choice == 1 && k.AmountAll == k.AmountWork) {
        std::cout << "\nВсе цеха уже запущены";
    }

    else if (choice == 2 && k.AmountWork != 0) {
        k.AmountWork -= 1;
        std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    }
    else if (choice == 2 && k.AmountWork == 0) {
        std::cout << "\nНи один цех не работает";
    }

}

void FileCheck1(Pipe& p) {
    if (p.length == 0 || p.diameter == 0 || (p.repair > 2 || p.repair < 1)) {
        std::cout << "\n!!!Данные трубы не существуют или записаны некорректно";
    }

}

void FileCheck2(KS& k) {
    if (k.name == "unnamed" || k.AmountAll < k.AmountWork) {
        std::cout << "\n!!!Данные КС не существуют или записаны некорректно";
    }

}

void Input(Pipe& p, KS& k) {
    string b;
    int i = 0;
    ifstream fin;
    fin.open("save.txt");
    string tmp;

    fin >> b;
    if (b == "Труба:") {
        fin >> p.length;
        fin >> p.diameter;
        fin >> p.repair;
        fin >> b;

        
            pipeExist = true;
        FileCheck1(p);
    }
    if (b == "КС:") {
        fin >> k.name;
        fin >> k.AmountAll;
        fin >> k.AmountWork;
        fin >> k.Effect;
        ksExist = true;
        FileCheck2(k);
    }

    std::cout << "\nДанные из файла записаны\n";
    fin.close();
}

void Output(Pipe& p, KS& k) {
    ofstream fout("save.txt");

    if (pipeExist) {
        fout << "Труба:\n";
        fout << p.length << "\n";
        fout << p.diameter << "\n";
        fout << p.repair << "\n";

    }
    if (ksExist) {
        fout << "КС:" << "\n";
        fout << k.name << "\n";
        fout << k.AmountAll << "\n";
        fout << k.AmountWork << "\n";
        fout << k.Effect << "\n";




    }

    std::cout << "\nФайл записан\n";
    fout.close();
}

int menu(int choice) {
    std::cout << "\n1. Добавить трубу\n";
    std::cout << "2. Добавить КС\n";
    std::cout << "3. Просмотр всех объектов \n";
    std::cout << "4. Редактировать трубу\n";
    std::cout << "5. Редактировать КС\n";
    std::cout << "6. Ввод с файла\n";
    std::cout << "7. Сохранение в файл\n";
    std::cout << "0. Выход\n";
    cout << "Что ты хочешь сделать? ";
    choice = Number();
    return choice;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice = 0;
    Pipe p;
    KS k;
    while (true)
    {
        switch (menu(choice)) {
        case 1:
            InputPipe(p);
            break;
        case 2:
            InputKS(k);
            break;
        case 3:
            PrintAll(p, k);
            break;
        case 4:
            if (pipeExist == true) {
                RedactPipe(p);
            }
            else {
                cout << "Сначала создайте трубу!";
            }

            break;
        case 5:
            if (ksExist == true) {
                RedactPipe(p);
            }
            else {
                cout << "Сначала создайте КС!";
            }
            break;
        case 6:
            Input(p, k);
            break;
        case 7:
            Output(p, k);
            break;
        case 0:
            exit(0);
            break;
        }
    }


}