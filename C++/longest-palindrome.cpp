class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letters;
        for (char c : s)
        {
            letters[c]++;
        }

        int ans = 0;

        int maxOdd = 0;
        char oddChar = '\0';

        for (auto it : letters)
        {
            char c = it.first;
            int n = it.second;

            if (n % 2 == 0)
            {
                ans += n;
            }
            else
            {
                if (n > 2)
                {
                    ans += n - 1;
                }

                if (n > maxOdd)
                {
                    maxOdd = n;
                    oddChar = c;
                }
            }
        }

        if (maxOdd)
        {
            ans += 1;
        }

        return ans;
    }
};