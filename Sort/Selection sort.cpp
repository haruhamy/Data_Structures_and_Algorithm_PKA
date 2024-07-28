#include <stdio.h>

void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void selectionSort(int arr[], int n)
{
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (int i = 0; i < 4; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}