#include <iostream>
#include <stack>
using namespace std;

class Queue{
public:
    Queue(){}
    void push(int value){
        addStk.push(value);
    }
    void pop(){
        int res;
        if(!delStk.empty()){
            res = delStk.top();
            delStk.pop();
            cout << "pop the front = " << res << endl;  
            return;
        }

        add2del(); // addStk 转移到 delStk
        
        res = delStk.top();
        delStk.pop();
        cout << "pop the front = " << res << endl; 
    }
    void top(){
        if(!delStk.empty()){
            cout << " front = " << delStk.top() << endl;
            return;
        }

        add2del();

        cout << " front = " << delStk.top() << endl;
    }
    void printStk(Queue que){
        stack<int>& queAdd = que.addStk;
        stack<int>& queDel = que.delStk;
        // 先遍历负责删除的那个栈，再遍历负责添加那个栈
        while(!queDel.empty()){
            int ttop = queDel.top();
            queDel.pop();
            cout << ttop << "\t";
        }
        while(!queAdd.empty()){
            int ttop = queAdd.top();
            queAdd.pop();
            cout << ttop << "\t";
        }
        cout << endl;
    }
private:
    stack<int> addStk; // 放数据 1 2 3 4 5 
    stack<int> delStk; // 删除数据
    void add2del(){
         while(!addStk.empty()){
            int tfront = addStk.top();
            addStk.pop();
            delStk.push(tfront);
        }
    }
};


int main(){
    Queue que;
    // 验证 push
    cout << "push: " << endl;
    for(int i = 1; i <= 5; i++){
        que.push(i);
        que.printStk(que);
    }
  
    // que：1	2	3	4	5
    
    // 验证 top
    cout << "top: " << endl;
    que.top(); // 1
    que.printStk(que);
    
    // 验证 pop
    cout << "pop: " << endl;
    que.pop(); //  2 3 4 5
    que.printStk(que);

    return 0;
}
