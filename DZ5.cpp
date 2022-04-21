/*
Дан линейный однонаправленный список L
1)	Разработать функцию, которая создает из значений узлов списка L два новых списка: L1 – из положительных элементов массива L; L2 – из остальных элементов списка L.
2)	Разработать функцию, которая удаляет из списка L2 все отрицательные элементы.
3)	Разработать функцию, которая в списке L1 узел с максимальным значением размещает перед первым узлом.
*/

#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (first == nullptr)
        {
            first = p;
            last = p;
            return;
        }
        last -> next = p;
        last = p;
    }

    void print() {
        if (first == nullptr) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p -> next;
        }
        cout << endl;
    }

    int size() 
    {
        Node* p = first;
        int k = 0;
        while (p != nullptr)
        {
            k ++;
            p = p->next;
        }
        return k;
    }

    void move_to_first(int element)
    {
        if (first->val == element) return;
        Node* p = new Node(element);
        p->next = first;
        first = p;
    }

    void del_elements(int element) //удаление по значению элемента
    {
        if (first->val == element)
        {
            Node* temp = first;
            first = first->next;
            delete temp;
            return;
        }
        else if (last->val == element) {
            Node* p = first;
            while (p->next != last)
            {
                p = p->next;
            }
            delete last;
            p->next = nullptr;
            last = p;
            return;
        }
        Node* p1 = first;
        Node* p2 = p1->next;
        while (p2->val != element)
        {
            p1 = p1->next;
            p2 = p1->next;
        }
        p1->next = p2->next;
        delete p2;
    }
};

void del_negative_L2(list& L2) //удаление отрицательных значений
{
    int elem, leng = L2.size();
    Node* p = L2.first;
    for (int i = 0; i < leng; i++)
    {
        elem = p->val;
        p = p->next;
        if (elem < 0) L2.del_elements(elem);
        if (p == nullptr) break;       
    }
}

void createLists(list L, list& L1, list& L2) // заполнение списков L1 и L2
{
    Node* p = L.first;
    while (p)
    {
        if (p->val > 0) L1.push_back(p->val);
        else L2.push_back(p->val);
        p = p->next;
    }
}

void random_generator(list &l, int n)
{
    srand(time(0));
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1000 + rand() % 10000;
        l.push_back(x);
    }
}

void replace_max(list &L)
{
    Node* p = L.first;
    int mx = 0;
    for (int i = 0; i < L.size(); i++)
    {
        if (p->val > mx) mx = p->val;
        p = p->next;
    }
    if (mx == 0) return;
    L.move_to_first(mx);
}

int main()
{
	setlocale(LC_ALL, "");
	list L, L1, L2;
    int n = 20;
    random_generator(L, n);
    L.push_back(0);
    createLists(L, L1, L2);
    L.print();
    L1.print();
    L2.print();
    del_negative_L2(L2);
    L2.print();
    replace_max(L1);
    L1.print();
	system("pause");
	return 0;
}
