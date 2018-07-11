// 关于n的阶乘以及组合数的一些数学问题
// 算法笔记 p181
#include <cstdio>

// 计算n的阶乘中含有多少个质因子p
// 用数学公式就行
// 可将p传入5算得末尾有几个0
int cal(int n, int p) {
    int ans = 0;
    while(n) {
        ans += n / p; // 累加p^k
        n /= p;       // 相当于分母多乘一个p
    }
    return ans;
}

// 递归求组合数
long long C(int n, int m) {
    if (m == 0 || n == m) return 1;
    return C(n - 1, m - 1) + C(n - 1, m);
}

int res[67][67] = { 0 };
// 加了缓存的递归求组合数 避免了重复计算
long long cacheC(int n, int m) {
    if (m == 0 || n == m) return 1;
    if (res[n][m] != 0 ) return res[n][m]; // 缓存中有直接返回
    res[n][m] = C(n - 1, m - 1) + C(n - 1, m);
    return res[n][m];
}

// 把所有组合数推出来，再从数组中直接取
void getAllC() {
    int n = 60;
    for (int i = 0;i < n;i++) {
        res[i][0] = res[i][i] = 1; // n = m或者m = 0的情况
    }
    for (int i = 2;i < n;i++) {
        for (int j = 1;j <= i / 2;j++) {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            res[i][i - j] = res[i][j];
        }
    }

}


int main() {
    int num;
    // scanf("%d", &num);
    // printf("%d\n", cal(num, 2));
    // printf("%lld\n", cacheC(5, 4));
    getAllC();
    printf("%d\n", res[7][2]);
    return 0;
}