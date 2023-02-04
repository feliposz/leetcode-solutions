class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hist1(26, 0);
        vector<int> hist2(26, 0);

        int sz1 = s1.size();        
        int sz2 = s2.size();
        
        if (sz1 > sz2) {
            return false;
        }

        for (int i = 0; i < sz1; i++) {
            hist1[s1[i] - 'a']++;
        }
        
        int i = 0;
        for (i = 0; i < sz1; i++) {
            hist2[s2[i] - 'a']++;
        }

        if (hist1 == hist2) {
            return true;
        }

        for (; i < sz2; i++) {
            hist2[s2[i-sz1] - 'a']--;
            hist2[s2[i] - 'a']++;
            if (hist1 == hist2) {
                return true;
            }
        }
        
        return false;
    }
};