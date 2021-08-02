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


//求位数
int getDig(int nums){
	int res = 0;
	while(nums){
		res++;
		nums /= 10;
	}	
	return res;
}


//得到数组中最大的数的 位数 
int getMaxDig(vector<int>& nums){
	// 找出nums最大值
	int max = INT_MIN;
	for(auto n:nums){
		max = (n > max) ? n : max; 
	}	
	// 求最大值位数
	return getDig(max);
}


//得到一个数的第 d 个十进制位的数字，比如 nums = 123, d = 3,则对应百位的1，返回1  
// 当 nums = 12, d = 3怎么处理？
// nums = 012,补 0  ---> ( x / ((int)pow(10, d-1)) )  % 10 这个就可以实现上述所有情况！！！ 
int getDigit(int x, int d){
	return ( ( x / ((int)pow(10, d-1)) )  % 10);		
}


void process(vector<int>& nums, int L, int R, int digit){
	const int radix = 10;  //radix 基数 
	int i = 0, j = 0;
	vector<int> bucket(R-L+1, 0);
	for(int d = 1; d <= digit; d++){ //在 1 ~ digit位上的每一位进行如下的操作 
		
		// 1.记录 nums[i]中，d位上对应的数字出现几次
		vector<int> count(radix, 0);
		for(i = L; i <= R; i++){
			j = getDigit(nums[i], d);
			count[j]++;
		} 
		
		// 2.将count变成count' ,即计算 count[i] = count[i]+count[i-1], 统计小于等于当前位置的次数之和 
		// 此过程后 count即代表count’ 
		for(i = 1; i < radix; i++){
			count[i] = count[i] + count[i-1];
		}
		
		// 3.从右往左遍历nums,结合count’,放到桶bucket中
		// nums[i]的d位数字j，然后去count'找到对应的数字count[j]，在 0~count[j]-1的范围，放在最后一个位置 
		// 即 bucket[count[j]-1] = nums[i]
		for(i = R; i >= L; i--){
			j = getDigit(nums[i], d);
			bucket[count[j]-1] = nums[i];
			count[j]--;
		} 
		
		// 4.将桶中的数字复制回nums
		for(i = L, j = 0; i <= R; i++, j++){
			nums[i] = bucket[j];
		} 
	} 
}



void bucket_sort(vector<int> &nums){
	if(nums.size() < 2) return;
	int digit = getMaxDig(nums); 
	process(nums, 0, nums.size()-1, digit);
}

int main(){
	vector<int> nums;
	rand_nums(nums);
	
	cout << "before:" << endl;
	print(nums);
	cout << endl;
	
	bucket_sort(nums);
	
	cout << "after sort:" << endl;
	print(nums);
	return 0;
} 
