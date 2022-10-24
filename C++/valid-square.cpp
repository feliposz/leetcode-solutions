class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> edges;
        
        edges.push_back(lengthSq(p1, p2));
        edges.push_back(lengthSq(p1, p3));
        edges.push_back(lengthSq(p1, p4));
        edges.push_back(lengthSq(p2, p3));
        edges.push_back(lengthSq(p2, p4));
        edges.push_back(lengthSq(p3, p4));
        
        sort(edges.begin(), edges.end());
        
        return (edges[0] == edges[1])
            && (edges[0] == edges[2])
            && (edges[0] == edges[3])
            && (edges[0] != edges[4])
            && (edges[4] == edges[5]);
    }

    int lengthSq(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) +  (a[1] - b[1]) * (a[1] - b[1]);
    }

};