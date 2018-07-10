// PAT 1059
#include <cstdio>
#include <cmath>

struct factor {
    int num;
    int time;
} fac[30];

bool p[100010] = { 0 };
long int prime[100010];
long int nPrime = 0;

int n = 0;

void findPrime(long int num) {
    int end = sqrt(num);
    for (int i = 2;i <= end;i++) {
        if (p[i] == false) {
            for (int j =  2 * i;j <= end;j += i) {
                p[j] = true;
            }
            prime[nPrime] = i;
            nPrime++;
        }
    }
}

void findFactors(long int num) {
    for (int i = 0;i < nPrime;i++) {
        long int dig = prime[i];
        if (num % dig == 0) {
            fac[n].num = dig;
            fac[n].time = 0;
            while (num % dig == 0) {
                num /= dig;
                fac[n].time++;
            }
            n++;
        }
        if (num == 1) break;
    }
    if (num > 1) {
        fac[n].num = num;
        fac[n].time = 1;
        n++;
    }
}

int main() {
    long int num;
    scanf("%ld", &num);
    if (num == 1) printf("1=1\n");
    else {
        findPrime(num);
        findFactors(num);
        printf("%ld=", num);
        for (int i = 0;i < n;i++) {
            printf("%d", fac[i].num);
            if (fac[i].time > 1) {
                printf("^%d", fac[i].time);
            }
            if (i < n - 1) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}