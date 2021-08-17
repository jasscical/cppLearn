#include <iostream>
#include <queue>
using namespace std;

class Stack{
public:
    Stack(){}
    void push(int value){
        que1.push(value);
    }
    void pop(){
        if(que1.empty()) return;
        getBack();
        //que1: 5
        //que2: 1 2 3 4
        int res = que1.front();
        que1.pop(); // que1最后一个元素pop
        restore();
        cout << "pop top = " << res << endl;      
    }
    void top(){
        if(que1.empty()) return;
        getBack();
        //que1: 5
        //que2: 1 2 3 4
        int res = que1.front();
        que1.pop();
        que2.push(res);
        //que1: 
        //que2: 1 2 3 4 5
        restore(); // 恢复
        //que1: 1 2 3 4 5
        //que2: 
        cout << "top = " << res << endl;
    }
    void printStk(Stack stk){
        queue<int>& que = stk.que1;
        while(!que.empty()){
            int ttop = que.front();
            que.pop();
            cout << ttop << "\t";
        }
        cout << endl;
    }
private:
    queue<int> que1; // 放数据 1 2 3 4 5 
    queue<int> que2; // 暂时存放数据
    /*得到队列que1最后一个元素*/
    void getBack(){
        //que1:  1 2 3 4 5
        //que2:
        if(!que1.empty()){
            int n = que1.size();
            while(!que1.empty()){
                int ttop = que1.front();
                que1.pop();
                que2.push(ttop);
                --n;
                if(n == 1) break;
            }
        }
    }
    /* que2 拷贝回 que1 */
    void restore(){
        //que1: 
        //que2: 1 2 3 4 5
        while(!que2.empty()){
            int ttop = que2.front();
            que2.pop();
            que1.push(ttop);
        }
        //que1: 1 2 3 4 5
        //que2: 
    }
};


int main(){
    Stack stk;
    // 验证 push
    cout << "push: " << endl;
    for(int i = 1; i <= 5; i++){
        stk.push(i);
        stk.printStk(stk);
    }
    // stk：1	2	3	4	5
    
    // 验证 top
    cout << "top: " << endl;
    stk.top(); // 5
    stk.printStk(stk);
    
    // 验证 pop
    cout << "pop: " << endl;
    stk.pop(); // 1 2 3 4
    stk.printStk(stk);


    return 0;
}
