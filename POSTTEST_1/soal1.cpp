#include <iostream>
using namespace std;

/*
Analisis Kompleksitas FindMin

Pseudocode Cost      Tmin      Tmax
-------------------------------------
1  min = A[0]        C1        1         1
2  for i=1 to n-1    C2        n         n
3  if A[i] < min     C3        n-1       n-1
4  min = A[i]        C4        0         n-1
5  return min        C5        1         1
--------------------------------------------

Best Case (data sudah minimum di awal):
Tmin(n) = C1 + C2n + C3(n-1) + 0 + C5
        = (C2 + C3)n + konstanta
        = O(n)

Worst Case (data selalu lebih kecil dari sebelumnya):
Tmax(n) = C1 + C2n + C3(n-1) + C4(n-1) + C5
        = (C2 + C3 + C4)n + konstanta
        = O(n)

Kesimpulan:
Best Case  = O(n)
Worst Case = O(n)
*/

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);

    cout << "Nilai Minimum : " << minimum << endl;
    cout << "Indeks Minimum : " << indexMin << endl;

    return 0;
}