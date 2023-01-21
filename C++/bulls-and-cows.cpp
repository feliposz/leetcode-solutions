class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int len = secret.length();
        map<char, int> m;
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            m[secret[i]]++;
        }
        
        for (int i = 0; i < len; i++) {
            if (m[guess[i]]) {
                m[guess[i]]--;
                cows++;
            }
        }
        
        cows -= bulls;
        
        string s = to_string(bulls) + "A" + to_string(cows) + "B";
        
        return s;
    }
};