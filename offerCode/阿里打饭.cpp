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
	while(t--){ // ����t������
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){ // ���� n ��ѧ�������� 
			cin >> s[i].L >> s[i].R;
			s[i].id = i + 1;
		} 
		
		sort(s, s + n, cmp); // �� n ��ѧ����������
		
		int time = s[0].L; // �ʼ��з�ʱ�� ���з�ʱ�������ۼӵ� 
		for(int j = 0; j < n; j++){ //�� n ��ѧ������з�ʱ����м�¼ 
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
