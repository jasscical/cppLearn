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
}


void bubble_sort(vector<int> &nums){
	int flag = 1;
	for(int i=0; i<nums.size() && flag; i++){
		for(int j=nums.size()-1; j>i; j--){
			flag = 0;
			if(nums[j] > nums[j-1]){
				swap_vec(nums, j, j-1);
				flag = 1;
			}
		}
	}
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	print(nums);
	cout << endl;
	
	bubble_sort(nums);
	print(nums);
	return 0;
} 
