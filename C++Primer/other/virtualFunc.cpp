#include <iostream>
using namespace std;


class A{
public:
    // 无论构造、析构都不建议在里面 调用 虚函数！！
    // virtual A();构造函数是不允许设置为虚函数的
    A(){
        cout << "A construction " << endl;
    }
    virtual void func1(){
        cout << "A func1 " << endl;
    }
    void func2(){
        cout << "A func2 " << endl;
    }
    virtual ~A(){ // 析构函数可以，而且鼓励支持
        cout << "A deconstruction " << endl;
    }
};

class B : public A{ // 声明为public继承，默认是private
public:
    void func1() override{
        cout << "B func1 " << endl;
    }
};

int main(){
    A a;
    B b;
    a.func1(); 
    b.func1(); // 只有声明为virtual的才会重写
   
    a.func2(); 
    b.func2(); // 继承父类
    return 0;
}