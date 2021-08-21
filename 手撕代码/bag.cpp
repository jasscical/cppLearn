#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void printV(vector<int>& nums){
    for(auto n:nums) cout << n << " ";
    cout << endl;
}


void zeroOneBag(vector<int> weight, vector<int> values, int bagWeight){
    /*  01背包
    *遍历每一个物品的重量
    *依次放入每一个背包容量，背包容量从 (最大背包容量) 到 ( >= 当前物品重量 )
    *如果背包容量 可以放下物品重量，该背包容量就可以由放入物品得到
    * 对应dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
    */ 
    cout << "01背包" << endl;
    // 装满背包容量为j的背包，所能够拥有的最大价值为dp[j]
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++){ // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--){ // 遍历背包
            dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
        cout << "物品i = " << i << endl;
        printV(dp);
    } 
    printV(dp);
}

// 完全背包
void totalBag(vector<int> weight, vector<int> values, int bagWeight){
    /*  完全背包
    *遍历每一个物品的重量
    *依次放入每一个背包容量，背包容量从 ( 当前物品容量 ) 到 (背包最大容量)
    *背包容量 可以放下 几个 当前物品重量，当前dp[j]由dp[j - weight[i]] + values[i]推来
    * 对应dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
    */ 
    
    cout << "完全背包" << endl;
    // 装满背包容量为j的背包，所能够拥有的最大价值为dp[j]
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++){ // 物品
        for(int j = weight[i]; j <= bagWeight; j++){ // 背包
            dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
        cout << "物品i = " << i << endl;
        printV(dp);
    }
    
    printV(dp);
}


int main(){
    vector<int> weight = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int bagWeight = 4;
    zeroOneBag(weight, values, bagWeight);
    cout << endl;
    totalBag(weight, values, bagWeight);
    return 0;
}