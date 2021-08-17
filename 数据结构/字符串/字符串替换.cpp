#include <iostream>
#include <string>
using namespace std;

string& replace_all(string& src, const string& oldStr, const string& newStr){
	/*
	for(auto pos = 0; pos != string::npos; pos += newStr.length()){
		// src.find(oldStr, pos) ���ַ���src��posλ�ÿ�ʼ���ַ���oldStr
		//  src.replace(pos, oldStr.length(), newStr) ���ַ���src��posλ�ÿ�ʼ��� oldStr.length()��λ�� �滻ΪnewStr 
		if((pos = src.find(oldStr, pos)) != string::npos){
			src.replace(pos, oldStr.length(), newStr);
		}else break;
	}
	*/
	
	string::size_type pos = 0;
	while((pos = src.find(oldStr, pos)) != string::npos){
		src.replace(pos, oldStr.size(), newStr);
		pos += newStr.size();
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
