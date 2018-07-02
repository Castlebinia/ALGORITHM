#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string s[5001];
int fail[5001][5001];
vector<int>p;

void foo(string s, int l) {
	p.clear();
	p.resize(l);
	for (int i = 1, j = 0; i < l; i++) {
		while (j > 0 && s[i] != s[j])j = p[j - 1];
		if (s[i] == s[j])p[i] = ++j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string w;
	cin >> w;
	int m = w.size();
	s[0] = w;
	for (int i = 1; i < m; i++) {
		s[i] = w.substr(i);
	}
	int ret = 0;
	for (int i = 0; i < m; i++) {
		foo(s[i], m - i);
		for (auto x : p)ret = max(ret, x);
	}
	cout << ret << '\n';
}