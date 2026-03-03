#include <iostream>
using namespace std;

void swapNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "\nSebelum swap:";
    cout << "\nx = " << x;
    cout << "\ny = " << y;

    swapNilai(x, y);

    cout << "\n\nSetelah swap:";
    cout << "\nx = " << x;
    cout << "\ny = " << y << endl;

    return 0;
}