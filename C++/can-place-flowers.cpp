class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int planted = 0;
        
        for (int i = 0; i < sz; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i-1] == 0) && 
                    (i == sz - 1 || flowerbed[i+1] == 0)) {
                    flowerbed[i] = 1;
                    planted++;
                    if (planted >= n) {
                        return true;
                    }
                }
            }
        }
        
        return n == 0;
    }
};