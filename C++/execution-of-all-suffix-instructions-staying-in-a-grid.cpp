class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        vector<int> ans;
        
        int sz = s.size();
        
        for (int i = 0; i < sz; i++) {

            int row = startPos[0];
            int col = startPos[1];
            int count = 0;
            
            for (int j = i; j < sz; j++) {
                switch(s[j]) {
                    case 'L': col--; break;
                    case 'R': col++; break;
                    case 'U': row--; break;
                    case 'D': row++; break;                        
                }
                if ((col >= 0) && (col < n) && (row >= 0) && (row < n)) {
                    count++;
                } else {
                    break;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;        
    }
};