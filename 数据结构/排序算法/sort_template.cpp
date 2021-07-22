#include <iostream>
#include <vector>
#include <algorithm> 
#define Num 100 

using namespace std;


//产生随机数 
void rand_nums(vector<int> &temp)
{
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }
    random_shuffle(temp.begin(), temp.end());
}






void swap_vec(vector<int> &nums, int i, int j){
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void print(vector<int> &nums){
	for(int i = 0; i<nums.size(); i++){
		cout << nums[i] << " ";
		if((i+1)%10 == 0) cout << "\n";
	}
	cout << endl; 
}


void func_sort(vector<int> &nums){

}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	cout << "before:" << endl;
	print(nums);
	cout << endl;
	
	func_sort(nums);
	
	cout << "after sort:" << endl;
	print(nums);
	return 0;
} 
