#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;

int dem[MAX]; // 0 <= a[i] < 10^6

void countingSort(int a[], int n)
{
    int K = -1e9;
    for (int i = 0; i < n; i++)
    {
        dem[a[i]]++;
        K = max(K, a[i]);
    }
    for (int i = 0; i <= K; i++)
    {
        if (dem[i])
        {
            for (int j = 0; j < dem[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    countingSort(a, n);
}