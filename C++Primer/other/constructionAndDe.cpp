#include <iostream>

using namespace std;

class A{
public:  
    A(){
        cout << "construction" << endl;
    }
    ~A(){
        cout << "deconstruction" << endl;
    }
};

int main(){
    A *a = new A;
    cout << "-1-" << endl;
    delete a;
    
    cout << "-2-" << endl;
    A a2;
    return 0;

}