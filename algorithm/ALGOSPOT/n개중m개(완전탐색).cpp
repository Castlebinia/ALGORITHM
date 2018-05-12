#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v) {
	for (auto a : v)cout << a << ' ';
	cout << '\n';
}
#include <algorithm>
void foo(int n,vector<int> &v, int limit) {
	if (limit == 0) {
		print(v);
		return;
	}
	int first = v.empty() ? 0 : v.back() + 1;
	for (int i = first; i < n; i++) {
		v.push_back(i);
		foo(n, v, limit - 1);
		v.pop_back();
	}
}

int main() {
	vector<int> v;
	foo(7, v, 4);
}