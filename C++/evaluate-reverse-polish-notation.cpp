class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long> stack;
        
        for (string &t: tokens) {
            if ((t == "+") || (t == "-") || (t == "*") || (t == "/")) {
                long a = stack.back();
                stack.pop_back();
                long b = stack.back();
                stack.pop_back();
                long c = 0;
                if (t == "+") {
                    c = a + b;
                }
                if (t == "-") {
                    c = b - a;
                }
                if (t == "*") {
                    c = a * b;
                } 
                if (t == "/") {
                    c = b / a;
                }
                stack.push_back(c);
            } else {
                stack.push_back(stoi(t));
            }
        }
        return (int)stack.back();
    }
};