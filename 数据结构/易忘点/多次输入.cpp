
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	vector<string> v;
	cout << "please input the count of number:";
	int count;
	cin >> count;
	cout << "please input the number" << endl;
	for (int i = 0; i < count; i++) {
		string ch;
		cin >> ch;
		v.push_back(ch);	
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
} 
