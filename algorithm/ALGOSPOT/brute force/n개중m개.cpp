#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v) {
	for (auto a : v)cout << a << ' ';
	cout << '\n';
}

void foo(vector<int> &v, int n, int m) {
	if (m == 0) {
		print(v);
		return;
	}
	int first = v.empty() ? 0 : v.back() + 1;
	for (int i = first; i < n; i++) {
		v.push_back(i);
		foo(n, v, m-1);
		v.pop_back();
	}
}

int main() {
	vector<int> v;
	int n,m;
	cin >> n >> m;
	foo(v,n,m);
}