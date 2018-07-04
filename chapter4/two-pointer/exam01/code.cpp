#include <cstdio>

// 找到一个有序递增数组中两个不同位置的数相加等于8
int main() {
    int a[] = { 1, 2, 3, 4, 5, 6 };
    int i = 0, j = 5;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == 8) {
            printf("%d %d\n", a[i], a[j]);
            i++;
            j--;
        } else if (sum > 8) {
            j--;
        } else {
            i++;
        }
    } 
    return 0;
}