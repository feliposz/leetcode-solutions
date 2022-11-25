class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b;
        for (int n : nums2) {
            if (a.count(n)) {
                b.insert(n);
            }
        }
        vector<int> ans(b.begin(), b.end());
        return ans;
    }
};