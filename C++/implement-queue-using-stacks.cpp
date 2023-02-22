class MyQueue {
public:
    vector<int> in, out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        transfer(out, in);
        in.push_back(x);
    }
    
    int pop() {
        transfer(in, out);
        int result = out.back();
        out.pop_back();
        return result;
    }
    
    int peek() {
        transfer(in, out);
        return out.back();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
    
    void transfer(vector<int> &src, vector<int> &dst) {
        while (!src.empty()) {
            dst.push_back(src.back());
            src.pop_back();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */