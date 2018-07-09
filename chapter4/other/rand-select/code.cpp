#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>

template <typename T, int N>
int randPartition(T (& arr)[N], int left, int right) {
    int seed = rand() % (right - left) + left;
    printf("right: %d, left: %d, seed: %d\n", right, left, seed);
    // printf("seed: %d\n", seed);
    std::swap(arr[seed], arr[left]);
    int temp = arr[left];
    // printf("fuck: %d\n", seed);
    int l = left, r = right;
    while (l < r) {
        while (arr[r] > temp && l < r) r--;
        arr[l] = arr[r]; 
        while (arr[l] <= temp && l < r) l++;
        arr[r] = arr[l];
    }
    arr[l] = temp;
    return l;
}

template<typename T, int N>
int randSelect(T (& arr)[N], int left, int right, int k) {
    if (left == right) return arr[left];
    int pos = randPartition(arr, left, right);
    int m = pos - left + 1;
    if (m < k) {
        return randSelect(arr, pos + 1, right, k - m);
    } else if (m > k) {
        return randSelect(arr, left, pos - 1, k);
    } else {
        return arr[pos];
    }
}

int main() {
    srand(unsigned(time(0)));

    int a[13] = { 2, 34, 11, 22, 14, 56, 6, 71, 4, 36, 19, 27, 53 };
    int ans = randSelect(a, 0, 12, 2);
    printf("%d\n", ans);
    return 0;
}
