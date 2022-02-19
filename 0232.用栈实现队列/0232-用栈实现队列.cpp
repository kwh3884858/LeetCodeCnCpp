class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        m_myQueue.push_back(x);
    }
    
    int pop() {
        int value = peek();
        m_myQueue.pop_front();
        return value;
    }
    
    int peek() {
        return *m_myQueue.begin();
        
    }
    
    bool empty() {
        return m_myQueue.empty();
    }

    deque<int> m_myQueue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */