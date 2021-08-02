#include <iostream>
#include <vector>
#include <algorithm> 
#define Num 100

using namespace std;
// ����
// ʱ�临�Ӷ� O(N*logN) 



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



vector<int> partition(vector<int>& nums, int L, int R) {
	int index = L;
	int less = L - 1;
	int more = R;  // �����൱�ڽ�nums[L...R-1] ��partion, ���һ��λ�� R �ǲ����룬���Ժ������swap(nums,R, more) 
	int p = nums[R]; //�����һ������Ϊ����ֵ p 
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
	return vector<int> {less + 1, more}; //�����ʾ ==p ������ 

}

void process(vector<int>& nums, int L, int R){
	if(L < R){
		// ȡ��[a,b)�����������rand()%(b-a)+a��
		// ȡ��[a,b]�����������rand()%(b-a+1)+a�� 
		swap_vec(nums, (rand()%(R-L+1)) + L, R);  //��nums�е����һ�����ŵ����һ��λ�� R 
		
		// ��һ�����ǽ�nums[L,R]��partition,partition���̣�nums[R]Ϊ����ֵ����nums[L...R-1]���� 
		vector<int> pos =  partition(nums, L, R); // ���� < == > �����Χ����\���ұ߽� 
		
		process(nums, L, pos[0]-1); // <�� 
		process(nums, pos[1]+1, R); // >�� 
	}
}

void quick_sort(vector<int> &nums){
	if(nums.size() < 2) return;
	process(nums, 0, nums.size()-1); // �����±� 
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
