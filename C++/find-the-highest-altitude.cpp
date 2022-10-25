class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;
        for (int g: gain) {
            altitude += g;
            if (maxAltitude < altitude) {
                maxAltitude = altitude;
            }
        }
        return maxAltitude;
    }
};