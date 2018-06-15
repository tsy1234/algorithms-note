#include <cstdio>
#include <cstring>

bool palindrome1(char str[]) {
    int size = strlen(str);
    int half = size / 2;

    for (int i = 0;i < half;i++) {
        if (str[i] != str[size - 1 - i]) return false;
    }
    return true;
}

int main() {
    char str1[] = "leaael";
    char str2[] = "leaeal";
    printf("%d\n", palindrome1(str1));
    printf("%d\n", palindrome1(str2));
    printf("%d\n", true == 1); // true equals to 1
    return 0;
}