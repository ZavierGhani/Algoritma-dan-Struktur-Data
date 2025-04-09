#include <iostream>
using namespace std;

struct Mahasiswa {
    char nama[50];
    char nim[20];
    char jurusan[30];
    int sks;
    int program; 

int main() {
    const int jumlahMhs = 2;
    Mahasiswa bayar[jumlahMhs];

    for (int i = 0; i < jumlahMhs; i++) {
        int sppTetap, sppVariabel;

        cout << "\n\n------------------------------\n";
        cout << "Input Data Mahasiswa ke-" << (i + 1) << "\n";
        cout << "------------------------------\n";

        cout << "Nama Mahasiswa        : ";
        cin.ignore(); 
        cin.getline(bayar[i].nama, 50);

        cout << "NIM                   : ";
        cin.getline(bayar[i].nim, 20);

        cout << "Jurusan [TI / PTK]    : ";
        cin.getline(bayar[i].jurusan, 30);

        do {
            cout << "Program [1 = D3, 2 = S1] : ";
            cin >> bayar[i].program;
            if (bayar[i].program != 1 && bayar[i].program != 2) {
                cout << "Program tidak sesuai. Silakan input ulang.\n";
            }
        } while (bayar[i].program != 1 && bayar[i].program != 2);

        cout << "Jumlah SKS            : ";
        cin >> bayar[i].sks;

        if (bayar[i].program == 1) {
            sppTetap = 500000;
            sppVariabel = bayar[i].sks * 25000;
        } else {
            sppTetap = 750000;
            sppVariabel = bayar[i].sks * 50000;
        }

        cout << "\n------------------------------\n";
        cout << "Output Data Mahasiswa ke-" << (i + 1) << "\n";
        cout << "------------------------------\n";
        cout << "Nama Mahasiswa        : " << bayar[i].nama << "\n";
        cout << "NIM                   : " << bayar[i].nim << "\n";
        cout << "Jurusan               : " << bayar[i].jurusan << "\n";
        cout << "Program               : " << (bayar[i].program == 1 ? "D3" : "S1") << "\n";
        cout << "Jumlah SKS            : " << bayar[i].sks << "\n";
        cout << "SPP Tetap             : Rp " << sppTetap << "\n";
        cout << "SPP Variabel          : Rp " << sppVariabel << "\n";
        cout << "Total Pembayaran      : Rp " << sppTetap + sppVariabel << "\n\n";
    }

    return 0;
}

