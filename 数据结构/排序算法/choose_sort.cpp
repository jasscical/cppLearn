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


void choose_sort(vector<int> &nums){
	for(int i = 0; i<nums.size(); i++){ //����ÿһ���� 
		int maxIndex = i;
		for(int j = i+1; j<nums.size(); j++){ //�����ֵ���±� 
			(nums[j] > nums[maxIndex]) ? (maxIndex = j) :(maxIndex=maxIndex);
		}
		swap_vec(nums, i, maxIndex); //�����ֵ������i��λ�� ����������ֵѡ��ǰ�� 
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
