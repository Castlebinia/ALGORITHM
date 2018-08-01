#include <iostream>
#include <algorithm>

int a[500001];

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		int l = lower_bound(a, a + n, x) - a+1;
		int r = upper_bound(a, a + n, x) - a+1;
		cout << r - l << ' ';
	}
	cout << '\n';
}