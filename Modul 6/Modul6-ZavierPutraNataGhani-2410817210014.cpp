#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int acak(int batas) {
    return rand() % batas;
}

void mulai_acak() {
    srand(time(0));
}

void hapusLayar() {
    system("cls");
}

void sequential() {
    hapusLayar();
    int nilai[100];
    int dicari = 20;
    int jumlahKetemu = 0;
    int posisiAkhir = -1;
    mulai_acak();
    cout << "Menghasilkan 100 angka secara acak...\n";
    for (int i = 0; i < 100; i++) {
        nilai[i] = acak(100) + 1;
        cout << nilai[i] << " ";
    }
    cout << "\nSelesai.\n";

    for (int i = 99; i >= 0; i--) {
        if (nilai[i] == dicari) {
            jumlahKetemu++;
            if (posisiAkhir == -1) posisiAkhir = i;
        }
    }

    if (jumlahKetemu > 0) {
        cout << "Data ada, sebanyak " << jumlahKetemu << "!\n";
        cout << "Pada indeks ke=" << posisiAkhir << endl;
    } else {
        cout << "Data tidak ada!\n";
    }
}

void binary() {
    int ukuran, awal, akhir, tengah, sementara, target;
    bool ditemukan = false;

    cout << "Jumlah data: ";
    cin >> ukuran;
    int *data = new int[ukuran];

    for (int i = 0; i < ukuran; i++) {
        cout << "Data ke-[" << i << "]: ";
        cin >> data[i];
    }

    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                sementara = data[j];
                data[j] = data[j + 1];
                data[j + 1] = sementara;
            }
        }
    }

    cout << "========================================\n";
    cout << "Data setelah diurutkan:\n";
    for (int i = 0; i < ukuran; i++) {
        cout << data[i] << " ";
    }
    cout << "\n========================================\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> target;

    awal = 0;
    akhir = ukuran - 1;
    while (awal <= akhir && !ditemukan) {
        tengah = (awal + akhir) / 2;
        if (data[tengah] == target) {
            ditemukan = true;
        } else if (target < data[tengah]) {
            akhir = tengah - 1;
        } else {
            awal = tengah + 1;
        }
    }

    if (ditemukan) {
        cout << "Angka ditemukan pada indeks: " << tengah << "!\n";
    } else {
        cout << "Angka tidak ditemukan!\n";
    }

    delete[] data;
}

void penjelasan() {
    cout << "\n== Sequential Search ==\n";
    cout << "Pencarian dengan memeriksa elemen satu per satu dari awal.\n";
    cout << "Contoh: mencari nama teman di daftar kelas yang belum diurut.\n";
    cout << "Kelebihan:\n- Cocok untuk data acak\n- Mudah digunakan\n";
    cout << "Kekurangan:\n- Tidak efisien jika data banyak\n\n";

    cout << "== Binary Search ==\n";
    cout << "Pencarian dengan membagi data jadi dua bagian setiap langkah.\n";
    cout << "Syarat: data harus terurut\n";
    cout << "Contoh: mencari kata di kamus.\n";
    cout << "Kelebihan:\n- Sangat cepat untuk data besar\n";
    cout << "Kekurangan:\n- Tidak bisa untuk data yang belum urut\n";
}

int main() {
    int pilihan;

    do {
        cout << "Pilih Menu:\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan perbedaan Sequential dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                sequential();
                break;
            case 2:
                binary();
                break;
            case 3:
                penjelasan();
                break;
            case 4:
                cout << "\nTerima Kasih\n";
                cout << "Made by Zavier Ghani." << endl;
                break;
            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        cout << "\n\n";
    } while (pilihan != 4);

    return 0;
}

