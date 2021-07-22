#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapInsert(vector<int>& nums, int index);
void heapify(vector<int>& nums, int index, int heapSize);
void heapSort(vector<int>& nums);
void print(vector<int>& nums, int start, int end);

int main(){
    vector<int> nums = {4, 2, 1, 5, 9, 6, 7, 10, 3, 8};
    print(nums, 0, nums.size() - 1);
    heapSort(nums);
    print(nums, 0, nums.size() - 1);
    return 0;
}


void heapInsert(vector<int>& nums, int index){ // 调整成大根堆
   // 给你一个节点下标是index，那么它的父节点是 (index - 1) / 2
   // 这一部分就是将父节点 调节成 大根堆
   while(nums[index] > nums[(index - 1) / 2]){
       swap(nums[index], nums[(index - 1) / 2]);
       index = (index - 1) / 2;
   }
}

void heapify(vector<int>& nums, int index, int heapSize){
    int left = 2 * index + 1;
    while(left < heapSize){
        // 1.父节点index、左右孩子的最大值
        int largest = (left + 1 < heapSize && nums[left + 1] > nums[left]) ? left + 1 : left;
        largest = (nums[largest] > nums[index]) ? largest : index;
        // 2.index赋值为最大值的下标，如果index本身就是最大值，
        // 则说明该节点下的已经是堆结构，不用继续
        if(largest == index) break;
        swap(nums[largest], nums[index]);
        index = largest;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int>& nums){
   // 1.一个一个插入节点，每次插入一个都要调整成为大根堆
   for(int i = 0; i < nums.size(); i++){
       heapInsert(nums, i);
   }
   print(nums, 0, nums.size() - 1);
   // 头尾节点交换，因为此刻头结点是最大值，交换后断连最后一个节点
   // 然后循环，将每一部分未断连的部分进行重新堆化，再交换，再断连
   // 这样断连的部分就是有序的
   int heapSize = nums.size();
   swap(nums[0], nums[--heapSize]);
   while(heapSize){
       heapify(nums, 0, heapSize);
       print(nums, 0, heapSize);
       swap(nums[0], nums[--heapSize]);
   }
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
