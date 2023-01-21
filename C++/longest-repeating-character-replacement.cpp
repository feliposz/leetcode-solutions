class Solution {
public:
    int characterReplacement(string s, int k) {
        int minLen = 1;
        int maxLen = s.size() + 1;

        while (minLen + 1 < maxLen) {
            int len = minLen + (maxLen - minLen) / 2;
            if (canReplace(s, k, len)) {
                minLen = len;
            } else {
                maxLen = len;
            }
        }
        
        return minLen;
    }

    bool canReplace(string &s, int k, int len) {
        int start = 0;
        int end = 0;
        int n = s.size();
        map<char,int> freq;
            
        int maxFreq  = 0;
        for (int end = 0; end < n; end++) {

            if (end - start + 1 > len) {
                freq[s[start]]--;
                start++;
            }
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);
            if (len - maxFreq <= k) {
                return true;
            }
        }

        return false;
    }
};