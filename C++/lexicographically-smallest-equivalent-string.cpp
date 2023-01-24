class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,set<char>> m;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            char a = s1[i];
            char b = s2[i];
            m[a].insert(b);
            m[b].insert(a);
        }
        string ans;
        for (char c : baseStr) {
            set<char> tmp;
            ans += smallest(c, m, tmp);
        }
        return ans;
    }

    char smallest(char c, map<char,set<char>> &m, set<char> &visited) {
        if (!visited.count(c)) {
            visited.insert(c);
            for (char d : m[c]) {
                smallest(d, m, visited);
            }
        }
        return *visited.begin();
    }
};