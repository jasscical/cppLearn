#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "abcdefghijklmnopqrstuvwxyz";
	string m = "meituan";
	int count = 0; // 统计轮数 
	int partial = 0;  //统计最终部分轮回 
	int size = m.size() - 1;
	for(int k = 0; k <= size; k++){
		if( k == size - 1 && m[k] < m[k + 1]){
			cout << "m[k] ~ m[k + 1]" << m[k] << m[k + 1] << endl;
			cout << "int -->m[k] ~ m[k + 1]" << (int)m[k] << (int)m[k + 1] << endl;
			partial = (int)m[k + 1] - (int)m[k] + 1;
			break;
		} 
		while(k <= size - 1 && m[k] < m[k + 1]){ //当前单词小于下一个单词，说明在共用一个轮回，就跳过 
			k++;
		}
		count++;	
	}
	int res = count * 26 + partial - m.size();
	cout << "count:" << count << " partial:" << partial << endl;
	cout << "cost :" << res;
} 
