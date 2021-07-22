#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void heap_build(vector<int> &nums, int n, int root) {
	if (root > n) return;
	//int max, l, r;	//�����±� index ���������� n ���±����ֵ�����ǽڵ������  root ��ʾ���ĸ��ڵ���жѽ��� 
	int max = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (l <= n && nums[l] > nums[max]) {	
		max = l;
	}
	if (r <= n && nums[r] > nums[max]) {//�����Һ��Ӳ������ڵ����ֵ��up ������ < n,��������������ӵ����һ���ڵ�
										//��6���޷����жѽ�������Ϊ 6 < 6Ϊfalse ,�����Ϊ <= n,��Ӧheap-sort���� 
										//���һ���ڵ㣬Ȼ��ʣ�� j-1 ���ڵ����½��жѵĽ�����û���߼���ͨ�ˡ� 
		max = r;
	}
	if (max != root) {
		swap(nums, root, max);
		heap_build(nums, n, max);
	}

}

void heap_sort(vector<int> &nums) {
	//������
	int n = nums.size() - 1;	// n Ϊ�±����ֵ 
	for (int i = (n - 1) / 2; i >= 0; i--) { //ֻ��ѡȡ���нڵ�� 0 ~ ��n-1��/2 ���жѽ��� ����������Ϊ���ڵ� 
		heap_build(nums, n, i);
	}
	//������ 
	for (int j = n; j > 0; j--) {
		swap(nums, j, 0);
		heap_build(nums, j-1, 0);	//��ʣ�µ� n-1 ���ڵ����½��жѽ��� ��upԭ�������� j ,���н��û�����⡣�����ȥ���
									// һ���ڵ��ʣ�½ڵ�ȥ���ж����� ������Ӧ���� j - 1 
	}
}


int main() {
	//��ʼ������ 
	vector<int> nums = { 4, 10, 3, 5, 1, 2, 6, 8};

	cout << "original nums:" << endl;
	for (auto n : nums) {
		cout << n << "\t";
	}
	cout << endl;

	//������	
	heap_sort(nums);


	cout << "after heap_sort nums:" << endl;
	for (auto n : nums) {
		cout << n << "\t";
	}
	system("pause");
	return 0;
}
