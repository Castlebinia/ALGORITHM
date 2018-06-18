#include <iostream>
#include <algorithm>

using namespace std;

int a[102];
int c[102];
int d[10002];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 10000; j >= 0; j--) {
			if (j - c[i]>=0)d[j] = max(d[j], d[j - c[i]] + a[i]);
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (d[i] >= m) {
			cout << i << '\n';
			break;
		}
	}
}