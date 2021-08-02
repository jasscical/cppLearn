#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& nums, int l, int r);
void print(vector<int>& nums, int start, int end);

int main(){
    vector<int> nums = {4, 2, 1, 5, 9, 6, 7, 10, 3, 8};
    print(nums, 0, nums.size() - 1);
    quickSort(nums, 0, nums.size() - 1);
    print(nums, 0, nums.size() - 1);
    return 0;
}

// 快速排序
void quickSort(vector<int>& nums, int l, int r){
    if(l > r) return;
    int i = l, j = r;
    int randNum = rand() % (r - l + 1) + l;
    swap(nums[l], nums[randNum]);
    while(i < j){
        while(i < j && nums[j] > nums[l]) j--;
        while(i < j && nums[i] < nums[l]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    quickSort(nums, l, i - 1);
    quickSort(nums, i + 1, r);
}

void print(vector<int>& nums, int start, int end){
    if(start > end){
        cout << "index error" << endl;
        return;
    }
    cout << endl;
    for(int i = start; i <= end; i++){
        cout << nums[i] << '\t';
    }
    cout << endl;
}
