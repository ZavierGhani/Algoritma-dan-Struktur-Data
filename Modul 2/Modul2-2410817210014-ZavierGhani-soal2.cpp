#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define n 10

// Deklarasi
char Q[n]; // Queue
int F, R;  // Front dan Rer
char HURUF;
int PIL;

// Inisialisasi qeue kosong
void Inisialisasi() {
    F = R = -1;
}

// Fungsi untuk mengecek apakah Queue penuh
bool isFull() {
    return R == n - 1;
}

// Fungsi untuk mengecek apakah Queue kosong
bool isEmpty() {
    return (F == -1 || F > R);
}

// Menambahkan data ke Queue,push
void INSERT() {
    if (isFull()) {
        cout << "Queue Penuh!" << endl;
    } else {
        cout << "Masukkan huruf: ";
        cin >> HURUF;
        if (isEmpty()) {
            F = R = 0;
        } else {
            R++;
        }
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " dimasukkan ke Queue." << endl;
    }
}

// Menghapus elemen dari Queue,pop
void DELETE() {
    if (isEmpty()) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Huruf " << Q[F] << " dihapus dari Queue." << endl;
        F++;
        if (F > R) {
            Inisialisasi();
        }
    }
}

// Menampilkann isi Queue
void CETAKLAYAR() {
    if (isEmpty()) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Inisialisasi();

    do {
        cout << "QUEUE MENU" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> PIL;

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

        if (PIL != 4) {
            cout << "\npress any key to continue...";
            getch();
            system("cls");
        }

    } while (PIL != 4);

    return 0;
}
