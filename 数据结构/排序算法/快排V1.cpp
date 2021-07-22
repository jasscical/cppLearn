#include <iostream> 
#include <vector>
using namespace std;


void quickSort(vector<int>& arr, int l, int r){
        if(l >= r) return; // 当数组只有一个数时，终止递归
        int i = l, j = r;  //哨兵划分范围（以 arr[l] 左边第一个数作为基准数）
        int &p = arr[l];
		while(i < j){
           	while(i < j && arr[j] >= p) j--; //这两个while有顺序的 ，j右边全部大于哨兵值 
            while(i < j && arr[i] <= p) i++; // i 左边全部小于哨兵值 
            swap(arr[i], arr[j]);  //此时交换i,j位置的值，那么（l, i）的值 <= 哨兵值， （i + 1, r） >= 哨兵值                  
			}
        swap(p, arr[i]); // 哨兵的位置排好了 
        // 递归左（右）子数组执行哨兵划分
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
    
    
int main(){
	vector<int> nums = {3, 2, 8, 7, 9, 4, 5, 6};
	cout << "original :" << endl;
	for(auto n : nums) cout << n << " ";
	cout << endl;
	quickSort(nums, 0 , nums.size() - 1);
	cout << endl;
	cout << "sort :" << endl;
	for(auto n : nums) cout << n << " ";
	return 0;
}
