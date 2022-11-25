class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        
        set<vector<int>> ans;
       
        for (int i = 0; i < sz - 2; i++) {
            int left = i + 1;
            int right = sz - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    add(ans, nums[i], nums[left++], nums[right--]);
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        vector<vector<int>> vans(ans.begin(), ans.end());
        return vans;
    }

    void add(set<vector<int>> &ans, int a, int b, int c) {
        vector<int> v = {a, b, c};
        //sort(v.begin(), v.end());
        ans.insert(v);             
    }    
    
};