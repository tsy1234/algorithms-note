#include <cstdio>
#include <cmath>

const double  eps = 1e-5;
const double PI = acos(-1.0);

double f(double R, double h) {
    double alpha = 2 * acos((R - h) / R);
    double L = 2 * sqrt(R * R - (R - h) * (R - h));
    double s1 = alpha * R * R / 2 - L * (R - h) / 2;
    double s2 = PI * R * R / 2;
    return s1 / s2;
}

double solve(double R, double r) {
    double left = 0, right = R;
    double mid = 0;
    while (right - left > eps) {
        mid = left + (right - left) / 2;
        if (f(R, mid) < r) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

int main() {
    double R, r;
    scanf("%lf%lf", &R, &r);
    double res = solve(R, r);
    printf("%.2lf\n", res);
    return 0;
}