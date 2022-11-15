class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26];
        for (int i = 0; i < 26; i++)
        {
            letters[i] = 0;
        }

        for (char c : magazine)
        {
            letters[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            if (letters[c - 'a']-- <= 0) {
                return false;
            }                
        }

        return true;
    }
};