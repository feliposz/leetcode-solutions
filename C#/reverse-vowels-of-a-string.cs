public class Solution {
    public string ReverseVowels(string s) {
        var vowels = new Stack<char>();
        foreach (char c in s)
        {
            if (IsVowel(c))
            {
                vowels.Push(c);
            }
        }
        var sb = new StringBuilder();
        foreach (char c in s)
        {
            if (IsVowel(c))
            {
                sb.Append(vowels.Pop());
            }
            else
            {
                sb.Append(c);
            }
        }
        return sb.ToString();
    }

    private static bool IsVowel(char c)
    {
        return c == 'a' || c == 'A'
            || c == 'e' || c == 'E'
            || c == 'i' || c == 'I'
            || c == 'o' || c == 'O'
            || c == 'u' || c == 'U';
    }
}