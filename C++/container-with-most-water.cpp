class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int n = height.size();
        
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int w = j - i;
            int h = min(height[i], height[j]);
            int a = w * h;
            maxA = max(a, maxA);
            if (h == height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return maxA;
    }
};