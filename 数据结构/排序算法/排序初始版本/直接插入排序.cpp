#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int> &nums){
	int i, j, index_max = nums.size()-1;
	for(i=1; i<=index_max; i++){	//	i从第二个数循环到最后一个数 
		int tmp = nums[i];
		for(j=i-1; j>=0; j--){	// j从 i 的前一个循环到第一个：就是看i之前的 有没比 nums[i](tmp),更大的，把它移到后面 
			if(nums[j] > tmp){
				nums[j+1] = nums[j];
			}else{
				break;
			}
			
		}
		nums[j+1] = tmp; //移动完后，将 tmp 插入到 它该到的位置 
	}
}

void printVec(vector<int> &nums){
	for(auto n:nums){
		cout << n <<"  ";
	}
	cout << endl;
} 

int main(){
	vector<int> nums = {2, 7, 9, 6, 10, 5, 8, 4, 3, 1};	//
	insert_sort(nums);
	printVec(nums);
	return 0;
}
