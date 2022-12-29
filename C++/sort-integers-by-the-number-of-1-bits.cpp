class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int na = countBits(a), nb = countBits(b);
            if (na == nb) {
                return a < b;
            } else {
                return na < nb;
            }
        });
        return arr;
    }

    int countBits(int x) {
        int c = 0;
        while (x) {
            c += x & 1;
            x >>= 1;
        }
        return c;
    };

};