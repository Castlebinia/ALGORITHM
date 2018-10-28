#include <iostream>
#include <algorithm>

const int INF = 987654321;
using namespace std;

int d[10002];
int a[102];

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= k; i++)d[i] = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if(j-a[i]>=0)
			d[j] = min(d[j],d[j - a[i]]+1);
		}
	}
	if (d[k] == INF)cout << -1 << '\n';
	else cout << d[k] << '\n';
}