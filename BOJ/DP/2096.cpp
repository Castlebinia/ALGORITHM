#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[3], d1[3], d2[3], t[3];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) cin >> a[j];
		t[0] = d1[0], t[1] = d1[1], t[2] = d1[2];
		d1[0] = max(t[0],t[1]) + a[0];
		d1[1] = max({ t[0],t[1],t[2] }) + a[1];
		d1[2] = max(t[1], t[2]) + a[2];
		t[0] = d2[0], t[1] = d2[1], t[2] = d2[2];
		d2[0] = min(t[0], t[1]) + a[0];
		d2[1] = min({ t[0],t[1],t[2] }) + a[1];
		d2[2] = min(t[1], t[2]) + a[2];
	}
	cout << max({ d1[0],d1[1],d1[2] }) << ' ' << min({ d2[0],d2[1],d2[2] }) << '\n';
}