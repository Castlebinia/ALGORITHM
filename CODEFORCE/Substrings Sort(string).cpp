#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, string>>v(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v[i] = { s.length(),s };
	}
	sort(v.begin(), v.end());
	for (int i =n-1 ; i>0; i--) {
		if (v[i].second.find(v[i - 1].second) == string::npos) { //찾는 게 없으면 npos 반환
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << v[i].second << '\n';
	}
}