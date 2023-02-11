class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        
        for (string &w: words) {
            m[w]++;
        }
        
        int len = 0;
        
        for (auto &p: m) {
            string k = p.first;
            
            if (p.second > 0) {
                string rev_k(k.rbegin(), k.rend());

                if (k == rev_k) {
                    while (m[k] >= 2) {
                        m[k] -= 2;
                        len += 4;
                    }
                }
                else if (m[rev_k] > 0) {
                    while ((m[k] > 0) && (m[rev_k] > 0)) {
                        m[k]--;
                        m[rev_k]--;
                        len += 4;                        
                    }
                }
            }            
        }
        
        for (auto &p: m) {
            string k = p.first;
            
            if (p.second == 1) {
                string rev_k(k.rbegin(), k.rend());

                if (k == rev_k) {
                    len += 2;
                    break;
                }
            }
        }
        
        return len;
    }
};