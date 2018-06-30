#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fail[1000001];

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main() {
	string s, w;
	int n;
	cin >> n;
	s.resize(n);
	w.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> w[i];
	s = s + s;
	s=s.substr(0, 2 * n - 1);
	int m = w.size();
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && w[i] != w[j])j = fail[j - 1];
		if (w[i] == w[j])fail[i] = ++j;
	}
	int ret = 0;
	int N = s.size();
	for (int i = 0, j = 0; i <N ; i++) {
		while (j > 0 && s[i] != w[j])j = fail[j - 1];
		if (s[i] == w[j]) {
			if (j == m - 1) {
				ret++;
				j = fail[j];
			}
			else j++;
		}
	}
	int g = gcd(ret, n);
	n /= g;
	ret /= g;
	cout << ret << '/' << n << '\n';

}