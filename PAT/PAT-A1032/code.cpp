#include <cstdio>
#include <stack>

using namespace std;

struct Node {
    char data;
    int next;
} nodes[100010];

int fHead, sHead, total, fEnd, sEnd;

stack<int> fStack;
stack<int> sStack;

int getAddresss() {
    int pos, next;
    char data;
    for (int i = 0;i < total;i++) {
        scanf("%d %c %d", &pos, &data, &next);
        nodes[pos].data = data;
        nodes[pos].next = next;
    }
    for (int i = fHead;nodes[i].next != -1;i = nodes[i].next) {
        fStack.push(i);
    }
    for (int i = sHead;nodes[i].next != -1;i = nodes[i].next) {
        sStack.push(i);
    }
    if (sStack.top() != fStack.top()) return -1;
    int prePos = sStack.top();
    while (!sStack.empty() && !fStack.empty()) {
        int fPos = fStack.top(), sPos = sStack.top();
        if (fPos != sPos) {
            return prePos;
        }
        sStack.pop();
        fStack.pop();
        prePos = fPos;
    }
    if (sStack.empty()) return sHead;
    if (fStack.empty()) return fHead;
}

int main() {
    scanf("%d %d %d", &fHead, &sHead, &total);
    int res = getAddresss();
    if (res == -1) printf("-1\n");
    else printf("%05d\n", res);    
    return 0;
}