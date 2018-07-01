#include <cstdio>

const double eps = 1e-5;

double f(double x) {
    return x * x;
}

int main() {
    double left = 1, right = 2, mid;
    while (right - left > eps) {
        double mid = left + (right - left) / 2;
        if (f(mid) > 2) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%.2lf", left);
    return 0;
}