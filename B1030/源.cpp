#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, arr[maxn];
//int binarySearch(int i, long long x) {
//	if (arr[n - 1] <= x) return n;
//	int l = i + 1, r = n - 1, mid;
//	while (l < r) {
//		mid = (l + r) / 2;
//		if (arr[mid] <= x) {
//			l = mid + 1;
//		}
//		else {
//			r = mid ;
//		}
//	}
//	return l;
//}
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int j, ans=1;
	for (int i = 0; i < n; i++) {
//		j = binarySearch(i, (long long)arr[i] * p);
		j = upper_bound(arr + i, arr + n, (long long ) arr[i] * p) - arr;
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}