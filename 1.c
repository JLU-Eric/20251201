//现有 N 名同学参加了期末考试，并且获得了每名同学的信息：姓名（不超过 8 个字符的仅有英文小写字母的字符串）、语文、数学、英语成绩（均为不超过 150 的自然数）。总分最高的学生就是最厉害的，请输出最厉害的学生各项信息（姓名、各科成绩）。如果有多个总分相同的学生，输出靠前的那位。
#include <stdio.h>

struct Student {
    char name[9];
    int chinese;
    int math;
    int english;
    int total;
};

int main() {
    int n;
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].chinese, &students[i].math, &students[i].english);
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].total > students[maxIndex].total) {
            maxIndex = i;
        }
    }
    printf("%s %d %d %d", students[maxIndex].name, students[maxIndex].chinese, students[maxIndex].math, students[maxIndex].english);
    return 0;
}