class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> freq;
        int maxCount = 0;
        int maxN = -1;
        for (int n: nums) {
            freq[n]++;
            if (maxCount < freq[n]) {
                maxCount = freq[n];
                maxN = n;
            }
        }
        return maxN;
    }
};