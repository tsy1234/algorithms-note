// 快速排序代码
#include <cstdio>
#include <cstdlib>
#include <ctime>

template <class T>
class QuickSort {
public:
    void quickSort(T [], int, int);
};

template <class T>
void QuickSort<T>::quickSort(T arr[], int left, int right) {
    if (left >= right) return ;
    int l = left, r = right;
    int temp = arr[l];
    
    while (l < r) {
        while (l < r && temp <= arr[r]) r--;
        arr[l] = arr[r];
        while (l < r && temp > arr[l]) l++;
        arr[r] = arr[l]; 
    }
    arr[l] = temp;
    quickSort(arr, left, l - 1);
    quickSort(arr, l + 1, right);


}

int main() {
    int a[13] = { 2, 34, 11, 22, 14, 56, 6, 71, 4, 36, 19, 27, 53 };
    QuickSort<int> q;
    q.quickSort(a, 0, 12);
    for (int i = 0;i < 13;i++) {
        printf("%d\n", a[i]);
    }
    // srand(unsigned(time(0)));
    // printf("%d\n", rand() % 5 + 4);    
    // printf("%d\n", rand() % 5 + 4);    

    return 0;
}