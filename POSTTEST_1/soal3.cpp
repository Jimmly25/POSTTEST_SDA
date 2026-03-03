#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int data[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array Sebelum Dibalik:\n";
    int* p = data;
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << *p << ", Alamat: " << p << endl;
        p++;
    }

    reverseArray(data, 7);

    cout << "\nArray Setelah Dibalik:\n";
    p = data;
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << *p << ", Alamat: " << p << endl;
        p++;
    }

    return 0;
}