class Solution {
public:
    int strStr(string haystack, string needle) {
        int szH = haystack.size(), szN = needle.size();
        
        for (int i = 0; i < (szH - szN + 1); i++) {
            int j = 0;
            for (j = 0; j < szN; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == szN) {
                return i;
            }                
        }
        
        return -1;
    }
};