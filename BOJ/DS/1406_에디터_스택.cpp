#include <iostream>
#include <string>
#include <stack>

using namespace std;

string text;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	stack<char> left, right;
	cin >> text;
	int len = text.length();
	for (int i = 0; i <len; i++) {
		left.push(text[i]);
	}
	int num;
	cin >> num;
	char n, in;
	while (num--) {
		cin >> n;
		switch (n) {
		case 'L':
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;

		case 'B':
			if (!left.empty())left.pop();
			break;
		case 'P':
			cin >> in;
			left.push(in);
			break;

		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}