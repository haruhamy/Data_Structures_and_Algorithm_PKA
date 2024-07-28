#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

// Hàm hoán đổi hai giá trị
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm in dãy số
void printPermutation(const vector<int> &permutation)
{
    for (int num : permutation)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Hàm backtracking để tìm các hoán vị
void backtrack(vector<int> &arr, int start, int end)
{
    // Nếu vị trí bắt đầu bằng vị trí kết thúc, in hoán vị hiện tại
    if (start == end)
    {
        printPermutation(arr);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            // Đổi chỗ phần tử thứ i với phần tử tại vị trí bắt đầu
            swap(arr[start], arr[i]);
            // Tiếp tục tạo các hoán vị từ vị trí tiếp theo
            backtrack(arr, start + 1, end);
            // Hoàn nguyên hoán vị để tiếp tục với phần tử khác
            swap(arr[start], arr[i]);
        }
    }
}

void runcase()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    backtrack(arr, 0, n - 1); // Gọi hàm backtracking
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