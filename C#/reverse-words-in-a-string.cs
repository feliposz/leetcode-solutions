public class Solution {
    public string ReverseWords(string s) {
        var words = s.Split(' ', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
        return String.Join(' ', words.Reverse());
    }
}