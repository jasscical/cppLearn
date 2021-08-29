#include <bits/stdc++.h>
using namespace std;



void printVec(vector<vector<int>>& nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[0].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << "; ";
    }
    cout << endl;
}

// 将字符串转化为整数 10:00 ==> 1000
int transform(string& str){
    // 去掉 ":"
    string t;
    for(auto s:str){
        if(s == ':') continue;
        t += s;
    }
    // 转化为整数
    return stoi(t);
}

// 按右边界升序
bool static cmp(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int OverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return 0;
    int count = 1;
    cout << "before:" << endl;
    printVec(intervals);

    sort(intervals.begin(), intervals.end(), cmp);
    
    cout << "after:" << endl;
    printVec(intervals);
    
    int end = intervals[0][1]; // 作为非重叠的右边界
    for(int i = 1; i < intervals.size(); i++){
        // 当前左边界大于之前的非重叠的右边界时，
        // 说明新的一个非重叠区间出现，需要更新
        if(intervals[i][0] >= end){
            end = intervals[i][1];
            count++;
        }
    }
    return count;
}



int main(){
    vector<vector<string>> str = {{"00:00", "12:00"}, {"03:00", "11:30"}, 
    {"11:30", "23:00"}, {"14:30", "15:00"}};
    vector<vector<int>> intervals(str.size(), vector<int>(2, 0));
    // 二维字符串数组 转化为 二维整数数组
    for(int i = 0; i < str.size(); i++){
        intervals[i][0] = transform(str[i][0]);
        intervals[i][1] = transform(str[i][1]);
    }

    int res = OverlapIntervals(intervals);
    cout << res << endl;
}