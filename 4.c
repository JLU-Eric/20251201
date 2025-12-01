//写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过 100 个字符），然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。
//THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
//THIS IS AN EXAMPLE TO TEST FOR YOUR
//HISTOGRAM PROGRAM.
//HELLO!
//                            *
//                            *
//        *                   *
//        *                   *     *   *
//        *                   *     *   *
//*       *     *             *     *   *
//*       *     * *     * *   *     * * *
//*       *   * * *     * *   * *   * * * *
//*     * * * * * *     * * * * *   * * * *     * *
//* * * * * * * * * * * * * * * * * * * * * * * * * *
//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
int main() {
    int count[26] = {0};
    char line[MAX_LEN + 2]; // +2 for newline and null terminator

    // Read 4 lines of input
    for (int i = 0; i < 4; i++) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            for (int j = 0; j < strlen(line); j++) {
                if (line[j] >= 'A' && line[j] <= 'Z') {
                    count[line[j] - 'A']++;
                }
            }
        }
    }

    // Find the maximum count for scaling the histogram
    int max_count = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    // Print the histogram
    for (int level = max_count; level > 0; level--) {
        for (int i = 0; i < 26; i++) {
            if (count[i] >= level) {
                printf("*");
            } else {
                printf(" ");
            }
            if (i < 25) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the letters at the bottom
    for (int i = 0; i < 26; i++) {
        printf("%c", 'A' + i);
        if (i < 25) {
            printf(" ");
        }
    }

    return 0;
}