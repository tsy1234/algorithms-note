// 使用素数筛选法找到0-100的素数表
// 算法笔记 p163
#include <cstdio>

int prime[100];
int pNum = 0;

bool p[101] = { 0 };

void findPrime() {
    for (int i = 2;i < 101;i++) {
        if (p[i] == false) {
            prime[pNum] = i;
            pNum++;
            for (int j = 2 * i;j < 101;j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    findPrime();
    for (int i = 1;i < pNum;i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}