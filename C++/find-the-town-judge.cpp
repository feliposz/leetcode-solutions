class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n), trusted(n);

        for (auto t: trust) {
            trusts[t[0]-1]++;
            trusted[t[1]-1]++;
        }

        int judge = -1;

        for (int i = 0; i < n; i++) {
            if (trusts[i] == 0 && trusted[i] == n - 1) {
                judge = i + 1;
            }
        }

        return judge;
    }
};