#include <iostream>
#include <algorithm>

using namespace std;

int n=5,a[5];

int gcd(int a,int b){ return b?gcd(b,a%b):a;}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ret=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int tmp=a[i]*a[j]/gcd(a[i],a[j]);
				ret=min(ret,tmp*a[k]/gcd(tmp,a[k]));
			}
		}
	}
	cout << ret;
}

