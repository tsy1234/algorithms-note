#include <cstdio>

typedef long long LL;

LL binaryPower(LL a, int n, LL m) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 != 0) {
        return  a * binaryPower(a, n - 1, m) % m;
    } else {
        LL mul = binaryPower(a, n / 2, m);
        return mul * mul % m;
    }
} 

int main() {
    LL a, m;
    int b;
    
    scanf("%lld%lld", &a, &m);
    scanf("%d", &b);
    printf("%.2lld\n", binaryPower(a, b, m));
    return 0;
}