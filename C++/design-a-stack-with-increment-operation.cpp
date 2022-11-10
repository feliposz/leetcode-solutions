class CustomStack {
public:
    vector<int> stack;
    int maxSz;
    
    CustomStack(int maxSize) {
        maxSz = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSz) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        int x = -1;
        if (stack.size() > 0) {
            x = stack.back();
            stack.pop_back();
        }
        return x;
    }
    
    void increment(int k, int val) {
        int sz = min((int)stack.size(), k);
        for (int i = 0; i < sz; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */