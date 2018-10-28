#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>tmp, pre, in, iin;


void foo(int pl, int pr, int il, int ir) {
	if (pl > pr)return;
	int root = pre[pl];
	int pos = iin[root];
	int left = pos - il;
	foo(pl + 1,pl+left, il, pos - 1);
	foo(pl + left + 1, pr, pos + 1, ir);
	cout << root << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	while (cin >> x) {
		tmp.push_back(x);
	}
	int n = tmp.size();
	pre = tmp;
	sort(tmp.begin(), tmp.end());
	in = tmp;
	iin.resize(1000001);
	for (int i = 0; i < tmp.size(); i++) {
		iin[in[i]] = i;
	}
	foo(0, n - 1, 0, n - 1);
}