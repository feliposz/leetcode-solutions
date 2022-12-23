class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < sz1; i++) {
            int x = -1;
            for (int j = 0; j < sz2; j++) {
                if (nums1[i] == nums2[j]) {
                    j++;
                    while (j < sz2) {
                        if (nums2[j] > nums1[i]) {
                            x = nums2[j];
                            break;
                        }
                        j++;
                    }
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};