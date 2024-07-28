#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

// Hàm hoán đổi hai phần tử
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch Hoare
int partition(int a[], int low, int high)
{
    int pivot = a[low]; // Chọn phần tử đầu tiên làm pivot
    int i = low - 1;    // Chỉ số i bắt đầu từ vị trí low - 1
    int j = high + 1;   // Chỉ số j bắt đầu từ vị trí high + 1

    while (1)
    {
        // Tìm phần tử lớn hơn hoặc bằng pivot từ trái sang phải
        do
        {
            i++;
        } while (a[i] < pivot);

        // Tìm phần tử nhỏ hơn hoặc bằng pivot từ phải sang trái
        do
        {
            j--;
        } while (a[j] > pivot);

        // Nếu i và j giao nhau, trả về chỉ số j
        if (i >= j)
            return j;

        // Hoán đổi a[i] và a[j]
        swap(&a[i], &a[j]);
    }
}

// Hàm Quick Sort
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        // Chia mảng và trả về chỉ số phân hoạch
        int p = partition(a, low, high);

        // Gọi đệ quy sắp xếp hai mảng con
        quickSort(a, low, p);
        quickSort(a, p + 1, high);
    }
}

// Hàm in mảng
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Chương trình chính
void runcase()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
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
/* Ví dụ từng bước chạy:
Giả sử mảng ban đầu là: [4, 10, 3, 5, 1]

1. **Gọi quickSort(a, 0, 4):**
   - Gọi partition(a, 0, 4): Chọn pivot là 4.
   - i = 0, j = 5
     - i tăng từ 0 lên 1, 2 (vì a[1] > 4, a[2] < 4 dừng tại 3)
     - j giảm từ 5 xuống 4, 3 (vì a[4] < 4, a[3] > 4 dừng tại 1)
   - Hoán đổi a[1] và a[4]: [4, 1, 3, 5, 10]
   - Tiếp tục:
     - i tăng từ 2 lên 3 (vì a[3] > 4 dừng tại 5)
     - j giảm từ 2 xuống 1 (vì a[1] < 4, dừng tại 1)
   - i >= j, trả về j = 2. Mảng phân hoạch thành: [4, 1, 3 | 5, 10]

2. **Gọi đệ quy quickSort(a, 0, 2):**
   - Gọi partition(a, 0, 2): Chọn pivot là 4.
   - i = 0, j = 3
     - i tăng từ 0 lên 1, 2 (vì a[1] < 4 dừng tại 3)
     - j giảm từ 3 xuống 2, 1 (vì a[2] < 4 dừng tại 3)
   - i >= j, trả về j = 1. Mảng phân hoạch thành: [4, 1 | 3]

3. **Gọi đệ quy quickSort(a, 0, 1):**
   - Gọi partition(a, 0, 1): Chọn pivot là 4.
   - i = 0, j = 2
     - i tăng từ 0 lên 1 (vì a[1] < 4 dừng tại 1)
     - j giảm từ 2 xuống 1, 0 (vì a[0] < 4 dừng tại 1)
   - i >= j, trả về j = 0. Mảng phân hoạch thành: [1 | 4]

4. **Gọi đệ quy quickSort(a, 0, 0) và quickSort(a, 1, 1):**
   - Không thay đổi vì low >= high.

5. **Gọi đệ quy quickSort(a, 3, 4):**
   - Gọi partition(a, 3, 4): Chọn pivot là 5.
   - i = 3, j = 5
     - i tăng từ 3 lên 4 (vì a[4] < 5 dừng tại 10)
     - j giảm từ 5 xuống 4, 3 (vì a[3] > 5 dừng tại 10)
   - i >= j, trả về j = 3. Mảng phân hoạch thành: [5 | 10]

6. **Gọi đệ quy quickSort(a, 3, 3) và quickSort(a, 4, 4):**
   - Không thay đổi vì low >= high.

Kết quả cuối cùng sau khi sắp xếp: [1, 3, 4, 5, 10]
*/
