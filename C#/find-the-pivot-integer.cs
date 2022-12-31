public class Solution {
    public int PivotInteger(int n) {
        if (n == 1) {
            return 1;
        }
        int total = (1 + n) * n / 2;
        int mid = n / 2;        
        for (int x = mid; x < n; x++) {
            int low = (1 + x) * x / 2;
            int high = total - low + x;
            if (low == high) {
                return x;
            } else if (low > high) {
                break;
            }
        }
        return -1;
    }
}