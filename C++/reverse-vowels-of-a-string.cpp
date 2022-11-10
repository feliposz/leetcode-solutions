class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        
        for (char c: s) {
            switch(c) {
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
                    vowels.push_back(c);
                    break;
            }
        }
        
        string t;
        for (char c: s) {
            switch(c) {
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
                    t += vowels.back();
                    vowels.pop_back();
                    break;
                default:
                    t += c;
            }            
        }
        return t;
    }
};