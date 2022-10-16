class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for (vector<string> &rule: items) {
            int i = -1;
            if (ruleKey == "type") {
                i = 0;
            } else if (ruleKey == "color") {
                i = 1;
            } else if (ruleKey == "name") {
                i = 2;
            }
            if (rule[i] == ruleValue) {
                count++;
            }
        }
        return count;
    }
};