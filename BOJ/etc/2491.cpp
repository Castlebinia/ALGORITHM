#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int last;
	int ret = 1, bret = 1, sret = 1;
	cin >> last;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		if (x < last) {
			sret++;
			ret = max({ ret,bret, sret });
			bret = 1;
		}
		else if (x > last) {
			bret++;
			ret = max({ ret,bret,sret });
			sret = 1;
		}
		else {
			sret++;
			bret++;
			ret = max({ ret,bret,sret });
		}
		last=x;
	}
	cout << ret << '\n';
}