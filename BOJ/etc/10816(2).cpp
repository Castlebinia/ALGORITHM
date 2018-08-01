#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	multiset<int>s;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		cout << s.count(x) << ' ';
	}
	cout << '\n';
}