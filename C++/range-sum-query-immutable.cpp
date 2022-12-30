class NumArray {
public:
    vector<int> data;
    
    NumArray(vector<int>& nums) {
        int acc = 0;
        for (int n: nums) {
            acc += n;
            data.push_back(acc);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = data[right];
        if (left > 0) {
            sum -= data[left-1];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */