//液晶屏上，每个阿拉伯数字都是可以显示成 3×5 的点阵的（其中 X 表示亮点，. 表示暗点）。现在给出数字位数（不超过 100）和一串数字，要求输出这些数字在显示屏上的效果。数字横向输出，注意每个数字之间都有一列.。
//例如，输入：10 0123456789，输出如下所示：
//XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
//X.X...X...X...X.X.X.X...X.....X.X.X.X.X
//X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
//X.X...X.X.....X...X...X.X.X...X.X.X...X
//XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
#include <stdio.h>
int main() {
    int n;
    char digits[101];
    char patterns[10][5][4] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
    };

    scanf("%d", &n);
    scanf("%s", digits);

    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            int digit = digits[i] - '0';
            printf("%s", patterns[digit][row]);
            if (i != n - 1) {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}