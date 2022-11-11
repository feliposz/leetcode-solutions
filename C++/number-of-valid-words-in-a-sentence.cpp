class Solution
{
public:
    int countValidWords(string sentence)
    {
        sentence += ' ';

        int count = 0;
        int sz = sentence.size();
        string word;
        for (int i = 0; i < sz; i++)
        {
            if (sentence[i] == ' ')
            {
                if (word.size())
                {
                    cout << word;
                    if (checkWord(word))
                    {
                        cout << " OK > " << ++count;
                    }
                    cout << '\n';
                }
                word = "";
            }
            else
            {
                word += sentence[i];
            }
        }

        return count;
    }

    bool isPunct(char c)
    {
        return c == '!' || c == '.' || c == ',';
    }

    bool checkWord(string word)
    {
        int hyphens = 0;
        int punct = 0;
        int digits = 0;
        int letters = 0;
        int other = 0;
        int sz = word.size();

        for (char c : word)
        {
            if (c >= '0' && c <= '9')
                digits++;
            else if (c == '-')
                hyphens++;
            else if (isPunct(c))
                punct++;
            else if (c >= 'a' && c <= 'z')
                letters++;
            else
                other++;
        }

        if (digits > 0 || other > 0 || hyphens > 1 || punct > 1)
        {
            return false;
        }

        if (punct == 1)
        {
            if (!isPunct(word[sz - 1]))
            {
                return false;
            }
            else if (hyphens == 1 && sz >= 2 && word[sz - 2] == '-')
            {
                return false;
            }
        }

        if (hyphens == 1 && word[0] == '-' || word[sz - 1] == '-')
        {
            return false;
        }

        return true;
    }
};