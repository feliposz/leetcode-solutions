class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        
        while (q.size() > 1) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x != y) {
                q.push(y - x);
            }
        }
        
        if (q.size() == 0) {
            return 0;
        }
        
        return q.top();
    }
};