#include <cstdio>

int main() {
    int total = 0;
    scanf("%d", &total);
    int scores[total + 1] = { 0 };
    int time = 0, sc = 0;
    for (int i = 0;i < total;i++) {
        scanf("%d%d", &time, &sc);
        scores[time] += sc;
    }

    int max = 0, k;
    // 找出最大值
    for (int i = 1;i <= total;i++) {
        if (scores[i] >= max) {
            k = i;
            max = scores[i];
        }
    }

    printf("max: %d", max);
    printf("pos: %d", k);
    
    return 0;
}
