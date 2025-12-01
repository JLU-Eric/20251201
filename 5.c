//给定只由 6 种括号字符组成的字符串：(, ), [, ], {, }。判断每个字符串是否为“合法括号序列”，合法则输出 YES，否则输出 NO。合法括号序列的定义：空串合法；若 A 合法，则 (A), [A], {A} 均合法；若 A 与 B 均合法，则 AB 合法。
//第一行一个整数 T，表示数据组数。接下来 T 行，每行一个只包含上述 6 种字符的字符串。
//对于每个字符串，输出一行：若其为合法括号序列，输出 YES；否则输出 NO。
#include <stdio.h>
#include <string.h>

int isValid(char *s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) return 0;
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[100];
        scanf("%s", s);
        if (isValid(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}