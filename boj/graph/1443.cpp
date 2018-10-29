#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
map<string, bool>check;

int d, p, limit=1, ret=-1;
string tmp = "00000000";
void foo(int x, int cnt) {
	if (x >= limit)return;
	if (check.count(tmp))return;
	check[tmp] = true;
	if (cnt == p) {
		ret = max(ret, x);
		return;
	}
	for (int i = 2; i <= 9; i++) {
		tmp[i-2]++;
		foo(x*i, cnt + 1);
		tmp[i-2]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> d >> p;
	for (int i = 0; i < d; i++)limit *= 10;
	foo(1, 0);
	cout << ret << '\n';
}
