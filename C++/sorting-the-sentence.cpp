class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        
        string word;
       
        for (char c: s) {
            if ((c >= '1') && (c <= '9')) {
                int pos = c - '1';
                words[pos] = word;
                word = "";
            } else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
                word += c;
            }
        }
        
        string ans;
        
        for (int i = 0; i < 9; i++) {
            if (words[i].length() == 0) {
                break;
            }            
            if (i > 0) {
                ans += ' ';
            }
            ans += words[i];    
        }    
        
        return ans;
    }
};