#include <cstdio>
// 从数组N中找到存在的M数组中的数
// 使用散列表来节省时间
bool hashTable[100010] = { false };

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0;i < n;i++) {
        int num;
        scanf("%d", &num);
        hashTable[num] = true;
    }

    for (int i = 0;i < m;i++) {
        int num;
        scanf("%d", &num);;
        if (hashTable[num]) {
            printf("%d exists\n", num);
        }
    }
    return 0;
}