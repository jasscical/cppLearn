#include <iostream>
#include <vector>
using namespace std;

int main(){
	cin >> n >> m;
	vector<int> a;  // ��� a 
	unordered_multiset<int> b;  // ��� b 
	int ai, bi;
	for(int i = 0; i < n; ++i){
	  cin >> ai;
	  a.push_back(ai);
	 }
	 
	 for(int i = 0; i < n; ++i){
	  cin >> bi;
	  b.insert(bi);
	 }
	 
	 int x = 0, flag = 1;
	 while (flag){
	  flag = 0;
	  
	  unordered_multiset<int> res; // res = (a+x)%m 
	  for(int i = 0; i < n; ++i){
	    res.insert( (a[i] + x) % m);
	  }
	  
	for(auto i = res.begin(); i != res.end(); ++i){ // res��ÿһ���� b�п��Ƿ��ҵõ� 
	   if (res.count(*i) != b.count(*i)) {
	    ++x;
	    flag = 1;
	    break;
	   }  
	  }
	 }
	 cout << x;			
} 
