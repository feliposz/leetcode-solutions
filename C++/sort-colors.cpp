class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0, 0, 0};
        for (int c: nums) {
            colors[c]++;
        }
        int j = 0;
        for (int i = 0; i < 3; i++) {
            while (colors[i]-- > 0) {
                nums[j++] = i;
            }
        }
    }
};