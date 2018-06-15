#include <cstdio>

void convertToTen(int s, int w) {
    int sum = 0, product = 1;
    while (s != 0) {
        sum += (s % 10) * product;
        product *= w;
        s /= 10;
    }

    printf("十进制为:%d\n", sum);
}

void convertToN(int s, int w) { 
    int c = s;
    int sum = 0, product = 1;

    while (s != 0) {
        sum += (s % w) * product;
        product *= 10;
        s /= w;
    }

    printf("十进制%d的%d进制为: %d", c, w, sum);
}

int main() {

    convertToTen(1011, 2);
    convertToN(11, 2);
    
    return 0;
}