#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class mystack {
public:
	int index;
	char *arr;
	mystack() {
		index = 0;
		arr = new char[300000];
	}
	~mystack() { delete[] arr; }
	void push(char x) {
		arr[index++] = x;
	}
	void pop() {
		index--;
	}
	bool empty() {
		return index == 0;
	}
	int size() {
		return index;
	}
	char top() {
		return arr[index-1];
	}
};

int main() {
	char a[25];
	char t[300000];
	scanf("%s %s", a, t);
	int a_size = strlen(a);
	int t_size = strlen(t);
	mystack left, right;
	int li = 0;
	int ri = t_size - 1;
	bool finl = false;
	while (li <= ri && li<t_size && ri>=0) {
		if (!finl) {
			left.push(t[li++]);
			if (left.size() >= a_size) {
				bool check = true;
				for (int i = left.size() - a_size,j=0; j < a_size;i++,j++) {
					if (left.arr[i] != a[j]) {
						check = false;
						break;
					}
				}
				if (check) {
					for (int k = 0; k < a_size; k++)left.pop();
					finl = true;
				}
			}
		}
		else {
			right.push(t[ri--]);
			if (right.size() >= a_size) {
				bool check = true;
				for (int i = right.size()-1,j=0; j<a_size;i--,j++) {
					if (right.arr[i] != a[j]) {
						check = false;
						break;
					}
				}
				if (check) {
					for (int k = 0; k < a_size; k++)right.pop();
					finl = false;
				}
			}
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
		bool check = true;
		for (int i = right.size() - 1, j = 0; j < a_size; i--, j++) {
			if (right.arr[i] != a[j]) {
				check = false;
				break;
			}
		}if (check) {
			for (int k = 0; k < a_size; k++)right.pop();
		}
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	
}