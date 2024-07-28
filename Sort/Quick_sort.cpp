#include <bits/stdc++.h>

using namespace std;

// Hàm phân hoạch theo Lomuto
int partition(int a[], int l, int r)
{
    int pivot = a[r]; // Chọn phần tử cuối làm pivot
    int i = l - 1;    // Chỉ số i bắt đầu từ vị trí l - 1

    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {                     // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
            ++i;              // Tăng chỉ số i
            swap(a[i], a[j]); // Hoán đổi phần tử tại i và j
        }
    }
    ++i;              // Tăng chỉ số i để hoán đổi pivot
    swap(a[i], a[r]); // Đưa pivot vào đúng vị trí
    return i;         // Trả về chỉ số của pivot
}

// Hàm Quick Sort
void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r); // Chia mảng và trả về chỉ số phân hoạch
        quicksort(a, l, p - 1);     // Gọi đệ quy sắp xếp mảng bên trái
        quicksort(a, p, r);         // Gọi đệ quy sắp xếp mảng bên phải
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
    quicksort(a, 0, n - 1);
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
1. **Gọi quicksort(a, 0, 4):**
   - Gọi partition(a, 0, 4): Chọn pivot là 1.
   - i = -1, j chạy từ 0 đến 3
     - j = 0: a[0] (4) > pivot, không hoán đổi, i = -1
     - j = 1: a[1] (10) > pivot, không hoán đổi, i = -1
     - j = 2: a[2] (3) > pivot, không hoán đổi, i = -1
     - j = 3: a[3] (5) > pivot, không hoán đổi, i = -1
   - Hoán đổi a[i+1] (a[0]) với a[r] (a[4]): [1, 10, 3, 5, 4]
   - Trả về p = 0

2. **Gọi đệ quy quicksort(a, 0, -1):**
   - Không thực hiện vì l >= r.

3. **Gọi đệ quy quicksort(a, 1, 4):**
   - Gọi partition(a, 1, 4): Chọn pivot là 4.
   - i = 0, j chạy từ 1 đến 3
     - j = 1: a[1] (10) > pivot, không hoán đổi, i = 0
     - j = 2: a[2] (3) <= pivot, hoán đổi a[i+1] (a[1]) với a[2]: [1, 3, 10, 5, 4], i = 1
     - j = 3: a[3] (5) > pivot, không hoán đổi, i = 1
   - Hoán đổi a[i+1] (a[2]) với a[r] (a[4]): [1, 3, 4, 5, 10]
   - Trả về p = 2

4. **Gọi đệ quy quicksort(a, 1, 1):**
   - Không thực hiện vì l >= r.

5. **Gọi đệ quy quicksort(a, 3, 4):**
   - Gọi partition(a, 3, 4): Chọn pivot là 10.
   - i = 2, j chạy từ 3 đến 3
     - j = 3: a[3] (5) <= pivot, hoán đổi a[i+1] (a[3]) với a[3]: [1, 3, 4, 5, 10], i = 3
   - Hoán đổi a[i+1] (a[4]) với a[r] (a[4]): [1, 3, 4, 5, 10]
   - Trả về p = 4

6. **Gọi đệ quy quicksort(a, 3, 3) và quicksort(a, 5, 4):**
   - Không thực hiện vì l >= r.

Kết quả cuối cùng sau khi sắp xếp: [1, 3, 4, 5, 10]
*/
