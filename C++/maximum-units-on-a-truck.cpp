class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });
        
        int units = 0;
        for (vector<int> &boxType: boxTypes) {
            int numberOfUnitsPerBox = boxType[1];
            int numberOfBoxes = boxType[0];
            while (numberOfBoxes > 0) {
                units += numberOfUnitsPerBox;
                numberOfBoxes--;
                truckSize--;
                if (truckSize <= 0) {
                   break;
                }
            }
            if (truckSize <= 0) {
                break;
            }
        }
        
        return units;
    }
};