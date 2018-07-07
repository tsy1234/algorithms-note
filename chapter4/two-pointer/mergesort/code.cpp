// 归并排序的递归实现
#include <cstdio>

template <class T>
class MergeSort {
public:
    void mergeSort(T arr[], int, int);
    
    void noRecSort(T arr[], int, int);
private:
    void merge(T arr[], int, int, int);
};

template <class T>
void MergeSort<T>::mergeSort(T arr[], int left, int right) {
    int mid = (left + right) / 2;
    if (left >= right) return ;
    // printf("%d %d\n", left, right);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 归并的非递归实现，循环实现
template <class T>
void MergeSort<T>::noRecSort(T arr[], int left, int right) {
    int n = right - left + 1;
    for (int step = 2;step / 2 <= n;step *= 2){
        for (int i = 0;i <= right;i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

template <class T> 
void MergeSort<T>::merge(T arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, index = 0;
    int temp[100];
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[index] = arr[i];
            i++;
        } else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    while (i <= mid) {
        temp[index] = arr[i];
        index++;
        i++;
    }

    while (j <= right) {
        temp[index] = arr[j];
        index++;
        j++;
    }

    for (int i = 0;i < index;i++) {
        arr[left + i] = temp[i];
    }
}

int main() {
    int a[13] = { 2, 34, 11, 22, 14, 56, 6, 71, 4, 36, 19, 27, 53 };
    MergeSort<int> m;
    m.noRecSort(a, 0, 12);
    for (int i = 0;i < 13;i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}