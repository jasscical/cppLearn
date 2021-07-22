#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 0) return 0;
	
	int zeroNum = 0;
	int oneNum = 0;
	vector<int> nums(n);

	/*
	for(int i = 0; i < n; i++){
		//cin >> nums[i];
		scanf("%d", &nums[i]);
		nums[i] == 0 ? zeroNum++ : oneNum++;
	}
	*/
	
	int k = 0;
	while(k < n && cin >> nums[k]){
		nums[k] == 0 ? zeroNum++ : oneNum++;
		k++;
	}
	
	cout << zeroNum  << ", "<< oneNum << endl;
	int maxSub = abs(zeroNum - oneNum);  // 保存最大差值 
	cout << maxSub << endl;
	
	int i = 0;
	while(i < nums.size()){
		int zero = 0;
		int one = 0;
		for(int j = i; j < i + 3 && j < nums.size() - 2; j++){
			nums[j] == 0 ? zero++ : one++;
		}
		int subTmp = abs( (zeroNum - zero) - (oneNum - one) ); // 假如这连续三个消除，产生的差值 
		cout << "i = " << i << ", subTmp = " << subTmp << ", maxSub = " << maxSub << endl;
		if(subTmp > maxSub){
			maxSub = subTmp;
			zeroNum = zeroNum - zero;
			oneNum = oneNum - one;
			i += 3; 
		}else{
			i += 1;
		}
	}
	
	cout << "maxSub = " << maxSub << endl;
	
	return 0;
} 
