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
	cout << endl; 
}


//��λ��
int getDig(int nums){
	int res = 0;
	while(nums){
		res++;
		nums /= 10;
	}	
	return res;
}


//�õ��������������� λ�� 
int getMaxDig(vector<int>& nums){
	// �ҳ�nums���ֵ
	int max = INT_MIN;
	for(auto n:nums){
		max = (n > max) ? n : max; 
	}	
	// �����ֵλ��
	return getDig(max);
}


//�õ�һ�����ĵ� d ��ʮ����λ�����֣����� nums = 123, d = 3,���Ӧ��λ��1������1  
// �� nums = 12, d = 3��ô����
// nums = 012,�� 0  ---> ( x / ((int)pow(10, d-1)) )  % 10 ����Ϳ���ʵ������������������� 
int getDigit(int x, int d){
	return ( ( x / ((int)pow(10, d-1)) )  % 10);		
}


void process(vector<int>& nums, int L, int R, int digit){
	const int radix = 10;  //radix ���� 
	int i = 0, j = 0;
	vector<int> bucket(R-L+1, 0);
	for(int d = 1; d <= digit; d++){ //�� 1 ~ digitλ�ϵ�ÿһλ�������µĲ��� 
		
		// 1.��¼ nums[i]�У�dλ�϶�Ӧ�����ֳ��ּ���
		vector<int> count(radix, 0);
		for(i = L; i <= R; i++){
			j = getDigit(nums[i], d);
			count[j]++;
		} 
		
		// 2.��count���count' ,������ count[i] = count[i]+count[i-1], ͳ��С�ڵ��ڵ�ǰλ�õĴ���֮�� 
		// �˹��̺� count������count�� 
		for(i = 1; i < radix; i++){
			count[i] = count[i] + count[i-1];
		}
		
		// 3.�����������nums,���count��,�ŵ�Ͱbucket��
		// nums[i]��dλ����j��Ȼ��ȥcount'�ҵ���Ӧ������count[j]���� 0~count[j]-1�ķ�Χ���������һ��λ�� 
		// �� bucket[count[j]-1] = nums[i]
		for(i = R; i >= L; i--){
			j = getDigit(nums[i], d);
			bucket[count[j]-1] = nums[i];
			count[j]--;
		} 
		
		// 4.��Ͱ�е����ָ��ƻ�nums
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
