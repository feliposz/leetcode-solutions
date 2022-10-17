class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for (char c: s) {
            if (c == '(') depth++;
            if (c == ')') depth--;
            if (maxDepth < depth) maxDepth = depth;
        }
        return maxDepth;
    }
};