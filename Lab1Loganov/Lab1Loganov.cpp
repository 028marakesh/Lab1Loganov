#include "windows.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;



struct Pipe
{
    int length=0 , diameter=0;
    int repair =0;
};
struct KS
{
    string name="unnamed";
    int AmountAll=0, AmountWork=0, Effect=0;
};





int Number(int a)
{
    while (!(cin >> a))
    {
        cout << "Введите число: ";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    return abs(a);
}
void InputPipe(Pipe &p) {
    
    int i=0;
    cout << "\nВведите длину трубы: ";
    p.length = Number(i);
    cout << "\nВведите диаметр трубы: ";
    p.diameter = Number(i);

    do {
        cout << "\nСостояние трубы\n1. В ремонте\n2. Не в ремонте\n";
        p.repair = Number(i);
    } while (p.repair > 2 || p.repair <= 0);
    
    
}

void InputKS(KS &q) {
    
    int i = 0;
    cout << "\nВведите имя КС: ";
    cin >> q.name;
    cout << "\nКоличество цехов: ";
    q.AmountAll = Number(i);
    do {
        cout << "\nЦехов в работе: ";
        q.AmountWork = Number(i);
    } while (q.AmountAll <= q.AmountWork);
    cout << "\nВведите эффективность: ";
    q.Effect = Number(i);
   
}

void CheckAll(Pipe &p, KS &k) {
   
    std::cout << "\nДлина трубы: " << p.length;
    std::cout << "\nДиаметр трубы: " << p.diameter;
    if (p.repair == 1) {
        std::cout << "\nСостояние трубы: в ремонте";
    }
    else if (p.repair == 2) {
        std::cout << "\nСостояние трубы: не в ремонте";
    }
    
    std::cout << "\nИмя КС: " << k.name;
    std::cout << "\nКоличество цехов: " << k.AmountAll;
    std::cout << "\nЦехов в работе: " << k.AmountWork;
    std::cout << "\nЭффективность: " << k.Effect;

}

void RedactPipe(Pipe &p) {
    int i = 0;
    if (p.repair == 1) {
        std::cout << "\nСостояние трубы: в ремонте";
    }
    else if (p.repair == 2) {
        std::cout << "\nСостояние трубы: не в ремонте";
    }
    do {
    std::cout << "\nНа что меняем?\n1. В ремонте\n2. Не в ремонте\n";
    p.repair = Number(i);
    } while (p.repair > 2 || p.repair <= 0);
}

void RedactKS(KS& k) {
    int i = 0;
    int choice;
    std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    do {
        std::cout << "\nВыбери действие?\n1. Запустить цех\n2. Остановить цех\n";
        choice = Number(i);
    } while (choice > 2 || choice <= 0);
    if (choice == 1 && k.AmountAll > k.AmountWork) {
        k.AmountWork += 1;
        std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    }
    else if (choice == 1 && k.AmountAll == k.AmountWork) {
        std::cout << "\nВсе цеха уже запущены";
    }

    else if (choice == 2 && k.AmountWork!=0) {
        k.AmountWork -= 1;
        std::cout << "\nЦехов в работе: " << k.AmountWork << " из " << k.AmountAll;
    }
    else if (choice == 2 && k.AmountWork == 0) {
        std::cout << "\nНи один цех не работает";
    }

}

void FileCheck1(Pipe& p) {
    if (p.length == 0 || p.diameter == 0 || (p.repair>2 || p.repair<1)) {
        std::cout << "\n!!!Данные трубы из файла записаны некорректно\n Исправьте данные в файле или создайте трубу через консоль";
    }

}

void FileCheck2(KS& k) {
    if (k.name == "unnamed" || k.AmountAll < k.AmountWork) {
        std::cout << "\n!!!Данные КС из файла записаны некорректно\n Исправьте данные в файле или создайте КС через консоль";
    }

}

void Input(Pipe& p, KS& k) {
    int i = 0;
    ifstream fin("input.txt");
    fin >> p.length>> p.diameter>> p.repair;
    FileCheck1(p);
    fin >> k.name >> k.AmountAll >> k.AmountWork >> k.Effect;
    FileCheck2(k);
    std::cout << "\nДанные из файла записаны\n";
    fin.close();
}

void Output(Pipe& p, KS& k) {
    ofstream fout("output.txt");
    fout << "\nДлина трубы: " << p.length;
    fout << "\nДиаметр трубы: " << p.diameter;
    if (p.repair == 1) {
        fout << "\nСостояние трубы: в ремонте";
    }
    else if (p.repair == 2) {
        fout << "\nСостояние трубы: не в ремонте";
    }
    fout << "\nИмя КС: " << k.name;
    fout << "\nКоличество цехов: " << k.AmountAll;
    fout << "\nЦехов в работе: " << k.AmountWork;
    fout << "\nЭффективность: " << k.Effect;
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
    std::cout << "8. Выход\n";
    cout << "Что ты хочешь сделать? ";
    choice = Number(choice);
    return choice;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice = 0;
    int count = 0;
    Pipe p;
    KS k;
    while (true)
    {
        count = menu(choice);
        if (count == 1) {
            InputPipe(p);
        }
        else if (count == 2) {
            InputKS(k);
        }
        else if (count == 3) {
            CheckAll(p,k);
        }
        else if (count == 4) {
            RedactPipe(p);
        }
        else if (count == 5) {
            RedactKS(k);
        }
        else if (count == 6) {
            Input(p,k);
        }
        else if (count == 7) {
            Output(p,k);
        }
        else if (count == 8) {
            exit(0);
        }

    }


}

