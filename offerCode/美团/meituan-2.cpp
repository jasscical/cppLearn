#include <bits/stdc++.h>
using namespace std;

/*
样例输入
4
1 2 3 4
2 4 3 4
样例输出
8
*/

vector<int> path;
long res = 0;
void backtracking(vector<int>& nums, vector<int>& b, vector<bool>& used){
    if(path.size() == nums.size()){
        int j = 0;
        for(; j < b.size(); j++){
            if(b[j] < path[j]) break;
        }
        if(j == b.size()) res++;
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
            continue;
        }
        if(nums[i] > b[i]) return;
        if(used[i] == false){
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, b, used);
            path.pop_back();
            used[i] = false;
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<bool> used(a.size(), false);
    backtracking(a, b, used);
    res = res % (1000000007);
    cout << res << endl;
}