#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "abcdefghijklmnopqrstuvwxyz";
	string m = "meituan";
	int count = 0; // ͳ������ 
	int partial = 0;  //ͳ�����ղ����ֻ� 
	int size = m.size() - 1;
	for(int k = 0; k <= size; k++){
		if( k == size - 1 && m[k] < m[k + 1]){
			cout << "m[k] ~ m[k + 1]" << m[k] << m[k + 1] << endl;
			cout << "int -->m[k] ~ m[k + 1]" << (int)m[k] << (int)m[k + 1] << endl;
			partial = (int)m[k + 1] - (int)m[k] + 1;
			break;
		} 
		while(k <= size - 1 && m[k] < m[k + 1]){ //��ǰ����С����һ�����ʣ�˵���ڹ���һ���ֻأ������� 
			k++;
		}
		count++;	
	}
	int res = count * 26 + partial - m.size();
	cout << "count:" << count << " partial:" << partial << endl;
	cout << "cost :" << res;
} 
