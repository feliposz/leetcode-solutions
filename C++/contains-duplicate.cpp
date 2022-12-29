class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> dup;
        
        for (int n: nums) {
            if (dup.count(n))
                return true;
            dup.insert(n);
        }
        
        return false;
    }
};