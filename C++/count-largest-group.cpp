class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> group;
        int largest = 0;
        for (int x = 1; x <= n; x++) {
            int digits = sumDigits(x);
            group[digits]++;
            if (largest < group[digits]) {
                largest = group[digits];
            }
        }
        
        int count = 0;
        for (auto g: group) {
            if (g.second == largest) {
                count++;
            }
        }
        return count;
    }
    
    int sumDigits(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};