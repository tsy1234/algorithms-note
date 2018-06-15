#include <cstdio>

int main() {
    char str[90][10];

    int num = 0;
    while (scanf("%s", str[num]) != EOF) {
        num++;
    }

    for (int i = num - 1;i >= 0;i--) {
        printf("%s", str[i]);
        if (i > 0) printf(" ");
    }

    return 0;
}