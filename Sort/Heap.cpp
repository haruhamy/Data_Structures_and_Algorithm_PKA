// Thuật toán Heapsort trong đề thi

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

// Hàm điều chỉnh Heap
//[6, 3, 8, 2, 4, 1, 5]
//[0, 1, 2, 3, 4, 5, 6]
// n =7
void ADJUST(int K[], int i, int n)
{
	int KEY = K[i];	   // Lưu giá trị phần tử tại vị trí i
	int j = 2 * i + 1; // Vị trí con trái

	while (j <= n)
	{								  // Duyệt đến hết cây
		if (j < n && K[j] < K[j + 1]) // Nếu con phải lớn hơn con trái, chọn con phải
			j = j + 1;

		if (KEY > K[j])
		{									  // Nếu KEY lớn hơn phần tử tại vị trí j, thoát vòng lặp
			K[(int)floor((j - 1) / 2)] = KEY; // Gán cha bằng Key, đặt Key vào vị trí cuối cùng
			return;
		}

		K[(int)floor((j - 1) / 2)] = K[j]; // Di chuyển phần tử lớn hơn lên vị trí cha
		j = 2 * j + 1;					   // Di chuyển xuống cây con
	}

	K[(int)floor((j - 1) / 2)] = KEY; // Đặt KEY vào vị trí cuối cùng
}

// Hàm Heap Sort
void HeapSort(int K[], int n)
{
	// (A) Xây dựng heap ban đầu
	for (int i = floor((n - 1) / 2); i >= 0; i--) // nút cha cuối cùng trong cây
	{
		ADJUST(K, i, n);
	}

	// (B) Sắp xếp mảng
	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = K[0]; // Đổi phần tử đầu và cuối
		K[0] = K[i + 1];
		K[i + 1] = tmp;
		ADJUST(K, 0, i); // Điều chỉnh heap với phần tử còn lại
	}
}

// Hàm in mảng
void printArray(int K[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", K[i]);
	}
	printf("\n");
}

void runcase()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	HeapSort(a, n - 1);
	printArray(a, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		runcase();
		cout << "\n";
	}
}