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