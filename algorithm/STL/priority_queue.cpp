#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/* 自定义排序规则
struct node{
    int age;
    string name;
    char sex;
    node(int _age, string _name, char _sex):age(_age), name(_name), sex(_sex){}
};

// 排序：按照权重定义规则
// 1.按年纪升序
// 2.年纪相等则男生优先
struct cmp{
    bool operator()(node& a, node& b){
        if(a.age > b.age) return true;
        if(a.age == b.age && a.sex == 'b') return true;
        return false;
    }
};

int main(){
    vector<node> nums = {
        {5, "jack", 'b'},
        {2, "casi", 'b'},
        {2, "casi", 'g'},
        {4, "mass", 'g'},
        {6, "xida", 'g'},
        {1, "kucoo", 'b'},
    };
    priority_queue<node, vector<node>, cmp> pri_que(nums.begin(), nums.end());
    while(!pri_que.empty()){
        node tmp = pri_que.top();
        cout << tmp.name << "\t" << tmp.age << "\t" << tmp.sex << endl;
        pri_que.pop();
    }
    return 0;
}
*/


/* API升序降序
int main(){
    vector<int> nums{2,5,1,3,9,7,8,4,6,10};
    // 降序
    //priority_queue<int, vector<int>, less<int>> pri_que(nums.begin(), nums.end());
    // 升序
    priority_queue<int, vector<int>, greater<int>> pri_que(nums.begin(), nums.end());
    while(!pri_que.empty()){
        cout << pri_que.top() << " ";
        pri_que.pop();
    }
    return 0;
}
*/