#include <iostream> 
#include <vector>
using namespace std;


template< typename T>
    bool cmp(const T& a, const T& b){
        return a <= b;
    }
    void quickSort(vector<int>& arr, int l, int r){
        if(l >= r) return;
        int i = l, j = r;
        int& p = arr[l];
        while(i < j){
            while(i < j && cmp(p, arr[j])) j--;
            while(i < j && cmp(arr[i], p)) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], p);
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
