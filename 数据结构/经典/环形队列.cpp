
const int maxn = 100;

template <class T>
class ringQueue {
public:
    ringQueue();
    ringQueue(const int len);
    ~ringQueue();
public:
    bool empty();
    bool full();
    void push(T x);
    void pop();
    T front();
    int size();

public:
    void resize();

private:
    T *m_data;
    int m_front;
    int m_rear;
    int m_length;
};

template <class T>
ringQueue<T>::ringQueue(){
    m_front = 0;
    m_rear = 0;
    m_data = new T[maxn];
    m_length = maxn;
}

template <class T>
ringQueue<T>::ringQueue(const int len){
    m_front = 0;
    m_rear = 0;
    m_data = new T[len];
    m_length = len;
}

template <class T>
ringQueue<T>::~ringQueue(){
    delete[] m_data;
    m_data = nullptr;
}

template <class T>
bool ringQueue<T>::empty(){
    return m_front == m_rear;
}

template <class T>
bool ringQueue<T>::full(){
    return m_front == (m_rear + 1) % m_length;
}

template <class T>
void ringQueue<T>::push(T x){
    if(full()){
        resize();
    }
    m_data[m_rear] = x;
    m_rear = (m_rear + 1) % m_length;
}

template <class T>
void ringQueue<T>::pop(){
    if(empty()){
        return;
    }
    m_front = (m_front + 1) % m_length;
}

template <class T>
T ringQueue<T>::front(){
    if(!empty()){
        return m_data[m_front];
    }
}

template <class T>
int ringQueue<T>::size(){
    return (m_rear - m_front + m_length) % m_length;
}

template <class T>
void ringQueue<T>::resize(){
    int len = int(m_length * 1.5);
    T *tmp = new T[len];
    int count = 0;
    for(int i = m_front; i != m_rear; i = (i + 1) % m_length){
        tmp[count++] = m_data[i];
    }
    m_front = 0;
    m_rear = count;
    m_length = len;
    delete[] m_data;
    m_data = tmp;
}
