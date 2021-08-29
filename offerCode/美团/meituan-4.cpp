#include <bits/stdc++.h>
using namespace std;

int n, m;
int k;
void cut(vector<vector<int>>& t, vector<vector<int>>& input, int idx){
    int x = input[idx][0] - 1, y = input[idx][1] - 1;
    int len = input[idx][2];
    int r = pow(len, 2);
    for(int i = - len; i <= len; i++){
        if(x + i < 0 && x + i >= n) continue;
        for(int j = - len; j <= len; j++){
            if(y + j < 0 && y + j >= m) continue;
            if(pow(i, 2) + pow(j, 2) <= r){
                t[x + i][y + j] = k - idx - 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> k;  
    vector<vector<int>> input(k, vector<int>(3));
    vector<vector<int>> t(n, vector<int>(m, k));
    for(int i = 0; i < k; i++){
        cin >> input[i][0] >> input[i][1] >> input[i][2];
        cut(t, input, i);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res += t[i][j];
        }
    }
    cout << res << endl;
    return 0;
}