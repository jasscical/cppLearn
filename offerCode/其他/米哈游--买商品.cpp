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
	�ܵ�˼·������������������һ���ض������£��������������ּ�ֵ��󣬵��������������� <= ����������
				���������� >= m �ſ��ԣ����Բ��ܽ�m��Ϊ������������Ȼ������� <= m����ӽ�m������ 
				
				��ô����������һ����С�� >= m ����ֵx �Ͷ�Ӧ�� ������ -  x �����ֵ 
				
				���Խ�������Ʒ��ֵ�����Ϊ�ܱ�����������ȥ��Ҫ�����Ŀ��m�������ֵ��Ϊ�µı���
				���µı��������ܵ���������ô��� �ܱ��� - �µı�����Ϊ����
				
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
