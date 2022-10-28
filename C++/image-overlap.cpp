class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxBits = 0;
        for (int offR = -n+1; offR < n; offR++) {
            for (int offC = -n+1; offC < n; offC++) {
                int bits = 0;
                for (int i = 0; i < n; i++) {
                    int i2 = i + offR;
                    if ((i2 >= 0) && (i2 < n)) {
                        for (int j = 0; j < n; j++) {
                            int j2 = j + offC;
                            if ((j2 >= 0) && (j2 < n)) {
                                if (img1[i][j] && img2[i2][j2]) {
                                    bits++;
                                }
                            }
                        }
                    }
                }
                if (maxBits < bits) {
                    maxBits = bits;
                }
            }
        }
        return maxBits;
    }
};