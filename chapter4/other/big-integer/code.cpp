#include <cstdio>
#include <cstring>

struct bign {
    int b[1000];
    int len;
    bign() {
        memset(b, 0, sizeof(b));
        len = 0;
    }
};

bign change(char s[]) {
    bign a;
    a.len = strlen(s);
    for (int i = 0;i < a.len;i++) {
        a.b[i] = s[a.len - 1 - i] - '0';
    }
    return a;
}

void printBign(bign a) {
    int len = a.len;
    for (int i = len - 1;i >= 0;i--) {
        printf("%d", a.b[i]);
    }
    printf("\n");
}

bign sub(bign a, bign b) {
    int aLen = a.len, bLen = b.len;
    bign c;
    
    for (int i = 0;i < aLen || i < bLen;i++) {
        if (a.b[i] < b.b[i]) {
            a.b[i + 1]--;
            c.b[i] = 10 + a.b[i] - b.b[i];
        } else {
            c.b[i] = a.b[i] - b.b[i];
        }
        c.len++;
    }

    // 消除减法执行完后多出的0,但要保证至少存在一位为0
    while (c.len > 1 && c.b[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

bign multi(bign a, int b) {
    int aLen = a.len;
    bign c;
    int carry = 0;
    for (int i = 0;i < aLen;i++) {
        int mul = a.b[i] * b + carry;
        carry = mul / 10;
        c.b[c.len] = mul % 10;
        c.len++;
    }

    while (carry > 0) {
        c.b[c.len] = carry % 10;
        c.len++;
        carry /= 10;
    }
    return c;
}


bign divide(bign a, int b, int & r) {
    int aLen = a.len;
    bign c;
    c.len = aLen;
    
    for (int i = aLen - 1;i >= 0;i++) {
        r = r * 10 + a.b[i];
        // 不够除
        if (r < b) {
            c.b[i] = 0;
        } else {
            int di = r / b;
            r = r % b;
            c.b[i] = di;
        }
    }
    while (c.len > 1 && c.b[c.len - 1] == 0) {
        c.len--;
    }
}

bign add(bign a, bign b) {
    int aLen = a.len, bLen = b.len;
    int carry = 0;
    bign c;
    for (int i = 0;i < aLen || i < bLen;i++) {
        int add = a.b[i] + b.b[i] + carry;
        carry = add / 10;
        c.b[c.len] = add % 10;
        c.len++;
    }
    if (carry > 0) {
        c.b[c.len] = carry;
        c.len++;
    }
    return c;
}

int main() {
    char a[10];
    scanf("%s", a);
    bign big = change(a);
    scanf("%s", a);
    bign b = change(a);
    bign res = sub(big, b);
    printBign(res);
    return 0;
}