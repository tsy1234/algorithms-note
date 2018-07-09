#include <cstdio>
#include <algorithm>

void to_array(int n, int num[4]) {
    for (int i = 0;i < 4;i++) {
        int temp = n % 10;
        n /= 10;
        num[i] = temp;
    }
}

int to_num(int num[4]) {
    int n = 0;
    for (int i = 3;i >= 0;i--) {
        n *= 10;        
        n += num[i];
    }
    return n;
}

// 按非增序排列
bool cmp(int a, int b) {
    return a >= b ? true : false;
}

int main() {
    int n = 0;
    int num[4] = { 0 };
    scanf("%d", &n);
    while (1) {
        to_array(n, num);
        std::sort(num, num + 4);
        int max = to_num(num);
        std::sort(num, num + 4, cmp);
        int min = to_num(num);
        
        n = max - min;
        printf("%04d - %04d = %04d\n", max, min, n);
        if (n == 0 || n == 6174) break;
    }

    return 0;
}