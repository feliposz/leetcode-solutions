class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int sz = arr.size();
        int count = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (abs(arr[i] - arr[j]) <= a)
                {
                    for (int k = j + 1; k < sz; k++) {
                        if ((abs(arr[j] - arr[k]) <= b) && (abs(arr[i] - arr[k]) <= c)) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};