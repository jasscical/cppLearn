#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/* 第一题
int main(){
    int N, K;
    cin >> N >> K;
    // 记录K个乘客起始时间nums[0], 终止时间nums[1]
    vector<vector<int>> nums(K, vector<int>(2));

    for(int i = 0; i < K; i++){
        int start, end;
        cin >> nums[i][0]
            >> start
            >> end;
        nums[i][1] = 5 * min(abs(end - start), N - abs(end - start)); // 环形，取最小的值
    }

    int ret = 0;
    vector<int> timeline(10000 + 1, 0); // 时间线
    // 遍历每个乘客，让每个乘客在[起始时间，终止时间]的时间线上加1，表示这一个时刻有多少乘客在使用
    // 用一个ret来统计这些时间线上的最大值
    for(int i = 0; i < K; i++){
        for(int j = nums[i][0]; j < nums[i][0] + nums[i][1]; j++){
            ++timeline[j];
            if(timeline[j] > ret) ret = timeline[j];
        }
    }
    cout << ret << endl;
    return 0;
}*/

/* 第 2 题
// 定义结构 T P
struct line{
    int T;
    int P;
};

// 优先级排序
bool static cmp(const line& a, const line& b){
    if(a.P < b.P) return true;
    if(a.P == b.P && a.T > b.T) return true;
    return false;
}
// 打印多行line
void print(const vector<line>& lines){
    for(auto l:lines){
        cout << l.T << ", " << l.P << endl;
    }
}
// 打印vector
void printVec(vector<int>& v){
    for(auto v1:v){
        cout << v1 << ",";
    }
    cout << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<line> lines(k);
    for(int i = 0; i < k; i++){
        cin >> lines[i].T >> lines[i].P;
    }
    //print(lines);
    //cout << endl;

    sort(lines.begin(), lines.end(), cmp);

    //cout << "after sort:" << endl;
   //print(lines);
    
    int res = 0;
    // 设备数多，不需要排队，直接取占用时间最大值
    if(n >= k){
        for(int i = 0; i < lines.size(); i++){
            res = max(res, lines[i].T);
        }
        cout << "n >=k " << endl;
        cout << res << endl;
    }
   
    vector<int> devices(n, 0); // n个设备，v[i]表示设备被占用时间
    // 遍历lines
    for(int i = 0; i < lines.size(); i++){
        // n 个设备先填满
        if(i < n){
            devices[i] = lines[i].T;
            cout << "devices[ ]" << i << ", "<< devices[i] << endl;
        }else{
            int minDivces = INT_MAX;
            int minIndex = 0;
            // devices[i]的最小值
            for(int j = 0; j < n; j++){
                if(devices[j] <  minDivces){
                    minDivces = devices[j];
                    minIndex = j;
                }
            }
            // 将lines.T加入到devices[i]的最小值上
            devices[minIndex] += lines[i].T;
            //cout << "lines[]" << i << ", " << endl;
            //printVec(devices);
        }
    }
    // 取设备最后最大值
    for(int i = 0; i < devices.size(); i++){
        res = max(res, devices[i]);
    }
    cout << "n < k " << endl;
    cout << res << endl;
    return 0;
}
*/