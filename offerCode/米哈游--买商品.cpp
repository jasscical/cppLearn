#include <bits/stdc++.h>
using namespace std;


int main(){	 
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		v.push_back(t);
	}
	
	int sum = accumulate(v.cbegin(), v.cend(), 0);
	/*
	总的思路：背包问题解决的是在一个特定容量下，尽可能塞满，又价值最大，但是塞的容量总是 <= 背包容量，
				本题是满足 >= m 才可以，所以不能将m作为背包容量，不然所求的是 <= m中最接近m的容量 
				
				那么反过来，找一个最小的 >= m 容量值x 就对应着 总容量 -  x 的最大值 
				
				所以将所有商品价值相加作为总背包容量，减去需要凑齐的目标m，这个差值作为新的背包
				往新的背包尽可能的塞满，那么最后 总背包 - 新的背包即为所求
				
	*/ 
	
	
	int bagWeight = sum - m;
	if(bagWeight <= 0) {
		cout << sum << endl;
		return 0;
	}
	vector<int> dp(bagWeight + 1, 0); 
	for(int i = 0; i < v.size(); i++){
		for(int j = bagWeight; j >= v[i]; j--){
			dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
		}
	}
	int res = sum - dp[bagWeight];
	cout << "res = " << res << endl;
}
