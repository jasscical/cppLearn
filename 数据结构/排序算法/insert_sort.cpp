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


void insert_sort(vector<int> &nums){
	for(int i = 1; i<nums.size(); i++){
		for(int j = i-1; j>=0; j--){ // 将i之前的数都比较一遍，并把更大的数放到前面 
			if(nums[j+1] > nums[j]){
				swap_vec(nums, j, j+1);
			}
		}
	}
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	print(nums);
	cout << endl;
	
	insert_sort(nums);
	print(nums);
	
	return 0;
} 
