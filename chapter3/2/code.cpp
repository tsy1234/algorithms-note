#include <cstdio>

const int months[13][2] = { { 0 , 0 }, { 31, 31 }, { 28, 29 }, { 31, 31 }, { 30, 30 },
                            { 31, 31 }, { 30, 30 }, { 31, 31 }, { 31, 31 }, { 30, 30 },
                            { 31, 31 }, { 30, 30 }, { 31, 31 } };

bool isLeap(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void change(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    int t1, y1, m1, d1;
    int t2, y2, m2, d2;

    while (scanf("%d%d", &t1, &t2) != EOF) {
        if (t1 > t2) {
            change(t1, t2);
        }

        int res = 1;

        y1 = t1 / 10000, m1 = t1 % 10000 / 100, d1 = t1 % 100;
        y2 = t2 / 10000, m2 = t2 % 10000 / 100, d2 = t2 % 100;

        while (y1 < y2 || m1 < m2 || d1 < d2) {
            d1++;
            int leap = isLeap(y1);
            if (d1 == months[m1][leap] + 1) {
                d1 = 1;
                m1++;
            }
            if (m1 == 13) {
                y1++;
                m1 = 1;
            }
            res++;
        }
        printf("%d\n", res);
    }

    return 0;
}