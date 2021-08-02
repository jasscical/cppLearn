#include <bits/stdc++.h>
using namespace std;

int main{
	int n, T;
	cin >> n >> T;
	int tmp;
	vector<int> a;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	
	int u, v, w, half = n - 1, all = 2 *(n - 1);
	
	vector<vector<int>> cost(all, vector<int>(3, 0));
	for(int i = 0; i < half; i++){
		cin >> u >> v >> w;
		// ÕýÏò 
		v[i][0] = u;
		v[i][1] = v;
		v[i][2] = w;
		// ÄæÏò 
		v[all - i - 1][0] = v;
		v[all - i - 1][1] = u;
		v[all - i - 1][2] = w;
	}
	int t = 0, ;
	a_max = INT_MIN;
	while()
	
		
}
