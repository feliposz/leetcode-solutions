class Solution {
public:
    string reversePrefix(string word, char ch) {
        int sz = word.size();
        int pos = -1;
        for (int i = 0; i < sz; i++) {
            if (word[i] == ch) {
                pos = i;
                break;
            }
        }
        if (pos >= 0) {
            for (int i = 0, j = pos; i < j; i++, j--) {
                swap(word[i], word[j]);
            }            
        }
        return word;
    }
};