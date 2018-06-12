#include <iostream>
#include <algorithm>

using namespace std;

int a[1002];
int d[1102];

int main() {
	int n;
	cin >> n;
	d[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0)continue;	//can not
		for (int j = 1; j <= a[i];j++) {
			if (d[i + j] == 0)d[i + j] = d[i] + 1;
			else d[i + j] = min(d[i + j], d[i] + 1);
		}
	}
	if (d[n] == 0)cout << -1 << '\n';
	else cout << d[n]-1 << '\n';
}