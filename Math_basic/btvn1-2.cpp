#include <stdio.h>

int max(int a, int b){
	return a<b? b :a;
}

int min(int a, int b){
	return a>b? b :a;
}

int main() {
	int n; scanf("%d", &n); int a[n];
	int prefSum[n+1], prefMin[n+1];
	int ans = -1000;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    prefSum[0] = prefMin[0] = 0;
    for (int i = 1; i <= n; i++)
      prefSum[i] = prefSum[i - 1] + a[i], prefMin[i] = min(prefMin[i - 1], prefSum[i]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, prefSum[i] - prefMin[i - 1]);
    printf("%d", ans);
}
