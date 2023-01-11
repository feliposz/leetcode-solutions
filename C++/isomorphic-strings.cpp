class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[256], mapT[256];
        int sz = s.size();
        
        for (int i = 0; i < 256; i++) {
            mapS[i] = -1;
            mapT[i] = -1;
        }
        
        for (int i = 0; i < sz; i++) {
            char a = s[i];
            char b = t[i];
            if (mapS[a] == -1) {
                mapS[a] = b;
            } 
            
            if (mapT[b] == -1) {
                mapT[b] = a;
            } 
            
            if ((mapS[a] != b) || (mapT[b] != a)) {
                return false;
            }
        }
        
        return true;
    }
};