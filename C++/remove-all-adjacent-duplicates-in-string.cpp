class Solution {
public:
    string removeDuplicates(string s) {        
        vector<char> stack;
        for (char c: s) {
            if (stack.empty() || c != stack.back())
            {
                stack.push_back(c);                
            } else {
                stack.pop_back();
            }
        }
        string t(stack.begin(), stack.end());
        return t;
    }
};