class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int expect = 1;
        for (int actual : arr) {
            while (expect < actual) {
                k--;
                if (k == 0) {
                    return expect;
                }
                expect++;
            }
            if (expect == actual) {
                expect++;
            }
        }
        while (k > 1) {
            expect++;
            k--;
        }
        return expect;
    }
};