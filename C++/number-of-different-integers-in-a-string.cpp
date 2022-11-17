class Solution {
public:
    int numDifferentIntegers(string word) {
        int sz = word.size();
        string val;
        set<string> nums;
        bool valid = false;
        for (int i = 0; i <= sz; i++) {
            if (i < sz && word[i] >= '0' && word[i] <= '9') {
                val += word[i];
                valid = true;
            } else {
                if (valid) {
                    val = stripZeros(val);
                    if (val.size() > 0) {
                        nums.insert(val);
                    } else {
                        nums.insert("0");
                    }
                }
                val = "";
                valid = false;
            }
        }
        return nums.size();
    }
    
    string stripZeros(string s) {
        int pos = 0;
        while (s[pos] == '0') {
            pos++;
        }
        return s.substr(pos);
    }
};