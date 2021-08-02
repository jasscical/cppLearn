#include <iostream>
#include <vector>
#include <algorithm> 
#define Num 100 

using namespace std;


//��������� 
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


int merge(vector<int> &nums, int l, int mid, int r){//�ϲ� l~mid, mid~r���������� 
	
	vector<int> tmp(r-l+1, 0);
	//int *tmp = new int[r-l+1];
	
	int p1 = l;
	int p2 = mid+1;
	int i = 0;	
	int res = 0; //---С���� 	
	while(p1 <=mid && p2 <=r){
		
		res += nums[p1]<nums[p2] ? nums[p1] *(r-p2+1) : 0; //---С���� 
		
		tmp[i++] = (nums[p1] <= nums[p2]) ? (nums[p1++]) : (nums[p2++]);
		//nums[p1]<=nums[p2] ? tmp.push_back(nums[p1++]) : tmp.push_back(nums[p2++]);
	}
	while(p1<=mid){
		//tmp.push_back(nums[p1++]);
		tmp[i++] = nums[p1++];
	}
	while(p2<=r){
		//tmp.push_back(nums[p2++]);
		tmp[i++] = nums[p2++];
	}
	for(int j = 0; j<(r-l+1)&&(l+j)<=r; j++){
		nums[l+j] = tmp[j];
	}
	
	return res;	//---С���� 
}

int process(vector<int> &nums, int l, int r){
	if(l == r) return 0;
	
	int mid = l+((r-l)>>1);
	
//	process(nums, l, mid);
//	process(nums, mid+1, r);
//	merge(nums, l, mid, r);
	
	return process(nums, l, mid) + process(nums, mid+1, r) + merge(nums, l, mid, r);
}

int merge_sort(vector<int> &nums){
	if(nums.size() < 2){
		return 0;
	}
	return process(nums, 0, nums.size()-1);
}


int main(){
	// ��һ�������У�ÿһ������߱ȵ�ǰ��С�����ۼ�������������������С�͡���һ������ ��С�͡�
	// ����һ��˼·�ǣ���һ����digit�ұ��ж��ٸ���������n����������ô �����������С�� n*digit 
	vector<int> nums{1,3,3,2,5}; //1+ 1 +1 +1+3+3+2= 4*1 + 1*3 + 1*3 + 1*2 =12
	//rand_nums(nums);
	
	cout << "before sort" << endl;
	print(nums);
	cout << endl;
	
	int smallSum = merge_sort(nums);
	
	cout << "after sort" << endl;
	print(nums);
	cout << endl;
	
	cout << "small sum: " << smallSum << endl;
	
	return 0;
} 
