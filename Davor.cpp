#include <cstdio>
int main()
{
    int n, x, k;
    scanf("%d", &n);
    for (k = 1;; ++k)//k越小越好，上限没有定
        for (x = 100; x > 0; --x)//x范围1~100
            if ((7 * x + 21 * k) * 52 == n)//刚好52周筹完
            {
                printf("%d\n%d\n", x, k);
                return 0;
            }
}
