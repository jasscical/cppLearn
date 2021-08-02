#include <iostream>
#include <string>
using namespace std;

string& replace_all(string& src, const string& oldStr, const string& newStr){
	/*
	for(auto pos = 0; pos != string::npos; pos += newStr.length()){
		// src.find(oldStr, pos) 在字符串src的pos位置开始找字符串oldStr
		//  src.replace(pos, oldStr.length(), newStr) 在字符串src的pos位置开始后的 oldStr.length()个位置 替换为newStr 
		if((pos = src.find(oldStr, pos)) != string::npos){
			src.replace(pos, oldStr.length(), newStr);
		}else break;
	}
	*/
	
	string::size_type pos = 0;
	while((pos = src.find(oldStr, pos)) != string::npos){
		src.replace(pos, oldStr.size(), newStr);
		pos += oldStr.size();
	}
	return src;
}

int main(){
	string src = "aaaaaaabbbbccdxgdddssaaa";
	string oldStr = "aa";
	string newStr = "^_^";
	string repStr = replace_all(src, oldStr, newStr);
	cout << repStr << endl;
} 
