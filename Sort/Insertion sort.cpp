#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

// Hàm thực hiện sắp xếp chèn theo thứ tự giảm dần
void insertionSort(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int pos = i - 1;
        int x = a[i];
        // Di chuyển các phần tử của a[0..i-1], lớn hơn x, lên một vị trí trước vị trí hiện tại
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
}

// Hàm xử lý từng trường hợp kiểm tra
void runcase()
{
    int n;
    cin >> n; // Đọc kích thước của mảng
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Đọc các phần tử của mảng
    }
    insertionSort(arr, n); // Sắp xếp mảng theo thứ tự giảm dần
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // In các phần tử của mảng đã được sắp xếp
    }
    cout << "\n"; // In xuống dòng sau mảng
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase; // Đọc số lượng trường hợp kiểm tra
    while (testcase--)
    {
        runcase(); // Chạy hàm xử lý cho từng trường hợp kiểm tra
    }
}
