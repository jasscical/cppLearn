#include <iostream>
#include <vector>
using namespace std;

int main(){
	cin >> n >> m;
	vector<int> a;  // 存放 a 
	unordered_multiset<int> b;  // 存放 b 
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
	  
	for(auto i = res.begin(); i != res.end(); ++i){ // res中每一个在 b中看是否找得到 
	   if (res.count(*i) != b.count(*i)) {
	    ++x;
	    flag = 1;
	    break;
	   }  
	  }
	 }
	 cout << x;			
} 
