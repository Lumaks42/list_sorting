// persort.cpp 
// сортировка объкктов через массив указателей на них

#include <iostream>
#include <string>
using namespace std;

class person                        // некоторый человек
{
protected:
    string name;                    // имя 
public:
    void setName()                  // установка имени
        {cout << "Enter name: "; cin >> name; }
    void printName()                // показ имени
        {cout << endl << name;}
    string getName()                // получение имени
        {return name;}
};

int main()
{
    void bsort(person**, int);      // прототип функции
    person* persPtr[100];           // массив указателей на prerson
    int a = 0;                      // кол-во элементов в массиве
    char choice;                    // переменная для ввода символа

    do 
    {
        persPtr[a] = new person;    // создаю новый объект
        persPtr[a]->setName();      // ввожу имя
        a++;                        // увеличиваю кол-во
        cout << "y/n?";             // спрашиваю, закончен ли ввод
        cin >> choice;
    } while (choice == 'y');
    cout << "\nunsorted list:";
    for (int j = 0; j < a; j++)     // покажу неотсортированный список
        persPtr[j]->printName();
    cout << endl;

    bsort(persPtr, a);              // отрисую указатели

    cout << "\nsorted list:";
    for (int j = 0; j < a; j++)     // покажу отсортированный список
        persPtr[j]->printName();
    cout << endl;
    return 0;
}

void bsort(person** pp, int a)
{
    void order(person**, person**); // прототип функции
    int j, k;                       // переменные для циклов

    for (j = 0; j < a - 1; j++)     // внешний цикл
        for (k = j + 1; k < a; k++) // внутрений цикл
            order(pp + j, pp + k);  // сортируем два элемента
}

void order(person** pp1, person** pp2)
{
    if ((*pp1)->getName() > (*pp2)->getName())           // если первая строка больше второй 
    {
        person* tempptr = *pp1;                          // меняем местами 
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}