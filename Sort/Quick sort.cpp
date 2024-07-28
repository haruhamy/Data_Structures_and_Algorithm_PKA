#include <bits/stdc++.h>

using namespace std;

void quickSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int p = a[l + rand() % (r - l + 1)];
	int i = l, j = r;
	// thao tác phân hoạch
	while (1)
	{ // chạy dến khi i == j
		while (a[i] < p)
			i++; // nếu phần tử bên trái nhỏ hơn pivot
		while (a[j] > p)
			j--; // nếu phần tử bên phải lớn hơn pivot
		if (i < j)
		{ // nếu không thì đổi chỗ a[i] và a[j]
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else
			break;
	}
	quickSort(a, l, j);
	quickSort(a, j + 1, r);
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}