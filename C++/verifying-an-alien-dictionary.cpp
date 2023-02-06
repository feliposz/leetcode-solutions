class Solution {
public:
    map<char,char> dict;

    bool isAlienSorted(vector<string>& words, string order) {
        int nOrder = order.size();
        int nWords = words.size();

        for (int i = 0; i < nOrder; i++) {
            dict[order[i]] = i + 'a';
        }

        string a = translate(words[0]);
        for (int i = 1; i < nWords; i++) {
            string b = translate(words[i]);
            if (a > b) {
                return false;
            }
            a = b;
        }

        return true;
    }

    string translate(string word) {
        string result;
        for (char c: word) {
            result += dict[c];
        }
        return result;
    }
};