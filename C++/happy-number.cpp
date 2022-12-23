class Solution {
public:
    bool isHappy(int n) {
        set<int> tested;
        
        int tmp = n;
        while (tmp != 1) {
            tested.insert(tmp);
            tmp = sumSqDig(tmp);
            if (tested.find(tmp) != tested.end())
                return false;            
        }
        
        return true;
    }
    
    int sumSqDig(int n) {
        int r = 0;
        while (n > 0) {
            int d = n % 10;
            r += d * d;
            n /= 10;
        }
        return r;
    }
};