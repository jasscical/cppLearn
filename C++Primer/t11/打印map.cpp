#include <map>
#include <iostream>

using namespace std;

int main(){
	map<string, int> smap = { {"A", 3}, {"S", 5}, {"D", 1}, {"F", 2}, {"G", 6}};
	map<string, int> smap_copy;
	smap_copy.insert(smap.begin(), smap.end()); 
	
	auto iter = smap_copy.begin();
	while(iter != smap.cend()){
		// Ĭ�ϰ� key ���ֵ���������� 
		//cout << iter->first << "-" << iter->second << endl;
		cout << (*iter).first << "-" << (*iter).second << endl;  // ���������һ��Ҫ����()  !!!! 
		iter++;
	}
}
