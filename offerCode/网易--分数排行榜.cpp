#include <bits/stdc++.h>
using namespace std;


static bool cmp(const vector<int>& a, const vector<int>& b){
	return a[1] > b[1]; 
}

int main(){
	int T;
	cin >> T;
	int N;
	//vector<int> resV(T, 0);
	for(int i = 0; i < T; i++){
		cin >> N; // N个玩家数据 
		int P, S; // 玩家P对应分数 
		vector<vector<int>> g(N, vector<int>(2, 0)); 
		unordered_set<int> set;
		int count = 0;
		int res = 0;
		for(int j = 0; j < N; j++){
			cin >> P >> S;
			
			// 几个玩家 
			if(set.count(P) == 0){ //前玩家不在榜 
				count++;
				set.insert(P);
				g.push_back({P, S}); // 添加一个玩家数据 
			}
			if(set.count(P) != 0){ // 当前玩家已经在榜 
				for(auto g1:g){
					if(g1[0] == P){ // 在榜上找到该玩家 
						if(S > g1[1]){ // 覆盖分数
							g1[1] = S;
						}
					}
				}
			}
			
			sort(g.begin(), g.end(), cmp); // 按分数高-》低排榜 
			
			float halfN = 0; // 取中位数
			if(count&1){ // 玩家为奇数 
				halfN = g[count/2][1];
			}
			else{
				halfN = (g[count/2][1] + g[count/2 - 1][1]) / 2;
			}
			if(g[j][1] == halfN){
				res++;
			}
		}
		cout << res << endl; 
		//resV.push_back(res);
	}
	/*
	for(auto r:resV){
		cout << r << endl;
	}
	*/
} 
