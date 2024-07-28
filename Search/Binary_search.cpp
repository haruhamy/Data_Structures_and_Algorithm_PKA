#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

bool binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return true;
        }
        else if (a[mid] < x)
        {
            // Tim kiem ben trai
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

void runcase()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (binarySearch(a, n, x))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
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