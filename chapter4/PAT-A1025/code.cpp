#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student {
    char id[15];
    int locationNum;
    int locationRank;
    int score;
}stu[30010];

bool cmp(Student s1, Student s2) {
    if (s1.score != s2.score) return s1.score > s2.score;
    else return strcmp(s1.id, s2.id) < 0;
}

int main() {
    int locationTotal;
    // get the total locations
    scanf("%d", &locationTotal);
    // the num of total testee
    int total = 0;
    for (int i = 0;i < locationTotal;i++) {
        int testeeTotal;
        // get total testee in one location
        scanf("%d", &testeeTotal);
        int start = total; // save the start pos of this location in array 
        for (int j = 0;j < testeeTotal;j++) {
            char id[15];
            int score;
            scanf("%s %d", id, &score);
            stu[total].score = score;
            strcpy(stu[total].id, id);
            stu[total].locationNum = i + 1; // 考场序号从1开始
            total++;
        }

        sort(stu + start, stu + start + testeeTotal, cmp);
        stu[start].locationRank = 1;
        int rank = 2;
        for (int i = start + 1;i < start + testeeTotal;i++) {
            if (stu[i].score == stu[i - 1].score) {
                stu[i].locationRank = stu[i - 1].locationRank;
                rank++;
            } else {
                stu[i].locationRank = rank;
                rank++;
            }
        }
    }

    sort(stu, stu + total + 1, cmp);
    int rank = 1;
    printf("%d\n", total);
    for (int i = 0;i <= total;i++) {
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            // 当与前一个分数不同，则真实排名为i+1
            rank = i + 1; 
        }
        // 若不满足if中的条件，则rank不变，与前一人排名相同
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", rank, stu[i].locationNum, stu[i].locationRank);
    }

    return 0;
}