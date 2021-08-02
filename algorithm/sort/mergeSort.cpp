#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>& nums, int l, int r);
void print(vector<int>& nums, int start, int end);
void merge(vector<int>& nums, int l, int mid, int r);

int main(){
    vector<int> nums = {4, 2, 1, 5, 9, 6, 7, 10, 3, 8};
    print(nums, 0, nums.size() - 1);
    mergeSort(nums, 0, nums.size() - 1);
    print(nums, 0, nums.size() - 1);
    return 0;
}

void merge(vector<int>& nums, int l, int mid, int r){ // 归并过程
    vector<int> help(r - l + 1); // 辅助数组
    int p1 = l, p2 = mid + 1; // 两个组：p1∈[l, mid]，p2∈[mid + 1, r]
    int i = 0; // i划过help数组的下标
    // 1.哪个小拷贝哪个
    while(p1 <= mid && p2 <= r){
        help[i++] = (nums[p1] <= nums[p2]) ? nums[p1++] : nums[p2++]; 
    }
    // 2.还有可能一个组没拷贝完，也要添加到help后面
    while(p1 <= mid) help[i++] = nums[p1++];
    while(p2 <= r) help[i++] = nums[p2++];
    // 3.拷贝回原数组
    for(int i = 0; i < help.size(); i++){
        nums[l + i] = help[i];
    }
}

// 归并排序
void mergeSort(vector<int>& nums, int l, int r){
    if(nums.size() < 2) return;
    if(l == r) return;
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid); // 左段有序
    mergeSort(nums, mid + 1, r); // 右段有序
    merge(nums, l, mid, r); // 合并左右
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
