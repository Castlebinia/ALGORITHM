#include <iostream>

using namespace std;

int ccw(int x1,int x2,int x3,int y1,int y2,int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp -= (y1*x2 + y2 * x3 + y3 * x1);
	if (temp > 0)return 1;
	else if (temp < 0)return -1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << ccw(x1, x2, x3, y1, y2, y3) << '\n';
}