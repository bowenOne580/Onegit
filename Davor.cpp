#include <cstdio>
int main()
{
    int n, x, k;
    scanf("%d", &n);
    for (k = 1;; ++k)//kԽСԽ�ã�����û�ж�
        for (x = 100; x > 0; --x)//x��Χ1~100
            if ((7 * x + 21 * k) * 52 == n)//�պ�52�ܳ���
            {
                printf("%d\n%d\n", x, k);
                return 0;
            }
}
