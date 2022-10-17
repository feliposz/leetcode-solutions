class Solution {
public:
    
    int findCenter(vector<vector<int>>& edges) {
        vector<int> nodes(edges.size() + 2);
        for (vector<int> &edge: edges) {
            nodes[edge[0]]++;
            nodes[edge[1]]++;
            if (nodes[edge[0]] > 1) {
                return edge[0];
            } else if (nodes[edge[1]] > 1) {
                return edge[1];
            }
        }
        return -1;
    }
};