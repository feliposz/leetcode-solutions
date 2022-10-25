class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a;
        string b;
        for (string w: word1) a += w;
        for (string w: word2) b += w;
        return a == b;
    }
};