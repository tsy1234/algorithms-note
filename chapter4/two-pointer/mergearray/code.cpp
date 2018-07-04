#include <cstdio>

int merge(int a[], int b[], int c[], int n, int m) {
    int p1 = 0 , p2 = 0;
    int index = 0;
    while (p1 < n && p2 < m) {
        if (a[p1] <= b[p2]) {
            c[index] = a[p1];
            p1++;
        } else {
            c[index] = b[p2];
            p2++;
        }
        index++;
    }

    while (p1 < n) {
        c[index] = a[p1];
        index++;
        p1++;
    }

    while (p2 < m) {
        c[index] = b[p2];
        index++;
        p2++;
    }
    return index;
}

int main() {
    int a[] = { 3, 4, 12, 23, 24, 27 };
    int b[] = { 2, 4, 7, 19, 21, 26, 33};
    int c[20];
    int len = merge(a, b, c, 6, 7);
    for (int i = 0;i < len;i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}