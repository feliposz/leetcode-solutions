class MyStack {
public:
    queue<int> a, b;
    
    MyStack() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int result = a.front();
        a.pop();
        swap(a, b);        
        return result;
    }
    
    int top() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int result = a.front();
        b.push(a.front());
        a.pop();
        swap(a, b);        
        return result;
    }
    
    bool empty() {
        return a.size() == 0 && b.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */