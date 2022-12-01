class Solution {
public:
    bool halvesAreAlike(string s) {
        int a = countVowels(s.substr(0, s.size() / 2));
        int b = countVowels(s.substr(s.size() / 2));
        return a == b;
    }
    
    int countVowels(string s) {
        int count = 0;
        for (char c: s) {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    count++;
                    break;
            }
        }
        return count;
    }
};