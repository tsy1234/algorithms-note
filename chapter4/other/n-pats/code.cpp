#include <cstdio>
#include <cstring>

const int MAXN = 10010;
char str[MAXN];
char leftP[MAXN] = { 0 };

int findPats(char s[], int n) {
    int pNum = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'p') {
            pNum++;
        } else if (s[i] == 'a') {
            leftP[i] = pNum;
        }
    }

    int ans = 0;
    int tNum = 0;
    for (int i = n - 1;i > 0;i--) {
        if (s[i] == 't') {
            tNum++;
        } else if (s[i] == 'a') {
            ans += tNum * leftP[i];
        }
    }

    return ans;
}

int main() {
    scanf("%s", str);
    int len = strlen(str);
    int ans = findPats(str, len);
    printf("%d\n", ans);
    return 0;
}