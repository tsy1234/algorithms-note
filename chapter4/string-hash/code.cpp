// 给出N个字符串(由恰好三位大写字母组成)，在给出M个查询字符串，问每个
// 查询字符串在N个字符串中出现的次数 
#include <cstdio>
// 大写字母
int hashTable[26 * 26 * 26 + 10] = { 0 };
int hashFunc(char s[], int len) {
    int id = 0;
    for (int i = 0;i < len;i++) {
        id = id * 26 + (s[i] - 'A');
    }
    return id;
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    char s[5];

    for (int i = 0;i < 3;i++) {
        scanf("%s", s);
        int id = hashFunc(s, 3);
        hashTable[id]++;
    }
    
    for (int i = 0;i < m;i++) {
        scanf("%s", s);
        int id = hashFunc(s, 3);
        int num = hashTable[id];
        if (num != 0) {
            printf("%s出现了%d次", s, num);
        } else {
            printf("%s出现了 0 次", s);
        }
    }
    return 0;
}