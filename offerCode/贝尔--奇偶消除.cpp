#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin >> n;
	vector<int> v;
	int t;
	for(int i = 0; i < n; i++){	 
		cin >> t;
		v.push_back(t);
	}
	
	sort(v.begin(), v.end());
	
	int res =  (n & 1) == 1 ? v[n / 2] : v[n /2 - 1];
	cout << "res = " << res << endl;	
} 
