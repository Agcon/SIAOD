/*
1.	Вычислить значение цифрового корня для некоторого целого числа N.
2.	Найти в двунаправленном списке количество четных элементов.
*/

#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
    int val; // данные
    Node* next, * prev;
};

class List
{
    // Голова, хвост
    Node* Head, * Tail;
    // Количество элементов
    int Count;

public:

    // Конструктор
    List();
    // Конструктор копирования
    List(const List&);
    // Деструктор
    ~List();

    // Удалить весь список
    void DelAll();
    void Del(int pos = 0);
    void Print();
    void AddTail(int n);
    void AddHead(int n);
    int Count_Even();
};

void List::Print()
{
    // Если в списке присутствуют элементы, то пробегаем по нему
    // и печатаем элементы, начиная с головного
    if (Count != 0)
    {
        Node* temp = Head;
        while (temp->next != 0)
        {
            cout << temp->val << ", ";
            temp = temp->next;
        }

        cout << temp->val << endl;
    }
}

int List::Count_Even()
{
    int counter = 0;
    Node* p = Head;
    while (p->next !=0)
    {
        if (p->val % 2 == 0) counter++;
        p = p->next;
    }
    return counter;
}

void List::Del(int pos)
{
    // если параметр отсутствует или равен 0, то запрашиваем его
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return;
    }

    // Счетчик
    int i = 1;

    Node* Del = Head;

    while (i < pos)
    {
        // Доходим до элемента, 
        // который удаляется
        Del = Del->next;
        i++;
    }

    // Доходим до элемента, 
    // который предшествует удаляемому
    Node* PrevDel = Del->prev;
    // Доходим до элемента, который следует за удаляемым
    Node* AfterDel = Del->next;

    // Если удаляем не голову
    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    // Если удаляем не хвост
    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    // Удаляются крайние?
    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    // Удаление элемента
    delete Del;

    Count--;
}

void List::AddHead(int n)
{
    // новый элемент
    Node* temp = new Node;

    // Предыдущего нет
    temp->prev = 0;
    // Заполняем данные
    temp->val = n;
    // Следующий - бывшая голова
    temp->next = Head;

    // Если элементы есть?
    if (Head != 0)
        Head->prev = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - головной
        Head = temp;

    Count++;
}

void List::AddTail(int n)
{
    // Создаем новый элемент
    Node* temp = new Node;
    // Следующего нет
    temp->next = 0;
    // Заполняем данные
    temp->val = n;
    // Предыдущий - бывший хвост
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != 0)
        Tail->next = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - хвостовой
        Tail = temp;

    Count++;
}

void List::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (Count != 0)
        Del(1);
}

List::~List()
{
    // Удаляем все элементы
    DelAll();
}

List::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    // Голова списка, из которого копируем
    Node* temp = L.Head;
    // Пока не конец списка
    while (temp != 0)
    {
        // Передираем данные
        AddTail(temp->val);
        temp = temp->next;
    }
}

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

int digital_root(int n)
{
    if (n / 10 == 0) return n;
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return digital_root(s);
}

int random_generator()
{
    srand(time(0));
    return -1000 + rand() % 10000;

}

void random_list(List &L, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            L.AddHead(-1000 + rand() % 10000);
        else
            L.AddTail(-1000 + rand() % 10000);
}

int main()
{
    setlocale(LC_ALL, "");
    int x = random_generator();
    cout << x << " Digital root: " << digital_root(x) << endl;
    List L;
    int n = 20;
    random_list(L, n);
    L.Print();
    cout << L.Count_Even() << endl;
    system("pause");
    return 0;
}
