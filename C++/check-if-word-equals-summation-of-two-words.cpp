class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return wordValue(firstWord) + wordValue(secondWord) == wordValue(targetWord);
    }
    
    int wordValue(string s) {
        int value = 0;
        for (char c: s) {
            value = value * 10 + c - 'a';
        }
        return value;
    }
};