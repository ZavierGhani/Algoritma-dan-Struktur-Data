#include <iostream>
using namespace std;

struct kendaraan {
    string plat;
    string jenis;
    string pemilik;
    string alamat;
    string kota;
};

int main() {
    kendaraan data;

    data.plat = "DA1234MK";
    data.jenis = "RUSH";
    data.pemilik = "Andika Hartanto";
    data.alamat = "Jl. Kayu Tangi 1";
    data.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan : " << data.plat << endl;
    cout << "Jenis Kendaraan : " << data.jenis << endl;
    cout << "Nama Pemilik : " << data.pemilik << endl;
    cout << "Alamat : " << data.alamat << endl;
    cout << "Kota : " << data.kota << endl;

    return 0;
}
