#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < nums.size(); i++) nums[i] = i + 1;
	int left, right;
	while(k--){
		cin >> left >> right; 
		reverse(nums.begin() + left - 1, nums.begin() + right);
	}
	
	for(auto n:nums) cout << n << '\t';
	return 0;
} 

/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	int n, k, l, r;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) {
		v[i] = i + 1;
	}
	for (int i = 0; i < k; ++i) {
		cin >> l >> r;
		reverse(v.begin() + l - 1, v.begin() + r);
	}
	for (int i : v) {
		cout << i << " ";
	}
}

*/
