class MinStack {
    vector<int> m;
    vector<int> v;
    int minVal = INT32_MAX;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        m.push_back(minVal);
        minVal = min(val, minVal);
        v.push_back(val);
    }
    
    void pop() {
        minVal = m.back();
        m.pop_back();
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */