#include <stdio.h>
#include <stdlib.h>

int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) return 0;

    for (long long i = a; i <= b; i++) {
        if (i % 2 == 0) { /* 特判偶数 */
            continue;
        }
        long long w = i, s = 0;
        while (w != 0) { /* 判断是否为回文数 */
            s = s * 10 + w % 10;
            w /= 10;
        }
        if (s != i) {
            continue;
        }
        int f = 0; /* 判断是否为质数 */
        for (long long j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            printf("%lld\n", i);
        }
    }

    return 0;
}