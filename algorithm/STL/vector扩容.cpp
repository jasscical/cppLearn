#include <iostream>
#include <vector>
using namespace std;


class A{
public:
    vector<int> data;
public:
    A(){
        data.reserve(2);
    }
    A(int len);
};



int main()
{
    /*
    vector<int> value{ 1, 2, 3, 4, 5 };
    //value.reserve(20);
    cout << "value 容量是1：" << value.capacity() << endl;
    cout << "value 大小是1：" << value.size() << endl;
    
    value.push_back(5);
    cout << "value 容量是2：" << value.capacity() << endl;
    cout << "value 大小是2：" << value.size() << endl; */

    A a;
    cout << "1-" << a.data.capacity() << endl;
    a.data.push_back(1);
    a.data.push_back(2);
    a.data.push_back(3);
    cout << "2-" << a.data.capacity() << endl;

    return 0;
}