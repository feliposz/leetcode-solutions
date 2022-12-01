class Solution {
public:
    vector<vector<int>> paths;
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int sz = graph.size();
        walkPath(0, sz-1, graph, {});
        return paths;
    }
    
    void walkPath(int source, int target, vector<vector<int>>& graph, vector<int> path)
    {
        path.push_back(source);
        if (source == target) {            
            paths.push_back(path);
            return;
        }
        for (int n: graph[source]) {
            walkPath(n, target, graph, path);
        }
    }
};