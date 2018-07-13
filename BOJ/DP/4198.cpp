#include <iostream>
#include <algorithm>

using namespace std;

int a[2001];
int d[2001];
int d2[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int ret = 0;
	for (int i = n - 1;i>=0; i--) {
		d[i] = d2[i] = 1;
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j])d[i] = max(d[i], d[j] + 1);
			if (a[i] < a[j])d2[i] = max(d2[i], d2[j] + 1);
		}
		ret = max(ret, d[i] + d2[i] - 1);
	}
	cout << ret << '\n';
}