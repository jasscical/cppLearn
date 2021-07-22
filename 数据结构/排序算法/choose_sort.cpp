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


void choose_sort(vector<int> &nums){
	for(int i = 0; i<nums.size(); i++){ //遍历每一个数 
		int maxIndex = i;
		for(int j = i+1; j<nums.size(); j++){ //找最大值的下标 
			(nums[j] > nums[maxIndex]) ? (maxIndex = j) :(maxIndex=maxIndex);
		}
		swap_vec(nums, i, maxIndex); //将最大值交换到i的位置 ，完成了最大值选择到前面 
	}
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	print(nums);
	cout << endl;
	
	choose_sort(nums);
	
	print(nums);
	return 0;
} 
