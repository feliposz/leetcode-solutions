class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letter(26);
        for (char c: sentence) {
            letter[c - 'a']++;
        }
        for (int n: letter) {
            if (n == 0) {
                return false;
            }
        }
        return true;
    }
};