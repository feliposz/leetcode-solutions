class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> balls(100);
        for (int n = lowLimit; n <= highLimit; n++) {
            int sum = 0;
            int x = n;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            balls[sum]++;
        }
        int max = 0;
        for (int i = 1; i < 100; i++) {
            if (max < balls[i]) {
                max = balls[i];
            }
        }
        return max;
    }
};