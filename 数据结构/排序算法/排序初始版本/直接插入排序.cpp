#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int> &nums){
	int i, j, index_max = nums.size()-1;
	for(i=1; i<=index_max; i++){	//	i�ӵڶ�����ѭ�������һ���� 
		int tmp = nums[i];
		for(j=i-1; j>=0; j--){	// j�� i ��ǰһ��ѭ������һ�������ǿ�i֮ǰ�� ��û�� nums[i](tmp),����ģ������Ƶ����� 
			if(nums[j] > tmp){
				nums[j+1] = nums[j];
			}else{
				break;
			}
			
		}
		nums[j+1] = tmp; //�ƶ���󣬽� tmp ���뵽 ���õ���λ�� 
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
