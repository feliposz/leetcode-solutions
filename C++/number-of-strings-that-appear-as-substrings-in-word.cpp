class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int num = 0;
        for (string &p: patterns) {
            if (word.find(p) != string::npos) {
                num++;
            }
        }
        return num;
    }
};