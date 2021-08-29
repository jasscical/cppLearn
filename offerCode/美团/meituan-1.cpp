#include <bits/stdc++.h>
using namespace std;

// 10
// 1 1 2 2 2 3 3 3 3 1
// 11

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = 0;
    unordered_set<int> uset;
    for(int i = 0; i < nums.size(); i++){
        int cur = nums[i];
        for(auto u:uset){
            if(u < cur)res++;
        }
        uset.insert(cur);
    }
    
    cout << res << endl;
}