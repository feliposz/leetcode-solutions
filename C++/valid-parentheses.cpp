class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            switch (c) {
                case '(': stack.push_back(')'); break;
                case '[': stack.push_back(']'); break;
                case '{': stack.push_back('}'); break;
                case ')':
                case ']':
                case '}':
                    if (!stack.empty() && stack.back() == c)
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }
        return stack.empty();
    }
};