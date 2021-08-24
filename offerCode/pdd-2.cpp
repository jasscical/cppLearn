#include <bits/stdc++.h>
using namespace std;

vector<int> path;
int res = -1;
vector<int> candidates = {-1, -2, 1, 999}; // 999表示晴天

void backtracking(int targetSum, int sum, int startIndex){
    if(sum > targetSum) return; // 剪枝
    if(sum == targetSum){
        if(path.size() < res) res = path.size();
        return;
    }
    for(int i = startIndex; i < candidates.size(); i++){
        if(candidates[i] == 999){ // 晴天
            sum *= 2;
                path.push_back(candidates[i]);
            backtracking(targetSum, sum, i);
            path.pop_back();
            sum /= 2;
        }
        else{ // 其他天气
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(targetSum, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
}

void combinationSum(int P, int target) {
    sort(candidates.begin(), candidates.end());
    backtracking(target, P, 0);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int P, Q;
        cin >> P >> Q;
        if(P == Q){
            cout << "0" << endl;
            continue;
        }
        combinationSum(P, Q);
        cout << res << endl;
    }
}