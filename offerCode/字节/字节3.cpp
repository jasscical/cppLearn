#include <vector>
#include <string>
#include <iostream>

using namespace std;

string res; // 保存每次的最大值，会有k个字符
/*
void getKMax(vector<int>& nums, int k){
    if(k == 0) return;
    int index, maxN;
    index = maxN = 0;
    int n = nums.size();
    
    // 找出 [0, n - k]的最大值，剩下k - 1个元素
    for(int i = index; i <= n - k; i++){
        if(nums[i] > maxN){
            maxN = nums[i];
            index = i;
        }
    }
    res.push_back(nums[index] + '0');
    nums.erase(nums.begin(), nums.begin() + index + 1);
    getKMax(nums, --k);
}*/

void getKMax(vector<int>& nums, int k, int start, int end){
    if(k == 0) return;
    int index, maxN;
    index = maxN = start;

    // 找出 [0, n - k]的最大值，剩下k - 1个元素
    for(int i = index; i <= end - k + 1; i++){
        if(nums[i] > maxN){
            maxN = nums[i];
            index = i;
        }
    }
    res.push_back(nums[index] + '0');
    getKMax(nums, --k, index + 1, end);
}


int main(){
    vector<int> nums = {4, 6, 2, 5, 4, 1, 9, 8};
    int k = 4;

   // getKMax(nums, k);
   getKMax(nums, k, 0, nums.size() - 1);

    int i = 0;
    while(res[i] == '0') i++;
    string str = res.substr(i);

    if(i == k) cout << 0 << endl;
    else cout << str << endl;

    return 0;
}