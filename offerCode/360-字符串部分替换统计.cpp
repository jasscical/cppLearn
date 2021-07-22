#include <vector>
#include <string>
#include <iostream> 
#include <algorithm> 
using namespace std;

string& replace_all(string& src, const string& old_value, const string& new_value) {
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;
}


int main(){
	string str;
	cin >> str;
	const int bigNum = 1000000007;
	string oldStr = "a";
	string newStr = "^";
	int count = 0;

	while(str.find(oldStr) != string::npos){
		replace_all(str, oldStr, newStr);
		//count++;
		count = (count + 1) % bigNum;
	}
	
	//replace(str.begin(), str.end(), oldStr, newStr); // ���ܴ����ַ��� 
	cout << "count = " << count << endl;
} 
