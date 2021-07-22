#include <iostream>
#include <vector>
#include <algorithm> 
#define Num 10 

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

void heap_insert(vector<int> &nums, int index){
	while(nums[index] > nums[(index-1)/2]){
		swap_vec(nums, index, (index-1)/2);
		index = (index-1)/2;
	}
}
void heapify(vector<int> &nums, int index, int heapSize){
	int left = 2 * index + 1;
	while(left < heapSize){
		int largest = left+1 < heapSize && nums[left+1] > nums[left]
					? left+1
					: left;
		largest = nums[largest] > nums[index]
					? largest
					: index;
		if(largest == index) break;
		swap_vec(nums, index, largest);
		index = largest;
		left = 2 * index + 1;
	}
}
void heap_sort(vector<int> &nums){
	if(nums.size() < 2){
		return;
	}
	
	for(int i=0; i<nums.size();i++){
		heap_insert(nums, i);
	}
	
	cout << "after heapInsert, nums: " << endl;
	print(nums); 
	cout << endl;
	
	int heapSize = nums.size();
	swap_vec(nums, 0, --heapSize);	// 0位置 跟 最后一个位置 交换完 ，然后--表示断连最后一个位置 
	while(heapSize > 0){
		heapify(nums, 0, heapSize);
		swap_vec(nums, 0, --heapSize);
	}
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	print(nums);
	cout << endl;
	
	heap_sort(nums);
	
	print(nums);
	return 0;
} 
