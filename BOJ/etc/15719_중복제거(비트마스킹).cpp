#include <iostream>
#include <set>

using namespace std;
int c[(1 << 24)+1];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int x = a / 32;
		int y = a % 32;
		if (c[x] & (1 << y)) {
			cout << a << '\n';
			return 0;
		}
		c[x] += (1 << y);
	}
}