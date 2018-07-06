#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		string s;
		cin >> s;
		if (s == "#")break;
		int pa = 0;
		for (int i = 0; s[i]; i++) {
			if (s[i] == '1')pa++;
		}
		int len = s.size();
		if ((s[len - 1] == 'e'&&pa % 2 == 0) || (s[len - 1] == 'o'&&pa % 2 != 0))s[len - 1] = '0';
		else s[len - 1] = '1';
		cout << s << '\n';
	}
}