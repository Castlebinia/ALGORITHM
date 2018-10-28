#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[1000001];
int b[1000001];
int n;

bool foo(int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int m = (left + right) / 2;
		if (x < a[m]) {
			right = m-1;
		}
		else if (x > a[m]) {
			left = m + 1;
		}
		else return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)cin >> b[i];
		sort(a, a + n);
		for (int i = 0; i < m; i++) {
			cout << foo(b[i]) << '\n';
		}
	}
}