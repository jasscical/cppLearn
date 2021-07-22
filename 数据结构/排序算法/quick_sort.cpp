#include <iostream>
#include <vector>
#include <algorithm> 
#define Num 100

using namespace std;
// 快排
// 时间复杂度 O(N*logN) 



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



vector<int> partition(vector<int>& nums, int L, int R) {
	int index = L;
	int less = L - 1;
	int more = R;  // 这里相当于将nums[L...R-1] 玩partion, 最后一个位置 R 是不参与，所以后面进行swap(nums,R, more) 
	int p = nums[R]; //以最后一个数作为划分值 p 
	while (index < more) {
		if (nums[index] < p) {
			swap_vec(nums, index++, ++less);
		}
		else if (nums[index] > p) {
			swap_vec(nums, index, --more);
		}
		else {
			index++;
		}
	}
	swap_vec(nums, R, more);   
	return vector<int> {less + 1, more}; //这个表示 ==p 的区域 

}

void process(vector<int>& nums, int L, int R){
	if(L < R){
		// 取得[a,b)的随机整数：rand()%(b-a)+a；
		// 取得[a,b]的随机整数：rand()%(b-a+1)+a； 
		swap_vec(nums, (rand()%(R-L+1)) + L, R);  //将nums中的随机一个数放到最后一个位置 R 
		
		// 这一步就是将nums[L,R]做partition,partition过程：nums[R]为划分值，对nums[L...R-1]划分 
		vector<int> pos =  partition(nums, L, R); // 返回 < == > 这个范围最左\最右边界 
		
		process(nums, L, pos[0]-1); // <区 
		process(nums, pos[1]+1, R); // >区 
	}
}

void quick_sort(vector<int> &nums){
	if(nums.size() < 2) return;
	process(nums, 0, nums.size()-1); // 传入下标 
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	cout << "before:" << endl;
	print(nums);
	cout << endl;
	
	quick_sort(nums);
	
	cout << "after sort:" << endl;
	print(nums);
	return 0;
} 
