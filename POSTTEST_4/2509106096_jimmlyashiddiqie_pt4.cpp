#include <iostream>
using namespace std;

struct Tiket {
    string nama;
    string rute;
};


struct Node {
    Tiket data;
    Node* next;
};


Node *front = NULL, *rear = NULL;

Node *top = NULL;


void enqueue() {
    Node* baru = new Node;

    cout << "Nama penumpang: ";
    cin >> baru->data.nama;
    cout << "Rute: ";
    cin >> baru->data.rute;

    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian!\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }

    Node* hapus = front;

    cout << "Diproses: " << hapus->data.nama
         << " | Rute: " << hapus->data.rute << endl;

    front = front->next;
    if (front == NULL) rear = NULL;


    Node* baru = new Node;
    baru->data = hapus->data;
    baru->next = top;
    top = baru;

    delete hapus;
}



void push(Tiket data) {
    Node* baru = new Node;
    baru->data = data;
    baru->next = top;
    top = baru;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return;
    }

    Node* hapus = top;
    cout << "Dihapus: " << hapus->data.nama << endl;

    top = top->next;
    delete hapus;
}

void peek() {
    if (front != NULL) {
        cout << "Depan Antrian: " << front->data.nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (top != NULL) {
        cout << "Transaksi Terakhir: " << top->data.nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}



void tampilQueue() {
    if (front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    Node* bantu = front;

    while (bantu != NULL) {
        cout << bantu->data.nama << " | "
             << bantu->data.rute << endl;
        bantu = bantu->next;
    }
}


void tampilStack() {
    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    Node* bantu = top;

    while (bantu != NULL) {
        cout << bantu->data.nama << " | "
             << bantu->data.rute << endl;
        bantu = bantu->next;
    }
}



int main() {
    int pilih;

    do {
        cout << "\n=== MENU POSTTEST 4 ===\n";
        cout << "1. Enqueue (Antrian)\n";
        cout << "2. Dequeue (Proses)\n";
        cout << "3. Pop Riwayat\n";
        cout << "4. Peek\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: tampilQueue(); break;
            case 6: tampilStack(); break;
        }

    } while(pilih != 0);

    return 0;
}