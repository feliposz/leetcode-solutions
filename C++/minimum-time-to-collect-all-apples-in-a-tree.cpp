class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<set<int>> tree(n);

        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }

        return dfs(n, 0, -1, tree, hasApple);
    }

    int dfs(int n, int i, int parent, vector<set<int>>& tree, vector<bool>& hasApple) {
        int totalTime = 0;
        for (auto child : tree[i]) {
            if (child == parent) {
                continue;
            }
            int childTime = dfs(n, child, i, tree, hasApple);
            if (childTime || hasApple[child]) {
                totalTime += childTime + 2;
            }
        }

        return totalTime;
    }
};