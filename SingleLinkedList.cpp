#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int naMhs;
    Node *next;
};

class LinkedList
{
    Node *START;
public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node();
        nodeBaru->naMhs = nim;

        if (START == NULL || nim <= START ->naMhs)
        {
            if (START != NULL && nim == START->naMhs)
            {
                cout << "\nDuplikasi naMhs tidak diijinkan\n";
                return;
            }
        
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while (current != NULL && nim > current->naMhs)
        {
            if (nim == current->naMhs)
            {
                cout << "\nDuplikasi naMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current)
    {
        previous = START;
        current = START;

        while (current != NULL && nim != current->naMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!search(nim, previous, current))
            return false;

        if (current == START)
            START = START->next;
            
        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData di dalam list adalah:\n";
            Node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->naMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

    