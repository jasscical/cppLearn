#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	int L;
	int R;
	int id;
}s[10001];

static bool cmp(const Student& a, const Student& b){
	return (a.L == b.L) ? (a.id < b.id) : (a.L < b.L);
}

int main(){
	int t;
	cin >> t;
	while(t--){ // 输入t组数据
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){ // 输入 n 个学生的数据 
			cin >> s[i].L >> s[i].R;
			s[i].id = i + 1;
		} 
		
		sort(s, s + n, cmp); // 对 n 个学生数据排序
		
		int time = s[0].L; // 最开始领盒饭时间 ，盒饭时间是在累加的 
		for(int j = 0; j < n; j++){ //对 n 个学生的领盒饭时间进行记录 
			if(time < s[j].L) time = s[j].L;   
			if(time >= s[j].L && time <= s[j].R){
				cout << time << " ";
				time++;
			}
			else{
				cout << "0" << " ";
			}
		} 
		cout << endl;
	}
}
