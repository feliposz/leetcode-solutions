class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        
        vector<int> v(s1 + s2);
        
        int i = 0, j = 0, k = 0;
        
        while ((i < s1) && (j < s2)) {
            if (nums1[i] < nums2[j]) {
                v[k++] = nums1[i++];
            } else {
                v[k++] = nums2[j++];
            }
        }

        while (i < s1) {
            v[k++] = nums1[i++];
        }
        
        while (j < s2) {
            v[k++] = nums2[j++];
        }
            
        int target1 = (s1 + s2) / 2;
        int target2 = target1;
        
        if ((s1 + s2) % 2 == 0) {
            target1--;
        }
        
        double d1 = v[target1];
        double d2 = v[target2];

        return (d1 + d2) / 2.0;
    }
};