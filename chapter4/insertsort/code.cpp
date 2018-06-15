#include <cstdio>

template<typename T, int N>
void insertSort(T (& arr)[N]) {
    for (int i = 1;i < N;i++) {
        int temp = arr[i], j = i;
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = temp;
    }
} 

int main() {
    double arr[] = { 32.1, 21.4, 45.2, 25.3, 66.6, 13.7 };
    int size = sizeof(arr) / (sizeof(double));

    insertSort(arr);

    for (int i = 0;i < size;i++) {
        printf("%f\n", arr[i]);
    }

    return 0;
}