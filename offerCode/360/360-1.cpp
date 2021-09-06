/*
又到了一学期一次的大学生期末考试。但很多人期末考试的卷面成绩是不能及格的，
需要靠较高的平时成绩来拖上去。
平时成绩与期末考试的占比已经确定，假设平时成绩占比为p，期末考试占比为q，平时分为a，
期末考试分数为b，则总成绩为(p*a+q*b)/100。（平时分与期末成绩都是整数，但总成绩可以是小数。）
饶老师心肠特别好，他希望自己的学生及格率尽可能的高。但他也坚持期末考试分数更高的学生平时成绩也一定要更高。饶老师想知道在这种情况下，他们班的最大及格人数是多少（及格是指总成绩不低于60分）。


第一行三个正整数n，p，q（1<=n<=200,0<=p<=100,0<=q<=100,p+q=100）

第二行n个正整数表示n个学生的期末考试分数（0<=分数<=100）

#include <bits/stdc++.h>
using namespace std;

bool static cmp(const vector<int>& a, const vector<int>& b){
    return a[0] > b[0];
}

int main(){
    int n, p, q;
    cin >> n >> p >> q;
    vector<vector<int>> data(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> data[i][0];
    sort(data.begin(), data.end(), cmp);
    int res = 0;
    int s = 100;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && data[j][0] == data[i][0]){
            data[j][1] = s;
            ++j;
        }
        i = j - 1;
        --s;
    }
    for(int i = 0; i < n; i++){
        double tmp = ((double)data[i][0] * p + (double)data[i][1] * q) / 100;
        if(res >= 60) res++;
    }
    cout << res << endl;
    return 0;
}



*/

// AC 73%
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p, q;
    cin >> n >> p >> q;
    vector<double> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i] *= q;
    }
    sort(b.rbegin(), b.rend()); // 期末考试占比 q * b, 降序
    // total = q * b + p * a
    int res = 0;
    int w = 100;
    for(int i = 0; i < n; i++){
        if(i <= n - 2 && b[i] > b[i + 1]) w--;
        b[i] += w * p;
        double sum = b[i] / 100.0;
        if(sum >= 60) res++;
        else break;
    }
    cout << res << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, q;
    cin >> n >> p >> q;
    vector<double> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end()); // 期末考试占比 q * b, 降序
    // total = q * b + p * a
    int res = 0;
    int w = 100;
    for(int i = n - 1; i >= 0; i--){
        if(i < n - 1 && b[i] < b[i + 1]) w--;
        double sum = b[i] * q / 100.0 + w * p / 100.0;
        if(sum >= 60.0) res++;
        else break;
    }
    cout << res << endl;
    return 0;
}