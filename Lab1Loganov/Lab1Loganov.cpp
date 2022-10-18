#include "windows.h"
#include <iostream>
#include <string>
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
    return a;
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
    std::cout << "\nСостояние трубы: " << p.repair;
    std::cout << "\nИмя КС: " << k.name;
    std::cout << "\nКоличество цехов: " << k.AmountAll;
    std::cout << "\nЦехов в работе: " << k.AmountWork;
    std::cout << "\nЭффективность: " << k.Effect;

}

void RedactPipe(Pipe &p) {
    int i = 0;
    std::cout << "\nТекущее состояние трубы: " << p.repair;
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
    if (choice == 1 && k.AmountAll>k.AmountWork) {
        k.AmountWork += 1;
    }
    else if (count == 2) {
        InputKS(k);
    }
}

int menu(int choice) {
    Pipe q;
    std::cout << "\n1. Добавить трубу\n";
    std::cout << "2. Добавить КС\n";
    std::cout << "3. Просмотр всех объектов \n";
    std::cout << "4. Редактировать трубу\n";
    std::cout << "5. Редактировать КС\n";
    cout << "Что ты хочешь сделать? ";
    choice = Number(choice);
    return choice;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice = 0;
    int count = 0;
    std::cout << "Hello World!\n";
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
            CheckAll(p, k);
        }

    }


}

