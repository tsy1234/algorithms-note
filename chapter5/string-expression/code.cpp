#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct node {
    double num;
    char op;
    bool flag;   // true 代表操作数，false代表操作符
};

string str;
stack<node> s;   // 操作符栈
queue<node> q;   // 后缀表达式序列
map<char, int> op;

// 将中缀表达式转化为后缀表达式
void change() {
    double num;
    node temp;
    for (int i = 0;i < str.length();) {
        if (str[i] >= '0' && str[i] <= 9) {
            temp.flag = true;
            temp.num = str[i++] - '0';
            i++;
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        } else { // 处理操作符
            temp.flag = true;
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// 计算后缀表达式
double cal() {
    double temp1, temp2;
    node cur, temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) s.push(cur);
        else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag == true;
            if (cur.op == '+') temp.num = temp1 + temp2;
            else if (cur.op == '-') temp.num = temp1 - temp2;
            else if (cur.op == '*') temp.num = temp1 * temp2;
            else if (cur.op == '/') temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main() {
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end();it != str.begin();it--) {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) {
            s.pop();
        }
        change();
        printf("%.2lf\n", cal());
    }
    return 0;
}