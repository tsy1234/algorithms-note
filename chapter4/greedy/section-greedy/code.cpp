#include <cstdio>
#include <algorithm>

struct pointer {
    int x, y;
} nodes[110];

bool cmp(pointer a, pointer b) {
    return a.x < b.x;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    for (int i = 0;i < num;i++) {
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
    }

    std::sort(nodes, nodes + num, cmp);

    int res = 1, i = 1;
    int pre = 0;
    while (i < num) {
        if (nodes[i].x > nodes[pre].y) {
            pre = i;
            i++;
            res++;
        } else {
            i++;
        }
    }
    printf("个数: %d\n", res);
    return 0;
}