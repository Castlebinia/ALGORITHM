#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<int>p;
const int MAX = 1000001;
int fail[MAX];

void foo(string w, int len) {
	memset(fail, 0, sizeof(fail));
	p.clear();
	p.resize(len);
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && w[i] != w[j])j = fail[j - 1];
		if (w[i] == w[j])fail[i] = ++j;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		string s;
		cin >> s;
		int n = s.size();
		if (s == ".")break;
		foo(s, n);
		double tmp = (double)fail[n - 1] / n;
		for (int i = 1; i < MAX; i++) {
			if ((double)(i - 1) / (double)i == tmp) {
				cout << i << '\n';
			}
		}
	}
}