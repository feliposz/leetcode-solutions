class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            int v = 0;
            switch (c)
            {
                case 'I': v = 1; break;
                case 'V': v = 5; break;
                case 'X': v = 10; break;
                case 'L': v = 50; break;
                case 'C': v = 100; break;
                case 'D': v = 500; break;
                case 'M': v = 1000; break;
            }
            if ((i + 1) < s.length())
            {
                char n = s[i + 1];
                if ((c == 'I') && ((n == 'V') || (n == 'X')))
                {
                    v = -1;
                } 
                else  if ((c == 'X') && ((n == 'L') || (n == 'C')))
                {
                    v = -10;
                }
                else if ((c == 'C') && ((n == 'D') || (n == 'M')))
                {
                    v = -100;
                }
            }
            result += v;
        }
        return result;
    }
};