#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int vi_tri_nho_nhat_lon_hon_hoac_bang(int a[], int n, int x)
{
	int l = 1;
	int r = n + 1;
	int i = n + 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] >= x)
		{
			i = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return i;
}
int heap[1000];
int sz = 0;

void heapify_up(int j)
{
	if (j == 1)
		return;	   // nếu heap chỉ có 1 phần tử
	int i = j / 2; // tìm node cha của j = j / 2
	if (heap[i] < heap[j])
	{							// nếu node cha nhỏ hơn j
		swap(heap[i], heap[j]); // đổi chỗ
		heapify_up(i);
	}
}

void push(int x)
{
	sz++;
	heap[sz] = x;	// the last element = x
	heapify_up(sz); // ổn định lại trật tự cây nhị phân sau khi push
}

void heapify_down(int i)
{
	int j = 2 * i; // tìm node con của i = 2*i = j
	if (j > sz)
		return; // nếu không có con
	if (j + 1 <= sz && heap[j] < heap[j + 1])
	{
		j++; // tìm node lớn nhất trong hai node con
	}
	if (heap[j] > heap[i])
	{
		swap(heap[i], heap[j]);
		heapify_down(j);
	}
}

void pop()
{
	heap[1] = heap[sz]; // gán element đầu tiên hay phần tử cần xóa là phần tử cuối cùng
	sz--;				//
	heapify_down(1);
}

int max_heap()
{
	return heap[1];
}
void heap_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		push(a[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = max_heap();
		pop();
	}
}
int main()
{
	int n = 8;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		// a[i] = rand() %10;
		cin >> a[i];
	}
	heap_sort(a, n);
	//	sort(a, a+n);
	for (int i = 0; i < n; i++)
	{
		// cout << i << ": " << a[i] << endl;
		cout << a[i] << " ";
	}
	// cout << "x = 3 => i = " << vi_tri_nho_nhat_lon_hon_hoac_bang(a, n, 3) << endl;
	// cout << "x = 8 => i = " << vi_tri_nho_nhat_lon_hon_hoac_bang(a, n, 8);
	return 0;
}
