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

       