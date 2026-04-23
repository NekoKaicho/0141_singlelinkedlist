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

        switch (ch)
        {
            case '1':
                mhs.addNode();
                break;
            
            case '2':
                if (mhs.listEmpty())
                {
                    cout << "\nList Kosong\n";
                    break;
                }

                cout << "\nMasukkan Nomor Mahasiswa yang akan dihapus: ";
                cin >> nim;

                if (mhs.delNode(nim) == false)
                    cout << "\nData tidak ditemukan\n";
                else
                    cout << "\nData dengan Nomor Mahasiswa " << nim << " berhasil dihapus\n";
                break;

            case '3':
                mhs.traverse();
                break;
            
            case '4':
            {
                if (mhs.listEmpty())
                {
                    cout << "\nList Kosong\n";
                    break;
                }

                Node *previous, *current;
                cout << "\nMasukkan Nomor Mahasiswa yang akan dicari: ";
                cin >> nim;

                if (mhs.search(nim, previous, current) == false)
                {
                    cout << "\nData tidak ditemukan\n";
                }
                else
                {
                    cout << "\nData ditemukan\n";
                    cout << "NIM Mahasiswa: " << current->naMhs << endl;
                }
                break;

                if (mhs.search(nim, previous, current) == false)
                {
                    cout << "\nData tidak ditemukan\n";
                }
                else
                {
                    cout << "\nData ditemukan\n";
                    cout << "NIM Mahasiswa: " << current->naMhs << endl;
                }
                break;
            }

            case '5':
                break;

            default:
                cout << "\nPilihan tidak valid\n";
        }
                
    } while (ch != '5');

    return 0;
    
}
