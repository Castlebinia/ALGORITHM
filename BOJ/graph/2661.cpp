#include <iostream>
#include <string>
#include <vector>

using namespace std;
char a[3] = { '1','2','3' };
bool flag;

bool foo(string s) {
	int len = s.size();
	int m = len / 2;
	for (int j = len - 1, k = 1; k <= m;k++,j--) 
		if (s.substr(j)==s.substr(j-k,k))return true;
	return false;
}

void solve(int x, int n, string s) {
	if (flag)return;
	if (foo(s))return;
	if (x == n) {
		cout << s << '\n';
		flag = true;
		return;
	}
	for (int i = 0; i < 3; i++) {
		solve(x + 1, n,s + a[i]);
	}
}

int main() {
	int n;
	cin >> n;
	solve(1, n,"1");
}