class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> freq;
        for (int n: nums) {
            freq[n]++;
        }
        
        
        for (auto &p: freq) {
            if (p.second % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};