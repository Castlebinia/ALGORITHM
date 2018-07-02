#include <iostream>

using namespace std;

int a[100002];
bool check[1<<21];

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int q, i, x;
		cin >> q;
		if (q == 1) {
			cin >> i >> x;
			x--;
			a[i] |= (1 << x);
		}
		else if (q == 2) {
			cin >> i >> x;
			x--;
			a[i] &= ~(1 << x);
		}
		else if (q == 3) {
			cin >> i;
			a[i]<<=1;
			a[i] &= ~(1 << 20);
		}
		else {
			cin >> i;
			a[i]>>=1;
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[a[i]]) {
			check[a[i]] = true;
			ret++;
		}
	}
	cout << ret << '\n';
}