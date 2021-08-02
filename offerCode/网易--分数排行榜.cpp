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
		cin >> N; // N��������� 
		int P, S; // ���P��Ӧ���� 
		vector<vector<int>> g(N, vector<int>(2, 0)); 
		unordered_set<int> set;
		int count = 0;
		int res = 0;
		for(int j = 0; j < N; j++){
			cin >> P >> S;
			
			// ������� 
			if(set.count(P) == 0){ //ǰ��Ҳ��ڰ� 
				count++;
				set.insert(P);
				g.push_back({P, S}); // ���һ��������� 
			}
			if(set.count(P) != 0){ // ��ǰ����Ѿ��ڰ� 
				for(auto g1:g){
					if(g1[0] == P){ // �ڰ����ҵ������ 
						if(S > g1[1]){ // ���Ƿ���
							g1[1] = S;
						}
					}
				}
			}
			
			sort(g.begin(), g.end(), cmp); // ��������-�����Ű� 
			
			float halfN = 0; // ȡ��λ��
			if(count&1){ // ���Ϊ���� 
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
