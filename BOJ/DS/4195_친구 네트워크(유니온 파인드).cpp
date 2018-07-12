#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string, string>p;
unordered_map<string, int>sum;
unordered_map<string, bool>check;

string find(string n) {
	if (p[n]=="root")return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(string a, string b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
	sum[a] += sum[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		p.clear();
		check.clear();
		sum.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (!check[a]) {
				sum[a] = 1;
				p[a] = "root";
				check[a] = true;
			}
			if (!check[b]) {
				sum[b] = 1;
				p[b] = "root";
				check[b] = true;
			}
			merge(a, b);
			cout << sum[find(a)]<< '\n';
		}
	}
}