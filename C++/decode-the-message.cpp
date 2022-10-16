class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> code;
        char l = 'a';
        for (char k: key) {
            if ((k >= 'a') && (k <= 'z') && (code[k] == 0)) {
                code[k] = l++;
            }
        }
        
        string decoded;
        for (char c: message) {
            if (code[c] > 0) {
                decoded += code[c];
            } else {
                decoded += c;
            }
        }
        
        return decoded;
    }
};