class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        
        set<string> transformations;
        
        for (string &word: words) {
            string code;
            for (char c: word) {
                code += morse[c - 'a'];
            }
            transformations.insert(code);
        }
        
        return transformations.size();       
    }
};