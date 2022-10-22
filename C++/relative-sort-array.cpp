class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        
        for (int n: arr1) {
            m[n]++;
        }
        
        vector<int> ans;
        
        for (int n: arr2) {
            if (m[n] > 0) {
                while (m[n]--) {
                    ans.push_back(n);
                }
            }
        }

        for (auto &p: m) {
            if (p.second > 0) {
                while (p.second--) {
                    ans.push_back(p.first);
                }    
            }
        }
        
        return ans;
    }
};