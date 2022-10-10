class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickMinutes = 0;
        int travelMinutes = 0;
        int travelG = 0;
        int travelM = 0;
        int travelP = 0;
        
        int sz = garbage.size();
        
        for (int i = 0; i < sz; i++) {
            for (char t: garbage[i]) {
                pickMinutes++;
                if (t == 'G') travelG = travelMinutes;
                if (t == 'P') travelP = travelMinutes;
                if (t == 'M') travelM = travelMinutes;
            }
            if (i < sz - 1) {
                travelMinutes += travel[i];
            }
        }
        
        return pickMinutes + travelG + travelM + travelP;
    }
};