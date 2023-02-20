class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int sz = nums.size();
        int minDif = INT32_MAX;
        int closest = INT32_MAX;
        
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                
                int partial = nums[i] + nums[j];
                int remaining = target - partial;
                
                int left = j + 1;
                int right = sz - 1;
                int middle = (left + right) / 2;
                
                while (left <= right) {
                    int middle = (left + right) / 2;
                    
                    int num = partial + nums[middle];
                    int dif = abs(num - target);
                    if (dif < minDif) {
                        minDif = dif;
                        closest = num;
                    }
                    
                    if (nums[middle] == remaining) {
                        return target;
                    } else if (remaining < nums[middle]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
                
                if (minDif == 0)
                    return closest;
            }
        }
        return closest;
    }
};