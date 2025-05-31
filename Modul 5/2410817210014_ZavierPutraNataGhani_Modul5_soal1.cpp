#include <iostream>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;
using namespace std::chrono;

void tampilkanData(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}


int filterHuruf(const string& s, char arr[]) {
    int index = 0;
    for (char c : s) {
        if (isalpha(c)) {
            arr[index++] = c;
        }
    }
    return index;
}


int stringToDigitChars(const string& s, char arr[]) {
    int index = 0;
    for (char c : s) {
        if (isdigit(c)) {
            arr[index++] = c;
        }
    }
    return index;
}

// Insertion Sort
void insertionSort(char arr[], int size) {
    for (int i = 1; i < size; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// Bubble Sort
void bubbleSort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

//Selection Sort
void selectionSort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//Shell Sort
void shellSort(char arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// QuickSort
int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(char arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(char arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    string nama = "Zavier Putra Nata Ghani";
    string nim = "2410817210014";
    int pilihan;

    char dataBefore[50], dataAfter[50];
    int sizeBefore;

    do {
        cout << "\n========================\n";
        cout << "==== MENU SORTING ======\n";
        cout << "========================\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Bubble Sort (NIM)\n";
        cout << "5. Quick Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Keluar\n";
        cout << "========================\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        high_resolution_clock::time_point start, end;

        switch (pilihan) {
            case 1:
                cout << "Sebelum: " << nama << endl;
                sizeBefore = filterHuruf(nama, dataBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                insertionSort(dataAfter, sizeBefore);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 2:
                cout << "Sebelum: " << nama << endl;
                sizeBefore = filterHuruf(nama, dataBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                mergeSort(dataAfter, 0, sizeBefore - 1);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 3:
                cout << "Sebelum: " << nama << endl;
                sizeBefore = filterHuruf(nama, dataBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                shellSort(dataAfter, sizeBefore);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 4:
                sizeBefore = stringToDigitChars(nim, dataBefore);
                cout << "Sebelum: "; tampilkanData(dataBefore, sizeBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                bubbleSort(dataAfter, sizeBefore);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 5:
                sizeBefore = stringToDigitChars(nim, dataBefore);
                cout << "Sebelum: "; tampilkanData(dataBefore, sizeBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                quickSort(dataAfter, 0, sizeBefore - 1);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 6:
                sizeBefore = stringToDigitChars(nim, dataBefore);
                cout << "Sebelum: "; tampilkanData(dataBefore, sizeBefore);
                for (int i = 0; i < sizeBefore; i++) dataAfter[i] = dataBefore[i];

                start = high_resolution_clock::now();
                selectionSort(dataAfter, sizeBefore);
                end = high_resolution_clock::now();

                cout << "Sesudah: "; tampilkanData(dataAfter, sizeBefore);
                cout << "Waktu eksekusi: "
                     << duration_cast<microseconds>(end - start).count()
                     << " mikrodetik\n";
                break;

            case 7:
                cout << "Program selesai. Terima kasih sudah menggunakan program sorting ini! \n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}
