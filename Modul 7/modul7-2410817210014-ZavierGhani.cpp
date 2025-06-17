#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int dataBaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = dataBaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
        cout << "Data bertambah" << endl;
    } else if (dataBaru < (*root)->data) {
        tambah(&(*root)->kiri, dataBaru);
    } else if (dataBaru > (*root)->data) {
        tambah(&(*root)->kanan, dataBaru);
    } else {
        cout << "Data sudah ada" << endl;
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    int pil, data;
    Node *pohon = NULL;
    do {
        system("cls");
        cout << "1. Tambah\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "\nPilihan : ";
        cin >> pil;
        switch (pil) {
            case 1:
                cout << "\nINPUT DATA\n-----------\n";
                cout << "Data baru : ";
                cin >> data;
                tambah(&pohon, data);
                break;
            case 2:
                cout << "\nPreOrder\n-------------------------\n";
                if (pohon != NULL)
                    preOrder(pohon);
                else
                    cout << "Masih Kosong";
                cout << endl;
                break;
            case 3:
                cout << "\nInOrder\n-------------------------\n";
                if (pohon != NULL)
                    inOrder(pohon);
                else
                    cout << "Masih Kosong";
                cout << endl;
                break;
            case 4:
                cout << "\nPostOrder\n-------------------------\n";
                if (pohon != NULL)
                    postOrder(pohon);
                else
                    cout << "Masih Kosong";
                cout << endl;
                break;
            case 5:
                return 0;
        }
        cout << "\n\nTekan ENTER untuk melanjutkan...";
        cin.ignore();
        cin.get();
    } while (pil != 5);
    return 0;
}
