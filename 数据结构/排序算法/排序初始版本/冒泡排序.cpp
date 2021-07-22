#include <iostream>
#include <vector>
using namespace std;

//冒泡排序 

void swap(vector<int> &nums, int i, int j){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
void bubble_sort(vector<int> &nums){
	int index_max = nums.size()-1;
	int i, j, flag = 1;		// flag来标记是否有进行交换，如果在遍历 i 时，发现后面根本没有进行交换，也就是说后面都已经是有序的了，就停止遍历 
	for(i = 0; i<index_max, flag==1; i++){
		flag = 0;
		for(j=index_max; j>i; j--){	
			if(nums[j-1] > nums[j]){//前一个数更大说明这个数需要往后，后面那个数往前移动 
				swap(nums, j-1, j);
				flag = 1;	//	 发生过交换说明nums[i] 后面 元素并不是有序的 
			}else{
				continue;
			}
		}
	}
}

void printVec(vector<int> &nums){
	for(auto n:nums){
		cout << n << " ";
	}
	cout << endl;
}
int main(){
	vector<int> nums = {2, 1, 5, 3, 6, 4};
	bubble_sort(nums);
	printVec(nums);
	return 0;
}
