#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		bool flag = false;
		int m, n, a, b;
		cin >> m >> n >> a >> b;
		int lcm = m * n / gcd(m, n);
		for (int i = 0, j = 0; m*i+a <= lcm;) {
			int x = m * i + a;
			int y = n * j + b;
			if (x>y)j++;
			else if (x<y)i++;
			else {
				cout << x << '\n';
				flag = true;
				break;
			}
		}
		if (!flag)cout << -1 << '\n';
	}
}