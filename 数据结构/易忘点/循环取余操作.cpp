#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> nums = {1, 2, 3, 4, 5};
	int temp = 0;
	int count = 0; 
	// i = (i + 1) % nums.size() 
	for(int i = 0; i < nums.size(); i = (i + 1) % nums.size()){
		cout << nums[i] << " ";
		++count;
		++temp;
		if(temp == 100) return 0;
		if(count % 5 == 0) cout << endl;
	}
} 
