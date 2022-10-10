class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int data = first;
        vector<int> ans;
        ans.push_back(first);
        for (int e: encoded) {
           data = data ^ e;
            ans.push_back(data);
        }
        return ans;
    }
};