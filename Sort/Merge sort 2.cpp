#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1; // số lượng phần tử từ chỉ số l->m
    int n2 = r - m;     // số lượng phần tử từ chỉ số m+1->r
    int x[n1], y[n2];
    for (int i = l; i <= m; i++)
    { // lưu các phần tử từ chỉ số l->m vào mảng x
        x[i - l] = a[i];
    }
    for (int i = m + 1; i <= r; i++)
    { // lưu các phần tử từ chỉ số m+1->r vào mảng x
        y[i - m - 1] = a[i];
    }
    // thao tác trộn hai mảng x và y
    int i = 0, j = 0, cnt = l;
    while (i < n1 && j < n2)
    {
        if (x[i] < y[j])
            a[cnt++] = x[i++];
        else
            a[cnt++] = y[j++];
    }
    while (i < n1)
        a[cnt++] = x[i++];
    while (j < n2)
        a[cnt++] = y[j++];
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2; // Or int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    for (int z = 0; z < 8; z++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        merge_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}