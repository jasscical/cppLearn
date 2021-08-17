#include <iostream>
#include <vector>
using namespace std;

int main(){
	int x[10];
	//int *p = x;
	int a = 4;
	int *p = &a;
	// 一个指针是4B
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "sizeof(*x) = " << sizeof(*x) << endl;
	cout << "sizeof(p) = " << sizeof(p) << endl;
	cout << "sizeof(*p) = " << sizeof(*p) << endl;
	
	cout << sizeof(x)/sizeof(*x) << endl;
	cout << sizeof(p)/sizeof(*p) << endl;
	return 0;
}
