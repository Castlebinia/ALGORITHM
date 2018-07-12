#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int d[41];
bool a[41];

int main() {
	d[0] = 1;
	d[1] = 1;
	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= n; i++)d[i] = d[i - 1] + d[i - 2]; 
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		a[x] = true;
	}
	int ret = 1;
	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			ret *= d[i - last-1];
			last = i;
		}
	}
	ret *= d[n - last];
	cout << ret << '\n';
}