#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct Node {
    int address, data, next;
    bool flag;  // 判断是否存在于以头结点开始的链表中
} nodes[maxn];

bool cmp(Node a, Node b) {
    if (!a.flag || !b.flag) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    for (int i = 0;i < maxn;i++) {
        nodes[i].flag = false;
    }

    int num, hAddr;
    scanf("%d %d", &num, &hAddr);
    for (int i = 0;i < num;i++) {
        int pos, data, next;
        scanf("%d %d %d", &pos, &data, &next);
        nodes[pos].address = pos;
        nodes[pos].data = data;
        nodes[pos].next = next;
    }

    int counts = 0;
    int p = hAddr;
    while (p != -1) {
        nodes[p].flag = true;
        p = nodes[p].next;
        counts++;
    }
    if (counts == 0) printf("%d -1\n", counts);
    else {
        sort(nodes, nodes + maxn, cmp); // 将有效的节点按升序排在最前面
        printf("%d %05d\n", counts, nodes[0].address);
        for (int i = 0;i < counts;i++) {
            if (i < counts - 1) {
                printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i + 1].address);
            } else {
                printf("%05d %d -1\n", nodes[i].address, nodes[i].data);
            }
        }
    }
    return 0;
}