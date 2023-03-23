class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        
        map<char, int> letters;
        map<char, int> anagram;
        
        for (int i = 0; i < pl; i++) {            
            letters[s[i]]++;
            anagram[p[i]]++;
        }
        
        vector<int> ans;
        
        for (int i = 0; i < sl - pl + 1; i++) {
            bool isAnagram = true;
            for (auto l: letters) {
                if (l.second != anagram[l.first]) {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram) {
                ans.push_back(i);
            }
            letters[s[i]]--;
            letters[s[i+pl]]++;
        }
        
        return ans;
    }
};