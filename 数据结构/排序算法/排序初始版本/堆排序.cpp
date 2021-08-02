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
	//int max, l, r;	//都是下标 index ，传进来的 n 是下标最大值而不是节点个数，  root 表示对哪个节点进行堆建立 
	int max = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (l <= n && nums[l] > nums[max]) {	
		max = l;
	}
	if (r <= n && nums[r] > nums[max]) {//当左右孩子不超过节点最大值，up 这里是 < n,那样我下面的例子的最后一个节点
										//的6就无法进行堆建立，因为 6 < 6为false ,这里改为 <= n,对应heap-sort剪掉 
										//最后一个节点，然后将剩下 j-1 个节点重新进行堆的建立就没错。逻辑就通了。 
		max = r;
	}
	if (max != root) {
		swap(nums, root, max);
		heap_build(nums, n, max);
	}

}

void heap_sort(vector<int> &nums) {
	//建立堆
	int n = nums.size() - 1;	// n 为下标最大值 
	for (int i = (n - 1) / 2; i >= 0; i--) { //只需选取所有节点的 0 ~ （n-1）/2 进行堆建立 ，将他们作为根节点 
		heap_build(nums, n, i);
	}
	//堆排序 
	for (int j = n; j > 0; j--) {
		swap(nums, j, 0);
		heap_build(nums, j-1, 0);	//将剩下的 n-1 个节点重新进行堆建立 ，up原先这里是 j ,运行结果没有问题。传入减去最后
									// 一个节点的剩下节点去进行堆排序 ，所以应该是 j - 1 
	}
}


int main() {
	//初始化数组 
	vector<int> nums = { 4, 10, 3, 5, 1, 2, 6, 8};

	cout << "original nums:" << endl;
	for (auto n : nums) {
		cout << n << "\t";
	}
	cout << endl;

	//堆排序	
	heap_sort(nums);


	cout << "after heap_sort nums:" << endl;
	for (auto n : nums) {
		cout << n << "\t";
	}
	system("pause");
	return 0;
}
