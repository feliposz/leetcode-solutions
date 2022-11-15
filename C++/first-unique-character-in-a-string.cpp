class Solution {
public:
    int firstUniqChar(string s) {
        int letters[26];
        
        for (int i = 0; i < 26; i++) 
            letters[i] = 0;
        
        for (char c : s)
            letters[c - 'a']++;
        
        int pos = 0;
        for (char c : s) {
            if (letters[c - 'a'] == 1) {
                return pos;
            }
            pos++;
        }
        
        return -1;
    }
};