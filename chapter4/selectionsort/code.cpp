#include <cstdio>
#include <climits>

template<typename T, size_t N>
void selectionSort(T (& arr)[N]) {
    for (int i = 0;i < N;i++) {
        // int min = INT_MAX, pos = i; min很难指定不同类型数据的最大值
        int pos = i;
        for (int j = i;j < N;j++) {
            if (arr[j] < arr[pos]) {
                pos = j;
            } 
        }
        // swap
        T temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main() {
    double arr[] = { 32.1, 21.4, 45.2, 25.3, 66.6, 13.7 };
    int size = sizeof(arr) / (sizeof(double));

    selectionSort(arr);

    for (int i = 0;i < size;i++) {
        printf("%f\n", arr[i]);
    }

    return 0;
}