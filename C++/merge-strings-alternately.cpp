class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, sz1 = word1.size(), sz2 = word2.size();
        
        string s;
        
        while ((i < sz1) && (j < sz2)) {
            s += word1[i++];
            s += word2[j++];
        }

        while (i < sz1) {
            s += word1[i++];
        }
        
        while (j < sz2) {
            s += word2[j++];            
        }
        
        return s;
    }
};