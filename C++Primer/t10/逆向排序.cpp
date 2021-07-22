#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> nums = {11,2,33,24,5};
	for(auto n:nums) cout << n << " ";
	cout << endl;
	// ÕýÐò 
	sort(nums.begin(), nums.end());
	for(auto n:nums) cout << n << " ";	
	cout << endl;
	
	// ÄæÐò 
	sort(nums.rbegin(), nums.rend());
	for(auto n:nums) cout << n << " ";
	
}
 
