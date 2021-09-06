#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
样例输入
1 1 1 1 1
4
5 6 6 2 0
5 5 6 2 1
2 2 2 4 5
9 0 0 2 1
样例输出
19
2
1
2

*/

int main(){
    int a, b, c, d, e; // 分数系数
    cin >> a >> b >> c >> d >> e;
    int n; // 人数
    cin >> n;
 
    vector<long> score(n, 0);
    for(int i = 0; i < n; i++){
        int bs1, bs2, bs3, bs4, bs5;
        cin >> bs1 >> bs2 >> bs3 >> bs4 >> bs5;
        score[i] = bs1 * a + bs2 * b + bs3 * c + bs4 * d + bs5 * e;
    }
    
    int maxScore = *max_element(score.begin(), score.end());  
    vector<int> v;
    for(int i = 0; i < score.size(); i++){
        if(score[i] == maxScore) v.push_back(i + 1);
    }
    cout << maxScore << endl;
    cout << v.size() << endl;
    for(auto vv:v)cout << vv << endl;
    return 0;
}

//第一步区间归一化
["192.168.0.1"] ==> ["192.168.0.1-192.168.0.1"]
["0.0.0.0-255.255.255.255"] ==> ["0.0.0.0-255.255.255.255"]

// 区间转化
//可以定义一个ip结构体
struct ipS {
    int one, two, three, four;
};

ipS ip1, ip2 
["0.0.0.0-255.255.255.255"] ==> [ip1, ip2]
ip1.one = 0, ip2.two = 0, ...
ip2.one = 255, ip2.two = 255, ...

//转化完放到一个数组
// [[ip1, ip2], [], [],...]

// 自定义（左右区间）排序方式
cmp(ipS ip1, ipS ip2){
    if(ip1.one < ip2.one) return false;
    if(ip1.two < ip2.two) return false;
    ...
}

// 结合力扣的函数