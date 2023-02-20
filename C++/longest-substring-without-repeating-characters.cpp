class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> freq;
        int j = 0, sz = s.size();
        int length = 0, maxlength = 0;
        
        for (int i = 0; i < sz; i++) {
            freq[s[i]]++;
            length++;
            while (freq[s[i]] > 1) {
                freq[s[j++]]--;
                length--;
            }
            maxlength = max(maxlength, length);
        }
        
        return maxlength;
    }
};