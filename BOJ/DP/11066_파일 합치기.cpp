#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 987654321;
int cost[502];
int sum[502];
int d[502][502];

int foo(int i, int j) {
	if (i == j)return 0;
	int &ret = d[i][j];
	if (ret != -1)return ret;
	ret = MAX;
	for (int k = i; k < j; k++) {
		int mi = foo(i, k) + foo(k + 1, j) + sum[j] - sum[i - 1];	//i~k,k+1~j i~j 합 더하기 
		if (ret > mi)ret = mi;		//최소
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(d, -1, sizeof(d));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		cout << foo(1, n) << '\n';
	}
}