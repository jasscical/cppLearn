#include <iostream>
#include <string>
using namespace std;

class A{
public:
    A(int a){
        this->age = a;
        cout << "age = " << this->age << endl;
    }
private:
    int age;
    string name;

};


int main(){
    A a(1);
    //cout << a.age << endl; 类对象不可以访问private成员
    return 0;
}