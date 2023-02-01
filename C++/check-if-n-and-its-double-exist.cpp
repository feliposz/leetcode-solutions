class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> nums;
        
        for (int i = 0; i < arr.size(); i++) {
            int n = arr[i];
            nums[n] = i;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            int n = arr[i];
            if (nums.count(n*2) && i != nums[n*2]) {
                return true;
            }
        }
        
        return false;
    }
};