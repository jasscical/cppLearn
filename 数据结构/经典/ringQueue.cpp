#include <vector>
#include <iostream>
using namespace std;

const int maxN = 5;

template <typename T>
class ringQueue{
public:
    vector<T> data;
    int length;
    int front;
    int rear;
public:
    ringQueue();
    ringQueue(int len);
    ~ringQueue();

    void push(T tdata);
    void pop();

    bool empty();
    bool full();

    int size();
    T frontData();
};

template <typename T>
ringQueue<T>::ringQueue(){
    data.reserve(maxN);
    length = maxN;
    front = 0;
    rear = 0;
    cout << "construction：" << endl << "length = " << length 
            << " ,front = " << front << ", rear = " << rear << endl;
}

template <typename T>
ringQueue<T>::ringQueue(int len){    
    data.reserve(len);
    length = len;
    front = 0;
    rear = 0;
    cout << "construction：" << endl << "length = " << length 
            << " ,front = " << front << ", rear = " << rear << endl;
}

template <typename T>
ringQueue<T>::~ringQueue(){
    data.clear();
    data.shrink_to_fit();
    cout << "deconstruction " << endl;
}

template <typename T>
void ringQueue<T>::push(T tdata){
    if(full()){  // 队列已满
        cout << "队列已满， 重新分配内存中...." << endl;
        
        data.push_back(tdata); // 利用vector的自动扩容机制
        
        length = data.capacity(); // 重新更新队列长度length
        front = 0, rear = data.size() - 1;
        cout << "重新分配后：" << endl << "length = " << length 
            << " ,front = " << front << ", rear = " << rear << endl;
        return;
    }
    data[rear] = tdata;
    rear = (rear + 1) % length;

    cout << "front = " << front << ", rear = " << rear << endl;
}

template <typename T>
void ringQueue<T>::pop(){
    if(empty()) {
        cout << "队列为空" << endl;
        return;
    }

    front = (front + 1) % length;

    cout << "front = " << front << ", rear = " << rear << endl;
}

template <typename T>
bool ringQueue<T>::full(){
    return front == (rear + 1) % length;
}

template <typename T>
bool ringQueue<T>::empty(){
    return rear == front;
}

template <typename T>
int ringQueue<T>::size(){
    return (rear - front + length) % length;
}

template <typename T>
T ringQueue<T>::frontData(){
    if(!empty()) return data[front];
}

int main(){
    ringQueue<int> rq(maxN);
    rq.push(1);
    rq.push(2);
    rq.push(3);
    rq.push(4);
    rq.push(5);
    rq.push(6);

    return 0;
}