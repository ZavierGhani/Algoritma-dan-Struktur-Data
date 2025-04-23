#include <iostream>
using namespace std;

const int maks = 5;

struct Stack {
    int data[maks];
    int atas;
};

Stack Tumpuk;

// Mengecek apakah stack kosong
int kosong() {
    return Tumpuk.atas == -1 ? 1 : 0;
}

// Mengecek apakah stack penuh
int penuh() {
    return Tumpuk.atas == maks - 1 ? 1 : 0;
}

// Menambahkan data ke stack
void input(int data) {
    if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack" << endl;
    } else {
        cout << "Tumpukan Penuh" << endl;
    }
}

// Menghapus data dari stack
void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil : " << Tumpuk.data[Tumpuk.atas] << endl;
        Tumpuk.atas--;
    } else {
        cout << "Tumpukan Kosong" << endl;
    }
}

// Menampilkan isi stack
void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong" << endl;
    }
}

int main() {
    Tumpuk.atas = -1;
    int pilihan, nilai;

    do {
       cout << "\n  STACK MENU\n";
        cout << "====================\n";
        cout << "1. PUSH (Masukkan Data)\n";
        cout << "2. POP (Hapus Data Teratas)\n";
        cout << "3. TAMPIL (Lihat Isi Stack)\n";
        cout << "4. KELUAR\n";
        cout << "PILIHAN : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Data: ";
                cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}
