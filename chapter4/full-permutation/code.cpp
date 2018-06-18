// 分治
#include <cstdio>
#include <cstdlib>


// 写出1~n的全排列
int n, h[11];
bool hashTable[11] = { false };
void getPermutation(int index) {
    if (index > n) {
        for (int i = 1;i <= n;i++) {
            printf("%d", h[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1;i <= n;i++) {
        if (!hashTable[i]) {
            h[index] = i;
            hashTable[i] = true;
            getPermutation(index + 1);
            hashTable[i] = false;
        }
    }
}
// n皇后问题
int count = 0;
void nQueue(int index) {
    // 递归边界
    if (index > n) {
        bool flag = true;
        // 如果在一条对角线上
        for (int i = 1;i <= n;i++) {
            for (int j = i + 1;j <= n;j++) {
                if (abs(i - j) == abs(h[i] - h[j])) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            for (int i = 1;i <= n;i++) {
                printf("%d", h[i]);
            }
            printf("\n");
            count++;
        }
    }

    // 递归式
    for (int i = 1;i <= n;i++) {
        if (!hashTable[i]) {
            h[index] = i;
            hashTable[i] = true;
            nQueue(index + 1);
            hashTable[i] = false;
        }
    }
}

// n皇后回溯法，在添加一个新的皇后之前，检测添加这个皇后是否会出错，出错返回
void nQueueBackTrace(int index) {
    if (index > n) {
        count++;
        for (int i = 1;i <= n;i++) {
            printf("%d", h[i]);
        }
        printf("\n");
    }

    for (int i = 1;i <= n;i++) {
        if (!hashTable[i]) {
            bool flag = true;
            for (int pre = 1;pre < index;pre++) {
                if (abs(pre - index) == abs(i - h[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                h[index] = i;
                hashTable[i] = true;
                nQueueBackTrace(index + 1);
                hashTable[i] = false;
            }
        }
    }
}   

int main() {
    n = 8;
    // getPermutation(1);
    // nQueue(1);
    nQueueBackTrace(1);
    printf("总共 %d 个", count);
    return 0;
}