#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

// Hàm tìm vị trí đầu tiên của phần tử lớn hơn hoặc bằng X trong mảng tăng dần
int lower(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= x)
        {
            res = mid;       // cập nhật kết quả
            right = mid - 1; // tiếp tục tìm về phía bên trái
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}
// Độ phức tạp: O(logN)

// Hàm tìm vị trí cuối cùng của phần tử nhỏ hơn hoặc bằng X trong mảng tăng dần
int upper(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= x)
        {
            res = mid;      // cập nhật kết quả
            left = mid + 1; // tiếp tục tìm về phía bên phải
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}
// Độ phức tạp: O(logN)

void runcase()
{
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