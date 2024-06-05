class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int count[26][100] = {0};
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (const char c : words[i]) {
                count[c-'a'][i]++;
            }
        }
        for (int c = 0; c < 26; c++) {
            int common = 100;
            for (int i = 0; i < n; i++) {
                common = min(common, count[c][i]);
            }
            string s(1, c + 'a');
            result.resize(result.size() + common, s);
        }
        return result;
    }
};