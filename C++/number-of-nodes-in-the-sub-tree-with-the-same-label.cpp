class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
         vector<set<int>> tree(n);

         for (auto edge : edges) {
             tree[edge[0]].insert(edge[1]);
             tree[edge[1]].insert(edge[0]);
         }

         vector<int> ans(n);
         dfs(0, -1, tree, labels, ans);

         return ans;
    }

    vector<int> dfs(int i, int parent, vector<set<int>>& tree, string& labels, vector<int> &ans) {
        vector<int> nodeCounts(26);
        nodeCounts[labels[i] - 'a'] = 1;

        for (int child : tree[i]) {
            if (child == parent) {
                continue;
            }
            vector<int> childCounts = dfs(child, i, tree, labels, ans);
            for (int j = 0; j < 26; j++) {
                nodeCounts[j] += childCounts[j];
            }
        }
        ans[i] = nodeCounts[labels[i] - 'a'];
        return nodeCounts;
    }
};