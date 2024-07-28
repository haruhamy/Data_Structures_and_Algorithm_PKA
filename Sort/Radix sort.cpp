#include <stdio.h>

void radix_sort(int a[], int n)
{
    int p = 1;
    int cnt[10], start[10], tmp[n + 1];
    for (int cs = 0; cs <= 9; cs++, p *= 10)
    {
        for (int i = 0; i < 10; i++)
        {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int j = (a[i] / p) % 10;
            cnt[j]++;
        }
        start[0] = 0;
        for (int i = 1; i < 10; i++)
        {
            start[i] = cnt[i - 1] + start[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            int j = (a[i] / p) % 10;
            tmp[start[j]] = a[i];
            start[j]++;
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = tmp[i];
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    radix_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}