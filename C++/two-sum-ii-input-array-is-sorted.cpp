class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        for (int i = 0; i < sz; i++) {
            int other = target - numbers[i];
            int j = i + 1, k = sz - 1;
            while (j <= k) {
                int mid = (j + k) / 2;
                if (numbers[mid] == other) {
                    return {i + 1, mid + 1};
                } else if (other < numbers[mid]) {
                    k = mid - 1;
                } else {
                    j = mid + 1;
                }                    
            }
        }
        return {-1, -1};
    }
};