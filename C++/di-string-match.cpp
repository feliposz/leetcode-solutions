class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> perm(n + 1);
        for (int i = 0; i <= n; i++) {
            perm[i] = i;
        }
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; i++) {
                if ((s[i] == 'I' && perm[i] > perm[i+1]) || 
                    (s[i] == 'D' && perm[i] < perm[i+1])) {
                    swap(perm[i], perm[i+1]);             
                    changed = true;
                }
            }
        }
        return perm;
    }
};