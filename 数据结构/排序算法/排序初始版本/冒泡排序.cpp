#include <iostream>
#include <vector>
using namespace std;

//ð������ 

void swap(vector<int> &nums, int i, int j){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
void bubble_sort(vector<int> &nums){
	int index_max = nums.size()-1;
	int i, j, flag = 1;		// flag������Ƿ��н��н���������ڱ��� i ʱ�����ֺ������û�н��н�����Ҳ����˵���涼�Ѿ���������ˣ���ֹͣ���� 
	for(i = 0; i<index_max, flag==1; i++){
		flag = 0;
		for(j=index_max; j>i; j--){	
			if(nums[j-1] > nums[j]){//ǰһ��������˵���������Ҫ���󣬺����Ǹ�����ǰ�ƶ� 
				swap(nums, j-1, j);
				flag = 1;	//	 ����������˵��nums[i] ���� Ԫ�ز���������� 
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
