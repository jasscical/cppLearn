#include <iostream>     // std::cout
#include <algorithm>    // std::upper_bound
#include <vector>       // std::vector
using namespace std;
//以普通函数的方式定义查找规则
bool mycomp(int i, int j) { return i > j; }

//以函数对象的形式定义查找规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i > j;
    }
};
/*
//查找[first, last)区域中第一个大于 val 的元素。
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                             const T& val);
//查找[first, last)区域中第一个不符合 comp 规则的元素
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                             const T& val, Compare comp);
其中，first 和 last 都为正向迭代器，[first, last) 用于指定该函数的作用范围；
val 用于执行目标值；comp 作用自定义查找规则，
此参数可接收一个包含 2 个形参（第二个形参值始终为 val）且返回值为 bool 类型的函数，
可以是普通函数，也可以是函数对象。                             

演示了 upper_bound() 函数的 2 种适用场景，其中 a[5] 数组中存储的为升序序列；
而 myvector 容器中存储的序列虽然整体是乱序的，但对于目标元素 3 来说，
所有符合 mycomp2(3, element) 规则的元素都位于其左侧，不符合的元素都位于其右侧，
因此 upper_bound() 函数仍可正常执行。
*/
int main() {
    int a[5] = { 1,2,3,4,5 };
    //从 a 数组中找到第一个大于 3 的元素
    int *p = upper_bound(a, a + 5, 3);
    cout << "*p = " << *p << endl;

    vector<int> myvector{ 1,2,3,4,5};
    //根据 mycomp2 规则，从 myvector 容器中找到第一个违背 mycomp2 规则的元素
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), 3, mycomp2());
    cout << "*iter = " << *iter << endl;
    while(iter != myvector.end()){
        cout << "*iter = " << *iter << " ";
        iter++;
    }
    return 0;
}