#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n;

// 这个代码写的非常差 非常冗余
// 没有考虑清楚边界值的情况
void isEqual(int digs, string num1, string num2) {
    int pos1 = num1.length(), pos2 = num2.length();
    bool res = false;

    if (num1.find(".") != string::npos) {
        pos1 = num1.find(".");
    } 
    if (num2.find(".") != string::npos) {
        pos2 = num2.find(".");
    }
    if (pos1 < num1.length()) {
        num1 = num1.erase(pos1, 1);
        if (num1.substr(0, 1) == "0") {
            num1.erase(0, 1);
            pos1 -= 1;
        }
    }
    num1.insert(0, "0.");
    if (pos2 < num2.length()) {
        num2 = num2.erase(pos2, 1);
        if (num2.substr(0, 1) == "0") {
            num2.erase(0, 1);
            pos2 -= 1;
        }    
    }
    num2.insert(0, "0.");

    if (num1.length() > digs + 2 && num2.length() > digs + 2) {
        num1 = num1.substr(0, digs + 2);
        num2 = num2.substr(0, digs + 2);
    } else {
        int l1 = num1.length(), l2 = num2.length();
        while (l1 < digs + 2 || l2 < digs + 2) {
            if (l1 < digs + 2) {
                num1 += "0";
                l1++;
            }
            if (l2 < digs + 2) {
                num2 += "0";
                l2++;
            }
        }
    }
    
    if (pos1 == pos2 && num1 == num2) {
        res = true;
    }

    if (res) {
        cout << "YES " << num1 << "*10^" << pos1 << endl;
    } else {
        cout << "NO " << num1 << "*10^" << pos1 << " " << num2 << "*10^" << pos2 << endl;
    }
}

string deal(string num, int & e) {
    string res;
    int i;
    for (i = 0;i < num.length() && num[i] == '0';i++);
    num = num.substr(i, num.length() - i);

    if (!num.empty() && num[0] != '.') {
        for (i = 0;i < num.length() && num[i] != '.';i++) e++;
        if (i < num.length()) {
            num.erase(i, 1);
        }
        res = num;
    }else if (!num.empty() && num[0] == '.') {
        num.erase(0, 1);
        for (i = 0;i < num.length() && num[i] == '0';i++) e--;
        if (i == num.length()) e = 0;
        num = num.substr(i, num.length() - i);
        res = num;
    } 
    while (res.length() < n) {
        res += "0";
    }
    res = res.substr(0, n);
    return "0." + res;
}

int main() {
    string num1, num2;
    int digs, e1 = 0, e2 = 0;
    cin >> n >> num1 >> num2;
    // isEqual(digs, num1, num2);
    string s1 = deal(num1, e1);
    string s2 = deal(num2, e2);
    if (s1 == s2 && e1 == e2) {
        cout << "YES " << s1 << "*10^" << e1 << endl;
    } else {
        cout << "NO " << s1 << "*10^" << e1 << " " << s2 << "*10^" << e2 << endl;        
    }
    return 0;
}