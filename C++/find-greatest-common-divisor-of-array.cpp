class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto a = min_element(nums.begin(), nums.end());
        auto b = max_element(nums.begin(), nums.end());
        return gcd(*a, *b);
    }
    
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        
        if (b == 0) {
            return a;
        }
        
        if (a == b) {
            return a;
        }
        
        if (a > b) {
            return gcd(a-b, b);
        } else {
            return gcd(a, b-a);
        }
    }
};