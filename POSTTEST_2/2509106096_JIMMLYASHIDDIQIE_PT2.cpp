#include <iostream>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

const int MAX = 100;
int jumlah = 0;

void swapData(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr) {
    if(jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA KERETA ===\n";
    for(int i = 0; i < jumlah; i++) {
        cout << "No: " << (arr+i)->nomor
             << " | Nama: " << (arr+i)->nama
             << " | Rute: " << (arr+i)->asal << " -> " << (arr+i)->tujuan
             << " | Harga: " << (arr+i)->harga << endl;
    }
}

void tambah(Kereta *arr, int &jumlah) {
    cout << "\n=== Tambah Data ===\n";
    cout << "Nomor: "; cin >> (arr+jumlah)->nomor;
    cout << "Nama: "; cin >> (arr+jumlah)->nama;
    cout << "Asal: "; cin >> (arr+jumlah)->asal;
    cout << "Tujuan: "; cin >> (arr+jumlah)->tujuan;
    cout << "Harga: "; cin >> (arr+jumlah)->harga;
    jumlah++;
}

void linearSearch(Kereta *arr) {
    string asal, tujuan;
    cout << "Cari Asal: "; cin >> asal;
    cout << "Cari Tujuan: "; cin >> tujuan;

    for(int i = 0; i < jumlah; i++) {
        cout << "Cek index " << i << endl;
        if((arr+i)->asal == asal && (arr+i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr+i)->nama << endl;
            return;
        }
    }
    cout << "Tidak ditemukan\n";
}

void sortNomor(Kereta *arr) {
    for(int i=0;i<jumlah-1;i++) {
        int minIdx = i;
        for(int j=i+1;j<jumlah;j++) {
            if((arr+j)->nomor < (arr+minIdx)->nomor)
                minIdx = j;
        }
        swapData(arr+i, arr+minIdx);
    }
}

void jumpSearch(Kereta *arr) {
    if(jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    sortNomor(arr); 

    int key;
    cout << "Masukkan nomor kereta: ";
    cin >> key;

    int step = sqrt(jumlah);
    int prev = 0;

    while((arr + min(step, jumlah)-1)->nomor < key) {
        cout << "Loncat ke index " << step << endl;
        prev = step;
        step += sqrt(jumlah);
        if(prev >= jumlah) {
            cout << "Tidak ditemukan\n";
            return;
        }
    }

    for(int i = prev; i < min(step, jumlah); i++) {
        cout << "Cek index " << i << endl;
        if((arr+i)->nomor == key) {
            cout << "Ditemukan: " << (arr+i)->nama << endl;
            return;
        }
    }

    cout << "Tidak ditemukan\n";
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[50], R[50];

    for(int i=0;i<n1;i++) L[i] = *(arr+l+i);
    for(int j=0;j<n2;j++) R[j] = *(arr+m+1+j);

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        if(L[i].nama <= R[j].nama)
            *(arr+k++) = L[i++];
        else
            *(arr+k++) = R[j++];
    }

    while(i<n1) *(arr+k++) = L[i++];
    while(j<n2) *(arr+k++) = R[j++];
}

void mergeSort(Kereta *arr, int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void selectionSort(Kereta *arr) {
    for(int i=0;i<jumlah-1;i++) {
        int minIdx = i;
        for(int j=i+1;j<jumlah;j++) {
            if((arr+j)->harga < (arr+minIdx)->harga)
                minIdx = j;
        }
        swapData(arr+i, arr+minIdx);
    }
}

int main() {
    Kereta data[MAX];
    int pilih;

    do {
        cout << "\n=== MENU KERETA API ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Linear Search (Rute)\n";
        cout << "4. Jump Search (Nomor)\n";
        cout << "5. Merge Sort (Nama A-Z)\n";
        cout << "6. Selection Sort (Harga Termurah)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampil(data); break;
            case 2: tambah(data, jumlah); break;
            case 3: linearSearch(data); break;
            case 4: jumpSearch(data); break;
            case 5: mergeSort(data,0,jumlah-1); cout << "Data diurutkan!\n"; break;
            case 6: selectionSort(data); cout << "Data diurutkan!\n"; break;
        }
    } while(pilih != 0);

    return 0;
}