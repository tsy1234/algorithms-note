#include <cstdio>
#include <algorithm>

// 每次将利润最高的月饼卖出即可

struct mooncake {
    double sPrice;
    double tValue;
    double tNum;
} cakes[1010];

bool compare(mooncake a, mooncake b) {
    return a.sPrice > b.sPrice;
}

int main() {
    int kindNum = 0;
    double maxNeed = 0;
    scanf("%d", &kindNum);
    scanf("%lf", &maxNeed);

    for (int i = 0;i < kindNum;i++) {
        int p = 0;
        scanf("%d", &p);
        cakes[i].tNum = p;
    }

    for (int i = 0;i < kindNum;i++) {
        double t = 0;
        scanf("%lf", &t);
        cakes[i].tValue = t;
        cakes[i].sPrice = t / cakes[i].tNum;
    }

    // 将数组按照月饼的利润从高到底排序
    std::sort(cakes, cakes + kindNum, compare);

    double res = 0;
    // 按照价格从高到底卖出月饼，直到满足最大需求量
    for (int i = 0;i < kindNum;i++) {
        if (maxNeed <= cakes[i].tNum) {
            res += maxNeed * cakes[i].sPrice;
            break;
        }
        res += cakes[i].tValue;
        maxNeed -= cakes[i].tNum;
    }
    printf("最大利润: %.2lf", res);
    return 0;
}
