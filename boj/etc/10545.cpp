#include <iostream>
#include <string>

using namespace std;

int a[9],b[26],cnt[26];
string key="033333434";

int main(){
	for(int i=1;i<=9;i++){
		int x;
		cin >> x;
		a[x]=i;
	}
	int idx=0;
	for(int i=0;i<9;i++){
		int x=key[i]-'0';
		for(int j=0;j<x;j++){
			b[idx+j]=a[i+1];
			cnt[idx+j]=j+1;
		}
		idx+=x;
	}
	string s;
	cin >> s;
	int last;
	for(int i=0;s[i];i++){
		int x=s[i]-'a';
		if(i!=0&&b[last]==b[x])cout << '#';
		for(int j=0;j<cnt[x];j++)cout << b[x];
		last=x;
	}
}
