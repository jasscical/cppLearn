#inclede <bits/stdc++.h>
using namespace std;


string& leftStr(string& s){
	
}

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){ // T组数据 
		int N, M;
		string s;
		cin >> s; // R > S > C
		int start = 0;
		int end = 1;
		for(int j = 0; j < M; j++){ // 全组人 M 次猜拳 
			// 1.返回猜拳后的子字符串 
			if(s.length() == 1){
				cout << "1" << endl;
				break;
			}
			
						
			
			s = leftStr(s); 
		} 
		cout << s.length();		
	}
	
	
}
